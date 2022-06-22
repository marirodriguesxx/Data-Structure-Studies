#include<string>
#include<iostream>
#include<fstream>
#include"Data.h"
#include<fstream>

using namespace std;

Data::Data(const int d,const int m,const int a){
    setDia(d);
    setMes(m);
    setAno(a);
}


int Data::getDia()const{
    return dia;
}
int Data::getMes()const{
    return mes;
}
int Data::getAno()const{
    return ano;
}

void Data::setDia(int d){
    if(d<1)
        d=1;
    else if(d>30)
        d=30;
    dia=d;
}
void Data::setMes(int m){
    if(m<1)
        m=1;
    else if(m>12)
        m=12;
    mes=m;
}
void Data::setAno(int a){
    if(a<2018)
        a=2018;
    else if(a>2020)
        a=2020;
    ano=a;
}

void Data::imprime() const {
	cout << *this;
}


int Data::compData(const Data &dma) const{
    int dist = difDias(dma);

    if(dist<0)
        return -1;
    else if(dist ==0)
        return 0;
    else
        return 1;    

}
/*int Data::difDias(const Data &dma) const{
    int x1,x2;
    x1=dia+mes*30+ano*360;
    x2=dma.dia+dma.mes*30+dma.ano*360;
    return x1-x2;
}*/

int Data::difDias(const Data &dt) const{
        int subdia1 = 0, subdia2 = 0, diferenca = 0;
        subdia1 = ((ano-1)*360)+((mes-1)*30)+dia;
        subdia2 = ((dt.ano-1)*360)+((dt.mes-1)*30)+dt.dia;
        diferenca = subdia1 -subdia2;
        return diferenca;
    }

std::istream& operator>>(std::istream &in, Data &dma) {
	int d,m,a;
	in >> d >> m >> a;
	dma.setDia(d);
	dma.setMes(m);
	dma.setAno(a);
	return in;
}

std::ostream& operator<<(std::ostream &out, const Data &dma) {
	out << dma.dia << " " << dma.mes << " " << dma.ano;
	return out;
}

