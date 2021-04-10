 
% TestPilot function argument u1
% TestPilot function returns y1..y3

function y = TestPilot(u)

    % Unpack the inputs
    time = u(1);
    RefuelSwitch = u(2);
    RefuelQuantity = u(3);
    RightEngine = u(4);
    LeftEngine = u(5);
    
        
    
    % Pack the outputs
    y(1) = RefuelSwitch;
    y(2) = RefuelQuantity;
    y(3) = LeftEngine;
    y(4) = RightEngine;
       
end
