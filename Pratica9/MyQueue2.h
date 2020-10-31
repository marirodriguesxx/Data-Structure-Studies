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

private:
	MyStack<T> pilha1; //nao mude nada nessa interface!!!
	MyStack<T> pilha2; //nao mude nada nessa interface!!!
};


template<class T>
void MyQueue2<T>::push(const T&el){
	if(pilha1.empty()){
		while(!pilha2.empty()){
			pilha1.push(pilha2.top());
			pilha2.pop();
		}
	}
	pilha1.push(el);
}
template<class T>
void MyQueue2<T>::pop(){
	if(pilha2.empty()){
		while(!pilha1.empty()){
			pilha2.push(pilha1.top());
			pilha1.pop();
		}
	}
	pilha2.pop();

}

template<class T>
bool MyQueue2<T>::empty(){
	return pilha1.empty() && pilha2.empty();	
}

template<class T>
const T MyQueue2<T>::front(){
	if(pilha2.empty()){
		while(!pilha1.empty()){
			pilha2.push(pilha1.top());
			pilha1.pop();
		}
	}
	return pilha2.top();
}

template<class T>
int MyQueue2<T>::size(){
	return pilha1.size();
}







#endif