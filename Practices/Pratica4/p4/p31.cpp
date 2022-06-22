#include "Conjunto2.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc,char *argv[]){

    int n =atoi(argv[1]);

    Conjunto<int> conjA(n), conjB(n);

    for(int i=0; i<n; i++){
        conjA.insere(i);
        conjB.insere(i);        
    }

    //União de A e B
    Conjunto<int> conjC= conjA + conjB;

   
    cout << conjC.pertence(10)<<endl;
    return 0;
    
}