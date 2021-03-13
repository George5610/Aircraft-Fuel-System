function y = Failure_Check(u)
%% inputs
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

    
    %Failure Memory dependancy in InitaliseFuelLibrary
    
%% right pump fail check
    if RMOn == 1 && RFeedPump1Stat == 1
       fprintf("Right Engine Feed Pump 1 Failure")
       
       RMOn = 0;  % Right feed pump A off
       RSOn = 1;  % Right feed pump B on
       RFP1F = 1;
      
    else
       RFP1F = 0;
        
    end
    
%% left pump fail check
    if LMOn == 1 && LFeedPump1Stat == 1
       fprintf("Left Engine Feed Pump 1 Failure")
       
       LMOn = 0;  % Left feed pump A off
       LSOn = 1;  % Left feed pump B on
       LFP1F = 1;
      
    else
       LFP1F = 0;
        
    end
    
 %% right Supp pump fail check
    if RSOn == 1 && RFeedPump2Stat == 1
       fprintf("Right Engine Feed Pump 2 Failure, closing engine valve")
       
       RMOn = 0;  % Right feed pump A off
       RSOn = 0;  % Right feed pump B off
       RFP2F = 1;
       REOpen = 0;
    else
       RFP2F = 0;
        
    end
    
%% left Supp pump fail check
    if LSOn == 1 && LFeedPump2Stat == 1
       fprintf("Left Engine Feed Pump 2 Failure, closing engine valve")
       
       LMOn = 0;  % Left feed pump A off
       LSOn = 0;  % Left feed pump B on
       LFP2F = 1;
       LEOpen = 0;
    else
       LFP2F = 0;
        
    end
    
%% Right Transfer Pump Fail Check

    if RTOn == 1 && RTransPumpStat == 1
       fprintf("Right Transfer Pump Failed")
        RTPF = 1;
    else
        RTPF = 0;
    end
    
%% Left Transfer Pump Fail Check

    if LTOn == 1 && LTransPumpStat == 1
       fprintf("Left Transfer Pump Failed")
        LTPF = 1;
    else
        LTPF = 0;
    end

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
