#ifndef Conjunto1_H
#define Conjunto1_H

#include <ostream>
#include <cstdlib>
#include <iostream>
#include<istream>
using std::cout;
using std::cin;
using std::endl;

using namespace std;

template <class T>
class Conjunto;

template <class T>
ostream &operator<<(ostream &,const Conjunto<T> &vet);

template <class T>
istream &operator>>(istream &, Conjunto<T> &vet);

template <class T>
class Conjunto {

    friend ostream &operator<< <T>(ostream &,const Conjunto<T> &vet);
    friend istream &operator>> <T>(istream &,Conjunto<T> &vet);

    public:
    
    Conjunto();
    Conjunto(int);
    ~Conjunto();
    const Conjunto &operator = (const Conjunto<T> &other);
    Conjunto(const Conjunto<T> &other);


    bool pertence(const T x)const;  //eh const pois vai apenas realizar comparações sem alterar o obj
    bool insere(const T &x);             
    int numelementos() const{ return num_elementos;};
    bool operator==(const Conjunto<T> &vet) const;
    //void le(Conjunto<T> );



    private:
    T*elementos ;
    int num_elementos = 0;
    int tam_array;
};

   //Destrutor - necessário pois há alocação dinâmica
    template <class T>
    Conjunto<T>::~Conjunto(){
        delete []elementos;
    }

    template <class T>
    Conjunto<T>::Conjunto(){
        tam_array = 10;
        elementos = new T[tam_array];
    }


    //Operador de atribuição - também necessário devido a alocação dinamica
    template <class T>
    const Conjunto<T> &Conjunto<T>::operator = (const Conjunto<T> &other){
        if(&other==this)                                            //compara os objetos, se forem iguais, retorna o ponteiro para o objeto
            return *this;
        delete[]elementos;
        num_elementos=other.num_elementos;
        tam_array = other.tam_array;
        elementos = new T[tam_array];
        for(int i=0; i<tam_array; i++)
            elementos[i] = other.elementos[i];
        return *this;
    }

    //Construtor por cópia - necessário devido a alocação dinamica
    template <class T>
    Conjunto<T>::Conjunto(const Conjunto<T> &other){
        elementos = NULL;
        *this = other;
    }

    //Construtor 
   template <class T>
   Conjunto<T>::Conjunto(int n) {
       tam_array = n;
       elementos = new T[n];
       /*for (int i=0; i<tam_array; i++)
            elementos[i] = T();*/
   } 


    //Função pertence - verifica se um elemento pertence ao array
   template <class T>
   bool Conjunto<T>::pertence(const T x)const {
       for(int i=0; i<num_elementos; i++){
           if(elementos[i]==x)                  //verifica cada posição e compara com o elemento x 
            return true ;
       }
       return false;
   }

    //Função insere - insere um elemento no array
   template <class T>
   bool  Conjunto<T>::insere(const T &x){
       if(num_elementos != tam_array && !pertence(x)){
           
           elementos[num_elementos] = x;
           num_elementos++;
           return true;
       }
        else 
            return false;
   }


    //Operação que verificará se um vetor é igual ao outro
    template <class T>
    bool Conjunto<T>::operator==(const Conjunto<T> &vet) const{
        if(num_elementos != vet.num_elementos) 
            return false;                //Se possuírem tamanhos diferentes, já não podem ser o mesmo conjunto 

        for(int i=0;i<vet.num_elementos;i++)
              if(!pertence(vet.elementos[i]))
                return false;                //verifica se cada elemento do vetor vet pertence ao array
        
        return true;
    }
    template <class T>
    std::ostream &operator<<(std::ostream &os,const Conjunto<T> &vet) {
        os <<"{";
	    for(int i=0; i<vet.num_elementos-1; i++) {
            os << vet.elementos[i] << ","; 
        } 
        if(vet.num_elementos>0){       
        os << vet.elementos[vet.num_elementos-1] ; 
        }
        os <<"}";
													
	return os;
    }
    


   template <class T>
    std::istream &operator>>(std::istream &in, Conjunto<T> &vet) {
        T aux;
    
	  while(in >> aux){
          vet.insere(aux);
      }
	//vet.le(vet);												
	return in;
    }



#endif