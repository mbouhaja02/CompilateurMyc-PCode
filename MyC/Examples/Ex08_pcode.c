// PCode Header
#include "PCode.h"

int main() {
pcode_main();
return stack[sp-1].int_value;
}

//Declare x of type 789394272 with offset 0 at depth 0 
LOADI(0)

//Declare y of type 789394336 with offset 1 at depth 0 
LOADI(0)

//Declare z of type 789394400 with offset 2 at depth 0 
LOADI(0)

void pcode_main(){
// Debut conditionelle 0
LOADP(2) // loading x value
LOADF(0.000000)
GTF 
IFN(False_0) 
// la condition 0 est vraie
// Debut conditionelle 1
LOADP(1) // loading y value
LOADF(0.000000)
GTF 
IFN(False_1) 
// la condition 1 est vraie
LOADI(1)
STOREP(0) // storing z value
GOTO(End_1)
//la condition 1 est fausse
LOADI(2)
STOREP(1) // storing z value
End_1
// Fin conditionelle 1
GOTO(End_0)
//la condition 0 est fausse
// Debut conditionelle 1
LOADP(0) // loading y value
LOADF(0.000000)
GTF 
IFN(False_1) 
// la condition 1 est vraie
LOADI(3)
STOREP(2) // storing z value
GOTO(End_1)
//la condition 1 est fausse
LOADI(4)
STOREP(3) // storing z value
End_1
// Fin conditionelle 1
End_0
// Fin conditionelle 0
LOADP(-1) // loading z value
return;
}