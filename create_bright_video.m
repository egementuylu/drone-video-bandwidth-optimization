%% Parlak Test Videosu Oluştur
% Siyah ekran sorununu çözmek için yüksek kontrast video

function create_bright_video()
    fprintf('=== PARLAK TEST VIDEOSU OLUŞTURULUYOR ===\n\n');
    
    % Video parametreleri
    width = 1280;
    height = 720;
    frameRate = 30;
    duration = 10; % saniye
    numFrames = frameRate * duration;
    
    % Output klasörü kontrolü
    outputDir = fullfile(pwd, 'data', 'input_videos');
    if ~exist(outputDir, 'dir')
        mkdir(outputDir);
        fprintf('✓ Klasör oluşturuldu: %s\n', outputDir);
    end
    
    outputFile = fullfile(outputDir, 'test_video.mp4');
    
    % Eğer dosya varsa yedekle
    if exist(outputFile, 'file')
        backupFile = fullfile(outputDir, 'test_video_backup.mp4');
        copyfile(outputFile, backupFile);
        fprintf('ℹ Eski video yedeklendi: test_video_backup.mp4\n');
    end
    
    % Video writer
    v = VideoWriter(outputFile, 'MPEG-4');
    v.FrameRate = frameRate;
    v.Quality = 95;
    open(v);
    
    fprintf('Video özellikleri:\n');
    fprintf('  Çözünürlük: %dx%d\n', width, height);
    fprintf('  Frame Rate: %d fps\n', frameRate);
    fprintf('  Süre: %d saniye\n', duration);
    fprintf('  Toplam frame: %d\n\n', numFrames);
    
    fprintf('Frame''ler oluşturuluyor...\n');
    
    % Her frame için
    for i = 1:numFrames
        % Zaman parametresi (0-1)
        t = i / numFrames;
        
        % Meshgrid oluştur
        [X, Y] = meshgrid(1:width, 1:height);
        
        % PARLAK renkli gradyanlar (128-255 arası - parlak)
        R = uint8(128 + 127*sin(2*pi*(X/(width*0.5) + t*2)));
        G = uint8(128 + 127*cos(2*pi*(Y/(height*0.5) + t*1.5)));
        B = uint8(128 + 127*sin(2*pi*((X+Y)/(width+height)*0.5 + t)));
        
        % RGB frame birleştir
        frame = cat(3, R, G, B);
        
        % Üst başlık - siyah metin, beyaz arka plan
        titleText = sprintf('DRONE VIDEO TEST - Frame %d/%d', i, numFrames);
        frame = insertText(frame, [40, 40], titleText, ...
            'FontSize', 45, 'BoxOpacity', 0.9, ...
            'TextColor', 'black', 'BoxColor', 'white');
        
        % Hareketli büyük daire (drone simülasyonu)
        centerX = width/2 + 350*cos(2*pi*t*1.5);
        centerY = height/2 + 200*sin(2*pi*t*2);
        
        % Sarı dolgu
        frame = insertShape(frame, 'FilledCircle', [centerX, centerY, 45], ...
            'Color', 'yellow', 'Opacity', 0.9);
        
        % Kırmızı kenarlık
        frame = insertShape(frame, 'Circle', [centerX, centerY, 45], ...
            'Color', 'red', 'LineWidth', 6);
        
        % Pozisyon bilgisi
        posText = sprintf('Drone Pos: (%.0f, %.0f)', centerX, centerY);
        frame = insertText(frame, [40, 120], posText, ...
            'FontSize', 35, 'BoxOpacity', 0.8, ...
            'TextColor', 'cyan', 'BoxColor', 'black');
        
        % Alt bilgi - zaman
        timeText = sprintf('Time: %.2f s | FPS: %d | Resolution: %dx%d', ...
            i/frameRate, frameRate, width, height);
        frame = insertText(frame, [40, height-80], timeText, ...
            'FontSize', 35, 'BoxOpacity', 0.9, ...
            'TextColor', 'white', 'BoxColor', 'blue');
        
        % İlerleme çubuğu
        progressWidth = round((i/numFrames) * (width - 80));
        frame = insertShape(frame, 'FilledRectangle', ...
            [40, height-30, progressWidth, 20], ...
            'Color', 'green', 'Opacity', 0.8);
        
        % Frame'i videoya yaz
        writeVideo(v, frame);
        
        % İlerleme göster
        if mod(i, 30) == 0 || i == numFrames
            fprintf('  [%s%s] %.0f%%\n', ...
                repmat('█', 1, round(i/numFrames*40)), ...
                repmat('░', 1, 40-round(i/numFrames*40)), ...
                i/numFrames*100);
        end
    end
    
    % Video dosyasını kapat
    close(v);
    
    % Sonuç raporu
    fprintf('\n╔════════════════════════════════════════╗\n');
    fprintf('║   VIDEO BAŞARIYLA OLUŞTURULDU! ✓      ║\n');
    fprintf('╚════════════════════════════════════════╝\n\n');
    
    fileInfo = dir(outputFile);
    fprintf('Dosya bilgileri:\n');
    fprintf('  Yol: %s\n', outputFile);
    fprintf('  Boyut: %.2f MB\n', fileInfo.bytes/1024/1024);
    fprintf('  Tarih: %s\n\n', fileInfo.date);
    
    % Video test et
    fprintf('Video test ediliyor...\n');
    try
        vr = VideoReader(outputFile);
        fprintf('  ✓ Video okunabiliyor\n');
        fprintf('  • Boyut: %dx%d\n', vr.Width, vr.Height);
        fprintf('  • Frame Rate: %.2f fps\n', vr.FrameRate);
        fprintf('  • Süre: %.2f saniye\n', vr.Duration);
        fprintf('  • Frame sayısı: %d\n', vr.NumFrames);
        
        % İlk frame'i kontrol et
        if hasFrame(vr)
            testFrame = readFrame(vr);
            minVal = min(testFrame(:));
            maxVal = max(testFrame(:));
            meanVal = mean(double(testFrame(:)));
            
            fprintf('  • İlk frame: min=%d, max=%d, mean=%.1f\n', ...
                minVal, maxVal, meanVal);
            
            if meanVal > 50 && maxVal > 200
                fprintf('\n✓ Video yeterince parlak ve kullanılabilir!\n');
            else
                warning('Video çok karanlık olabilir!');
            end
        end
        
    catch ME
        warning('Video test edilemedi: %s', ME.message);
    end
    
    fprintf('\n');
end