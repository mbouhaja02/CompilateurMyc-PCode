// PCode Header
#include "PCode.h"

int main() {
pcode_main();
return stack[sp-1].int_value;
}

void pcode_main() {
// Declare x of type int with offset 0 at depth 1 
LOADI(0)

LOADI(3)
STOREP(bp + 1) // storing x value in current block
SAVEBP // entering block
// Declare y of type int with offset 1 at depth 1 
LOADI(0)

LOADP(0) // loading x value
STOREP(bp + 1) // storing y value in current block
SAVEBP // entering block
// Declare z of type int with offset 1 at depth 1 
LOADI(0)

LOADP(0) // loading x value
STOREP(bp + 1) // storing z value in current block
RESTOREBP // exiting block
RESTOREBP // exiting block
LOADI(1)
return;
}