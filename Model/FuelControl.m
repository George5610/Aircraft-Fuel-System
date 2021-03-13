% FuelControl function arguments u1..u16
% FuelControl function returns y1..y14

function y = FuelControl(u)
    % signals on Simulink schamtic
    %t

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
    RThrottleIN = u(17);
    LThrottleIN = u(18);
    % Instrumentation
  %  fprintf('Controller: Time[%f] Left[%f/%f] Right[%f/%f]\n',time,LProbe1,LProbe2,RProbe1,RProbe2);
    
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
    BOpen     = 0.0;  % Bowser valve closed
    RTank_Mass = 0.0;
    LTank_Mass = 0.0;
    

    
%% right tank volume
    if RProbe1 <= 5/6
        RFuel_Vol = (0.5 * (tand(5.711) * (0.6 * RProbe1)) * (0.6 * RProbe1)) * 100;
        
    elseif RProbe1 == 1
        RFuel_Vol = (0.5 * 5 * 0.5) + (0.5 * RProbe2) * 5;
        
    else
        RFuel_Vol = (0.5 * 5 * 0.5) + ((0.6 * RProbe1) - 0.5) * 5;
    end
     
        
%% left tank volume
    if LProbe1 <= 5/6
        LFuel_Vol = (0.5 * (tand(5.711) * (0.6 * LProbe1)) * (0.6 * LProbe1)) * 100;
        
    elseif LProbe1 == 1
        LFuel_Vol = (0.5 * 5 * 0.5) + (0.5 * LProbe2) * 5;
        
    else
        LFuel_Vol = (0.5 * 5 * 0.5) + ((0.6 * LProbe1) - 0.5) * 5;
    end
    
%% Tank Litres to KG

    RTank_Mass = RFuel_Vol * 797;
    LTank_Mass = LFuel_Vol * 797;

    fprintf('Tank Lvls: Time[%f] Right[%f] Left[%f]\n',time,RTank_Mass,LTank_Mass);
    
%% Bowser Control (temp sol)
    Total_Fuel = RTank_Mass + LTank_Mass;
    if  RefuelSwitch == 1 && Total_Fuel < RefuelQuantity
        BOpen = 1;
        RIOpen = 1;
        LIOpen = 1;
    else 
        BOpen = 0;
        RIOpen = 0;
        LIOpen = 0;
    end
 
%% Throttle Control

    RThrottleIN = RThrottle;
    LThrottleIN = LThrottle;
    
    if StartSwitch == 1
       RMOn = 1;
       LMOn = 1;
       REOpen = 1;
       LEOpen = 1;
       
    else
       RMOn = 0;
       LMOn = 0;
       REOpen = 0;
       LEOpen = 0;
    end
%% Pack the outputs
    y(1)  = LThrottle ;
    y(2)  = LEOpen    ;
    y(3)  = LIOpen    ;
    y(4)  = LMOn      ;
    y(5)  = LSOn      ;
    y(6)  = LTOn      ;
    y(7)  = RThrottle ;
    y(8)  = REOpen    ;
    y(9)  = RIOpen    ;
    y(10) = RMOn      ;
    y(11) = RSOn      ;
    y(12) = RTOn      ;
    y(13) = XFOpen    ;
    y(14) = BOpen     ;  
    y(15) = RTank_Mass;
    y(16) = LTank_Mass;
end

