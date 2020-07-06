//#ifndef AVIAO_H_INCLUDED
//#define AVIAO_H_INCLUDED
using namespace std;
#include <iostream>
class Aviao{
    public:
        
        int vel=0;
        int velMax;
        string tipo;
        Aviao(int tp); //Prototipando o Construtor
        void Imprimir();
    private:
};

Aviao::Aviao(int tp){//Declaracao do Metodo Construtor
    if(tp==1){
        tipo="Jato";
        velMax=800;
    }else if(tp==2){
        tipo="Monomotor";
        velMax=350;
    }else if(tp==3){
        tipo="Planador";
        velMax=180;
    }
}
void Aviao::Imprimir(){
    cout << "---------------------------" << endl;
    cout<< "Tipo............: " << tipo << endl;
    cout<< "Velocidade maxima: " << velMax << endl;
    cout<< "Velocidade atual.: " << vel << endl;
    cout << "---------------------------" << endl;

}
//#endif