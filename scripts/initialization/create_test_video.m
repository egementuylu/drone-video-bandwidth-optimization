%% Test Videosu Oluştur - Güvenli Versiyon
% Drone simülasyonu için basit test videosu

clear; clc;
close all;

fprintf('=== DRONE TEST VİDEOSU OLUŞTURULUYOR ===\n\n');

%% 1. Klasör kontrolü ve oluşturma
baseDir = pwd;  % Şu anki dizin
dataDir = fullfile(baseDir, 'data');
videoDir = fullfile(dataDir, 'input_videos');

fprintf('Klasör kontrolü:\n');
fprintf('  Base dir: %s\n', baseDir);

if ~exist(dataDir, 'dir')
    mkdir(dataDir);
    fprintf('  ✓ data klasörü oluşturuldu\n');
end

if ~exist(videoDir, 'dir')
    mkdir(videoDir);
    fprintf('  ✓ input_videos klasörü oluşturuldu\n');
end

%% 2. Video parametreleri
width = 1280;
height = 720;
frameRate = 30;
duration = 10;  % saniye
numFrames = frameRate * duration;

fprintf('\nVideo özellikleri:\n');
fprintf('  Çözünürlük: %dx%d\n', width, height);
fprintf('  Frame Rate: %d fps\n', frameRate);
fprintf('  Süre: %d saniye\n', duration);
fprintf('  Toplam frame: %d\n\n', numFrames);

%% 3. Video writer oluştur
outputFile = fullfile(videoDir, 'test_video.mp4');

try
    v = VideoWriter(outputFile, 'MPEG-4');
    v.FrameRate = frameRate;
    v.Quality = 95;
    open(v);
    fprintf('✓ Video dosyası oluşturuldu: %s\n\n', outputFile);
catch ME
    fprintf('✗ HATA: Video dosyası oluşturulamadı!\n');
    fprintf('  Sebep: %s\n', ME.message);
    return;
end

%% 4. Frame'leri oluştur
fprintf('Frame''ler render ediliyor...\n');
progressBar = 0;

for i = 1:numFrames
    % Hareketli renkli gradyan
    [X, Y] = meshgrid(1:width, 1:height);
    
    % Zamanla değişen renkli patern
    t = i / numFrames;
    R = uint8(128 + 127*sin(2*pi*(X/width + t)));
    G = uint8(128 + 127*sin(2*pi*(Y/height + t*0.7)));
    B = uint8(128 + 127*cos(2*pi*((X+Y)/(width+height) + t*0.5)));
    
    frame = cat(3, R, G, B);
    
    % Başlık metni
    titleText = sprintf('DRONE VIDEO TEST | Frame %d/%d', i, numFrames);
    frame = insertText(frame, [20, 20], titleText, ...
        'FontSize', 35, 'BoxOpacity', 0.7, ...
        'TextColor', 'white', 'BoxColor', 'black');
    
    % Zaman damgası
    timeText = sprintf('Time: %.2f sec | FPS: %d', i/frameRate, frameRate);
    frame = insertText(frame, [20, height-70], timeText, ...
        'FontSize', 28, 'BoxOpacity', 0.7, ...
        'TextColor', 'yellow', 'BoxColor', 'blue');
    
    % Simüle edilmiş drone hareketi (kırmızı top)
    droneX = width/2 + 300*cos(2*pi*t);
    droneY = height/2 + 200*sin(2*pi*t);
    frame = insertShape(frame, 'FilledCircle', [droneX, droneY, 25], ...
        'Color', 'red', 'Opacity', 0.9);
    
    % Drone bilgisi
    droneInfo = sprintf('Drone Position: (%.0f, %.0f)', droneX, droneY);
    frame = insertText(frame, [20, 100], droneInfo, ...
        'FontSize', 24, 'BoxOpacity', 0.6, ...
        'TextColor', 'cyan');
    
    % Frame'i videoya yaz
    writeVideo(v, frame);
    
    % İlerleme göstergesi
    newProgress = floor(i/numFrames * 20);
    if newProgress > progressBar
        progressBar = newProgress;
        fprintf('  [%s%s] %d%%\n', ...
            repmat('=', 1, progressBar), ...
            repmat(' ', 1, 20-progressBar), ...
            round(i/numFrames*100));
    end
end

%% 5. Video dosyasını kapat
close(v);

%% 6. Sonuç raporu
fileInfo = dir(outputFile);
fprintf('\n=== VIDEO BAŞARIYLA OLUŞTURULDU! ===\n');
fprintf('Dosya yolu: %s\n', outputFile);
fprintf('Dosya boyutu: %.2f MB\n', fileInfo.bytes/1024/1024);
fprintf('Oluşturma tarihi: %s\n\n', fileInfo.date);

fprintf('Videoyu izlemek için:\n');
fprintf('  >> implay(''%s'')\n\n', outputFile);

%% 7. Otomatik önizleme (opsiyonel)
response = input('Videoyu şimdi izlemek ister misiniz? (y/n): ', 's');
if strcmpi(response, 'y')
    implay(outputFile);
end