#include "Snake.h"

Snake::Snake(int tamInicialSnake){
    dataFirst = dataLast  = NULL;
    for(int i=0;i<tamInicialSnake;i++){ 
        push_back(0,i); 
	}
}

void Snake::destroy(Node  *first) {
	if(first==NULL) return;
	destroy(first->next);
	delete first;
}

void Snake::destroy() { 
	destroy(dataFirst);
}

void Snake::push_back(const int &r, const int &c) {
	coordinates elem;
	elem.row = r;
	elem.col =c;
	if(dataFirst==NULL) { 
		dataFirst = dataLast = new Node(elem);
	} 
    else {
		dataLast->next = new Node(elem);
		dataLast->next->prev = dataLast;
		dataLast = dataLast->next;
	}	
}

int Snake::getLength()const{
	//return getLength(dataLast);
	int cont = 0;
	Node *first = dataFirst;
	while(first!=NULL){
		cont++;
		first = first->next;
	}
	return cont;
}

int Snake::getNextcol(const int dc)const{
	Node* aux = dataLast;
	return aux->data.col +dc;
}

int Snake::getNextrow(const int dr)const{
	Node* aux = dataLast;
	return aux->data.row +dr;

}
 int Snake::getPrevrol()const{
	 Node* aux = dataLast;
	 return aux->prev->data.row;
	 
}
int Snake::getPrevcol()const{
	Node* aux = dataLast;
	return aux->prev->data.col;
}

void Snake::draw(Screen &s,int state){
	Node* cobra = dataFirst;
	while(cobra != NULL){
		s.set(cobra->data.row,cobra->data.col,state);
		cobra = cobra -> next;
	}
}



void Snake::move(int dr,int dc,bool eating){
	coordinates newHead_;
	newHead_.row = getNextrow(dr);
	newHead_.col = getNextcol(dc);
	push_back(newHead_.row,newHead_.col);	
	if(!eating ){
		Node* oldTail = dataFirst;
		dataFirst = dataFirst -> next;
		delete oldTail;
	}
}