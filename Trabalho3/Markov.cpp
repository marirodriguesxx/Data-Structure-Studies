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
        if(!isalpha(line[i]) && line[i] != '-'){
            line[i] = '\n';
        }
        else if(isupper(line[i])){          //Se for uma letra maíscula, transformamos para minúscula
            line[i] = tolower(line[i]);
        }
    }
};

//Funcao que auxilia no armazenamento das palavras importantes ======================================================================
void storage(const string &line, MyVec<string> &tokens){
    //Aqui, ieremos salvar em uma string auxiliar apenas as palvras ja formatas e importantes para o dicionario em um vetor
    istringstream aux(line);
    while(aux){
        string tok;
        aux >> tok;
        //cout << "token: " << tok << endl;
        tokens.push_back(tok);
    }
}

//Função que ordena de acordo com o valor ===========================================================================================
void sort(MyMap<string, int> &mp1){ 
}

//Funções maps1, map2 e map3 auxiliares=============================================================================================
void createmap1 (MyMap<string,int> &map1,  MyVec<string>& words){    
    for(int i=0; i<words.size(); i++){
        map1[words[i]]++;
        //cout<<"certo: "<<map1[words[i]]<<endl;
        //cout<< words[i] << " ("<<map1[words[i]]<<")"<<'\n';
    }

}

//Função imprime ==================================================================================================================
void print(MyMap<string,int> &m1){
    MyMapIterator<string, int> it1 = m1.begin();
    while(it1 != m1.end()){
        cout<<(*it1).first <<" "<<"("<< (*it1).second<<")"<<"\n";
        it1++;
    }
}

void AddDictionary( MyVec<string>& words, MyMap<string,int> &mp1){
    createmap1(mp1,words);

}


//Funções para leitura do arquivo ==================================================================================================
void readTreino(string &line){
    MyVec<string> tokens;
    MyMap<string,int>mp1;
    if(line == "COMECO_TREINO"){        
        do{
            //Primeiro, recebemos o consteúdo das linhas e formatamos para auxiliar na criação do dicionário
            getline(cin,line);
            if(line ==  "FINAL_TREINO") break;
            format(line);                  
            storage(line,tokens);
            //AddDictionary(tokens,mp1);
            //cout<<tokens<<endl;
        }
        while(line != "FINAL_TREINO");
        AddDictionary(tokens,mp1);
        print(mp1);
    } 
}

void readComando(string &operation, string &word, int &k){
    // convertendo para inteiro (k) o valor recebido no arquivo
    k = atoi(&word[1]);
    cout<<"word[1]: "<<word[1]<<"\n";
    if(operation.compare("consultar") ==0)
        cout<<"estou consultando\n";
    else if (operation.compare("gerar") ==0)
        cout<<"estou gerando\n";
};



int main(int argc, char *argv[]){
    string word;
    string line;
    int k = 0;

    MyMap<string,int>map1;
    MyMap<string,MyMap<string,int>>map2;
    MyMap<string, MyMap<string,MyMap<string,int>>>map3;
    

    while(getline(cin,line)){
        readTreino(line); 
        
        //faremos isso para ignorar a linha "FINAL_TREINO"
        // if(line != "FINAL_TREINO"){
        // getline(cin,word);
        // cout<<line<<word<<endl;
        // readComando(line,word,k);
        // cout<<"k: "<<k<<endl;
        // }       
        
    }
    

    return 0;
}