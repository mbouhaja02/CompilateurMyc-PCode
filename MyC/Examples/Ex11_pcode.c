// PCode Header
#include "PCode.h"

int main() {
pcode_main();
return stack[sp-1].int_value;
}

void pcode_main(){
//Declare x of type int with offset 0 at depth 0 
LOADI(0)

LOADI(3)
STOREP(0) // storing x value
SAVEBP // entering block
//Declare y of type int with offset 1 at depth 0 
LOADI(0)

LOADP(1) // loading x value
STOREP(1) // storing y value
SAVEBP // entering block
//Declare z of type int with offset 1 at depth 0 
LOADI(0)

LOADP(1) // loading x value
STOREP(2) // storing z value
RESTOREBP // exiting block
RESTOREBP // exiting block
LOADI(1)
return;
}