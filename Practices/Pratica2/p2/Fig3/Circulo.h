
#ifndef __Circulo_h
#define __Circulo_h
#include"FigBase.h"
#include<fstream>

class Circulo : public FigBase{
private:
    //double x, y;   // centro
    double raio;

    // atributos da linha
    //int espessura; // inteiro de 1 a 5
    //int cor;       // inteiro de 1 a 5
    //int tipo;      // inteiro de 1 a 3

public:
    Circulo(double, double, double, int, int, int);

    //double getX() const;
    //void setX(double);

    //double getY() const;
    //void setY(double);

    double getRaio() const;
    void setRaio(double);

    //int getEspessura() const;
    //void setEspessura(int);

    //int getCor() const;
    //void setCor(int);

    //int getTipo() const;
    //void setTipo(int);

    float area() const;
    float perimetro() const;

    void imprime() ;

    friend std::ostream& operator<<(std::ostream &out, const Circulo &);
    friend std::istream& operator>>(std::istream &in, Circulo &);

};

#endif
