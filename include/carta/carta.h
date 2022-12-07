#ifndef CARTA_H
#define CARTA_H

#include <iostream>


class Carta{
    //std::string identidade;
    std::string nome;
    //int int_nome;
    int gols;
    int assistencias;
    int velocidade;
    int forca;
    int trofeus;
    
    public:
        //Carta(std::string nm, int inome, int gols)

        //void setIdentidade(std::string nm);
        //std::string getIdentidade();

        void setNome(std::string nm);
        std::string getNome();

        /* void setInt_nome(int inome);
        int getInt_nome();        
 */
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