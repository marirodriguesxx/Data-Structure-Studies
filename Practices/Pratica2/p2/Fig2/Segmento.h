#ifndef SEGMENTO_H
#define SEGMENTO_H
#include<fstream>

#include"FigBase.h"

class Segmento : public FigBase {
    public:
    Segmento();
    Segmento(double, double, double, double, int, int, int);

    double getX2()const;
    double getY2()const;

    void setX2(double);
    void setY2(double);

    float area();
    float perimetro();

    void imprime();
    
    friend std::ostream& operator<<(std::ostream &out, const Segmento &);
    friend std::istream& operator>>(std::istream &in, Segmento &);

    private:
    double x2;
    double y2;
};

#endif