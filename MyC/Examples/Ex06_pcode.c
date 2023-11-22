// PCode Header
#include "PCode.h"

int main() {
pcode_main();
return stack[sp-1].int_value;
}

//Declare x of type x with offset 0 at depth 0 
LOADI(0)

//Declare y of type y with offset 0 at depth 0 
LOADI(0)

void pcode_main(){
LOADI(3)
STOREP(0) // storing -993868960 value
LOADF(2.000000)
STOREP(1) // storing -993868896 value
LOADI(1)
LOADP(1)
LOADP(0)
MULTI
ADDI
return ();
}