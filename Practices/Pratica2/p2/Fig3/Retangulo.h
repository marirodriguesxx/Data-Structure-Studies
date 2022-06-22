
#ifndef __Retangulo_h
#define __Retangulo_h
#include"FigBase.h"
#include<fstream>

class Retangulo : public FigBase{
private:
    //double x, y;     // canto inferior esquerdo
    double largura, altura;

    // atributos da linha
    //int espessura; // inteiro de 1 a 5
    //int cor;       // inteiro de 1 a 5
    //int tipo;      // inteiro de 1 a 3

public:
    Retangulo(double, double, double, double, int, int, int);

    //double getX() const;
    //void setX(double);

    //double getY() const;
    //void setY(double);

    double getLargura() const;
    void setLargura(double);

    double getAltura() const;
    void setAltura(double);

    //int getEspessura() const;
    //void setEspessura(int);

    //int getCor() const;
    //void setCor(int);

    //int getTipo() const;
    //void setTipo(int);

    float area() const;
    float perimetro() const;

    void imprime() ;
    friend std::ostream& operator<<(std::ostream &out, const Retangulo &);
    friend std::istream& operator>>(std::istream &in, Retangulo &);

};

#endif
