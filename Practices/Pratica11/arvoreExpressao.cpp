#include <iostream>
#include "MyVec.h"
#include <algorithm>    
using namespace std;


class ArvoreExpressao {
public:
	void imprimeArrays() const;

	void leArvore();
	void imprimeExpressao() const;
	int avaliaValor() const;
	int altura() const;
	int nivelMaisNodos() const;

	//Funções auxiliares para usar recursividade 
	void imprimeExpressao(int pos) const;
	int avaliaValor(int pos) const;
	int altura(int pos) const;
	void nivelMaisNodos(int *vec,int pos,int nivel) const;


private:
	//Nao adicione nenhum membro de dados na sua classe!!!!
	//Funcoes auxiliares podem ser adicionadas se necessario.

	MyVec<int> filhoEsquerdo;
	MyVec<int> filhoDireito;
	MyVec<char> operador;
};

void ArvoreExpressao::imprimeArrays() const {
	for(int i=0;i<filhoEsquerdo.size();i++) cout << i << " "; cout << "\n";
	for(int i=0;i<filhoEsquerdo.size();i++) cout << filhoEsquerdo[i] << " "; cout << "\n";
	for(int i=0;i<filhoDireito.size();i++) cout << filhoDireito[i] << " "; cout << "\n";
	for(int i=0;i<operador.size();i++) cout << operador[i] << " "; cout << "\n";
}

/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
//sua implementacao:


void ArvoreExpressao::leArvore() {
	int tam =0 ;
	cin>>tam;	//quantidade de nodos da árvore
	
	int left=0, right=0,pos =0;
	char operation;
	for(int i=0; i<tam;i++){
		cin>>pos;
		cin>>left>>right>>operation;
		filhoEsquerdo.insert(left,pos);
		filhoDireito.insert(right,pos);
		operador.insert(operation,pos);
	}
	
}

void ArvoreExpressao::imprimeExpressao(int pos) const {
    if (operador.size()==1){		//No caso em que possuir apenas um nodo
        cout << operador[pos];
        return;
    }
    if (pos==0){		
        imprimeExpressao(filhoEsquerdo[pos]);
        cout << operador[pos];
        imprimeExpressao(filhoDireito[pos]);
    }
    else if (operador[pos]=='+' ||operador[pos]=='-'||operador[pos]=='*'){// quando houver mais de uma expressão, devemos usa parenteses
        cout << "(";
        imprimeExpressao(filhoEsquerdo[pos]);
        cout << operador[pos];
        imprimeExpressao(filhoDireito[pos]);
        cout << ")";
    }
    else
        cout << operador[pos];
    
}

void ArvoreExpressao::imprimeExpressao() const {
	imprimeExpressao(0);
}

int ArvoreExpressao:: avaliaValor(int pos) const{
    if (operador[pos]=='+'){
        return (avaliaValor(filhoEsquerdo[pos])+avaliaValor(filhoDireito[pos]));
    }
    else if (operador[pos]=='-'){
        return (avaliaValor(filhoEsquerdo[pos])-avaliaValor(filhoDireito[pos]));
    }
    else if (operador[pos]=='*'){
        return (avaliaValor(filhoEsquerdo[pos]) * avaliaValor(filhoDireito[pos]));
    }
    else{
        char aux=operador[pos];
		// promove a conversão de uma string para inteiro 
        return atoi(&aux);
    }
}

int ArvoreExpressao::avaliaValor() const {
	return avaliaValor(0);
}

int ArvoreExpressao::altura() const {
	return altura(0);	//inicializamos as alturas com -1 para o caso em que seja uma árvore vazia
}

int ArvoreExpressao::altura(int pos) const{ 
	if (operador[pos]=='+'|| operador[pos]=='-'||operador[pos]=='*'){
		int maiorLeft = altura(filhoEsquerdo[pos]);
		int maiorRight =altura(filhoDireito[pos]);
		return max(maiorLeft,maiorRight) + 1;		//retornamos o caminho que possuir a maior altura
	}
	else
		return 0;

}

void ArvoreExpressao::nivelMaisNodos(int *vec,int pos,int nivel) const {
	if (operador[pos]=='+'||operador[pos]=='-'||operador[pos]=='*'){
		nivelMaisNodos(vec,filhoEsquerdo[pos],nivel+1);
		nivelMaisNodos(vec,filhoDireito[pos],nivel+1);
	}
	vec[nivel]++;
}
int ArvoreExpressao::nivelMaisNodos() const{
	if(altura() +1 ==0 ) return 1;
	//inicializamos todas as poisições com zero 
    int vec[altura() +1]={0};
    nivelMaisNodos(vec,0,0);
    int maior=0;
	int pos = 0;
	//verificamos qual posição possui mais nodos, e salvamos na variável auxiliar maior 
	for (int i = 0; i < altura()+1 ; i++){
		if(vec[i]>maior){
			maior=vec[i];
			pos=i;
		}
	}

    return pos+1;
}




/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/

//Nao modifique aqui
//OBS: cada arquivo de teste começa com a descricao de uma arvore.
//A seguir, ha um numero indicando qual etapa sera testada...
int main() {
	ArvoreExpressao a;
	a.leArvore();

	int etapa;
	cin >> etapa; 
	switch(etapa) {
		case 1:
			cout << "Etapa 1:" << endl;
			a.imprimeArrays();
			break;
		case 2:
			cout << "Etapa 2:" << endl;
			a.imprimeExpressao();
			cout << endl;
			break;
		case 4:
			cout << "Etapa 4:" << endl;
			cout << a.avaliaValor() << endl;
			break;
		case 5:
			cout << "Etapa 5:" << endl;
			cout << a.altura() << endl;
			cout << a.nivelMaisNodos() << endl;
			break;
		default:
			cout << "Erro! Etapa invalida" << endl;
			break;
	}

}