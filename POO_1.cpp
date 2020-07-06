#include <iostream>
using namespace std;
//Criar o objeto
class Aviao{
    public:
        int vel=0;
        int velMax;
        string tipo;
        //prototipo de um método
        void ini(int tp);
    private:
};
//declarando o método
void Aviao::ini(int tp){
    system("cls");
  // 1 = Jato, 2=Monomotor, 3=Planador
  if(tp==1){
      this->velMax=800;//this -> Para essa classe Aviao
      this->tipo="Jato";
  }else if(tp==2){
      this->velMax=350;
      this->tipo="Monomotor";
  }else if(tp==3){
      this->velMax=180;
      this->tipo="Planador";
  }
}
int main(){
    //instanciando um novo objeto
    Aviao *av1 = new Aviao();//Precisa declarar como ponteiro
    //inicializando av1
    Aviao *av2 = new Aviao();
    av2->ini(2);
    av1->ini(3);
    cout << av1->velMax <<endl;
    cout << av2->velMax << endl;
    return 0;
}