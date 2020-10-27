% TestPilot function argument u1
% TestPilot function returns y1..y3

function y = TestPilot(u)

    % Unpack the inputs
    time = u(1);

    % Set default outputs if "pilot" does nothing
    RefuelSwitch = 0;
    RefuelQuantity = 0;
    EnginesOnSwitch = 0;

    % Instrumentation
    fprintf('Pilot: Time[%f]\n',time);
    
    %% First test
    if((time >= 1) && (time <= 5))
        
        % Do stuff with outputs
        
    %% Second test
    elseif((time >= 10) && (time <= 15))
    
        % Do stuff with outputs
        
    end
    
    % Pack the outputs
    y(1) = RefuelSwitch;
    y(2) = RefuelQuantity;
    y(3) = EnginesOnSwitch;
       
end
