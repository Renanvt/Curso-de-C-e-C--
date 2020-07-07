using namespace std;
class Veiculo{
    public:
        int vel;
        int blind; //blindagem
        int rodas;
        void setTipo(int tp);
        void setVelMax(int vm);
        void setArma(bool ar);
        void imp();
    private:
        int tipo; //1=Moto, 2=Carro, 3=Caminhao, 4=Tanque
        int velMax;
        bool arma;
};

//Classe moto herda a classe veiculo
class Moto:public Veiculo{
    public:
        Moto(); //Construtor
};
void Veiculo::setTipo(int tp){
    tipo=tp;
}
void Veiculo::setVelMax(int vm){
    velMax=vm;
}
void Veiculo::setArma(bool ar){
    arma=ar;
}
void Veiculo::imp(){
    cout << "Tipo veiculo.....: " << tipo <<endl;
    cout << "Velocidade Maxima: " << velMax <<endl;
    cout << "Qtde rodas.......: " << rodas <<endl;
    cout << "Blindagem........: " << blind <<endl;
    cout << "Armamento........: " << arma <<endl;
    cout << "-----------------------: " << tipo <<endl;

}

Moto::Moto(){
    //Declaracao do construtor
    vel=0;
    blind=0;
    rodas=2;
    setTipo(1);
    setVelMax(120);
    setArma(false);
}
class Carro:public Veiculo{
    public:
        Carro();
};
Carro::Carro{
    vel=0;
    blind=0;
    rodas=4;
    setTipo(2);
    setVelMax(180);
    setArma(false);
}