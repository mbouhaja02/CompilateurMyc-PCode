// PCode Header
#include "PCode.h"

int main() {
pcode_main();
return stack[sp-1].int_value;
}

//Declare x of type int with offset 0 at depth 0 
LOADI(0)

void pcode_main(){
LOADI(3)
STOREP(0) // storing 1983783776 value
LOADI(1)
LOADP(0)
ADDI
return ();
}