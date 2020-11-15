#include "Mediana.h"
void Mediana::insere(int elem){
    if(fila1.size() == 0) 
        fila1.push(elem);
    else{
        if(elem > fila1.top()) 
            fila2.push((-1)*(elem));
        else 
            fila1.push(elem);

        if((fila1.size() - fila2.size()) >= 2){
            fila2.push((-1)*(fila1.top()));
            fila1.pop();
        }
        else if((fila2.size() - fila1.size()) >= 2){
            fila1.push((-1)*(fila2.top()));
            fila2.pop();
        }

    }
}


int Mediana::getMediana(){
    if((fila1.size() == fila2.size()) || ((fila1.size() + fila2.size()) % 2 == 0)) 
        return ((fila1.top() + fila2.top()*(-1))/2);
 
    else{
        if(fila1.size() > fila2.size()) return fila1.top();
        else return (-1) * fila2.top();
    }
}