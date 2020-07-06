using namespace std;
class Veiculo{
    //As propriedades public e privados só podem ser manipulados dentro da própria classe
    public:
        int vel;
        int tipo;
        Veiculo(int tp);//Construtor
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
        velMax=200;
    }else if(tipo==2){
        nome="Aviao";
        velMax=800;
    }else if(tipo==3){
        nome="Navio";
        velMax=120;
    }
}