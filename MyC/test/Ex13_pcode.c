// PCode Header
#include "../PCode/PCode.h"


void pcode_main() {
// Declare x of type int with offset 1 at depth 1 
LOADI(0)

// Declare y of type int with offset 2 at depth 1 
LOADI(0)

LOADI(3)
STOREP(bp + 1) // storing x value in current block
SAVEBP // entering block
// Declare x of type int with offset 1 at depth 2 
LOADI(0)

LOADI(4)
STOREP(bp + 1) // storing x value in current block
SAVEBP // entering block
// Declare x of type int with offset 1 at depth 3 
LOADI(0)

LOADI(5)
STOREP(bp + 1) // storing x value in current block
// Removing variable x at depth 3
RESTOREBP // exiting block
LOADP(bp+1) // loading x value
STOREP(stack[bp].index_value + 2) // storing y value in current block
// Removing variable x at depth 2
RESTOREBP // exiting block
LOADP(bp+1) // loading x value
STOREP(bp + 2) // storing y value in current block
LOADP(bp+2) // loading y value
return;
// Removing variable y at depth 1
// Removing variable x at depth 1
// Exiting function block, removing loc var and arg from TDS
}
int main() {
pcode_main();
return stack[sp-1].int_value;
}

