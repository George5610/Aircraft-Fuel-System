
%% Names of model, variables anf files
mdl0 = 'testListenerMdlOriginal';
mdl = 'testListenerMdl';
blk = 'testListenerMdl/BusCreator';
busObjectName = 'BO';
definitionFile = 'myBusDef';

%Open original model and save under a ner name
open_system(mdl0)
save_system(mdl0,mdl)

%% setup the bus
% Create a bus object
busInfo = Simulink.Bus.createObject(mdl,blk);
% Give it the desired name
assignin('base',busObjectName,eval(busInfo.busName));
clear(busInfo.busName);
% Save the bus definition in a MATLAB file
if exist(definitionFile,'file')
    delete([definitionFile '.m']);
end
Simulink.Bus.save(definitionFile,'object',{busObjectName});
% Set the definition file to be executed when loading the model
set_param(mdl,'preLoadFcn',definitionFile);
% Configure the Bus Creator to use the Bus Object
set_param(blk,'OutDataTypeStr',['Bus: ' busObjectName]);
set_param(blk,'NonVirtualBus','on');
save_system(mdl)



%% Setup model callbacks to register event listener 

% Add the bus definition file to the preload callback
set_param(mdl,'preLoadFcn',definitionFile)

% callback to register event listener
startFcnCb = sprintf(['%% Full path to the block\n',...
'blk = ''testListenerMdl/BusCreator'';\n',...
'\n',...
'%% Attach the event listener\n',...
'h = add_exec_event_listener(blk, ...\n',...
'         ''PostOutputs'', @displayBusdata);'])

set_param(mdl,'startFcn',startFcnCb)
save_system(mdl)

%% Simulate the model

% try simulate using the siomulation stepper to see the figure changing
% every step