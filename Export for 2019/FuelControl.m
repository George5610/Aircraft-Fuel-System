function y = FuelControl(u)

    % Time in the outside world 
    time = u(1);
    
    % Inputs from the pilot
    RefuelSwitch   = u(2);
    RefuelQuantity = u(3);
    LeftStartSwitch = u(4);
    RightStartSwitch = u(5);
    
    % Inputs from the fuel system 
    LProbe1        = u(6);  % Left tank Probe 1
    LProbe2        = u(7);  % Left tank Probe 2
    LFuelUsed      = u(8);  % LEngBurnt signal from left engine 
    LFeedPump1Stat = u(9);  % LFP1Stat (Left Feed Pump 1 Status) 
    LFeedPump2Stat = u(10);  % LFP2Stat (Left Feed Pump 2 Status)
    LTransPumpStat = u(11); % LTPStat (Left Transfer Pump Status)
    
    RProbe1        = u(12); % Right tank Probe 1
    RProbe2        = u(13); % Right tank Probe 2
    RFuelUsed      = u(14); % REngBurnt signal from right engine
    RFeedPump1Stat = u(15); % RFP1Stat (Right Feed Pump 1 Status) 
    RFeedPump2Stat = u(16); % RFP2Stat (Right Feed Pump 2 Status)
    RTransPumpStat = u(17); % RTPStat(Right Transfer Pump Status)
    RThrottleIN    = u(18);
    LThrottleIN    = u(19);
    LMOn_Delay     = u(20);
    LSOn_Delay     = u(21);
    RMOn_Delay     = u(22);
    RSOn_Delay     = u(23);
    RThrottle_Delay = u(24);
    LThrottle_Delay = u(25);
    RTOn_Delay     = u(26);
    LTOn_Delay     = u(27);
    RTankDiff      = u(28);
    LTankDiff      = u(29);
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
    RTank_Mass = 0.0; % the tank mass
    LTank_Mass = 0.0; % the tank mass

    
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

  %  fprintf('Tank Lvls: Time[%f] Right[%f] Left[%f]\n',time,RTank_Mass,LTank_Mass);

%% Throttle and engine Control

    RThrottle = RThrottleIN;
    LThrottle = LThrottleIN;
    
%% Right Engine Failure Check
%{
    persistent REFail
    if isempty(REFail)
        REFail = 0;
    end
    
    if RThrottleIN > 0 && RThrottle_Delay ~= RFuelUsed * 4 && RightStartSwitch == 1 && RFuelUsed > 0
        REFail = 1;
        
    end
    
    if REFail == 1
        
        RThrottle = 0;
        REOpen = 0;
        RMOn = 0;
        RSOn = 0;
        fprintf("Right Engine Fuel Consumption off\n");
        RightStartSwitch = 0;       
        
    end
    
%% Left Engine Failure Check

    persistent LEFail
    if isempty(LEFail)
        LEFail = 0;
    end
    
    if LThrottleIN > 0 && LThrottle_Delay ~= LFuelUsed * 4 && LeftStartSwitch == 1 && LFuelUsed > 0

        LEFail = 1;

    end
    
    if LEFail == 1 && LeftStartSwitch == 1
        
        LThrottle = 0;
        LEOpen = 0;
        LMOn = 0;
        LSOn = 0;
        fprintf("Left Engine Fuel Consumption off\n");
        LeftStartSwitch = 0;
        
    end
    
    %}    
%% engines on
    if RightStartSwitch == 1 && RThrottle > 0 && RTank_Mass > 20
       RMOn = 1;
       REOpen = 1;
       
    else
       RMOn = 0;
       REOpen = 0;
    end
    
    if LeftStartSwitch == 1 && LThrottle > 0 && LTank_Mass > 20
        LMOn = 1;
        LEOpen = 1;
        
    else
        LMOn = 0;
        LEOpen = 0;
        
    end

%%COG controller
%differance calculator

    if RTankDiff >= 15
      RTOn = 1;
      LIOpen = 1;
    else
      RTOn = 0;
      LIOpen = 0;
    end

    if LTankDiff >= 15
       LTOn = 1;
       RIOpen = 1;
    else
       LTOn = 0;
        RIOpen = 0;
    end
     
 
%% right main pump fail check

    persistent RMPFail
    if isempty(RMPFail)
        RMPFail = 0;
    end
    
    if RMOn_Delay == 1 && RFeedPump1Stat == 1
        RMPFail = 1;
    end
    
    if RMPFail == 1
        
       fprintf("Right Engine Feed Pump 1 Failure\n");
       
       RMOn = 0;  % Right feed pump A off
       RSOn = 1;  % Right feed pump B on
    end
    
%% Left main Pump Fail    
    persistent LMPFail
    if isempty(LMPFail)
        LMPFail = 0;
    end
    
    if LMOn_Delay == 1 && LFeedPump1Stat == 1
        LMPFail = 1;
    end
    
    if LMPFail == 1
        
       fprintf("Left Engine Feed Pump 1 Failure\n");
       
       LMOn = 0;  % Right feed pump A off
       LSOn = 1;  % Right feed pump B on
    end

 %% Right Supp pump fail check
 persistent RSPFail
 if isempty(RSPFail)
     RSPFail = 0;
 end
    if RSOn_Delay == 1 && RFeedPump2Stat == 1
        RSPFail = 1;
    end
    
    if RSPFail == 1
        fprintf("Duel right pump failure, enabling x feed\n");
        XFOpen = 1;
        RMOn = 0;
        RSOn = 0;
        LMOn = 1;
        LSOn = 1;
    end
    
 %% Left Supp pump fail check
 persistent LSPFail
 if isempty(LSPFail)
     LSPFail = 0;
 end
    if LSOn_Delay == 1 && LFeedPump2Stat == 1
        LSPFail = 1;
    end
    
    if LSPFail == 1
        fprintf("Duel left pump failure, enabling x feed\n");
        XFOpen = 1;
        RMOn = 1;
        RSOn = 1;
        LMOn = 0;
        LSOn = 0;
    end
    
%% Right Transfer Pump Fail Check
 persistent RTPFail
 if isempty(RTPFail)
     RTPFail = 0;
 end
 
    if RTOn_Delay == 1 && RTransPumpStat == 1
       RTPFail = 1;
    end
    
    if RTPFail == 1
        fprintf("Right Transfer Pump Failed\n")
        RTOn = 0;
    end
    
%% LEft Transfer Pump Fail Check
 persistent LTPFail
 if isempty(LTPFail)
     LTPFail = 0;
 end
 
    if LTOn_Delay == 1 && LTransPumpStat == 1
       LTPFail = 1;
    end
    
    if LTPFail == 1
        fprintf("Left Transfer Pump Failed\n")
        LTOn = 0;
    end
 
%% Duel pump failures
%{
%left
 persistent DLPFail
 if isempty(DLPFail)
     DLPFail = 0;
 end
    if LMOn_Delay == 1 && LFeedPump1Stat == 1 && LSOn_Delay == 1 && LFeedPump2Stat == 1 && LeftStartSwitch == 1
        DLPFail = 1;
    end
    
    if DLPFail == 1
        XFOpen = 1;
        RMOn = 1;
        RSOn = 1;
        LMOn = 0;
        LSOn = 0;
    end
    
%right
 persistent DRPFail
 if isempty(DRPFail)
     DRPFail = 0;
 end
    if RMOn_Delay == 1 && RFeedPump1Stat == 1 && RSOn_Delay == 1 && RFeedPump2Stat == 1 && ReftStartSwitch == 1
        DRPFail = 1;
    end
    
    if DRPFail == 1
        XFOpen = 1;
        RMOn = 0;
        RSOn = 0;
        LMOn = 1;
        LSOn = 1;
    end  

%}
%% Fuel tanks run out condtion
%right
 persistent RTankCrit
 if isempty(RTankCrit)
     RTankCrit = 0;
 end  

    if RTank_Mass < 20 && RightStartSwitch == 1
      RTankCrit = 1;

    end
    
    if RTankCrit == 1
       RMOn = 0;
       RSOn = 0;
       REOpen = 0;
       fprintf("RTank Mass Critical\n");    
    end
    
    % left
 persistent LTankCrit
 if isempty(LTankCrit)
     LTankCrit = 0;
 end  

    if LTank_Mass < 20 && LeftStartSwitch == 1
      LTankCrit = 1;

    end
    
    if LTankCrit == 1
       LMOn = 0;
       LSOn = 0;
       LEOpen = 0;
       fprintf("LTank Mass Critical\n");    
    end

%% right probe failures

    if RProbe1 == 0 && LProbe1 > 0.01
        fprintf("Right probe1 failed\n");
    elseif RProbe1 == 0 && RProbe2 > 0
        fprintf("Right probe 1 failed\n");
    end

    if RProbe2 == 0 && LProbe2 > 0.01 && RTankCrit ~= 1
        fprintf("Right probe 2 failed\n");
    end

%% Left Probe failures

    if LProbe1 == 0 && RProbe1 > 0.01
        fprintf("Left probe1 failed\n");
    elseif LProbe1 == 0 && LProbe2 > 0
        fprintf("Left probe 1 failed\n");
    end

    if LProbe2 == 0 && RProbe2 > 0.01 && RTankCrit ~= 1
        fprintf("Left probe 2 failed\n");
    end
    
%% Bowser Control 
    Total_Fuel = RTank_Mass + LTank_Mass;
    if  RefuelSwitch == 1 && Total_Fuel < RefuelQuantity
        BOpen = 1;
        RIOpen = 1;
        LIOpen = 1;
    else 
        BOpen = 0;
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