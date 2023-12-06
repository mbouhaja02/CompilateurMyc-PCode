// PCode Header
#include "../PCode/PCode.h"


void pcode_main() {
LOADF(1.000000)
LOADF(2.200000)
LOADF(3.500000)
MULTF 
ADDF 
return;
// Exiting function block, removing loc var and arg from TDS
}
int main() {
pcode_main();
return stack[sp-1].int_value;
}

