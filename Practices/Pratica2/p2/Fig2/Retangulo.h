
#ifndef __Retangulo_h
#define __Retangulo_h
#include"FigBase.h"
#include<fstream>

class Retangulo : public FigBase{
private:
    
    double largura, altura;

public:
    Retangulo();
    Retangulo(double, double, double, double, int, int, int);

    double getLargura() const;
    void setLargura(double);

    double getAltura() const;
    void setAltura(double);

    float area() const;
    float perimetro() const;

    void imprime() ;
    friend std::ostream& operator<<(std::ostream &out, const Retangulo &);
    friend std::istream& operator>>(std::istream &in, Retangulo &);

};

#endif
