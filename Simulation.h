#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <sstream>
#include <string>
#include <utility>
using namespace std;

#include "Prey.h"
#include "Predator.h"

class Simulation{
    private:
        int timeStep;
        float predatorGrowth;
        float preyGrowth;
        pair<float,float> result;

    public:
        Simulation(): timeStep(0), predatorGrowth(0), preyGrowth(0), result(0,0){};
        Simulation(int timS, float predatorG, float preyG){
            timeStep = timS;
            predatorGrowth = predatorG;
            preyGrowth = preyG;
        }
        void setTimeStep(int timS);
        int getTimeStep(){return timeStep;}
        void setPpGrowth(Predator tasaR, Predator tasaM, Predator popPredator, Predator tasaD, 
        Prey tasaN, Prey popPrey, float preyG, float predatorG, int timS);
        pair<float,float> getPpGrowth(){return result;}
};

void Simulation::setTimeStep(int timS){
    timeStep = timS;
}
void Simulation::setPpGrowth(Predator tasaR, Predator tasaM, Predator popPredator, Predator tasaD, 
        Prey tasaN, Prey popPrey, float preyG, float predatorG, int timS){

            for(int i = timS; i > 0; i = i-1){
                float x, y;
                x = popPredator.getPopulationPredator();
                y = popPrey.getPopulationPrey();
                predatorG = (x+predatorG)*(y*tasaR.getReproduccion()-tasaM.getMortalidad());
                preyG = (y+preyG)*(tasaN.getNatalidad()-tasaD.getDepredacion()*x);

                result = make_pair(predatorG, preyG);
            }
}

#endif