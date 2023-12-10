// PCode Header
#include "../PCode/PCode.h"


void pcode_main() {
LOADI(3)
STOREP(bp + 1) // storing x value in current block
SAVEBP // entering block
LOADI(4)
STOREP(bp + 1) // storing x value in current block
SAVEBP // entering block
LOADI(5)
STOREP(bp + 1) // storing x value in current block
// Removing variable x at depth 3
RESTOREBP // exiting block
// Removing variable x at depth 2
RESTOREBP // exiting block
LOADI(1)
return;
// Removing variable x at depth 1
// Exiting function block, removing loc var and arg from TDS
}
int main() {
// Declare x of type int with offset 1 at depth 3 
LOADI(0)

pcode_main();
return stack[sp-1].int_value;
}

