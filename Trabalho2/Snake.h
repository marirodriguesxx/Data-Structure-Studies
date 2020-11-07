
#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
<<<<<<< HEAD
#include "Screen.h"
using namespace std;
//struct para armazenar as coordenadas da cobra na tela
struct coordinates{
    int height =0;
    int width=0;
};
=======
3include "Screen.h"
using namespace std;
>>>>>>> 0738e25a2dc91a8448bf2ec0466f71d8e3c47ddb

class Node;
class Node {
	public:
<<<<<<< HEAD
		Node(const coordinate &elem): data(elem), next(NULL), prev(NULL) {}
		T data;
		Node *next;
		Node *prev;
=======
		Node(const T&elem): data(elem), next(NULL), prev(NULL) {}
		T data;
		Node<T> *next;
		Node<T> *prev;
>>>>>>> 0738e25a2dc91a8448bf2ec0466f71d8e3c47ddb
};

class Snake{
    public:
    Snake (int tamInicialSnake);
    ~Snake();

<<<<<<< HEAD
    void draw(Screen &s,int state);
    void move(int dr,int dc,bool eating);
    //Funções recursivas para armarzenarmos o tamanho da cobra
    int getLength(){return getLength(dataLast);}const;
    int getLength(Node<coordinates> *last)const;

    void push_back(const int &h, const int &w);

    private:
    Node *dataFirst, * dataLast;
=======
    void draw(Screen s,int state);
    void move(int dr,int dc,bool eating);
    int getLength()const;

    private:
    Node<T> *dataFirst, * dataLast;
>>>>>>> 0738e25a2dc91a8448bf2ec0466f71d8e3c47ddb
};

#endif