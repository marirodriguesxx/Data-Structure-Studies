#include "Screen.h"
Screen::Screen(const int altura,const int largura){
    //Esse vetor recebera a quantidade de 'linhas' da matriz que representará a nossa tela
    //Primeiro, alocaremos da forma mais fácil, uma matriz retangular, iremos tratar os espeaços desnecessários na função set!
    data = new int [altura];
    //Alocaremos agora as colunas de todas as linhas
    for(int i=0; i<largura; i++)
        data[i] = new int [largura];
        
}
void Screen::set(const int r,const int c,const int val){
    data[r][c] = val;
    //sempre que setarmos um novo elemento, daremos resize na matriz, para que aloque apenas o necessário sempre
    if(val != EMPTY)
        resizeRow(r,c);
}
int Screen::get(const int r,const int c){
    //Este if trata o caso em que é feita uma consulta em alguma posição fora dos limites da tela
    if(r>getWidth() || c>getHeight())
        return WALL;
    return data[r][c];

}

//Função para redisionamento da matriz a cada chamada do método set
void Screen::resizeRow(const int pos,const int newcols){   
    //Atualizando o size
    int dif = 0; 
    dif = newcols - dataHeight[pos];           //fazemos essa conta pois somaremos, ou subtraímos, a diferença do numero de colunas naquela linha, que reflete no numero de elementos da matriz
    
    int menor=0;
    if(newcols<dataHeight[pos])
        menor = newcols;
    else
        menor = dataHeight[pos];
    
    //Alocamos um vetor auxiliar, pois alteraremos apenas o vetor de colunas da linha desejada
    T* aux = new int[newcols];
    for(int i=0; i<newcols; i++)
        aux[i]=T();                     //inicializamos todos os valores com o valor padrão, para caso aumente o numero de colunas, as novas colunas sejam preenchidas com seu respectivo valor padrão de tipo
    for(int i=0; i<menor; i++)
        aux[i] = data[pos][i];        //salvamos os elementos gurdados nas colunas da linha desejada
    
    
    //deletando o vetor correspondente a linha na qual será efetivada a mudança, e depois realocamos com o novo tamanho desejado
    delete []data[pos];
    data [pos] = new int[newcols];
    for(int i=0; i<newcols; i++)
        data[pos][i] = aux[i];           // resgatamos os valores salvos na variavel auxiliar
    
    delete []aux;                       //deletamos a variável auxiliar pois não será mais util
    dataHeight[pos] = newcols;                 // atualizamos o numero de colunas que está armazenado no vetor tam    
}