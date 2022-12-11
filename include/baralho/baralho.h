#ifndef BAR_H
#define BAR_H

#include <random>
//#include <functional>
//#include <iterator>
#include <algorithm>
#include <carta/carta.h>

namespace trabalho{
class Baralho{
    private:
        std::vector<Carta> Sequencia_de_Cartas;
    public:
        void criarCartas();
        void embaralhar();
        void status();
        void mostrar_topo();
        long unsigned int numero_de_cartas();
        void inserir_carta(Carta c1);
        void apagar_primeira();
        Carta show_carta(long unsigned int pos);
        Carta primeira_carta();
        Carta ultima_carta();
        /* Baralho & operator +(const Carta c);
        Baralho & operator = (const Baralho Atr); */
        Baralho & operator +=(const Carta c);
        Baralho & operator--();
};
}
#endif