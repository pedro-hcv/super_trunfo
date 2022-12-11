#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include <vector>

namespace trabalho{
class Carta{
    private:
        std::string classe;
        long unsigned int numero;
        std::string nome;
        
        int gols;
        int assistencias;
        int jogos;
        int velocidade;
        int drible;    
    public:
        Carta(std::vector<int> atri);

        void setClasse(std::string ind);
        std::string getClasse();

        void setNumero(long unsigned int num);
        long unsigned int getNumero();

        void setNome(std::string nm);
        std::string getNome();

        void setGols(int g);
        int getGols();

        void setAssistencias(int asst);
        int getAssistencias();

        void setJogos(int jg);
        int getJogos();

        void setVelocidade(int vel);
        int getVelocidade();


        void setDrible(int dr);
        int getDrible();

        void atribuir_valores(std::vector<int> carta1);

};
}
#endif