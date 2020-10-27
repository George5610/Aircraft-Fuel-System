% FuelControl function arguments u1..u16
% FuelControl function returns y1..y14

function y = FuelControl(u)
    % signals on Simulink schamtic
    %

    % Time in the outside world 
    time = u(1);
    
    % Inputs from the pilot
    RefuelSwitch   = u(2);
    RefuelQuantity = u(3);
    StartSwitch    = u(4);
    
    % Inputs from the fuel system 
    LProbe1        = u(5);  % Left tank Probe 1
    LProbe2        = u(6);  % Left tank Probe 2
    LFuelUsed      = u(7);  % LEngBurnt signal from left engine 
    LFeedPump1Stat = u(8);  % LFP1Stat (Left Feed Pump 1 Status) 
    LFeedPump2Stat = u(9);  % LFP2Stat (Left Feed Pump 2 Status)
    LTransPumpStat = u(10); % LTPStat (Left Transfer Pump Status)
    
    RProbe1        = u(11); % Right tank Probe 1
    RProbe2        = u(12); % Right tank Probe 2
    RFuelUsed      = u(13); % REngBurnt signal from right engine
    RFeedPump1Stat = u(14); % RFP1Stat (Right Feed Pump 1 Status) 
    RFeedPump2Stat = u(15); % RFP2Stat (Right Feed Pump 2 Status)
    RTransPumpStat = u(16); % RTPStat(Right Transfer Pump Status)

    % Instrumentation
    fprintf('Controller: Time[%f] Left[%f/%f] Right[%f/%f]\n',time,LProbe1,LProbe2,RProbe1,RProbe2);
    
    % Outputs defaults used if controller does nothing
    LThrottle = 0.0;  % Left engine throttle
    LEOpen    = 0.0;  % Left engine safety valve
    LIOpen    = 0.0;  % Left tank transfer valve
    LMOn      = 0.0;  % Left feed pump A on
    LSOn      = 0.0;  % Left feed pump B on
    LTOn      = 0.0;  % Left transfer pump on
    RThrottle = 0.0;  % Right engine throttle
    REOpen    = 0.0;  % Right engine safety valve
    RIOpen    = 0.0;  % Right tank transfer valve
    RMOn      = 0.0;  % Right feed pump A on
    RSOn      = 0.0;  % Right feed pump B on
    RTOn      = 0.0;  % Right transfer pump on
    XFOpen    = 0.0;  % Crossfeed valve open
    BOpen     = 0.0;  % Bowser valve open 
    
    % Control stuff could go here
    LIOpen    = 1.0;
    BOpen     = 1.0;  
  
       
    % Pack the outputs
    y(1)  = LThrottle;
    y(2)  = LEOpen   ;
    y(3)  = LIOpen   ;
    y(4)  = LMOn     ;
    y(5)  = LSOn     ;
    y(6)  = LTOn     ;
    y(7)  = RThrottle;
    y(8)  = REOpen   ;
    y(9)  = RIOpen   ;
    y(10) = RMOn     ;
    y(11) = RSOn     ;
    y(12) = RTOn     ;
    y(13) = XFOpen   ;
    y(14) = BOpen    ;  

end

function [LI,RI] = ExampleSubFunction(L,R)

    %% Defaults
    LI = 0;
    RI = 0;
    
    % Active conditions
    if (L >= 0.5) 
        LI = 1;
    end
    
    if (R >= 0.5) 
        RI = 1;
    end
    
end
