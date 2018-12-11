#ifndef neuron_h
#define neuron_h
#include "utility.h"
#include <string>
const double E = std::exp(1.0);

namespace BrainWave {
    class Neuron {
        public:
            Neuron(int v, std::string actT = "sigma") {
                value = v; 
                activationType = actT;
            }


            void setVal(double v) { value = v;}

            double getVal() {return value;}

            //activation function for neural network
            const std::vector<std::string> functions = {"sigma","softmax","htan"};

            //for soft-max
            double total = 0.0;
            
            //activation function
            void activate(std::vector<Neuron > * layer = nullptr);

            double getActivatedVal() {  return activatedValue; }

            std::string getActivationType() { return activationType; }
            void setActivationType(std::string t){ activationType = t; }
            
            void setBias(bool b) {isBias = b;}
            bool getBias() {return isBias;}
        private:
            bool isBias = false;
            std::string activationType;


            std::unordered_map< std::string, int > s2i;
            double value = 0.0;
            double activatedValue = 0.0;
            void mapActivationFunctions();

    };
    

    void Neuron::activate(std::vector<Neuron > * layer) {
        if(isBias) {
            activatedValue = value;
            return;//idk about this for now
        }
        
        std::transform(activationType.begin(), activationType.end(), activationType.begin(), ::tolower);
        switch(s2i[activationType]) {
            case 0:
                //sigma activation
                activatedValue = 1.0 / (1.0 + std::pow(E,-1.0 * value));
                break;
            case 1:
                //softmax activation
                //takes the layer pointer given as input (which the neuron instance is usually in)
                //and calculates its value in reference to the other values of the layer
                for(int i = 0; i < layer->size(); i++) {
                    total += layer->at(i).getVal();
                }
                activatedValue = value / total;
                break;
            case 2:
                //htan activation
                break;
            default:
                //activation function doesnt exist, throw error!
                std::string msg;
                msg = "The activation function ";
                msg += activationType;
                msg += " doesn't exist!";
                throw std::runtime_error(msg);
                break;
        }
    }


    void Neuron::mapActivationFunctions() {
        for(int i = 0; i < functions.size(); i++) {
            s2i[functions[i]] = i;
        }
    }
 
}
#endif

