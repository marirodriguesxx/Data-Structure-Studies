#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include "Screen.h"
#include<utility>
using namespace std;
//struct para armazenar as coordenadas da cobra na tela
struct coordinates{
    int row =0;
    int col=0;
};

class Node;
class Node {
	public:
		Node(const coordinates &elem): data(elem), next(NULL), prev(NULL) {}
		coordinates data;
		Node *next;
		Node *prev;
};

class Snake{
    public:
    Snake (int tamInicialSnake);
    ~Snake(){ destroy(); };


    void draw(Screen &s,int state);
    void move(int dr,int dc,bool eating);
    int getLength()const;

    int getNextcol(const int dc)const;
    int getNextrow(const int dr)const;

    void push_back(const int &h, const int &w);
    void destroy();
    void destroy(Node *first);

    private:
    Node *dataFirst, * dataLast;
};

#endif