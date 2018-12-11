#ifndef layer_h
#define layer_h

#include "neuron.h"
#include "matrix.h"
namespace NeuralNetwork {
    class Layer {
        public:
            Layer(int s);
            ~Layer();

            void setVals(Matrix<double> input);            
            Matrix<double> getVals();  
            
            //todo
            void addNeuron();
            void popNeuron();
       
            private:
            int size = 0;
            std::vector<Neuron*> layer;
    };



    Layer::Layer(int s){
        //allocate all memory used for neurons in the layer
        for(int i = 0; i < s; i++) {
            layer.push_back(new Neuron(0));
        }
        
        size = s;
    }


    Layer::~Layer(){
        //deallocate all memory used for Neurons in the layer
        for(int i = 0; i < size; i++ ) {
            delete layer.at(i);
        }
     }
    
    void Layer::setVals(Matrix<double> input) {
        if(input.numRows() != size) throw std::runtime_error("inputs for layer not correct size!");

        for(int i = 0; i < size; i++) {
            layer.at(i)->setVal(input.at(i,0));
        }

    }

    Matrix<double> Layer::getVals() {
        Matrix<double> vals(size - 1, 1);
        for(int i = 0; i < size; i++) {
            vals.at(i,0) = layer.at(i)->getVal();
        }
        return vals;
     }





}
    


#endif
