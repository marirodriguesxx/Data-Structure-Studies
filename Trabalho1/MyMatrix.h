
////////Controle de versão e atualizações ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ~~~~~~~~Ãnálise de desempenho~~~~~~~~~~~~~~~~~~~~                                                                                                                //
// 07/10 - Construtor, métos get e set                                                                                                                              //
// 11/10 - função print, ConvertToRagged, ConvertToTraditional                                                                                                      //
// 15/10 - finalização das funções de resize - até então, sem erros no valgrind!                                                                                    //
// 16/10 - 8 tentativa de envio - erro está na ResizeRows para ragged - da erro ao diminuir eloementos da linha zero                                                //
// 18//10 - resolução do problema relatado anteriormente, 30/30 mas com warning/erro e compilação - rever testes de const !!!!                                      //
// 19/10  - mudança nas funções resize e convert, estava declarando como int e não como T                                                                           //
// 20/10 - procura do erro de compilção                                                                                                                             //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef MyMatrix_
#define MyMatrix_

#include <iostream>
using namespace std;

template <class T>
class MyMatrix {

public:

//Construtores da classe
~MyMatrix(){ destroy(); };
MyMatrix(const int numLinhas, const int *numColunas,const bool tipo); 

//Construtor de copia----------------------------------------------------------
MyMatrix(const MyMatrix<T> &);
MyMatrix<T>& operator=(const MyMatrix<T> &);


const T& get(const int linha,const int coluna)const;                   
void set(const int linha,const int coluna,const T ct);   

//Complexidade no modo ragged = complexidade no modo tradicional = O(1) - ambas retornam apenas uma variável, sem dependência do número de elmeentos, linhas ou colunas
int getNumRows ()const {return rows;};  
int getNumCols (const int linha)const;  
//Complexidade no modo ragged = complexidade no modo tradicional = O(1) - ambas retornam apenas uma variável, sem dependência do número de elmeentos, linhas ou colunas
int getNumElems()const{return size;};   

void convertToRagged(); 
void convertToTraditional();    
void print()const;  

bool isRagged()const;               

void resizeRow(const int pos,const int newcols); 
void resizeNumRows(const int newNumRows); 


protected:
int rows = 0 ;               //numero de linhas da matriz.
int size = 0 ;               //número de elementos da matriz
int *tam = NULL ;            //vetor de apontadores para as posições para matriz
T **matriz = NULL;
int *start = NULL;           //vetor de apontadores para as posições do vetor Ragged
T *ragged = NULL;

//Funções auxiliares 
void create();
void destroy();


};

//Ordem de complexidade para uma matriz ragged : O(1) - apenas deletamos a memória alocada de um array, sem precisar percorrer nenhuma iteração 
//Ordem de complexidade para uma matriz tradicional : O(R) - neste caso, tivemos que percorrer o número de linhas de matriz no for
//Função auxiliar destroy-----------------------------------------------------
template<class T>
void MyMatrix<T>::destroy(){
    if(isRagged()){
        delete []ragged;
        delete []start;
    }
    else{
        delete []tam;
        for (int i = 0; i<getNumRows(); i++){
            delete []matriz[i];
        }
        delete []matriz;
    }
}

//Função para alocar matrizes e vetores vazios - O(1) pois apenas faz apontar para NULL
template<class T>
void MyMatrix<T>::create() {
        start = NULL;
        ragged=NULL;
        tam=NULL;
        matriz=NULL;

	size=rows=0;
}

//Função booleana - verifica o formato da matriz-----------------------------
//A complexidade será a mesma para os dois tipos de matrz, O(1). Pois apenas realiza duas comparações, sem depender do numero de linhas, colunas ou elementos da matriz
template <class T>
bool MyMatrix<T>::isRagged()const{
    if(tam == NULL && matriz == NULL)        // Uma matriz esta no formato Ragged quando tam=matriz=NULL 
        return true;
    else
        return false;
}

// Construtor ----------------------------------------------------------------
//Ordem de complexidade para uma matriz ragged = ordem de complexidade para uma matriz tradicional = O(RC)
//ambas irão andar pelas linhas da matriz, percorrendo todos os elementos de suas respectivas colunas, fazendo com que a complexidade seja a mesma
template <class T>
MyMatrix<T>::MyMatrix(const int numLinhas,const int *numColunas,const bool tipo){
    //O(RC) 
    rows = numLinhas;                                  // salvando o numero de linhas e o numero de elementos da matriz
    for(int i=0; i<numLinhas; i++)
        size+=numColunas[i];                           //somando o número de colunas que há em cada linha, resultando no número total de elementos da matriz
    

    if(tipo==true){                                  // se for Ragged Array 
        int linhas_start = numLinhas+1;
        start = new int[linhas_start];               //+1 pois terá sempre a posição incial a mais 
        start[0] = 0;                             // inicia a primeira posição do vetor start com zero
        for(int i=1; i<linhas_start; i++){           // percorro as linhas da matriz
            start[i] = numColunas[i-1] + start[i-1];          // a posição i do vetor start é a soma da posição anterior do outro vetor com a posição anterior dele mesmo
        }

        ragged = new T[size];             //inicializamos a matriz ragged com lixo
    }
    else{
        tam = new int[numLinhas];
        for(int i=0; i<numLinhas; i++){
            tam[i] = numColunas[i];        
        }

        matriz = new T*[numLinhas];     //inicializamos a matriz tradicional com lixo
        for (int i = 0; i<numLinhas; i++){
            matriz[i] = new T[tam[i]];
        }
    }           
    

}

//Operador de atribuição--------------------------------------------------------
//Funciona semelhante ao construtor, porém aqui iremos, ao invés de inicializar com lixo, inicializar com os valores recebido de other
//Ordem de complexidade para uma matriz ragged = Ordem de complexidade para uma matriz tradicional = O(RC)
//ambas irão andar pelas linhas da matriz, percorrendo todos os elementos de suas respectivas colunas, fazendo com que a complexidade seja a mesma
template <class T>
MyMatrix<T> & MyMatrix<T>::operator=(const MyMatrix<T> &other){
    if(other.isRagged()){                       //se other for do tipo ragged, excluimos e realocamos o objeto 
        if(this==&other) return *this;
        destroy();                              // é necessário destruir para realocar com o novo tamanho necessário
        create();
        rows = other.rows;
        size = other.size;
        start = new int[getNumRows()+1];             
        for(int i=0; i<getNumRows()+1; i++){           
            start[i] = other.start[i];        
        }

        ragged = new T [size];             
        for(int i=0; i<getNumRows(); i++){
            for(int j=0; j<start[i+1] - start[i]; j++)
                ragged [start[i] + j] = other.ragged [start[i] + j];
        }
        return *this;

    }
    else{
        if(this==&other) return *this;
        destroy();
        create();
        rows = other.rows;
        size = other.size;
        
        tam = new int[getNumRows()];
        for(int i=0; i<getNumRows(); i++){
            tam[i] = other.tam[i];        
        }

        matriz = new T*[getNumRows()];     
        for (int i = 0; i<getNumRows(); i++){
            matriz[i] = new T[tam[i]];
        }
        for (int i = 0; i<getNumRows(); i++){
            for(int j=0; j<tam[i]; j++){
                matriz[i][j] = other.matriz[i][j];
            }
        }
        return *this;

    }    
}

//Construtor de cópia---------------------------------------------------------
//Chama a sobrecarga do operador de atribuição, e faz com que o objeto apontado por this seja igual ao recebido por parametro (other)
//Por isso teremos a seguinte ordem de complexidade, derivada do operador de atribuição
//Ordem de complexidade para uma matriz ragged = Ordem de complexidade para uma matriz tradicional = O(RC)
//ambas irão andar pelas linhas da matriz, percorrendo todos os elementos de suas respectivas colunas, fazendo com que a complexidade seja a mesma
template <class T>
MyMatrix<T>::MyMatrix(const MyMatrix<T> &other){
    create();
    *this = other;
    
}

// Métodos get e set ---------------------------------------------------------
//Ordem de complexidade é a mesma para os dois formatos, O(1), pois ambos independem do numero de linhas, colunas e elementos, descartando a necessidade de laços de repetição 
template <class T>
int  MyMatrix<T>::getNumCols(const int linha)const{
    if(isRagged()==true){                                   // não esta verificando, pq? faltou iniciar com NULL nas declarações!!!       
        return start[linha+1]-start[linha];                 //o número de elementos de uma coluna é a posição da próxima linha no vetor start menos a posição da linha anterior
    }
    else{
        return tam[linha];                                  // trivial, pois o vetor tam armazena em cada linha a quantidade respectiva de colunas dessa linha
    }
    
}

//Ordem de complexida da matriz tradicional é a mesma de uma ragged, pois ambos são O(1), pois não precisam de laços de repetição relacionados ao numero de linhas, colunas ou elementos
template <class T>
void MyMatrix<T>::set(const int linha,const int coluna,const T ct){         
    if(isRagged()){
        ragged [start[linha] + coluna] = ct;       //na matriz linearizada, o elemento na pos[m][n] corresponde à onde começa a linha + coluna desejada
    }

    else{
        matriz[linha][coluna] = ct;
    }
}

//Aqui, apenas acessamos uma posição da matriz, sem precisar de iterações, fazendo com que a complexidade de ambos formatos seja O(1)
template <class T>
const T& MyMatrix<T>::get(const int linha,const int coluna)const{
    if(isRagged()){            
        return ragged[start[linha]+coluna];
    }

    else{
        return matriz[linha][coluna];
    }
}

// Função print ------------------------------------------------------------
//Para ambos os modos temos a complexidade O(RC) - percorremos as linhas no primeiro for e, printamos, elemento por elemento de cada coluna
template <class T>
void MyMatrix<T>::print()const{
    cout<<"Rows: "<<getNumRows()<<"\n";                 //Essas primeiras linhas serão as mesmas , independente do formato o qual a matriz está sendo representada
    cout<<"Elems: "<<getNumElems()<<"\n";
    if(isRagged()){
          int aux_numelems = 0;
          int pos = 0;                              // variavel auxiliar para indicar a posição da linha no vetor ragged
        for(int i=0; i<getNumRows(); i++){
            aux_numelems = start[i+1] - start[i];   // isso representa o numero de elementos de cada linha
            if(aux_numelems!=0)
                cout<<aux_numelems<<": ";
            else
                cout<<aux_numelems<<":";
            for(int j=pos; j<pos+aux_numelems-1; j++){    //percorremos a linha correspondente ate a ultima coluna dessa linha, representadas pela posição da linha no vetor + a quantidade de elementos que há na linha, ou seja, percorremos a linha coluna por coluna
                if(aux_numelems==0) cout<<"\n";
                else
                cout<<ragged[j]<<" ";
            }   
            if(aux_numelems!=0) 
                cout<<ragged[pos+aux_numelems-1];
            pos = pos+aux_numelems;
            cout<<"\n";           
        }
    }
    else{                                       //percorremos as linhas no primeiro for e as colunas no segundo
        for(int i=0; i<getNumRows(); i++){   
            if(tam[i]!=0)   
            cout<<tam[i]<<": ";
            else
            cout<<tam[i]<<":";
            for(int j=0; j<tam[i]; j++){
                if(j==tam[i]-1)
                    cout<<matriz[i][j];
                else
                    cout<<matriz[i][j]<<" ";            //imprimimos o elementos da linha e coluna respectiva
            }
            
            cout<<"\n";
        }
    }
}

// Funções para conversão de tipo -------------------------------------------
//Ordem de complexidade : O(RC) - pois percorremos todas as linhas e, depois, todas as colunas, copiando todos os elementos para a outra matriz
template <class T>
void MyMatrix<T>::convertToRagged(){                    
        if(!isRagged()){
        //Faremos , antes, a conversão do vetor tam para o vetor star        
        start = new int[getNumRows()+1];             //Alocamos os vetores ragged e start
        ragged = new T[getNumElems()]; 

        start[0] = 0;                        // inicia a primeira posição do vetor start com zero
        start[rows] = getNumElems();           //a última posição contém sempre o número de elementos total da matriz

        //podemos notar que, ao percorrermos de tras pra frente a matriz start, cada posição equivale à soma de todas as posições de matriz tam, desconsiderando apenas a posição atual
        // por exemplo, start[4] = 0 = tam[0] + tam[1] + tam[2] +tam[3] - e esse será o metodo usado apra preenchermos a amtriz start, faremos um for, preenchendo-a de trás para frente
        for(int i=getNumRows()-1 ; i>0; i--){           
            start[i] =start[i+1] - tam[i];         
        }

        for(int i=0; i<getNumRows(); i++){
            for( int j=0; j<tam[i]; j++){
                 ragged [start[i] + j] = matriz[i][j];
            }
        }  
        delete []tam;
        for (int i = 0; i<getNumRows(); i++){
            delete []matriz[i];
        }
        delete [] matriz;
        tam = NULL;                     //fazemos com queo vetor tam e a matriz seja NULL, caracterizando o novo tipo ragged
        matriz = NULL;
        }
} 

//Ordem de complexidade : O(RC) - pois percorremos todas as linhas e, depois, todas as colunas, copiando todos os elementos para a outra matriz
template <class T>
void MyMatrix<T>::convertToTraditional(){                    
        if(isRagged()){
            //Alocando o vetor tam e a matriz matriz 
            tam = new int[getNumRows()];
            matriz = new T*[getNumRows()];     
            for (int i = 0; i<getNumRows(); i++) //O(R)
                matriz[i] = new T[getNumElems()];
            
            //Notemos que a tam[i] equivale à subtração de start[i+1] com start[i]. Por exemplo: tam[3] = start[4] - start[3] = 9 - 4= 5
            for(int i=0; i<getNumRows(); i++){ //O(R)
                tam[i] = start[i+1] - start[i];
            }
            for(int i=0; i<getNumRows(); i++){ //O(R*C)
                for( int j=0; j<tam[i]; j++){
                    matriz[i][j] = ragged [start[i] + j];
                }
            }
            //Definindo start e ragegd como NULL, pois isso é o que definirá, na função booleana, true or false
            delete []ragged;
            delete []start;
            ragged = NULL;
            start = NULL;
        
    }
} 

// Funções para redimensionamento ------------------------------------------- 
//Ordem de complexidade para o modo ragged: O(R+T) - Para atualizarmos o vetor start, devemos percorrer todas suas linhas ,O(R)
//Depois, é preciso criar um vetor auxiliar e percorrrer ele até o número de elementos para copiar e depois reatribuir ao vetor ragged realocado - O(T-1)
//Ordem de complexidade para o modo tradicional: O(C) - em todas as iterações feitas nos for's percorreu-se até o número de colunas da respectiva linha a ser alterada 
template <class T>
void MyMatrix<T>::resizeRow(const int pos,const int newcols){  
    if(isRagged()){ 
        //O número antigo de colunas e a variavel difserá necessário para quando formos fazer uma verficação
        //e apartir daí, não preencheremos as posições novas indevidamente
        int oldcols = start[pos+1] - start[pos];
        int dif = newcols - oldcols;           //fazemos essa conta pois somamos, ou subtraímos, a diferença do numero de colunas naquela linha, que reflete no numero de elementos da matriz
        
        //Atualizando o size
        size = size + dif; 

        //Alterando endereço dos apontadores no vetor start  O(R)
        for(int i=pos+1; i<getNumRows()+1; i++){
            start[i] = start[i] + dif;                 //somamos a diferança de colunas obtida em todas as linhas, começando a partir da linha que desejamos alterar
        }

        //Alocando um vetor auxlia, sempre com o size já alterado
        T* aux = new T[size];

        //preenchendo os elementos com valor padrão O(T-1)
        for(int i=0; i<getNumElems(); i++)
            aux[i] = T();

        
        //Variável auxiliar que será usarda para acessar uma posição necessária nos casos de diminuição do número de colunas
        int modulo=0;       
        if(dif<0)     
            modulo = -1*dif;        
        
        //Salvando os valores do vetor ragged no vetor aux. Note que a condição do if "salta" as posições que foram adicionadas e, portando, devem permanecer com o valor padrão
        //O primeiro if verifica os casos em que aumentaremos o numero de colunas em uma determinada linha e incrementa o contador de aux, de forma a não preencher tais posições indevidamente
        //Dentro do primeiro if fazemos uma verificação, essa verificação nos garante que so preencheremos posições válidas
        //o segundo, verifica o caso em que iremos diminuir o numero de inhas e por isso incrementamos o contador do vetor ragged, para não ler posições indesejadas 
        for(int i=0, posragged=0; i<getNumElems(); i++,posragged++){    //O(T-1)
            if(i==start[pos]+oldcols && dif>0 ){ 
                i=i+dif;
                if(i<=size-dif)
                aux[i] = ragged[posragged];
            }
            else if( i==start[pos]+newcols && dif<0 ){                
                posragged = posragged+modulo;
                aux[i] = ragged[posragged]; 
                
            } 
            else {            
                aux[i] = ragged[posragged];   
            }    
        }                 
        //deletando o vetor ragged para alocarmos ele com o novo numero de colunas O(T-1)
        delete []ragged;
        ragged = new T[size];
        for(int i=0; i<getNumElems(); i++)  //O(T-1)
            ragged[i] = aux[i];
        
        delete [] aux;       

    }
    else{ 
        //Atualizando o size
        int dif = 0; 
        dif = newcols - tam[pos];           //fazemos essa conta pois somaremos, ou subtraímos, a diferença do numero de colunas naquela linha, que reflete no numero de elementos da matriz
        size = size + dif;
        
        int menor=0;
        if(newcols<tam[pos])
            menor = newcols;
        else
            menor = tam[pos];
        
        //Alocamos um vetor auxiliar, pois alteraremos apenas o vetor de colunas da linha desejada
        T* aux = new T[newcols];
        for(int i=0; i<newcols; i++)
            aux[i]=T();                     //inicializamos todos os valores com o valor padrão, para caso aumente o numero de colunas, as novas colunas sejam preenchidas com seu respectivo valor padrão de tipo
        for(int i=0; i<menor; i++)
            aux[i] = matriz[pos][i];        //salvamos os elementos gurdados nas colunas d alinha desejada
        
        
        //deletando o vetor correspondente a linha na qual será efetivada a mudança, e depois realocamos com o novo tamanho desejado
        delete []matriz[pos];
        matriz [pos] = new T[newcols];
        for(int i=0; i<newcols; i++)
            matriz[pos][i] = aux[i];           // resgatamos os valores salvos na variavel auxiliar
        
        delete []aux;                       //deletamos a variável auxiliar pois não será mais util
        tam[pos] = newcols;                 // atualizamos o numero de colunas que está armazenado no vetor tam
       
    }

    
}

//Ordem de complexidade para o modo ragged: O(R+T) - No caso de aumentar o número de inhas, percorremos o numero de linhas para fazer cópia do vetor start - O(R)
//No caso de diminuir, além de percorrer as linhas, devemos percorrer todos os elementos para atualizar o vetor ragged - O(R+T)
//Ordem de complexidade para o modo tradicional: O(R) - Em todos os casos, percorremos no máximo até o número de linhas, independente do numero de colunas e/ou elementos
template <class T>
void MyMatrix<T>::resizeNumRows(const int newnumRows){
    if(isRagged()){ // O(4R + 2C) = O(R+C)
    //Alocamos um vetor auxiliar pe copiamos os dados do vetor start para ele
        int* startaux = new int[getNumRows()+1];
        for(int i=0; i<getNumRows()+1; i++){ // O(R)
            startaux[i] = start[i];
        } 

        //Deletamos o vetor start para realocarmos ele com seu novo tamanho e, posteriormente, resgatar os valores salvos no vetor auxilair 
        delete []start;
        start = new int[newnumRows+1];

        if(newnumRows>rows){  // O(R+C) - Se o novo numero de linhas for maior, percorremos apenas até o antigo número de linhas, para que não ocorra acesso em posições inválidas do vetor auxiliar
            for(int i=0; i<getNumRows()+1; i++){ // O(R) - copiamos os valores do vetor auxilair
                start[i] = startaux[i];
            }
            //Fazemos com que a diferença entre as novas linhas a serem criadas com as anteriores seja zero
            for(int i=getNumRows()+1; i<newnumRows+1; i++){ // O(R)
                start[i] = start[rows];
            }    
        }
        else{
            for(int i=0; i<newnumRows+1; i++){ // O(R)
                start[i] = startaux[i];
            }
            T* raggedaux = new T[start[newnumRows]];        //No caso de diminuir o numero de linhas, devemos realocar a ragged com o novo numero de elementos respectivos
            for(int i=0; i<start[newnumRows]; i++){         // O(T) - percorremos ate o novo numero total de elementos e salvamos os valores de ragged
                raggedaux[i] = ragged[i];
            }
            delete []ragged;
            ragged = new T[start[newnumRows]];
            for(int i=0; i<start[newnumRows]; i++)          // O(T) - resgatamos os valores armazenados no vetor auxiliar 
                ragged[i] = raggedaux[i];
            delete []raggedaux;                             // deletamos o vetor auxiliar alocado
            size = start[newnumRows];                       //atualizamos o numero de elementos 
        }

        //Por fim, atualizamos o novo número de linhas para o que foi recebido via parâmetro e desalocamos o vetor auxiliar
        rows = newnumRows;
        delete []startaux;
        
    }
    else{ // O(5R) = O(R)

        //Alocamos um vetor e uma matriz auxiliar com o novo numero de linhas
        int* tamaux = new int[newnumRows];
        T** matrizaux = new T*[newnumRows];

        //Inicializamos as posições 
        for(int i=0; i<newnumRows; i++){ // O(R)
            tamaux[i] = 0;
            matrizaux[i]=NULL;
        }
        
        //Dependendo se o numero de linhas aumentou ou diminiu, salvaremos o menor valor para percorrer no vetor tam e na matriz matriz
        int menor=0;
        if(newnumRows<rows)
            menor = newnumRows;
        else
            menor = rows;
        
        //percorrendo e copiando os elementos para os auxiliares
        for(int i=0; i<menor; i++){ // O(R)
            tamaux[i] = tam[i];
            matrizaux[i] = matriz[i];
        }
        
        //desalocando o vetor e a matriz para realocar com o novo tamanho
        for(int i =menor; i<getNumRows(); i++)
            delete []matriz[i];
        
        delete []tam;
        delete []matriz;

        tam = new int[newnumRows];
        matriz= new T*[newnumRows];

        //copiando os valores armazenados nos auxiliares
        for(int i=0; i<newnumRows; i++){ // O(R)
            tam[i] = tamaux[i];
            matriz[i] = matrizaux[i];
        }
        delete []tamaux;
        delete []matrizaux;
        
        //atualizando o novo numero de elementos e linhas da matriz
        int sizeaux=0;     
        for(int i=0; i<newnumRows; i++) // O(R)
            sizeaux+=tam[i];
        
        size = sizeaux;
        rows=newnumRows;

    }
    

}


#endif


