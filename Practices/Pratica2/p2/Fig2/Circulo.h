
#ifndef __Circulo_h
#define __Circulo_h
#include"FigBase.h"    
#include<fstream>

class Circulo : public FigBase{
private:
    
    double raio;

public:
    Circulo();
    Circulo(double, double, double, int, int, int);

    double getRaio() const;
    void setRaio(double);

    float area() const;
    float perimetro() const;

    void imprime() ;

    friend std::ostream& operator<<(std::ostream &out, const Circulo &);
    friend std::istream& operator>>(std::istream &in, Circulo &);

};

#endif
