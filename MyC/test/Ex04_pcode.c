// PCode Header
#include "../PCode/PCode.h"


void pcode_main() {
LOADI(1)
LOADF(2.200000)
LOADI(3)
I2F // converting second arg to float
MULTF 
I2F2 // converting first arg to float
ADDF 
return;
// Exiting function block, removing loc var and arg from TDS
}
int main() {
pcode_main();
return stack[sp-1].int_value;
}

