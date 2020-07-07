//uma classe herda caracteristicas de mais de uma classe
using namespace std;
//PROTOTIPO
class Base1{
    public:
        void impBase1();
};
class Base2{
    public:
        void impBase2();
};
//DECLARACAO
void Base1::impBase1(){
    cout << "Imp classe Base1" << endl;
}
void Base2::impBase2(){
    cout << "Imp classe Base2" << endl;
}

//HERANCA MULTIPLA
class CFB:public Base1, public Base2{
    //A classe CFB é uma superclasse que herdas as caracteristicas de suas subclasses
    
};