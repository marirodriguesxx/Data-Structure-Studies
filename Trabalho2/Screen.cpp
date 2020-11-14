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
    cout<<"Screen construída!\n";
        
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
    if((r>getWidth()-1 && r<getWidth()-1)  || (c>getHeight()-1 && c<getHeight()-1)){
        return WALL;
    }
    else if(dataHeight[c]==0 || r>= dataHeight[c] ){
        return EMPTY;
    }
    else if(r>=0 && c>=0){
        return data[c][r];
    }

}

//Método set ====================================================================
void Screen::set(const int r,const int c,const int val){ //ok
    //sempre que setarmos um novo elemento, daremos resize na matriz, para que aloque apenas o necessário sempre
    cout<<"-----------------------set----------------------------\n";
    cout<<"linha: "<<r<<endl;
    cout<<"coluna: "<<c<<endl;
    if(val !=EMPTY){
        resizeCol(c,r+1);
        data[c][r] = val;
        cout<<"data na linha "<<r<<" e coluna "<<c<<" = "<<data[c][r]<<endl;
        cout<<"dataHeight["<<c<<"] = "<<dataHeight[c]<<endl; 
    }
    if(val == EMPTY && dataHeight[c] != 0){
        cout<<"caso de setar empty\n";
        data[c][r] = val;
        dataHeight[c] = dataHeight[c]-1;
        cout<<"dataHeight["<<c<<"] = "<<dataHeight[c]<<endl; 
        cout<<"data na linha "<<r<<" e coluna "<<c<<" = "<<data[c][r]<<endl;
    }    
}

//Função para redisionamento da matriz a cada chamada do método set
void Screen::resizeCol(const int pos,const int newrows){          //ok   
    // if(dataHeight[pos] < newrows){
    //     int* aux = new int[newrows];
    //     for(int i=0; i<newrows; i++)
    //         aux[i]=EMPTY;      
        
    //     for(int i=0; i<dataHeight[pos]; i++)
    //         aux[i] = data[pos][i];        

    //     delete []data[pos];
        
    //     data[pos] = new int[newrows];

    //     for(int i=0; i<newrows; i++)
    //         data[pos][i] = aux[i];           
    //     cout<<"AQUI\n";
    //     delete []aux;     
    //     cout<<"newrows: "<<newrows<<endl;                 
    //     dataHeight[pos] = newrows;    
        
    if(dataHeight[pos] == newrows)
        return;

        int menor =0;
        if(dataHeight[pos]<newrows)
            menor = dataHeight[pos];
        else
            menor = newrows;
        
        int* aux = new int[newrows];
        for(int i=0; i<newrows; i++)
            aux[i]=EMPTY;      
        
        for(int i=0; i<menor; i++)
            aux[i] = data[pos][i];        

        delete []data[pos];
        
        data[pos] = new int[newrows];

        for(int i=0; i<newrows; i++)
            data[pos][i] = aux[i];   
        delete []aux;     
        cout<<"newrows: "<<newrows<<endl;                 
        dataHeight[pos] = newrows;  
}
