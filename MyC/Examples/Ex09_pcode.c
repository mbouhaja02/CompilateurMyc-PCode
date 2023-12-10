// PCode Header
#include "../PCode/PCode.h"


void pcode_main() {
LOADI(3)
STOREP(0) // storing x value
LOADI(5)
STOREP(1) // storing y value
LOADI(0)
STOREP(2) // storing z value
StartLoop_0: // chargement condition boucle while 0
LOADP(0) // loading x value
LOADI(0)
GTI
IFN(EndLoop_0)
// Debut boucle while 0 
SAVEBP // entering block
LOADP(2) // loading z value
LOADP(1) // loading y value
ADDI 
STOREP(2) // storing z value
LOADP(0) // loading x value
LOADI(1)
SUBI 
STOREP(0) // storing x value
RESTOREBP // exiting block
GOTO(StartLoop_0)
//Fin boucle while 0
EndLoop_0:
LOADP(2) // loading z value
return;
// Exiting function block, removing loc var and arg from TDS
}
int main() {
// Declare z of type int with offset 2 at depth 0 
LOADI(0)

pcode_main();
return stack[sp-1].int_value;
}

