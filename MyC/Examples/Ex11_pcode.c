// PCode Header
#include "../PCode/PCode.h"


void pcode_main() {
LOADI(3)
STOREP(bp + 1) // storing x value in current block
SAVEBP // entering block
LOADP(stack[bp].int_value+1) // loading x value
STOREP(bp + 1) // storing y value in current block
SAVEBP // entering block
LOADP(stack[stack[bp].int_value].int_value+1) // loading x value
STOREP(bp + 1) // storing z value in current block
// Removing variable z at depth 3
RESTOREBP // exiting block
// Removing variable y at depth 2
RESTOREBP // exiting block
LOADI(1)
return;
// Removing variable x at depth 1
// Exiting function block, removing loc var and arg from TDS
}
int main() {
// Declare z of type int with offset 1 at depth 3 
LOADI(0)

pcode_main();
return stack[sp-1].int_value;
}

