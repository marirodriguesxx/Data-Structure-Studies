#include "Snake.h"

Snake::Snake(int tamInicialSnake){
    dataFirst = dataLast  = NULL;
    for(int i=0;i<tamInicialSnake;i++){ 
        push_back(0,i); 
	}
	cout<<"Snake construída!\n";
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

void Snake::draw(Screen &s,int state){
	Node* cobra = dataFirst;
	while(cobra != NULL){
		s.set(cobra->data.row,cobra->data.col,state);
		cobra = cobra -> next;
	}
}

void Snake::move(int dr,int dc,bool eating){
	if(!eating){
		cout<<"nao to comendo, diminuindo o rabo\n";
		cout<<"Antiga linha da kbça : "<<dataFirst->data.row<<" -> Antiga coluna da kbça: "<<dataFirst->data.col<<endl;
		Node* oldTail = dataFirst;
		dataFirst = dataFirst -> next;
		cout<<"Nova linha da kbça : "<<dataFirst->data.row<<" -> Nova coluna da kbça: "<<dataFirst->data.col<<endl;
		delete oldTail;
	}	
	// if(dataLast->data.row==0 && dr<0){
	// 	dr = -1*dr;
	// }
	// if(dataLast->data.col ==0 && dc<0){
	// 	dc = 18*dc;
	// }
	coordinates newHead_;
	cout<<"Antiga linha: "<<dataLast->data.row<<" -> Antiga coluna: "<<dataLast->data.col<<endl;
	newHead_.row = dataLast->data.row +dr;
	newHead_.col = dataLast->data.col + dc;
	push_back(newHead_.row,newHead_.col);
	cout<<"Nova linha: "<<newHead_.row<<" -> Nova coluna: "<<newHead_.col<<endl;
}