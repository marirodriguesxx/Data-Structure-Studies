#ifndef FIGBASE_H
#define FIGBASE_H

class FigBase{
    public:
    FigBase(double, double, int, int, int);

    double getX()const;
    double getY()const;
    int getEspessura()const;
    int getCor()const;
    int getTipo()const;

    void setX(double);
    void setY(double);
    void setEspessura(int);
    void setCor(int);
    void setTipo(int);

    void imprime();


    private:
    double x;
    double y;
    int espessura;
    int cor;
    int tipo;
};


#endif