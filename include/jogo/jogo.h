#ifndef JOGO_H
#define JOGO_H

#include <baralho/baralho.h>

class Jogo{
    Baralho Cartas_Super_trunfo;
    std::vector<Baralho> Cartas_dos_jogadores;
    long unsigned int numero_de_jogadores = 2;
    public:
        void distribuir_cartas();
        void inicio();
        void jogada();
        void status();
};

#endif