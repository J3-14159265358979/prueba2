#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "Simulation.h"

int main(){
    Prey conejo(1.1, "conejo blanco", 10);
    Predator zorro(0.4, 0.1, 0.4, "zorro rojo", 10);
    Simulation simulation1;
    simulation1.setPpGrowth(zorro, zorro, zorro, zorro, conejo, conejo, 1.1, 0.4, 2);
    pair<float,float> res = simulation1.getPpGrowth();
    cout << "Depredadores: " << res.first << endl << res.second;
}
