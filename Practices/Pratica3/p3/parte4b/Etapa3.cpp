#include <iostream>
#include<typeinfo>
using namespace std;

#include "FigBase.h"
#include "Retangulo.h"
#include "Circulo.h"
#include "Segmento.h"
      
int main() {
   
    Retangulo r;
    Circulo c; 
    Circulo c1;
    Segmento s;
    Segmento s1;

    FigBase *p[5];

    
    p[0] = &r;
    p[1] = &c;
    p[2] = &c1;
    p[3] = &s;
    p[4] = &s1;

    int i;

    for (i=0; i < 5; i++) {
        cin>>*p[i];
     }

     cout<<endl; 
    
    for(int i = 0; i<5; i++){
        cout << *p[i] << endl;
    }


    Circulo *circuloPtr;

    for(int i=0;i<5;i++){
        circuloPtr = dynamic_cast <  Circulo * > ( p[ i ] ); 
        if( circuloPtr != 0 ){
            double oldraio = circuloPtr->getRaio();
            circuloPtr->setRaio(oldraio*2);
            cout << *circuloPtr << endl;
        }
    }



       
    
    return 0;
    
} // fim de main


/* ----------------------------------------------------------
                 RESULTADO ESPERADO

Objeto 1
Perimetro = 12
Area = 8

Objeto 2
Perimetro = 25.1327
Area = 50.2655

Objeto 3
Perimetro = 5.38516
Area = 0

---------------------------------------------------------------
*/
