#include <iostream>
#include <algorithm> //biblioteca para uso da função sort
#include <cstring>
#include<string>
#include "MyVecNewIterator.h"
#include "MyMap.h"
#include <utility>
#include<sstream>
#include <algorithm>
using namespace std;

//Função responsável pela remoção dos caracteres indesejaveis =======================================================================
void format(string &line){
    int tam =line.size()+1;
    for(int i=0; i<tam;i++){
        //A estratégia usada foi uma dica dada pelo professor. Consiste na troca de todos os caracteres que não forem letras do alfabeto serem trocados por uma quebra de linha
        //Dessa forma, sera mais facil a passagem para um vetor auxiliar, o qual armazenara apenas as string relevantes para nosso dicionario
        if(line[i] == '\n' || line[i] =='\t' ||line[i] =='\'' ||line[i] =='\"' || line[i] == ' '){
            line[i] = ' ';
        }
        else if(isalpha(line[i]) || line[i] == '-'){
            line[i] = tolower(line[i]);
        }
        else{         
            line[i] = '\n';
        }
    }
};

//Funções maps1, map2 e map3 auxiliares=============================================================================================
void createmap1 (MyMap<string,int> &map1,  MyVec<string>& words){  
        map1[words[0]]++;
    
}
void createmap2(MyMap<string,MyMap<string,int>> &map2,  MyMap<string,int> &map1, MyVec<string>& words){
        map2[words[0]][words[1]]++;    
    
}
void createmap3(MyMap<string, MyMap<string,MyMap<string,int>>> &map3,MyMap<string,MyMap<string,int>> &map2,  
MyMap<string,int> &map1, MyVec<string>& words){
        map3[words[0]][words[1]][words[2]]++;    
}

//Função para criação do dicionário ================================================================================================
void AddDictionary( MyVec<string>& words, MyMap<string,int> &map1,
    MyMap<string,MyMap<string,int>> &map2, MyMap<string, MyMap<string,MyMap<string,int>>> &map3, int tam){
    if(tam>=1){ // sempre iremos ter o map 1 
        createmap1(map1,words);
    }
    if(tam>=2){
        createmap2(map2,map1,words);
    }
    if(tam>=3){
        createmap3(map3,map2,map1,words);
    }    
}

//Funcao que auxilia no armazenamento das palavras importantes ======================================================================
void tokenize(const string &line, MyVec<string> &tokens){
    //Aqui, ieremos salvar em uma string auxiliar apenas as palvras ja formatas e importantes para o dicionario em um vetor
    istringstream aux(line);
    while(aux){
        string tok;
        aux >> tok;
        if(tok.size()>0) //para nao salvarmos strings vazias em nosso vetor
            tokens.push_back(tok);
    }
}
void storage(const string &line, MyMap<string,int> &map1,
MyMap<string,MyMap<string,int>> &map2, MyMap<string, MyMap<string,MyMap<string,int>>> &map3){
    //Aqui, ieremos salvar em uma string auxiliar apenas as palvras ja formatas e importantes para o dicionario 
    string tok;
    istringstream aux(line);
    while(getline(aux,tok,'\n')){
        istringstream aux2(tok);
        string word;
        MyVec<string> words(3);
        int cont = 0;
        while(aux2>>word){
            swap(words[2],words[1]);
            swap(words[1],words[0]);
            words[0] = word;
            cont++;
            if(words.size()>0)
                AddDictionary(words,map1,map2,map3,cont);
        }
    }
    
}

//Função que ordena de acordo com o valor ===========================================================================================
void printSorted(MyVec<pair<string, int>> sorted){      //Função auxiliar para ajudar na depuração do código
    for (int i = 0; i < sorted.size(); i++)	{
		cout << sorted[i].first << ": " << sorted[i].second << endl;
	}
}

bool bigger(const pair<string, int> &x, const pair<string, int> &y){ 
    return (x.second > y.second); 
}
//Nas funções abaixo percorresmo, de forma semelhante que no print, mas, ao invés de printarmos, salvamos em um vetor para ordenalo depois
void sort1(MyMap<string, int> &map, MyVec<pair<string, int>> &sorted){ 
    //MyVec<pair<string, int>> sorted;
    MyMapIterator<string, int> it = map.begin();
    while(it != map.end()){
            sorted.push_back(make_pair((*it).first, (*it).second));
        it++;
    } 
    sort(sorted.begin(), sorted.end(), &bigger);
  
}
void sort2(MyMap<string,int> &m1, MyMap<string,MyMap<string,int>> &m2, MyVec<pair<string, int>> &sorted){ 
    //MyVec<pair<string, int>> sorted;
    MyMapIterator<string,MyMap<string,int>> it2 = m2.begin();
    while(it2 != m2.end()){
        MyMapIterator<string, int> it1 = (*it2).second.begin();
            while(it1 != m1.end()){
                string chave = (*it1).first + " " + (*it2).first;
                    sorted.push_back(make_pair(chave, (*it1).second));
                it1++;
            }
        it2++;
    }
    sort(sorted.begin(), sorted.end(), &bigger);
  
}
void sort3(MyMap<string,int> &m1, MyMap<string,MyMap<string,int>> &m2,  MyMap<string, MyMap<string,MyMap<string,int>>> &m3, 
MyVec<pair<string, int>> &sorted){
    MyMapIterator<string, MyMap<string,MyMap<string,int>>> it3 = m3.begin();
    while(it3 != m3.end()){
        MyMapIterator<string,MyMap<string,int>> it2 = (*it3).second.begin();
        while(it2 != m2.end()){
            MyMapIterator<string, int> it1 = (*it2).second.begin();
            while(it1 != m1.end()){
                string chave = (*it1).first + " " + (*it2).first + " "+(*it3).first;
                    sorted.push_back(make_pair(chave, (*it1).second));
                it1++;
            }
            it2++;
        }
        it3++;
    }
    sort(sorted.begin(), sorted.end(), &bigger);
}

//Funções para leitura do arquivo ==================================================================================================
void readTreino(MyMap<string,int> &map1, MyMap<string,MyMap<string,int>> &map2,
MyMap<string, MyMap<string,MyMap<string,int>>> &map3){
    string line;
    //Lemos a primeira linha para que, na função de leitura do treino, possamos delimitar o inicio e o fim de tal etapa
    getline(cin,line);
    if(line == "COMECO_TREINO"){  
        string texto;      
        do{
            //Primeiro, recebemos o consteúdo das linhas e formatamos para auxiliar na criação do dicionário
            getline(cin,line);
            if(line ==  "FINAL_TREINO") break;
            format(line);
            texto +=line;        
        }
        while(line != "FINAL_TREINO");
        storage(texto,map1,map2,map3); // Aqui, trataremos para obter o melhor formato e depois inserir em nosso dicionário
    } 
}

//Funções auxiliares para realizar consulta e geração ==================================================================================
void consultar(int k,const string &phrase, MyMap<string,int> &map1, MyMap<string,MyMap<string,int>> &map2,
MyMap<string, MyMap<string,MyMap<string,int>>> &map3, MyVec<pair<string, int>> &sorted1,  MyVec<pair<string, int>> &sorted2,  
MyVec<pair<string, int>> &sorted3){
    MyVec<string> tokens;
    tokenize(phrase,tokens);    //Facilita a comparação, porém e bem indeficiente
    //Para o caso de estarmos verificando apenas uma palavra, olharemos no map 1 e no map 2
    if(tokens.size()==1){    
        cout << tokens[0] <<" "<<"("<<map1[tokens[0]]<<")"<<"\n";
        for(int i=0; i<sorted2.size(); i++){
            MyVec<string> sorted2aux;  
            tokenize(sorted2[i].first,sorted2aux);
            if(sorted2aux[0] == tokens[0]){
                cout<<sorted2aux[0]<<" "<<sorted2aux[1]<<" "<<"("<<sorted2[i].second<<")"<<"\n";
                k--;
            }
            if(k==0) break;
        }
    }
    //Para o caso de estarmos verificando apenas duas palavras, olharemos no map 2 e no map 3
    if(tokens.size() == 2 ){    
        cout << tokens[0] <<" " <<tokens[1] <<" "<<"("<<map2[tokens[1]][tokens[0]]<<")"<<"\n";
        for(int i=0; i<sorted3.size(); i++){
            MyVec<string> sorted3aux;  
            tokenize(sorted3[i].first,sorted3aux);
            if(sorted3aux[0] == tokens[0] && sorted3aux[1] == tokens[1]){
                cout<<sorted3aux[0]<<" "<<sorted3aux[1]<<" "<<sorted3aux[2]<<" "<<"("<<sorted3[i].second<<")"<<"\n";
                k--;
            }
            if(k==0) break;
        }
    }
    //Para o caso de estarmos verificando tre palavras, analisaremos no map 3
    if(tokens.size()== 3){
        cout << tokens[0] <<" " <<tokens[1]<<" "<<tokens[2] <<" "<<"("<<map3[tokens[2]][tokens[1]][tokens[0]]<<")"<<"\n";
        k--;
    }

}

void gerar(int k, const string &phrase, MyMap<string,int> &map1, MyMap<string,MyMap<string,int>> &map2,
MyMap<string, MyMap<string,MyMap<string,int>>> &map3, MyVec<pair<string, int>> &sorted1,  MyVec<pair<string, int>> &sorted2,  
MyVec<pair<string, int>> &sorted3){
    MyVec<string> tokens;
    string modo ;
    tokenize(phrase,tokens);
    if(tokens.size()<=1)return;
    //Aqui, iremos imprimir o início da frase, a partir do 1 para elimidar o modo de geração
    for(int i=1; i<tokens.size(); i++){
        cout<<tokens[i]<<" ";
    }

    //tokens na posição 0 indica se é modo aleatório ou padrão
    for(int j=0; j<k; j++){         //percorremos k vezes, adicionando a palavra mais frequente de cada map e printando
        int numpalavras = tokens.size()-1;
        bool picked = false;        //para evitar repetições
        if(numpalavras == 2 || !picked){     
            string palavra;
            for(int i=0; i<sorted3.size(); i++){
                MyVec<string> sorted3aux;  
                tokenize(sorted3[i].first,sorted3aux);
                if(sorted3aux[0] == tokens[numpalavras-1] && sorted3aux[1] == tokens[numpalavras]){
                    palavra =sorted3aux[2];
                    tokens.push_back(palavra);
                    cout<<palavra<<" ";                    
                    picked=true;
                    break;
                }
            } 
        }   
        if(picked)continue; 
        if(numpalavras == 1 || !picked){    
            string palavra;
            for(int i=0; i<sorted2.size(); i++){
                MyVec<string> sorted2aux;  
                tokenize(sorted2[i].first,sorted2aux);
                if(sorted2aux[0] == tokens[numpalavras]){
                    palavra = sorted2aux[1];
                    //cout<<palavra<<endl;
                    tokens.push_back(palavra);
                    cout<<palavra<<" ";
                    picked=true;
                    break;
                }
            } 
        }
        if(picked)continue;
        if(numpalavras == 0 || !picked){  
            string palavra;
            palavra = sorted1[0].first;
            tokens.push_back(palavra);
            cout<<palavra<<" ";
        }
    }


}

//Funções auxiliares para facilitar na leitura do arquivo ==========================================================================
void readComando( MyMap<string,int> &map1, MyMap<string,MyMap<string,int>> &map2,
MyMap<string, MyMap<string,MyMap<string,int>>> &map3, MyVec<pair<string, int>> &sorted1,  MyVec<pair<string, int>> &sorted2,  
MyVec<pair<string, int>> &sorted3){
    string phrase, command;
    int k=0;
    while(cin>>command>>k){   
        getline(cin,phrase); 
        if(command.compare("consultar") ==0){
            consultar(k,phrase,map1,map2,map3,sorted1,sorted2,sorted3);
            cout<<"\n";
        }
        else if (command.compare("gerar") ==0){
            gerar(k,phrase,map1,map2,map3,sorted1,sorted2,sorted3);   
            cout<<"\n\n";     
        }
    }
};


int main(){
    MyMap<string,int>map1;
    MyMap<string,MyMap<string,int>>map2;
    MyMap<string, MyMap<string,MyMap<string,int>>>map3;
    MyVec<pair<string, int>> sorted1;
    MyVec<pair<string, int>> sorted2;
    MyVec<pair<string, int>> sorted3;

    //Esta função tratará a leitura delimitada pelas strings pré definidas no roteiro 
    readTreino(map1,map2,map3);  
    //Para a ordenação, foram criados vetores auxiliares, contendo pares, pois não seria possivel ordenr a partir  do valor dos maps
    //Além disso, ordenamos antes de realizar a consulta, para que esta operação se torne mais eficiente
    sort1(map1,sorted1);
    sort2(map1,map2,sorted2);
    sort3(map1,map2,map3,sorted3);
    //Por fim, realizamos as operações
    readComando(map1,map2,map3,sorted1,sorted2,sorted3);   
             
    return 0;
}