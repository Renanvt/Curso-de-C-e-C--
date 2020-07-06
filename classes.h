using namespace std;
class Veiculo{
    //As propriedades public e privados só podem ser manipulados dentro da própria classe
    public:
        int vel;
        int tipo;
        Veiculo(int tp);//Construtor
        int getVelMax();
        bool getLigado(); //retorna se o carro está ligado ou desligado 
        void setLigado(int l);
    private:
        void setVelMax(int vm); //Pode ser acessado somente pela classe e não por fora
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
    setLigado(0);
}
bool Veiculo::getLigado(){
    return ligado;
}
void Veiculo::setLigado(int l){
    if(l==1){
        ligado=true;
    }else if(l==0){
        ligado=false;
    }
}

int Veiculo::getVelMax(){
    return velMax;
}

void Veiculo::setVelMax(int vm){
    velMax=vm;
}