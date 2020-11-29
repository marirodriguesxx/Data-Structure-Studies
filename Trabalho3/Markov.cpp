
#include <iostream>
#include <algorithm>
#include <cstring>
#include "MyVecNewIterator.h"
#include "MyMap.h"
#include <utility>

using namespace std;

void format(string & line){
    transform(line.begin(), line.end(), line.begin(), ::tolower);
    replace( line.begin(), line.end(), ' ', ',');
    replace( line.begin(), line.end(), '!', ',');
    replace( line.begin(), line.end(), '0', ',');
    replace( line.begin(), line.end(), '1', ',');
    replace( line.begin(), line.end(), '2', ',');
    replace( line.begin(), line.end(), '3', ',');
    replace( line.begin(), line.end(), '4', ',');
    replace( line.begin(), line.end(), '5', ',');
    replace( line.begin(), line.end(), '6', ',');
    replace( line.begin(), line.end(), '7', ',');
    replace( line.begin(), line.end(), '8', ',');
    replace( line.begin(), line.end(), '9', ',');
};
void AddDictionary(const string& line){

};

int main(int argc, char *argv[]){

    string entrada;
    string line;
    int k = 0;

    MyMap<string,int>map1;
    MyMap<string,MyMap<string,int>>map2;
    MyMap<string, MyMap<string,MyMap<string,int>>>map3;
    
    // getline(cin,line);
    // cout<<line<<endl;       
    while(cin>>line){
    cin>>line;
    cout<<line<<endl;  
    if(line.compare("COMECO_TREINO") == 0 ){  
        while(line.compare("FINAl_TREINO") != 0){
            cin>>line;
            if(line.compare("FINAl_TREINO") == 0) break;
        }
         cout<<"aqui\n";
    }
    }
    

    return 0;
}