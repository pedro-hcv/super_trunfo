#include <interface/interface.h>

namespace trabalho{

Interface::Interface(){
    inicio();
};

void Interface::inicio(){
    distribuir_cartas();
    Jogo::inicio();
};

}