// PCode Header
#include "../PCode/PCode.h"


void pcode_main() {
LOADI(1)
LOADI(2)
LOADI(3)
MULTI 
ADDI 
return;
// Exiting function block, removing loc var and arg from TDS
}
int main() {
pcode_main();
return stack[sp-1].int_value;
}

