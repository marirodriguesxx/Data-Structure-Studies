#ifndef MyQueue2_H__
#define MyQueue2_H__

#include "MyStack.h"
#include <iostream>
using namespace std;

template<class T>
class MyQueue2 {
public:
	MyQueue2() {} 

	void push(const T&el);
	const T front() ; //Nesta implementacao vamos permitir retorno por copia...
	void pop() ;
	//Função auxiliar para reverter uma lista

	bool empty() ;
	int size() ;
	void change();

private:
	MyStack<T> pilha1; //nao mude nada nessa interface!!!
	MyStack<T> pilha2; //nao mude nada nessa interface!!!
};

template<class T>
void MyQueue2<T>::push(const T&el){
    pilha1.push(el);
}


template<class T>
int MyQueue2<T>::size() {
    return pilha1.size() + pilha2.size();
}

template<class T>
bool MyQueue2<T>::empty(){
	return pilha1.empty() && pilha2.empty();	
}

template<class T>
// chamamaremos essa função para copiar os elementos, em ordem inversa, da pilha 1 para a pilha 2
void MyQueue2<T>::change(){
	//percorremos a pilha 1 enquanto ela ainda não estiver vazia
	//Acada iteração vamos copiando o elemento do topo da pilha 1 para a pilha 2 e, após esse processo, removemos o top da pilha 1
	while(!pilha1.empty()){
		pilha2.push(pilha1.top());
		pilha1.pop();
	}
}

//Nas funçoes abaixo chamamos a change pois, quando passamos os elementos da pilha 1 para a pilha 2 fizemos com que o top correspondesse ao que seria o front de uma fila
template<class T>
const T MyQueue2<T>::front(){
    if (pilha2.empty())				
		change();
    return pilha2.top();
}

template<class T>
void MyQueue2<T>::pop(){
    if (pilha2.empty())
		change();
    pilha2.pop();
}

#endif