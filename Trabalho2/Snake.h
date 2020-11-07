#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include "Screen.h"
using namespace std;
//struct para armazenar as coordenadas da cobra na tela
struct coordinates{
    int height =0;
    int width=0;
};

class Node;
class Node {
	public:
		Node(const coordinate &elem): data(elem), next(NULL), prev(NULL) {}
		T data;
		Node *next;
		Node *prev;
};

class Snake{
    public:
    Snake (int tamInicialSnake);
    ~Snake();

    void draw(Screen &s,int state);
    void move(int dr,int dc,bool eating);
    //Funções recursivas para armarzenarmos o tamanho da cobra
    int getLength(){return getLength(dataLast);}const;
    int getLength(Node<coordinates> *last)const;

    void push_back(const int &h, const int &w);

    private:
    Node *dataFirst, * dataLast;
};

#endif