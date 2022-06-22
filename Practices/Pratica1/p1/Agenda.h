#ifndef AGENDA_H
#define AGENDA_H
#include "Data.h"
#include"Horario.h"
#include<string>
#include<iostream>
#include<fstream>

class ItemAgenda{
    public:
    ItemAgenda();
    ItemAgenda(const std::string &desc, const Data &dt, const Horario &hr);

    void setDesc(const std::string &desc);
    void setData(const Data &dt);
    void setHorario(const Horario &hr);

    const std::string& getDesc()const;
    const Data& getData()const;
    const Horario& getHorario()const; 
    private:
    std::string descr;
    Data data;
    Horario horario;
};

class Agenda{

    public:
    Agenda ();
    void inserirItem(const ItemAgenda &it) ;
    void compromissosData(const Data &dt)const;

    private:
        ItemAgenda vetor[1000];
        int cont=0;

};

#endif