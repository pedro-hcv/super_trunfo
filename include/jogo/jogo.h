#ifndef JOGO_H
#define JOGO_H

#include <baralho/baralho.h>
namespace trabalho{
class Jogo{
    private:
        Baralho Cartas_Super_trunfo;
        std::vector<std::string> Nomes_dos_jogadores;
        std::vector<Baralho> Cartas_dos_jogadores;
        long unsigned int numero_de_jogadores = 2;
        bool fim_do_jogo = false;
        //std::string Vencedor = "Ninguém";
    public:
        void distribuir_cartas();
        void inicio();
        void jogada();
        void status();
        void nomes();
        void qtd_cartas_jogadores();
        void decisao(long unsigned int vencedor);
        void mostrar_carta_jogador(long unsigned int pos);
        bool trunfo();
};
}
#endif