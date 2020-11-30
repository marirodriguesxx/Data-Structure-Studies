
#include <iostream>
#include <algorithm>
#include <cstring>
#include "MyVecNewIterator.h"
#include "MyMap.h"
#include <utility>
#include <fstream>
#include <algorithm>
using namespace std;

void format(string & line){
    int tam =line.size();

    for(int i=0; i<tam; i++){
        if(line[i]=='\"' || line[i] =='\'' ||line[i] == '\n' || line[i] ==' '){
                
                if(line[i-1] != ',' && line[i-1]!='\0' && line[i-1] != '\n') //adicionamos este if pois aqui tratamos os casos possiveis de inio de linha
                line[i] = ',';
                else{
                line[i] = '\0';
                }
        }
        else if((ispunct(line[i]) || isdigit(line[i])) && line[i] != '-' ){           //Se for um ponto (exceto travessão)ou dígito substituímos por \n
                if(line[i-1] != '\n')
                line[i] = '\n';
                else
                line[i] = '\0';
        }
        else if(isupper(line[i])){          //Se for uma letra maíscula, transformamos para minúscula
            line[i] = tolower(line[i]);
        }
    }
};

void leTreino(string &line){
        if(line == "COMECO_TREINO"){
        
            do{
                getline(cin,line);
                if(line ==  "FINAL_TREINO") break;
                format(line);
                cout<<line;
            }
            while(line != "FINAL_TREINO");
        } 
}

void leComando(string &operation, string &word, int &k){
    // convertendo para inteiro (k) o valor recebido no arquivo
    k = atoi(&word[1]);
    cout<<"word[1]: "<<word[1]<<"\n";
    if(operation.compare("consultar") ==0)
        cout<<"estou consultando\n";
    else if (operation.compare("gerar") ==0)
        cout<<"estou gerando\n";
}

void AddDictionary(const string& line){

};

int main(int argc, char *argv[]){
    string word;
    string line;
    int k = 0;

    MyMap<string,int>map1;
    MyMap<string,MyMap<string,int>>map2;
    MyMap<string, MyMap<string,MyMap<string,int>>>map3;
    

    while(getline(cin,line)){
        leTreino(line); 
        
        //faremos isso para ignorar a linha "FINAL_TREINO"
        // if(line != "FINAL_TREINO"){
        // getline(cin,word);
        // cout<<line<<word<<endl;
        // leComando(line,word,k);
        // cout<<"k: "<<k<<endl;
        // }       
        
    }
    

    return 0;
}