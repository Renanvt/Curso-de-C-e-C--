using namespace std;
class Veiculo{
    //As propriedades public e privados só podem ser manipulados dentro da própria classe
    public:
        int vel;
        int tipo;
        Veiculo(int tp);//Construtor
        int getVelMax();
        void setVelMax(int vm);
    private:
        string nome;
        int velMax;
        bool ligado;
};

Veiculo::Veiculo(int tp){
    // 1 = Carro, 2 = Aviao, 3=Navio
    tipo=tp;
    if(tipo==1){
        nome="Carro";
        setVelMax(200);
    }else if(tipo==2){
        nome="Aviao";
        setVelMax(800);
    }else if(tipo==3){
        nome="Navio";
        setVelMax(120);
    }
}

int Veiculo::getVelMax(){
    return velMax;
}

void Veiculo::setVelMax(int vm){
    velMax=vm;
}