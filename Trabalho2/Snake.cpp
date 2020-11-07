#include "Snake.h"

Snake::Snake(int tamInicialSnake){
    dataFirst = dataLast  = NULL;
    for(int i=0;i<tamInicialSnake;i++){ 
        push_back(0,i); 
	}
}

void Snake::push_back(const int &h, const int &w) {
	coordinates elem;
	elem.height = h;
	elem.width =w;
	if(dataFirst==NULL) { 
		dataFirst = dataLast = new Node<cordinates>(elem);
	} 
    else {
		dataLast->next = new Node<coordinates>(elem);
		dataLast->next->prev = dataLast;
		dataLast = dataLast->next;
	}	
}

int Snake::getLength(Node *last)const{
	//Passo básico da recursão : se for uma lista vazia, seu size é zero
	if(last==NULL){
		return 0;
	}	
	//Andamos do final ao inicio da lista, somando 1 no retorno
	return size(last->prev) + 1;
}

void Snake::draw(Screen &s,int state){
	Node* cobra = dataFirst;
	for(int i=0; i<getLength(); i++){
		s.set(cobra.height,cobra.width,state);
		cobra = cobra -> next;
	}
}

void Snake::move(int dr,int dc,bool eating){
	if(eating = false){
		if(dr != 0 )
			dataLast->data.height +=dr;
		else
			dataLast->data.height +=dc;
	}
}