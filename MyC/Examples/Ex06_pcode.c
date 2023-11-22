// PCode Header
#include "PCode.h"

int main() {
pcode_main();
return stack[sp-1].int_value;
}

//Declare x of type x with offset 0 at depth 0 
LOADI(0)

//Declare y of type y with offset 1 at depth 0 
LOADI(0)

void pcode_main(){
LOADI(3)
STOREP(2) // storing x value
LOADF(2.000000)
STOREP(3) // storing y value
LOADI(1)
LOADP(3)
LOADP(2)
MULTI 
ADDI 
return;
}