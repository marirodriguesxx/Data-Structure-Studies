#include"FigBase.h"
#include<iostream>

using namespace std;

FigBase::FigBase(){}


FigBase::FigBase(double x=0, double y=0, int esp=0, int c=0, int t=0){
    setX(x);
    setY(y);
    setEspessura(esp);
    setCor(c);
    setTipo(t);
}
    double FigBase::getX()const{
        return x;
    }
    double FigBase::getY()const{
        return y;
    }
    int FigBase::getEspessura()const{
        return espessura;
    }
    int FigBase::getCor()const{
        return cor;
    }
    int FigBase::getTipo()const{
        return tipo;
    }

    void FigBase::setX(double x){
        this->x = x;
    }
    void FigBase::setY(double y){
        this->y = y;
    }
    void FigBase::setEspessura(int esp){
        espessura = (esp < 1 || esp > 5) ? 1 : esp;
    }
    void FigBase::setCor(int c){                      //1,2,3,4,5 = preto, vermelho, verde, azul, amarelo
        cor = (c < 1 || c > 5) ? 1 : c;
    }
    void FigBase::setTipo(int t){                 //tratamos do tipo de linha : 1= contínua, 2=tracejada e 3=pontilhada
        tipo = (t < 1 || t > 3) ? 1 : t;
    }

    void FigBase::imprime(){
    cout << " Atributos da linha: " << endl;
    cout << "     Espessura = " << getEspessura() << endl;
    cout << "     Cor       = " << getCor() << endl;
    cout << "     Tipo      = " << getTipo() << endl;          
    cout << " x = " << getX() << " y = " << getY() << endl;
    }
