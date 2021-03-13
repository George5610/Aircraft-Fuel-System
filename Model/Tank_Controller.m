function y = Tank_Controller(u)

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

    Fuel_Total  = 5977.5; %total fuel mass in both tanks
    
%% right tank volume
    if RProbe1 <= 5/6
        RFuel_Vol = 0.5 * ((0.6 * RProbe1) / tan(78.69)) * (0.6 * Rprobe1);
        
    elseif Rprobe1 == 1
        RFuel_Vol = (0.5 * 5 * 0.5) + (0.5 * RProbe2) * 5;
        
    else
        RFuel_Vol = (0.5 * 5 * 0.5) + ((0.6 * Rprobe1) - 0.5) * 5;
    end
     
        
%% left tank volume
    if LProbe1 <= 5/6
        LFuel_Vol = 0.5 * ((0.6 * LProbe1) / tan(78.69)) * (0.6 * Lprobe1);
        
    elseif Lprobe1 == 1
        LFuel_Vol = (0.5 * 5 * 0.5) + (0.5 * LProbe2) * 5;
        
    else
        LFuel_Vol = (0.5 * 5 * 0.5) + ((0.6 * Lprobe1) - 0.5) * 5;
    end
    
%% Tank Litres to KG

    RTank_Mass = RFuel_Vol * TypicalFuelDensity;
    LTank_Mass = LFuel_Vol * TypicalFuelDensity;

%% Pack the outputs
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