#ifndef CARTA_H
#define CARTA_H

#include <iostream>


class Carta{
    std::string nome;

    int gols;
    int assistencias;
    int velocidade;
    int forca;
    int trofeus;
    
    public:
        //Carta()
        void setNome(std::string nm);
        std::string getNome();

        void setGols(int g);
        int getGols();

        void setAssistencias(int asst);
        int getAssistencias();

        void setVelocidade(int vel);
        int getVelocidade();

        void setForca(int fr);
        int getForca();

        void setTrofeus(int tr);
        int getTrofeu();

};

#endif