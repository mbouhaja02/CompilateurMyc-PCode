// PCode Header
#include "../PCode/PCode.h"


void pcode_castToFloat() {
// Argument  of function castToFloat in TDS with offset -1
LOADP(bp+-1) // loading x value
return;
// Removing variable x at depth 1
// Exiting function block, removing loc var and arg from TDS
}
void pcode_main() {
// loading function castToFloat arguments
LOADI(1)
I2F
SAVEBP 
CALL(pcode_castToFloat) 
RESTOREBP 
ENDCALL(1)  // unloading 1 args of function castToFloat
return;
// Exiting function block, removing loc var and arg from TDS
}
int main() {
pcode_main();
return stack[sp-1].int_value;
}

