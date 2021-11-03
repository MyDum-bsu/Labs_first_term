#include <iostream>
#include "quadratic_equations.h"

int main() {
quadraticEquations yce(1, -5, 6);
yce.solve();

quadraticEquations zer(0, 0, 0);
zer.solve();

quadraticEquations comp(4, 1, 2);
comp.solve();

quadraticEquations no(0, 0, 1);
no.solve();

quadraticEquations ano(0, 1, 3);
ano.solve();
return 0;
}