#ifndef BAR_H
#define BAR_H

#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <iterator>
#include <algorithm>
#include <carta/carta.h>


class Baralho{
    std::vector<Carta> Sequencia_de_Cartas;
    public:

        void criarCartas();
        void embaralhar();
        void status();
        long unsigned int numero_de_cartas();
        void inserir_carta(Carta c1);
        Carta show_carta(long unsigned int pos);
        Carta ultima_carta();
        /* Baralho & operator +(const Carta c);
        Baralho & operator = (const Baralho Atr); */
        Baralho & operator +=(const Carta c);
        Baralho & operator--();
};

#endif