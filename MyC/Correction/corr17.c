// PCode Header
#include "PCode.h"

int main() {
pcode_main();
return stack[sp-1].int_value;
}

void pcode_castToFloat() {
// Argument x of function castToFloat in TDS with offset -1
LOADP(bp+-1) // Loading x value in curent block
return;
}
void pcode_main() {
// loading function castToFloat arguments
LOADI(1)
I2F // Converting first arg
SAVEBP 
CALL(pcode_castToFloat) 
RESTOREBP 
ENDCALL(1)  // unloading 1 args of function plusUn
return;
}