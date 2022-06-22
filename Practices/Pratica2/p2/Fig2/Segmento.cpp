#include"Segmento.h"
#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

    Segmento::Segmento(){}

    Segmento::Segmento(double x2=0, double y2=0, double x=0, double y=0,
                                 int esp=0, int c=0, int t=0): FigBase(x,y,esp,c,t){
        setX2(x2);
        setY2(y2);
    }

    double Segmento::getX2()const{
            return x2;
    }
    double Segmento::getY2()const{
            return y2;
    }

    void Segmento::setX2(double x2){
            this->x2 = x2;
    }
    void Segmento::setY2(double y2){
            this->y2 = y2;
    }

    float Segmento::area(){
            return 0;
    }
    
    float Segmento::perimetro(){
            return sqrt( (pow((x2 - getX()),2)) + pow((y2 - getY()),2) );
    }

    void Segmento::imprime(){
        cout << "--- [Segmento] ---" << endl;
        FigBase::imprime();
        cout << " area = " << area() << " perimetro = " << perimetro() << endl;         
    }

    std::istream& operator>>(istream &in, Segmento &segmento) {
	int x2,y2;
	in >> x2 >> y2;
	segmento.setX2(x2);
        segmento.setY2(y2);
	return in;
    }

    std::ostream& operator<<(ostream &out, const Segmento &segmento) {
	    out << segmento.getX2() << " " << segmento.getY2();
	    return out;
    }