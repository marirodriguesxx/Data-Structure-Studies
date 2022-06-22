#ifndef DATA_H
#define DATA_H

#include<iostream>
#include<fstream>

class Data {
    public:

    
    Data (int d=1, int m=1, int a=2018); 
    Data(const Data &dt);

    void setDia(int d);
    void setMes(int m);
    void setAno(int a);

    int getDia()const;                          //perguntar do const e &
    int getMes()const;
    int getAno()const;

    int compData(const Data &dma) const;
    int difDias(const Data &) const;
    void imprime()const;
    friend std::ostream& operator<<(std::ostream &out, const Data &dma);
    friend std::istream& operator>>(std::istream &in, Data &dma);

    private:
     int dia;
     int mes;
     int ano;

};

#endif