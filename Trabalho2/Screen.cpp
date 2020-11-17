#include "Screen.h"
Screen::Screen(const int altura_,const int largura_){
    altura = altura_;
    largura = largura_;
    //Esse vetor recebera a quantidade de 'linhas' da matriz que representará a nossa tela
    //Primeiro, alocaremos da forma mais fácil, uma matriz retangular, iremos tratar os espeaços desnecessários na função set!
    dataHeight = new int[largura];
    data = new int *[largura];
    //Alocaremos agora as linhas de todas as colunas
    for(int i=0; i<largura; i++){
        dataHeight[i] = 0;
        data[i] = NULL;    
    }
        
}
//Destrutor da matriz==========================================
Screen::~Screen(){
    for(int i=0; i<largura; i++)
        delete []data[i];
    delete []data;
    delete []dataHeight;
        
}

//Método get=================================================
int Screen::get(const int r,const int c)const{ //ok
    //Este if trata o caso em que é feita uma consulta em alguma posição fora dos limites da tela
    if((r>=getHeight() || c>=getWidth()) || (r<0 || c<0)){
        return WALL;
    }
    else if(dataHeight[c]==0 || r>= dataHeight[c] ){
        return EMPTY;
    }
    else {
        return data[c][r];
    }

}

//Método set ====================================================================
void Screen::set(const int r,const int c,const int val){ //ok
    //sempre que setarmos um novo elemento, daremos resize na matriz, para que aloque apenas o necessário sempre o necessário
    if(val !=EMPTY){
        resizeCol(c,r+1);
        data[c][r] = val;
    }
    if(val == EMPTY && dataHeight[c] != 0){
        data[c][r] = val;
        dataHeight[c] = dataHeight[c]-1;
    }    
}

//Função para redisionamento da matriz a cada chamada do método set
void Screen::resizeCol(const int pos,const int newrows){          //ok   
    if(dataHeight[pos] < newrows){
        int* aux = new int[newrows];
        for(int i=0; i<newrows; i++)
            aux[i]=EMPTY;      
        
        for(int i=0; i<dataHeight[pos]; i++)
            aux[i] = data[pos][i];        

        delete []data[pos];
        
        data[pos] = new int[newrows];

        for(int i=0; i<newrows; i++)
            data[pos][i] = aux[i];    
            
        delete []aux;                     
        dataHeight[pos] = newrows; 
    }   
        
}
