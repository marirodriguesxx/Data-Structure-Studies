#include<iostream>
#include<fstream>
#include<string>
#include "Agenda.h"


using namespace std;

ItemAgenda::ItemAgenda(){
    this->descr = "";
    this->data= Data();
    this->horario=Horario();
}

ItemAgenda::ItemAgenda(const std::string &desc, const Data &dt, const Horario &hr){
    setDesc(desc);
    setData(dt);
    setHorario(hr);
}

/*ItemAgenda::ItemAgenda(const ItemAgenda &item){
    this->descr = item.descr;
    this->data = item.data;
    this->horario = item.horario;
}*/

  const string& ItemAgenda::getDesc()const{
      return descr;
  }
  const Data& ItemAgenda::getData()const{
      return data;
  }
  const Horario& ItemAgenda::getHorario()const{
      return horario;
  }
  
  void ItemAgenda::setDesc(const string &desc){
      this->descr= desc;
  }
  void ItemAgenda::setData(const Data &dt){
      this->data=dt;
  }
  void ItemAgenda::setHorario(const Horario &hr){  
      this->horario=hr;    
  }

 Agenda::Agenda(){
  }
  void Agenda::inserirItem(const ItemAgenda &it){
      vetor[cont]=it;
      cont++;
  }
  void Agenda::compromissosData(const Data &dt)const{
      for(int i=0;i<cont;i++){
          if((vetor[i].getData().compData(dt))==0)
                      cout<<vetor[i].getHorario()<<" "<<vetor[i].getDesc()<<endl;
      }

  }

