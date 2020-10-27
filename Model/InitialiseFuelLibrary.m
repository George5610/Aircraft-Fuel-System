% FSP-generic initialisations for Fuel Network Simulation

% Add paths to S-function directories
addpath('C:\Users\smy-zaidi\Desktop\FuelSystemCoursework2020-2021\Model\FuelLibrary');
addpath('C:\Users\smy-zaidi\Desktop\FuelSystemCoursework2020-2021\Model\FuelLibrary\ProbeBlock');

% Logic handling
BooleanThreshold        = 0.5;
BooleanOn               = 1.0;
BooleanOff              = 0.0;
BoolThreshold           = BooleanThreshold;
DiscreteSwitchThreshold = BooleanThreshold;
DiscreteSwitchOn        = BooleanOn;
DiscreteSwitchOff       = BooleanOff;

% Sampling periods
FspSamplingPeriod = 0.250; % 250 msecs

% Load WS settings
WrightSolverSamplingPeriod = FspSamplingPeriod;
InfiniteResistance  = -999.0; % Negative used to represent infinity
FloatingVoltage     = 1e50;
NearInfiniteVoltage = 1e30; % Bigger than any practical voltage, but not FloatingVoltage
NoCurrentOverride   = 1e50;

% Constants and translation factors
TypicalFuelDensity = 797.0;                        % kg/m3                                     [Supplied in Flowmaster model]
FuelSpecificHeatCapacity = 1930;                   % J/(kg.K)                                  ["Handbook of Aviation Fuel Properties" CRC530, Co-ordinating Research Council]
g = 9.81;                                          % ms-2                                      [Physical constant]
SecsPerHour = 3600;                                % sec/hr                                    [Physical constant]
SecsPerMin  = 60;                                  % sec/min                                   [Physical constant]
Mins2Secs = SecsPerMin;                            % sec/min                                   [Physical constant]
Litres2CubeM = 1/1000;                             % Translate litres to cubic metres          [Physical constant]
kpl2kpm3 = 1/Litres2CubeM;                         % Translate kg/litre to kg/m3               [Physical constant]
PerMin2PerSec = 1/SecsPerMin;                      % Translate per-min to per-sec              [Physical constant]
PerSec2PerMin = SecsPerMin;                        % Translate per-sec to per-min              [Physical constant]
PerSec2PerCycle = FspSamplingPeriod;               % Translate per-second to per-cycle         [Physical constant]
PerCycle2PerSec = 1/PerSec2PerCycle;               % Translate per-cycle to per-second         [Physical constant]
PerMin2PerCycle = PerMin2PerSec * PerSec2PerCycle; % Translate per-minute to per-cycle         [Physical constant]
lpm2mps = Litres2CubeM/Mins2Secs;                  % Translate litres-per-minute to m3-per-sec [Physical constant]
lpm2kps = lpm2mps * TypicalFuelDensity;            % Translate litres-per-minute to kg-per-sec [Physical constant]
Pascal2Bar = 1/100000;                             % Translate Pascals to bar                  ["Internal Flow Systems" Miller]
Psi2Pascal = 6894.757;                             % Translate Psi to pascals                  [Physical constant]
Bar2Pascal = 100000;                               % Translate bar to pascals                  ["Internal Flow Systems" Miller]
BarPerLpm2PascalPerMps = Bar2Pascal/lpm2mps;       % Translate bar-per-lpm to pascal-per-m3ps  [Derived from Bar2Pascal]
BarPerLpm2PascalPerKps = Bar2Pascal/lpm2kps;       % Translate bar-per-lpm to pascal-per-kps   [Derived from Bar2Pascal]

% Typical values
DefaultTemp = 20;                     % degC                        [Typical atmospheric temperature]
NominalAValue = 1.000384;             % Fuel A-value: Dimensionless [Source to be supplied]
MinAValue     = 0.5;                  % Fuel A-value: Dimensionless 
MaxAValue     = 1.5;                  % Fuel A-value: Dimensionless 
NominalBValue = 1.1492;               % Fuel B-value: Dimensionless [Source to be supplied]
MinBValue     = 0.5;                  % Fuel B-value: Dimensionless 
MaxBValue     = 1.5;                  % Fuel B-value: Dimensionless 

% General infinite values
InfiniteVolume = 1e9;                              % [Selected to avoid calculation saturation]
InfiniteLevel = 1e9;                               % [Selected to avoid calculation saturation]
InfinitePressure = 1e9;                            % [Selected to avoid calculation saturation]
InfiniteFlow = 1e9;                                % [Selected to avoid calculation saturation]
InfiniteTemp = 1e6;                                % [Selected to avoid calculation saturation]
InfiniteTime = 1e9;                                % [Selected to avoid calculation saturation]
InfiniteMass = 1e9;                                % [Selected to avoid calculation saturation]

% General near-zero values
NearZeroResistance = 1e-9 * BarPerLpm2PascalPerKps; % Pascal/kgs-1 [Selected to avoid calculation saturation]
NearZeroFlow = 1e-4 * lpm2kps;                      % kg/sec       [Selected to avoid calculation saturation]
NearZeroMass = 0.001;                               % kg           [Selected to avoid calculation saturation]
NearZeroTime = FspSamplingPeriod/10;                % sec          [Selected to avoid calculation saturation]

% Special values for NaN, Inf, etc
FloatingPressure = FloatingVoltage;
UnknownValue  = 1e50;
NullBasePress = InfinitePressure; % Pascal [Select to avoid selection by pressure network]

% Error injection control
NoError            = 0;
ValveFlapOpenError = 1;
ValveFlapShutError = 2;
PumpNrvOpenError   = 1;
TankEmptyFlowError = 1;
TankFixedMassError = 2;
InletPressureMode  = 1;
InletFlowMode      = 2;

% Tank positions
Left  = 0;
Right = 1;

% Reset/override mechanism parameters
PipeDisconnected = -1000;
TankNoReset      = -1000; 
MeterNoReset     = -1000; 
FlowNoOverride   = NoCurrentOverride; 

% Valve parameters
ValveOpenTime       = 2.0; % secs
ValveClosedPosition = 0;   % 0-1 fraction
ValveSwitchPosition = 0.5; % 0-1 fraction
ValveOpenPosition   = 1;   % 0-1 fraction

% Pump parameters
PumpOnTime = 2.0;

%% Initialisation for Aircraft-specific Fuel Network Simulation

%% Typical values for this aircraft
TypicalFlow		= (150.0 * lpm2kps);  % kg/sec                      [Supplied in Flowmaster model]
TypicalPressure	= (1.0 * Bar2Pascal); % Pascal                      [Supplied in Flowmaster model]
TypicalResistance = (3.000000e-005) * BarPerLpm2PascalPerKps;       % Typical pipe resistance
TypicalCabinPressure = (1.7 * Bar2Pascal);	%Pascal [A340 A/C Maintenance manuel ACT -> CT Vent Pipe Pressure 0.63 to 0.89] 

%% Pipe parameters
TrimTankCrossResistance = 0.1e-6 * BarPerLpm2PascalPerKps;
XFlowResistance         = 0.1e-3 * BarPerLpm2PascalPerKps * 3;

%% Pump parameters
BowserOnPressure           = (2.0 * Bar2Pascal);                          % Pascal       [Supplied in Flowmaster model]
PumpOnPressure             = (3.5 * Bar2Pascal);                          % Pascal       [Supplied in Flowmaster model]
PumpOnLowPressure          = (1.7 * Bar2Pascal);                          % Pascal       [Derived from RFI/E35/3148]
FeedPumpOnPressure         = (2.9 * Bar2Pascal);                          % Pascal       [Supplied in Flowmaster model]
TrimPumpOnPressure         = (2.6 * Bar2Pascal);                          % Pascal       [Supplied in Flowmaster model]
PumpOffPressure            = (0.0 * Bar2Pascal);                          % Pascal       [Supplied in Flowmaster model]
PumpZeroPressureFlow       = (530 * lpm2kps);                             % kg/s         [Supplied in Flowmaster model]
FeedPumpZeroPressureFlow   = (1000 * lpm2kps);                            % kg/s         [Supplied in Flowmaster model]
TrimPumpZeroPressureFlow   = (250 * lpm2kps);                             % kg/s         [Supplied in Flowmaster model]
PumpInternalResistance     = PumpOnPressure/PumpZeroPressureFlow;         % Pascal/kgs-1 [Supplied in Flowmaster model]
FeedPumpInternalResistance = FeedPumpOnPressure/FeedPumpZeroPressureFlow; % Pascal/kgs-1 [Supplied in Flowmaster model]
TrimPumpInternalResistance = TrimPumpOnPressure/TrimPumpZeroPressureFlow; % Pascal/kgs-1 [Supplied in Flowmaster model]
JetPumpOrifaceTypicalFlow  = 75 * lpm2kps;

%% Network resistances (derived from bar and lit/min values in Flowmaster model)
ValveOnResistance            = 4e-6 * BarPerLpm2PascalPerKps;             % Pascal/kgs-1 [Derived from Flowmaster model]
ValveOffResistance           = InfiniteResistance;                        % Pascal/kgs-1 [Derived from Flowmaster model]
RestrictorValveOffResistance = 1.4e-2 * BarPerLpm2PascalPerKps;
RestrictorFwdResistance      = NearZeroResistance;
RestrictorBackResistance     = ValveOnResistance;
NonRetResistance             = 1e-5 * BarPerLpm2PascalPerKps;             % Pascal/kgs-1 [Derived from Flowmaster model]
NonRetLeakageResistance      = 1e2  * BarPerLpm2PascalPerKps;             % Pascal/kgs-1 [Derived from Flowmaster model]
TankInletResistance          = 1e-5 * BarPerLpm2PascalPerKps;             % Pascal/kgs-1 [Derived from Flowmaster model]
BowserInletResistance        = 1e-5 * BarPerLpm2PascalPerKps;             % Pascal/kgs-1 [Derived from Flowmaster model]
PipeResistance               = 1e-5 * BarPerLpm2PascalPerKps;             % Pascal/kgs-1 [Derived from Flowmaster model]
TJBranchResistance           = 1e-5 * BarPerLpm2PascalPerKps;             % Pascal/kgs-1 [Derived from Flowmaster model]
DiffuserResistance           = 10e-5 * BarPerLpm2PascalPerKps;            % Pascal/kgs-1 [Derived from Flowmaster model]
JettisionNozzleResistance    = 20e-5 * BarPerLpm2PascalPerKps;            % Pascal/kgs-1 [Derived from Flowmaster model]
WeirResistance               = TypicalResistance/10.0;
TransferValveResistance      = 30e-5 * BarPerLpm2PascalPerKps;

%% Temporary orifice C values
OrifaceC = 10000;

%% Refuel/Defuel coupling parameters
CouplingOnPressure     = 0.70 * Bar2Pascal;
CouplingOffPressure    = 0.01 * Bar2Pascal;
CouplingResistance     = (1.0 * Bar2Pascal)/((4000.0 - 2300.0) * lpm2kps);
LinearCouplingResistance = (1.0 * Bar2Pascal)/(3300 * lpm2kps);
CouplingOffsetPressure = (1500.0 * lpm2kps) * CouplingResistance;
