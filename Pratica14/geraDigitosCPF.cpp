#include<iostream>
#include<string.h>
#include<cstring>

using namespace std;

int digit1(const int cpf[]){
    int s=0;
    for(int i=0, value=10; i<9; i++,value--){ //value é o fator multiplicador de cada digito, começando em 10 e sendo decrementado
        s +=cpf[i]*value;          //s é a soma acumulada da multiplicação dígito x coeficiente
    }
    return ((s*10)%11);
}
int digit2(const int cpf[],int firstDigit){
    int s=0;
    for(int i=0, value=11; i<9; i++,value--){ //value é o fator multiplicador de cada digito, começando em 10 e sendo decrementado
        s +=cpf[i]*value;          //s é a soma acumulada da multiplicação dígito x coeficiente
    }
    s+=firstDigit*2;
    return ((s*10)%11);
}

int main(){
    char digit;
    int cpf[9];
    int n;      //número de dígitos a serem verificados
    cin>>n;

    for(int i=0; i<n; i++){
        for(int i=0; i<9; i++){
            cin>>digit;
            cpf[i] = atoi(&digit);              //convertendo cada char recebido para inteiro e armazenando em um vetor
        }
        //Aqui, calculamos e já printamos o primeiro dígito verificador 
        int first = digit1(cpf);
        if(first==10)
            first=0;
        cout<<first;
        int second = digit2(cpf,first);
        cout<<second<<endl;
    }
    return 0;
}