// PCode Header
#include "PCode.h"

int main() {
pcode_main();
return track[sp-1].int_value;
}

void pcode_main() { 
LOADI(1) 
LOADI(2) 
LOADI(3) 
MULTI
ADDI
return();
}