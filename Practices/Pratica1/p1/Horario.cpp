#include<iostream>
#include<fstream>
#include"Horario.h"

using namespace std;

Horario::Horario(int h, int m, int s){
    setHora(h);
    setMinuto(m);
    setSegundos(s);
}

Horario::Horario(const Horario &hr){
    this->hora =hr.hora;
    this->minuto =hr.minuto;
    this->segundo =hr.segundo;
}

int Horario::getHora()const{
    return hora;
}
int Horario::getMinuto()const{
    return minuto;
}
int Horario::getSegundo()const{
    return segundo;
}


void Horario::setHora(int h){
    if(h<0)
        h=0;
    else if(h>23)
        h=23;
    hora=h;
}
void Horario::setMinuto(int m){
    if(m<0)
        m=0;
    else if(m>60)
        m=60;
    minuto=m;
}
void Horario::setSegundos(int s){
    if(s<0)
        s=0;
    else if(s>60)
        s=60;
    segundo=s;
}

int Horario::compHorario(const Horario &hms)const{
    int dist = difSegundos(hms);

    if(dist<0)
        return -1;
    else if(dist==0)
        return 0;
    else
        return -1;
    
}
int Horario::difSegundos(const Horario &hms)const{
    int h1,h2;
    h1=hora*3600+minuto*60+segundo;
    h2=hms.hora*3600+hms.minuto*360+hms.segundo;

    return h1-h2;
}

void Horario::imprime() const {
	cout << *this;
}

std::ostream& operator<<(std::ostream &out, const Horario &hms) {
	out << hms.hora << " " << hms.minuto << " " << hms.segundo;
	return out;
}


std::istream& operator>>(std::istream &in, Horario &hms) {
	int h,m,s;
	in >> h >> m >> s;
	hms.setHora(h);
	hms.setMinuto(m);
	hms.setSegundos(s);
	return in;
}
