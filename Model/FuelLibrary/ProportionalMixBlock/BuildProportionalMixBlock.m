% Script for building of block S-function
display('Building ProportionalMixBlock S-function MEXW32')
mex -DOS_WIN ...
	-DENDIAN_LITTLE ...
	-DPROC_X86 ...
	-DDLL_EXPORT_INTERFACE ...
	-DSIMULINK_SIMULATION ...
   -IW:\FuelLibrary\Common_Generic ...
   -IW:\FuelLibrary ...
   W:\FuelLibrary\ProportionalMixBlock\ProportionalMixBlockWrapper.c ...
   W:\FuelLibrary\ProportionalMixBlock\ProportionalMixBlock.c ...
   W:\FuelLibrary\FspUtils.c 
