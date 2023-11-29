// PCode Header
#include "PCode.h"

int main() {
pcode_main();
return stack[sp-1].int_value;
}

void pcode_fact() {
// Argument  of function fact in TDS with offset -1
// Debut conditionelle 0
LOADP(stack[bp]+-1) // loading x value
LOADI(1)
LTI
IFN(False_0) 
// la condition 0 est vraie
LOADI(1)
return;
}
GOTO(End_0)
False_0
//la condition 0 est fausse
LOADP(stack[bp]+-1) // loading x value
// loading function fact arguments
LOADP(stack[bp]+-1) // loading x value
LOADI(1)
SUBI 
SAVEBP 
CALL(pcode_plusUn) 
RESTOREBP 
ENDCALL(1) // unloading 1 args of function
MULTI 
return;
}
End_0:
// Fin conditionelle 0
void pcode_main() {
// loading function fact arguments
LOADI(5)
SAVEBP 
CALL(pcode_plusUn) 
RESTOREBP 
ENDCALL(1) // unloading 1 args of function
return;
}
