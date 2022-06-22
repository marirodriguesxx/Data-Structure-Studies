#ifndef HORARIO_H
#define HORARIO_H

class Horario{
    public:
        Horario(int=0, int=0, int=0);
        Horario(const Horario &hr);

        void setHora(int h);
        void setMinuto(int m);
        void setSegundos(int s);

        int getHora()const;
        int getMinuto()const;
        int getSegundo()const;

        int compHorario(const Horario &hms)const;
        int difSegundos(const Horario &hms)const;
        void imprime()const;

    friend std::ostream& operator<<(std::ostream &out, const Horario &hms);
    friend std::istream& operator>>(std::istream &in, Horario &hms);

    private:
    int hora;
    int minuto;
    int segundo;
};

#endif