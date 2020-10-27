function ProbeBlock(block)
setup(block);
%endfunction

%% Function: setup ===================================================
function setup(block)

    % Register number of ports
    block.NumInputPorts  = 3;
    block.NumOutputPorts = 4;

    % Setup port properties to be inherited or dynamic
    block.SetPreCompPortInfoToDefaults;
    block.SetPreCompPortInfoToDefaults;

    % Override input port properties
    for i = 1:block.NumInputPorts
        block.InputPort(i).Dimensions  = 1;
        block.InputPort(i).DatatypeID  = 0;  % double
        block.InputPort(i).Complexity  = 'Real';
        block.InputPort(i).DirectFeedthrough = true;
    end

    % Override output port properties
    for i = 1:block.NumOutputPorts
        block.OutputPort(i).Dimensions  = 1;
        block.OutputPort(i).DatatypeID  = 0; % double
        block.OutputPort(i).Complexity  = 'Real';
    end

    % Register parameters
    block.NumDialogPrms     = 0;

    % Register sample times
    %  [0 offset]            : Continuous sample time
    %  [positive_num offset] : Discrete sample time
    %
    %  [-1, 0]               : Inherited sample time
    %  [-2, 0]               : Variable sample time
    block.SampleTimes = [0 0];

    % Specify the block simStateCompliance. The allowed values are:
    %    'UnknownSimState', < The default setting; warn and assume DefaultSimState
    %    'DefaultSimState', < Same sim state as a built-in block
    %    'HasNoSimState',   < No sim state
    %    'CustomSimState',  < Has GetSimState and SetSimState methods
    %    'DisallowSimState' < Error out when saving or restoring the model sim state
    block.SimStateCompliance = 'DefaultSimState';

    %% Register methods
    block.RegBlockMethod('PostPropagationSetup',    @DoPostPropSetup);
    block.RegBlockMethod('InitializeConditions', @InitializeConditions);
    block.RegBlockMethod('Start', @Start);
    block.RegBlockMethod('Outputs', @Outputs);     % Required
    block.RegBlockMethod('Update', @Update);
    block.RegBlockMethod('Derivatives', @Derivatives);
    block.RegBlockMethod('Terminate', @Terminate); % Required

%end setup

%% PostPropagationSetup:
function DoPostPropSetup(block)
  block.NumDworks                = 1;
  block.Dwork(1).Name            = 'x1';
  block.Dwork(1).Dimensions      = 1;
  block.Dwork(1).DatatypeID      = 0;      % double
  block.Dwork(1).Complexity      = 'Real'; % real
  block.Dwork(1).UsedAsDiscState = true;
%end PostPropagationSetup

%% InitializeConditions:
function InitializeConditions(block)
%end PostPropagationSetup

%% Start:
function Start(block)
block.Dwork(1).Data = 0;
%end Start

%% Outputs:
function Outputs(block)
    [block.OutputPort(1).Data,   ...
     block.OutputPort(2).Data    ...
     block.OutputPort(3).Data    ...
     block.OutputPort(4).Data] = ...
       ProbeFunctions(block.InputPort(1).Data, ...
                        block.InputPort(2).Data, ...
                          block.InputPort(3).Data);

%end Outputs

%% Update:
function Update(block)
block.Dwork(1).Data = block.InputPort(1).Data;
%end Update

%% Derivatives:
function Derivatives(block)
%end Derivatives

%% Terminate:
function Terminate(block)
%end Terminate

