// PCode Header
#include "../PCode/PCode.h"


void pcode_plusUn() {
// Argument  of function plusUn in TDS with offset -1
LOADP(bp+-1) // loading x value
LOADI(1)
ADDI 
return;
// Removing variable x at depth 1
// Exiting function block, removing loc var and arg from TDS
}
void pcode_main() {
// loading function plusUn arguments
LOADI(1)
SAVEBP 
CALL(pcode_plusUn) 
RESTOREBP 
ENDCALL(1)  // unloading 1 args of function plusUn
return;
// Exiting function block, removing loc var and arg from TDS
}
int main() {
pcode_main();
return stack[sp-1].int_value;
}

