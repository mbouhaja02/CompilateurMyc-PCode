// PCode Header
#include "PCode.h"

int main() {
pcode_main();
return stack[sp-1].int_value;
}

void pcode_castToFloat() {
// Argument  of function castToFloat in TDS with offset -1
LOADP(bp+-1) // loading x value
return;
}
void pcode_main() {
// loading function castToFloat arguments
LOADI(1)
SAVEBP 
CALL(pcode_castToFloat) 
RESTOREBP 
ENDCALL(1)  // unloading 1 args of function castToFloat
return;
}
