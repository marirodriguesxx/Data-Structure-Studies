
#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
3include "Screen.h"
using namespace std;

class Node;
class Node {
	public:
		Node(const T&elem): data(elem), next(NULL), prev(NULL) {}
		T data;
		Node<T> *next;
		Node<T> *prev;
};

class Snake{
    public:
    Snake (int tamInicialSnake);
    ~Snake();

    void draw(Screen s,int state);
    void move(int dr,int dc,bool eating);
    int getLength()const;

    private:
    Node<T> *dataFirst, * dataLast;
};

#endif