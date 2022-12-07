#include <carta/carta.h>

void Carta:: setNome(std::string nm){
    nome = nm;
};

std::string Carta::getNome(){
    return nome;
};




void Carta::setGols(int g){
    gols = g;
};

int Carta::getGols(){
    return gols;
};

void Carta::setAssistencias(int asst){
    assistencias = asst;
};

int Carta::getAssistencias(){
    return assistencias;
};

void Carta::setVelocidade(int vel){
    velocidade = vel;
};
int Carta::getVelocidade(){
    return velocidade;
};

void Carta::setForca(int fr){
    forca = fr;
};
int Carta::getForca(){
    return forca;
};

void Carta::setTrofeus(int tr){
    trofeus = tr;
};
int Carta::getTrofeu(){
    return trofeus;
};
