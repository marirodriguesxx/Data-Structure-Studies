#include <iostream>

using namespace std;


#include "MyStack.h"
#include "MyQueue.h"
#include "MyQueue2.h"

// Insira aqui o codigo para a etapa 1....
void etapa1() {
	float entrada; 
    MyQueue<float> fila;
    MyStack<float> pilha;
    for(int i = 0; i<6; i++){
        cin >> entrada;
        fila.push(entrada);
        pilha.push(entrada);
    }
    for(int i = 0; i<6; i++){
        cout << pilha.top() << " ";
        pilha.pop();
    }
    cout << endl;
    for(int i = 0; i<6; i++){
        cout << fila.front() << " ";
        fila.pop();
    }
    cout << endl;
	
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....
void etapa2() {

	MyStack<char> stack;
	char c;
	while(cin>>c){
		if(c=='(' || c=='[' || c=='{')
			stack.push(c);
			
		if(stack.empty() && (c==')' || c==']' || c=='}')){
			cout << "Inconsistente\n"; return;
		}

		if(c==')' && stack.top()=='(')
			stack.pop();
		else if(c==']' && stack.top()=='[')
			stack.pop();
		else if(c=='}' && stack.top()=='{')
			stack.pop();
		
		
	}
	if(stack.empty())
		cout << "Consistente\n";
	else
		cout << "Inconsistente\n";
}

//---------------------------------------

// Na etapa 3 voce deve implementar MyQueue2.h e descomentar os codigos de teste abaixo...

void etapa3() {
	/*char operacao;
	MyQueue2<string> q;

	//le um arquivo contendo "comandos" para a fila e aplica-os a fila criada com sua classe...
	while(cin>> operacao) {
		if(operacao=='p') {
			string st;
			cin >> st;
			q.push(st); //insere um novo elemento na sua fila...
		} else if(operacao=='f') {
			cout << q.front() << "\n";
		} else if(operacao=='P') {
			q.pop();
		} else if(operacao=='e') {
			cout << ((q.empty())?"vazia":"cheia") << "\n";
		} else cout << q.size() << "\n";
	}	*/
}

//---------------------------------------

// Insira aqui o codigo para a etapa 4....


void etapa4() {
	
}

//---------------------------------------


int main() {
	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
		case 4:
			cout << "Etapa 4" << endl;
			etapa4();
			break;
	}
}