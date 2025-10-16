%% Video Compression Model - Otomatik Oluşturma (DÜZELTME)
% Tüm blokları ve bağlantıları otomatik olarak oluşturur
clear; clc; close all;

fprintf('========================================\n');
fprintf('VIDEO COMPRESSION MODEL OLUŞTURULUYOR\n');
fprintf('========================================\n\n');

%% Model Parametreleri
modelName = 'step2_compression_simulation';
modelPath = 'models/video_compression/';

% Tam yol
if ~exist(modelPath, 'dir')
    mkdir(modelPath);
end

fullModelPath = fullfile(modelPath, modelName);

%% Eski Modeli Temizle
if bdIsLoaded(modelName)
    close_system(modelName, 0);
    fprintf('✓ Eski model kapatıldı\n');
end

if exist([fullModelPath '.slx'], 'file')
    delete([fullModelPath '.slx']);
    fprintf('✓ Eski model dosyası silindi\n');
end

%% Yeni Model Oluştur
fprintf('\n1. Yeni model oluşturuluyor...\n');
h = new_system(modelName, 'Model');
open_system(h);

%% Blok Pozisyonları (Düzenli görünüm için)
pos = struct();
pos.video_source = [30, 100, 180, 150];
pos.bitrate_const = [30, 200, 120, 230];

pos.compressor = [250, 100, 400, 200];
pos.psnr = [250, 250, 400, 350];
pos.ssim = [250, 400, 400, 500];

pos.goto_compressed = [450, 130, 500, 150];
pos.from_psnr = [450, 280, 500, 300];
pos.from_ssim = [450, 430, 500, 450];
pos.from_viewer = [450, 560, 500, 580];

pos.disp_bitrate = [450, 180, 550, 210];
pos.disp_psnr = [550, 280, 650, 310];
pos.disp_ssim = [550, 430, 650, 460];

pos.viewer_orig = [250, 550, 380, 630];
pos.viewer_comp = [550, 550, 680, 630];

%% 1. VIDEO SOURCE
fprintf('2. Video Source bloğu ekleniyor...\n');

% From Multimedia File bulma denemeleri
videoSourcePaths = {
    'visionutilities/From Multimedia File'
    'computervision/From Multimedia File'
    'vision/From Multimedia File'
};

videoSourceAdded = false;
for i = 1:length(videoSourcePaths)
    try
        add_block(videoSourcePaths{i}, [modelName '/Video_Source'], ...
                  'Position', pos.video_source);
        fprintf('  ✓ Video Source eklendi: %s\n', videoSourcePaths{i});
        videoSourceAdded = true;
        break;
    catch
        % Bu yol çalışmadı, devam et
    end
end

if ~videoSourceAdded
    fprintf('  ⚠ Video Source bulunamadı, manuel ekleme gerekebilir\n');
end

% Video parametrelerini ayarla
videoFile = fullfile(pwd, 'data', 'input_videos', 'test_video.mp4');
if exist(videoFile, 'file') && videoSourceAdded
    try
        set_param([modelName '/Video_Source'], ...
                  'Filename', videoFile, ...
                  'PlayCount', 'inf');
        fprintf('  ✓ Video dosyası ayarlandı\n');
    catch
        fprintf('  ⚠ Video parametreleri manuel ayarlanmalı\n');
    end
end

%% 2. TARGET BITRATE CONSTANT
fprintf('3. Target Bitrate bloğu ekleniyor...\n');
add_block('simulink/Sources/Constant', [modelName '/Target_Bitrate_Mbps'], ...
          'Value', '2', ...
          'Position', pos.bitrate_const);
fprintf('  ✓ Target Bitrate (2 Mbps) eklendi\n');

%% 3. VIDEO COMPRESSOR (MATLAB Function)
fprintf('4. Video Compressor bloğu ekleniyor...\n');
compressorBlock = [modelName '/Video_Compressor'];
add_block('simulink/User-Defined Functions/MATLAB Function', ...
          compressorBlock, ...
          'Position', pos.compressor);

fprintf('  ℹ Video Compressor kodu manuel girilecek\n');

%% 4. PSNR CALCULATOR (MATLAB Function)
fprintf('5. PSNR Calculator bloğu ekleniyor...\n');
psnrBlock = [modelName '/PSNR_Calculator'];
add_block('simulink/User-Defined Functions/MATLAB Function', ...
          psnrBlock, ...
          'Position', pos.psnr);

fprintf('  ℹ PSNR Calculator kodu manuel girilecek\n');

%% 5. SSIM CALCULATOR (MATLAB Function)
fprintf('6. SSIM Calculator bloğu ekleniyor...\n');
ssimBlock = [modelName '/SSIM_Calculator'];
add_block('simulink/User-Defined Functions/MATLAB Function', ...
          ssimBlock, ...
          'Position', pos.ssim);

fprintf('  ℹ SSIM Calculator kodu manuel girilecek\n');

%% 6. GOTO/FROM BLOKLAR (Dallanma için)
fprintf('7. Goto/From blokları ekleniyor...\n');

% Goto - Compressed
add_block('simulink/Signal Routing/Goto', ...
          [modelName '/Goto_Compressed'], ...
          'GotoTag', 'compressed_video', ...
          'Position', pos.goto_compressed);

% From blokları
add_block('simulink/Signal Routing/From', ...
          [modelName '/From_PSNR'], ...
          'GotoTag', 'compressed_video', ...
          'Position', pos.from_psnr);

add_block('simulink/Signal Routing/From', ...
          [modelName '/From_SSIM'], ...
          'GotoTag', 'compressed_video', ...
          'Position', pos.from_ssim);

add_block('simulink/Signal Routing/From', ...
          [modelName '/From_Viewer'], ...
          'GotoTag', 'compressed_video', ...
          'Position', pos.from_viewer);

fprintf('  ✓ Goto/From blokları eklendi\n');

%% 7. DISPLAY BLOKLAR
fprintf('8. Display blokları ekleniyor...\n');

add_block('simulink/Sinks/Display', [modelName '/Display_Bitrate'], ...
          'Position', pos.disp_bitrate);

add_block('simulink/Sinks/Display', [modelName '/Display_PSNR'], ...
          'Position', pos.disp_psnr);

add_block('simulink/Sinks/Display', [modelName '/Display_SSIM'], ...
          'Position', pos.disp_ssim);

fprintf('  ✓ Display blokları eklendi\n');

%% 8. VIDEO VIEWERS
fprintf('9. Video Viewer blokları ekleniyor...\n');

viewerPaths = {
    'visionutilities/Video Viewer'
    'computervision/Video Viewer'
    'vision/Video Viewer'
};

viewerAdded = false;
for i = 1:length(viewerPaths)
    try
        add_block(viewerPaths{i}, [modelName '/Video_Viewer_Original'], ...
                  'Position', pos.viewer_orig);
        add_block(viewerPaths{i}, [modelName '/Video_Viewer_Compressed'], ...
                  'Position', pos.viewer_comp);
        fprintf('  ✓ Video Viewer blokları eklendi\n');
        viewerAdded = true;
        break;
    catch
        % Bu yol çalışmadı
    end
end

if ~viewerAdded
    fprintf('  ⚠ Video Viewer eklenemedi\n');
end

%% 9. BAĞLANTILAR (CONNECTIONS)
fprintf('10. Bağlantılar oluşturuluyor...\n');

try
    % Video Source bağlantıları
    if videoSourceAdded
        add_line(modelName, 'Video_Source/1', 'Video_Compressor/1', 'autorouting', 'on');
        add_line(modelName, 'Video_Source/1', 'PSNR_Calculator/1', 'autorouting', 'on');
        add_line(modelName, 'Video_Source/1', 'SSIM_Calculator/1', 'autorouting', 'on');
        if viewerAdded
            add_line(modelName, 'Video_Source/1', 'Video_Viewer_Original/1', 'autorouting', 'on');
        end
    end
    
    % Target Bitrate
    add_line(modelName, 'Target_Bitrate_Mbps/1', 'Video_Compressor/2', 'autorouting', 'on');
    
    % Video Compressor çıkışları
    add_line(modelName, 'Video_Compressor/1', 'Goto_Compressed/1', 'autorouting', 'on');
    add_line(modelName, 'Video_Compressor/2', 'Display_Bitrate/1', 'autorouting', 'on');
    
    % From → Hedefler
    add_line(modelName, 'From_PSNR/1', 'PSNR_Calculator/2', 'autorouting', 'on');
    add_line(modelName, 'From_SSIM/1', 'SSIM_Calculator/2', 'autorouting', 'on');
    if viewerAdded
        add_line(modelName, 'From_Viewer/1', 'Video_Viewer_Compressed/1', 'autorouting', 'on');
    end
    
    % Kalite metrikleri → Display
    add_line(modelName, 'PSNR_Calculator/1', 'Display_PSNR/1', 'autorouting', 'on');
    add_line(modelName, 'SSIM_Calculator/1', 'Display_SSIM/1', 'autorouting', 'on');
    
    fprintf('  ✓ Tüm bağlantılar oluşturuldu\n');
catch ME
    fprintf('  ⚠ Bazı bağlantılar manuel yapılmalı: %s\n', ME.message);
end

%% 10. SİMÜLASYON PARAMETRELERİ
fprintf('11. Simülasyon parametreleri ayarlanıyor...\n');

set_param(modelName, 'StopTime', '10');
set_param(modelName, 'SolverType', 'Variable-step');
set_param(modelName, 'MaxStep', '1/30');

fprintf('  ✓ Simülasyon süresi: 10 saniye\n');

%% 11. MODELİ KAYDET
fprintf('12. Model kaydediliyor...\n');
save_system(modelName, fullModelPath);

fprintf('\n========================================\n');
fprintf('✓ MODEL İSKELETİ OLUŞTURULDU!\n');
fprintf('========================================\n\n');

%% 12. MATLAB FUNCTION KODLARINI HAZIRLA
fprintf('========================================\n');
fprintf('MANUEL ADIMLAR - MATLAB FUNCTION KODLARI\n');
fprintf('========================================\n\n');

fprintf('Şimdi şu adımları takip edin:\n\n');

fprintf('--- VIDEO_COMPRESSOR BLOĞU ---\n');
fprintf('1. "Video_Compressor" bloğuna ÇİFT TIKLAYIN\n');
fprintf('2. Açılan pencereye şu kodu YAPIŞTIRIN:\n\n');

fprintf('function [compressed, actual_bitrate] = Video_Compressor(original, target_bitrate_mbps)\n');
fprintf('    persistent frameCount;\n');
fprintf('    if isempty(frameCount), frameCount = 0; end\n');
fprintf('    frameCount = frameCount + 1;\n');
fprintf('    [height, width, channels] = size(original);\n');
fprintf('    maxBitrate = 20;\n');
fprintf('    quality = min(1.0, max(0.1, target_bitrate_mbps / maxBitrate));\n');
fprintf('    ycbcr = rgb2ycbcr(original);\n');
fprintf('    Y = ycbcr(:,:,1); Cb = ycbcr(:,:,2); Cr = ycbcr(:,:,3);\n');
fprintf('    Cb_sub = imresize(Cb, 0.5); Cr_sub = imresize(Cr, 0.5);\n');
fprintf('    quantLevel = round(50 / quality);\n');
fprintf('    Y_quant = round(Y / quantLevel) * quantLevel;\n');
fprintf('    Cb_sub_quant = round(Cb_sub / quantLevel) * quantLevel;\n');
fprintf('    Cr_sub_quant = round(Cr_sub / quantLevel) * quantLevel;\n');
fprintf('    Cb_recon = imresize(Cb_sub_quant, [height, width]);\n');
fprintf('    Cr_recon = imresize(Cr_sub_quant, [height, width]);\n');
fprintf('    ycbcr_recon = cat(3, Y_quant, Cb_recon, Cr_recon);\n');
fprintf('    compressed = ycbcr2rgb(ycbcr_recon);\n');
fprintf('    if quality < 0.5\n');
fprintf('        blockSize = round(16 * (1 - quality));\n');
fprintf('        compressed = imresize(compressed, 1/blockSize, ''nearest'');\n');
fprintf('        compressed = imresize(compressed, [height, width]);\n');
fprintf('    end\n');
fprintf('    compressionRatio = quality * 0.05;\n');
fprintf('    frameSize_bits = height * width * channels * 8;\n');
fprintf('    compressed_size_bits = frameSize_bits * compressionRatio;\n');
fprintf('    fps = 30;\n');
fprintf('    actual_bitrate = (compressed_size_bits * fps) / 1e6;\n');
fprintf('    compressed = uint8(compressed);\n');
fprintf('end\n\n');

fprintf('3. Ctrl+S ile kaydedin\n');
fprintf('4. Pencereyi kapatın\n\n');

fprintf('--- PSNR_CALCULATOR BLOĞU ---\n');
fprintf('5. "PSNR_Calculator" bloğuna ÇİFT TIKLAYIN\n');
fprintf('6. Şu kodu YAPIŞTIRIN:\n\n');

fprintf('function psnr_db = PSNR_Calculator(original, compressed)\n');
fprintf('    orig = double(original);\n');
fprintf('    comp = double(compressed);\n');
fprintf('    mse = mean((orig(:) - comp(:)).^2);\n');
fprintf('    if mse < 1e-10\n');
fprintf('        psnr_db = 100;\n');
fprintf('    else\n');
fprintf('        max_pixel = 255;\n');
fprintf('        psnr_db = 10 * log10((max_pixel^2) / mse);\n');
fprintf('    end\n');
fprintf('    psnr_db = max(0, min(100, psnr_db));\n');
fprintf('end\n\n');

fprintf('7. Ctrl+S ile kaydedin\n\n');

fprintf('--- SSIM_CALCULATOR BLOĞU ---\n');
fprintf('8. "SSIM_Calculator" bloğuna ÇİFT TIKLAYIN\n');
fprintf('9. Şu kodu YAPIŞTIRIN:\n\n');

fprintf('function ssim_value = SSIM_Calculator(original, compressed)\n');
fprintf('    if size(original, 3) == 3\n');
fprintf('        orig_gray = rgb2gray(original);\n');
fprintf('        comp_gray = rgb2gray(compressed);\n');
fprintf('    else\n');
fprintf('        orig_gray = original;\n');
fprintf('        comp_gray = compressed;\n');
fprintf('    end\n');
fprintf('    ssim_value = ssim(comp_gray, orig_gray);\n');
fprintf('    ssim_value = max(0, min(1, ssim_value));\n');
fprintf('end\n\n');

fprintf('10. Ctrl+S ile kaydedin\n');
fprintf('11. Modeli kaydedin (Ctrl+S)\n');
fprintf('12. Simülasyonu çalıştırın!\n\n');

fprintf('========================================\n\n');

fprintf('Model konumu: %s.slx\n\n', fullModelPath);

fprintf('ÇALIŞTIRMA:\n');
fprintf('>> sim(''%s'')\n\n', modelName);