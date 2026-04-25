%% ==========================================================
%  【录像增强版】二维伊辛模型物理仿真
%  基于你的修复版代码，新增了 .avi 影片录制功能
%  ==========================================================
clc; clear; close all;

%% 1. GUI 用户参数输入 (弹窗设计)
% ----------------------------------------------------------
prompt = {'输入网格大小 N (建议 30-50):', ...
          '输入温度 T (临界点约 2.27):', ...
          '输入模拟总步数 (建议 >2000):', ...
          '是否录制影片? (1=是, 0=否):'}; % <--- ✨ [新增 1] 录像选项
dlgtitle = '伊辛模型参数设置';
dims = [1 40];
% 默认值 (默认开启录像)
definput = {'100', '2.27', '3000', '1'}; 

% 弹出对话框获取输入
answer = inputdlg(prompt, dlgtitle, dims, definput);

% 如果用户点击取消，则退出
if isempty(answer)
    disp('用户取消操作。');
    return;
end

% 将输入的字符串转换为数字
N = str2double(answer{1});
T = str2double(answer{2});
total_steps = str2double(answer{3});
is_record = str2double(answer{4}); % <--- ✨ [新增 2] 读取录像标记
J = 1; 

fprintf('开始模拟: N=%d, T=%.2f, Steps=%d, Video=%d\n', N, T, total_steps, is_record);

%% ✨ [新增 3] 视频文件初始化 ✨
if is_record == 1
    % 自动命名文件名，例如 Ising_T2.27.avi
    video_filename = ['Ising_T', num2str(T), '.avi'];
    v = VideoWriter(video_filename); 
    v.FrameRate = 15; % 设置播放速度 (数值越大越快)
    open(v);
    fprintf('--> 正在录制影片，保存为: %s \n', video_filename);
end

% ----------------------------------------------------------

%% 2. 系统初始化
% 随机初始化网格 (+1 或 -1)
grid_spin = sign(rand(N, N) - 0.5); 
grid_spin(grid_spin == 0) = 1; 

% 创建一个网格坐标系统，用于画箭头
[X, Y] = meshgrid(1:N, 1:N);

% 准备绘图窗口
figure('Name', '高级伊辛模型物理仿真', 'Color', 'white', 'Position', [50, 100, 1400, 500]);
magnetization_history = zeros(1, total_steps);

%% 3. 主循环 (Metropolis Monte Carlo)
for step = 1:total_steps
    
    % --- Metropolis 算法核心 ---
    for k = 1 : (N * N) 
        r = randi(N); c = randi(N);
        r_up = mod(r - 2, N) + 1; r_down = mod(r, N) + 1;
        c_left = mod(c - 2, N) + 1; c_right= mod(c, N) + 1;
        
        sum_neighbors = grid_spin(r_up, c) + grid_spin(r_down, c) + ...
                        grid_spin(r, c_left) + grid_spin(r, c_right);
        
        dE = 2 * J * grid_spin(r, c) * sum_neighbors;
        
        if dE <= 0 || rand() < exp(-dE / T)
            grid_spin(r, c) = -grid_spin(r, c);
        end
    end
    
    % --- 记录数据 ---
    magnetization_history(step) = abs(sum(grid_spin(:))) / (N * N);
    
    % --- 高级实时可视化 (每 20 步刷新一次) ---
    if mod(step, 20) == 0 || step == 1
        % [图1：宏观色块图]
        subplot(1, 3, 1);
        imagesc(grid_spin); 
        colormap(jet(2)); 
        title(['宏观磁畴 (Step: ', num2str(step), ')'], 'FontSize', 12);
        axis square; axis off;
        
        % [图2：微观自旋箭头图]
        subplot(1, 3, 2);
        U = zeros(N, N); 
        V = grid_spin;   
        quiver(X, Y, U, V, 0.6, 'k', 'LineWidth', 1); 
        xlim([0.5 N+0.5]); ylim([0.5 N+0.5]);
        title('微观自旋组态 (箭头指向)', 'FontSize', 12);
        axis square; 
        set(gca, 'YDir', 'reverse'); 
        box on; grid off;
        
        % [图3：数据曲线图]
        subplot(1, 3, 3);
        plot(1:step, magnetization_history(1:step), 'r-', 'LineWidth', 1.5);
        xlim([0 total_steps]); ylim([0 1.1]);
        xlabel('时间步', 'FontSize', 10);
        ylabel('总磁化强度 |M|', 'FontSize', 10);
        title(['相变过程 (T = ', num2str(T), ')'], 'FontSize', 12);
        grid on;
        
        drawnow; 
        
        %% ✨ [新增 4] 写入影片帧 ✨
        if is_record == 1
            frame = getframe(gcf); % 抓取当前窗口画面
            writeVideo(v, frame);  % 写入影片
        end
    end
end

%% ✨ [新增 5] 收尾工作 ✨
if is_record == 1
    close(v); % 关闭影片文件，保存数据
    msgbox(['模拟完成！影片已保存为: ', video_filename], '成功');
else
    msgbox('模拟完成！请截图保存结果图。', '成功');
end

disp('模拟完成！');

