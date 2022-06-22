#ifndef Mediana_H
#define Mediana_H
#include"MyPriorityQueue.h"

class Mediana{
    public:
    void insere(int);
    int getMediana();

    private:
    MyPriorityQueue<int> fila1; 
    MyPriorityQueue<int> fila2; 
};


#endif
