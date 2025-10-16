%% Drone Video Bandwidth Optimization - Initialization Parameters
% Kullanım: run('scripts/initialization/init_parameters.m')

clear; clc;
fprintf('=== PARAMETRELERİ YÜKLEME ===\n\n');

%% Video Parametreleri
videoParams = struct();
videoParams.inputFile = 'data/input_videos/test_video.mp4';
videoParams.resolution = [1280, 720];
videoParams.frameRate = 30;
videoParams.duration = 10;

fprintf('✓ Video: %dx%d @ %dfps\n', ...
    videoParams.resolution(1), videoParams.resolution(2), videoParams.frameRate);

%% H.264 Encoder Parametreleri
encoderParams = struct();
encoderParams.targetBitrate = 2e6;        % 2 Mbps
encoderParams.minBitrate = 500e3;         % 500 Kbps
encoderParams.maxBitrate = 8e6;           % 8 Mbps
encoderParams.gopSize = 30;

fprintf('✓ Encoder: Target Bitrate = %.1f Mbps\n', encoderParams.targetBitrate/1e6);

%% Network Parametreleri
networkParams = struct();
networkParams.bandwidth = 5e6;            % 5 Mbps
networkParams.latency = 100;              % 100 ms
networkParams.jitter = 20;                % ±20 ms
networkParams.packetLoss = 0.02;          % 2%

fprintf('✓ Network: %.1f Mbps, %dms latency, %.0f%% loss\n', ...
    networkParams.bandwidth/1e6, networkParams.latency, networkParams.packetLoss*100);

%% Kalite Parametreleri
qualityParams = struct();
qualityParams.targetPSNR = 32;
qualityParams.minPSNR = 28;
qualityParams.targetSSIM = 0.90;
qualityParams.minSSIM = 0.80;

fprintf('✓ Kalite: PSNR > %.0fdB, SSIM > %.2f\n', ...
    qualityParams.minPSNR, qualityParams.minSSIM);

%% Simülasyon Parametreleri
simParams = struct();
simParams.stopTime = 30;
simParams.solverType = 'Variable-step';

fprintf('✓ Simülasyon: %ds\n', simParams.stopTime);

%% Workspace'e Kaydet
assignin('base', 'videoParams', videoParams);
assignin('base', 'encoderParams', encoderParams);
assignin('base', 'networkParams', networkParams);
assignin('base', 'qualityParams', qualityParams);
assignin('base', 'simParams', simParams);

fprintf('\n✓ TÜM PARAMETRELER YÜKLENDİ!\n\n');