
function [probe1,probe2,surfHeight,maxVol] = ProbeFunctions(side,roll,vol)

    % Defend against bad inputs
    if(vol < 0.0) 
        vol = 0.0;
    end

    % Basic tank dimensions - note width=leading-trailing, length=root-tip
    tankWidth  = 1.0; % metres
    wingHeight = 1.0;
    wingLength = 10.0 ;
    tankLength = 5.0;
    
    % Calculate empty section
    emptyBaseHeight = wingHeight * (tankLength / wingLength); %  By similar triangles
    emptyHeight     = wingHeight - emptyBaseHeight;
    emptyLength     = wingLength - tankLength;
    emptyCrossArea  = (emptyHeight * emptyLength) / 2.0;
    
    % Calculate wing
    wingCrossArea = (wingHeight * wingLength) / 2.0;
    
    % Calculate tank
    tankCrossArea = wingCrossArea - emptyCrossArea;

    % Calculate surface height
    tankTriangleHeight  = emptyBaseHeight;
    tankTriangleArea    = (tankTriangleHeight * tankLength) / 2.0;
    volArea = vol / tankWidth;
    %
    % Calculate parts above and below triangle/rectangle inflection
    if (volArea < tankTriangleArea) 
        surfHeight = sqrt( (volArea * tankTriangleHeight * 2.0) / tankLength );
    else 
        rectVolArea = volArea - tankTriangleArea;
        rectHeight = rectVolArea / tankLength;
        surfHeight = tankTriangleHeight + rectHeight;
        
    end

    % Calculate probes
    probe1Base   = 0.0;
    probe1Length = 0.6;
    if (surfHeight <= probe1Base)
        probe1 = 0.0;
    elseif (surfHeight >= (probe1Base + probe1Length))
        probe1 = 1.0;
    else
        probe1 = (surfHeight - probe1Base) / probe1Length;
    end
    %
    probe2Base   = 0.5;
    probe2Length = 0.5;
    if (surfHeight <= probe2Base)
        probe2 = 0.0;
    elseif (surfHeight >= (probe2Base + probe2Length))
        probe2 = 1.0;
    else
        probe2 = (surfHeight - probe2Base) / probe2Length;
    end
    
    % Max volume
    maxVol  = tankCrossArea * tankWidth;

    % Instrumentation
    % fprintf('Volume[%f] Surf[%f] P1[%f] P2[%f] Max[%f]\n',vol,surfHeight,probe1,probe2,maxVol);
    
% end of function
