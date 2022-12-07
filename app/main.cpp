#include <iostream>
#include <baralho/baralho.h>
#include <jogo/jogo.h>

int main(){
    /* Baralho b1;
    b1.criarCartas();
    b1.embaralhar();
    b1.status(); */
    Jogo j1;
    j1.distribuir_cartas();
    j1.status();
    j1.inicio();
    j1.status();
}
