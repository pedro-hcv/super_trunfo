#ifndef INTER_H
#define INTER_H

#include <jogo/jogo.h>

namespace trabalho{
class Interface : private Jogo{

    public:
        Interface();
        void inicio();
        //void status();
};
}

#endif