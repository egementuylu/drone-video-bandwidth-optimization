%% Step 1 Model Oluştur - Video Reader (Düzeltilmiş Versiyon)
clear; clc;

fprintf('=== Step 1: Video Reader Modeli Oluşturuluyor ===\n\n');

% Model parametreleri
modelName = 'step1_video_reader';
modelPath = 'models/video_compression/';

% Modelin tam yolu
if ~exist(modelPath, 'dir')
    mkdir(modelPath);
end

fullPath = fullfile(modelPath, modelName);

% Eğer model zaten varsa kapat
if bdIsLoaded(modelName)
    close_system(modelName, 0);
end

% Eğer model dosyası varsa sil (temiz başlangıç için)
if exist([fullPath '.slx'], 'file')
    delete([fullPath '.slx']);
    fprintf('Eski model silindi.\n');
end

try
    %% Yeni model oluştur
    fprintf('Yeni model oluşturuluyor...\n');
    h = new_system(modelName, 'Model');
    open_system(h);
    
    %% DOĞRU BLOK YOLLARI
    % Önce mevcut blok yollarını bulalım
    fprintf('Uygun bloklar aranıyor...\n');
    
    % Video okuyucu bloğu - birkaç olasılık deneyelim
    videoReaderPaths = {
        'visionutilities/From Multimedia File'
        'computervision/From Multimedia File'
        'vision/From Multimedia File'
        'visionhdlsupport/From Multimedia File'
    };
    
    videoViewerPaths = {
        'visionutilities/Video Viewer'
        'computervision/Video Viewer'
        'vision/Video Viewer'
        'visionhdlsupport/Video Viewer'
    };
    
    % Çalışan bloğu bul
    videoReaderBlock = '';
    for i = 1:length(videoReaderPaths)
        try
            find_system('SearchDepth', 0, 'Name', videoReaderPaths{i});
            videoReaderBlock = videoReaderPaths{i};
            fprintf('✓ Video Reader bulundu: %s\n', videoReaderBlock);
            break;
        catch
            % Bu yol çalışmadı, devam et
        end
    end
    
    videoViewerBlock = '';
    for i = 1:length(videoViewerPaths)
        try
            find_system('SearchDepth', 0, 'Name', videoViewerPaths{i});
            videoViewerBlock = videoViewerPaths{i};
            fprintf('✓ Video Viewer bulundu: %s\n', videoViewerBlock);
            break;
        catch
            % Bu yol çalışmadı, devam et
        end
    end
    
    % Eğer bloklar bulunamadıysa alternatif kullan
    if isempty(videoReaderBlock)
        fprintf('⚠ From Multimedia File bloğu bulunamadı!\n');
        fprintf('Manuel ekleme gerekiyor.\n');
        error('Video okuyucu bloğu bulunamadı.');
    end
    
    if isempty(videoViewerBlock)
        fprintf('⚠ Video Viewer bloğu bulunamadı!\n');
        fprintf('Simulink Scope kullanılacak.\n');
        videoViewerBlock = 'simulink/Sinks/Scope';
    end
    
    %% Blokları ekle
    fprintf('\nBloklar ekleniyor...\n');
    add_block(videoReaderBlock, ...
              [modelName '/Video_Source'], ...
              'Position', [50 80 150 130]);
    fprintf('  ✓ Video Source eklendi\n');
    
    add_block(videoViewerBlock, ...
              [modelName '/Video_Display'], ...
              'Position', [250 80 350 130]);
    fprintf('  ✓ Video Display eklendi\n');
    
    %% Blokları bağla
    fprintf('\nBloklar bağlanıyor...\n');
    add_line(modelName, 'Video_Source/1', 'Video_Display/1', 'autorouting', 'on');
    
    %% Video Source parametrelerini ayarla
    fprintf('\nVideo parametreleri ayarlanıyor...\n');
    videoFile = fullfile(pwd, 'data', 'input_videos', 'test_video.mp4');
    
    if exist(videoFile, 'file')
        fprintf('  ✓ Video dosyası bulundu: %s\n', videoFile);
        
        try
            set_param([modelName '/Video_Source'], ...
                      'Filename', videoFile, ...
                      'PlayCount', 'inf');
        catch
            fprintf('  ⚠ Otomatik parametre ayarlanamadı, manuel ayarlama gerekebilir.\n');
        end
    else
        fprintf('  ✗ Video dosyası bulunamadı!\n');
        fprintf('    Önce test_video.mp4 oluşturun.\n');
    end
    
    %% Simülasyon parametrelerini ayarla
    fprintf('\nSimülasyon parametreleri ayarlanıyor...\n');
    set_param(modelName, 'StopTime', '10');
    set_param(modelName, 'SolverType', 'Variable-step');
    
    %% Modeli kaydet
    fprintf('\nModel kaydediliyor...\n');
    save_system(modelName, fullPath);
    
    fprintf('\n=== MODEL BAŞARIYLA OLUŞTURULDU! ===\n');
    fprintf('Dosya: %s.slx\n', fullPath);
    fprintf('\nŞimdi yapmanız gerekenler:\n');
    fprintf('1. Video Source bloğuna çift tıklayın\n');
    fprintf('2. Filename: data/input_videos/test_video.mp4 ayarlayın\n');
    fprintf('3. Simülasyonu çalıştırın\n\n');
    
catch ME
    fprintf('\n✗ HATA: %s\n', ME.message);
    fprintf('\n=== MANUEL OLUŞTURMA ÖNERİLİR ===\n');
    fprintf('Lütfen şu adımları takip edin:\n\n');
end