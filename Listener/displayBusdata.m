function displayBusdata(block, ~)
% Get the figure handle
h = findobj('Tag','busFigure');
if (block.currentTime==0)
    % Initialize
    if ~isempty(h)
        close(h);
    end
    figure('Tag','busFigure');
    time = block.currentTime;
    data = block.OutputPort(1).Data.a + block.OutputPort(1).Data.b;
    plot(time,data)
else
    %Add new point
    hl = findobj(h,'type','line');
    time = get(hl(1),'Xdata');
    data = get(hl(1),'Ydata');
    time = [time block.currentTime];
    data = [data block.OutputPort(1).Data.a+block.OutputPort(1).Data.b];
    set(hl(1),'Xdata',time);
    set(hl(1),'Ydata',data);
end


% disp('------')
% disp(['At time t = ' num2str(block.currentTime) ]);
% disp(['Sine Wave = ' num2str(block.OutputPort(1).Data.a) ]);
% disp(['Pulse  = ' num2str(block.OutputPort(1).Data.b) ]);





