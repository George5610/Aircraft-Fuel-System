% Script for building of block S-function
display('Building InletControlBlock S-function MEXW32')
mex -DOS_WIN ...
	-DENDIAN_LITTLE ...
	-DPROC_X86 ...
	-DDLL_EXPORT_INTERFACE ...
	-DSIMULINK_SIMULATION ...
	-IW:\FuelLibrary\InletControlBlock ...
	-IW:\FuelLibrary ...
	-IW:\FuelLibrary\WrightSolver ...
	-IW:\FuelLibrary\Common_Generic ...
    -IW:\FuelLibrary\Models\Fsp ...
   W:\FuelLibrary\InletControlBlock\InletControlBlockWrapper.c ...
   W:\FuelLibrary\InletControlBlock\InletControlBlock.c
