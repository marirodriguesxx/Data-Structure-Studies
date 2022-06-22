
#include "Retangulo.h"
#include <iostream>
#include<fstream>
using std::cout;
using std::endl;

Retangulo::Retangulo(double x=0, double y=0, 
                     double larg=0, double alt=0,
                     int esp=0, int c=0, int t=0)
                        : FigBase(x,y,esp,c,t) {
    setLargura(larg);
    setAltura(alt);
}

/*double Retangulo::getX() const {
    return x;
}*/

/*void Retangulo::setX(double x) {
    this->x = x;
}*/

/*double Retangulo::getY() const {
    return y;
}*/

/*void Retangulo::setY(double y) {
    this->y = y;
}*/

double Retangulo::getLargura() const {
    return largura;
}

void Retangulo::setLargura(double larg) {
    largura = larg;
}
double Retangulo::getAltura() const {
    return altura;
}

void Retangulo::setAltura(double alt) {
    altura = alt;
}

/*int Retangulo::getEspessura() const {
    return espessura;
}*/

/*void Retangulo::setEspessura(int esp) {
    espessura = (esp < 1 || esp > 5) ? 1 : esp;
}*/

/*int Retangulo::getCor() const {
    return cor;
}*/

/*void Retangulo::setCor(int c) {
    cor = (c < 1 || c > 5) ? 1 : c;
}*/
    
/*int Retangulo::getTipo() const {
    return tipo;
}*/

/*void Retangulo::setTipo(int t) {
    tipo = (t < 1 || t > 3) ? 1 : t;;
}*/

float Retangulo::area() const {
    return altura * largura;     
}      
          
float Retangulo::perimetro() const {
    return 2*(largura + altura);      
}

void Retangulo::imprime()  {
    cout << "--- [Retangulo] ---" << endl;  
    FigBase::imprime();
    cout << " largura = " << getLargura() << " altura = " << getAltura() << endl;  
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}

 std::istream& operator>>(std::istream &in, Retangulo &retangulo) {
	double larg, alt;
	in >> larg >> alt;
	retangulo.setLargura(larg);
    retangulo.setAltura(alt);
	return in;
    }

std::ostream& operator<<(std::ostream &out, const Retangulo &retangulo) {
    out << retangulo.getLargura() << " " << retangulo.getAltura();
    return out;
}
