%% Drone Video Bandwidth Optimization - Initialization Parameters
% Bu script tüm simülasyon parametrelerini yükler
% Kullanım: run('scripts/initialization/init_parameters.m')

clear; clc;
fprintf('=== Parametreler yükleniyor ===\n\n');

%% Video Parametreleri
videoParams = struct();
videoParams.inputFile = 'data/input_videos/test_video.mp4';  % Test videosu
videoParams.resolution = [1280, 720];      % 720p
videoParams.frameRate = 30;                % 30 fps
videoParams.duration = 10;                 % 10 saniye

fprintf('✓ Video parametreleri: %dx%d @ %d fps\n', ...
    videoParams.resolution(1), videoParams.resolution(2), videoParams.frameRate);

%% H.264 Encoder Parametreleri
encoderParams = struct();
encoderParams.targetBitrate = 2e6;         % 2 Mbps (başlangıç değeri)
encoderParams.minBitrate = 500e3;          % 500 Kbps (minimum)
encoderParams.maxBitrate = 8e6;            % 8 Mbps (maksimum)
encoderParams.gopSize = 30;                % Group of Pictures boyutu
encoderParams.profile = 'Main';            % H.264 profile
encoderParams.qualityPreset = 'Medium';    % Speed/Quality dengesi

fprintf('✓ Encoder parametreleri: Target Bitrate = %.1f Mbps\n', ...
    encoderParams.targetBitrate/1e6);

%% Network (Ağ) Parametreleri
networkParams = struct();
networkParams.bandwidth = 5e6;             % 5 Mbps (toplam bant genişliği)
networkParams.latency = 100;               % 100 ms (ortalama gecikme)
networkParams.jitter = 20;                 % ±20 ms (gecikme değişkenliği)
networkParams.packetLoss = 0.02;           % %2 paket kaybı

fprintf('✓ Network parametreleri: %.1f Mbps, %d ms latency, %.1f%% loss\n', ...
    networkParams.bandwidth/1e6, networkParams.latency, networkParams.packetLoss*100);

%% Kalite Metrikleri ve Hedefler
qualityParams = struct();
qualityParams.targetPSNR = 32;             % Hedef PSNR (dB)
qualityParams.minPSNR = 28;                % Minimum kabul edilebilir PSNR
qualityParams.targetSSIM = 0.90;           % Hedef SSIM
qualityParams.minSSIM = 0.80;              % Minimum kabul edilebilir SSIM

fprintf('✓ Kalite hedefleri: PSNR > %.1f dB, SSIM > %.2f\n', ...
    qualityParams.minPSNR, qualityParams.minSSIM);

%% Adaptif Kontrol Parametreleri
adaptiveParams = struct();
adaptiveParams.enabled = true;             % Adaptif bitrate açık/kapalı
adaptiveParams.updateInterval = 1;         % Her 1 saniyede bir güncelle
adaptiveParams.increaseStep = 0.1;         % %10 artış
adaptiveParams.decreaseStep = 0.15;        % %15 azalış

fprintf('✓ Adaptif kontrol: %s\n', ...
    string(adaptiveParams.enabled));

%% Simülasyon Parametreleri
simParams = struct();
simParams.stopTime = 30;                   % 30 saniye simülasyon
simParams.solverType = 'VariableStep';     % Variable step solver
simParams.maxStep = 1/videoParams.frameRate;  % Max step size

fprintf('✓ Simülasyon süresi: %d saniye\n\n', simParams.stopTime);

%% Workspace'e Kaydet
assignin('base', 'videoParams', videoParams);
assignin('base', 'encoderParams', encoderParams);
assignin('base', 'networkParams', networkParams);
assignin('base', 'qualityParams', qualityParams);
assignin('base', 'adaptiveParams', adaptiveParams);
assignin('base', 'simParams', simParams);

fprintf('=== Tüm parametreler başarıyla yüklendi! ===\n');
fprintf('Simulink modelinizi açabilirsiniz.\n\n');