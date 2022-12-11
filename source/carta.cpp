#include <carta/carta.h>

namespace trabalho{
Carta::Carta(std::vector<int> atri){
    atribuir_valores(atri);
};

void Carta::setNumero(long unsigned int num){
    numero = num;
};
long unsigned int Carta::getNumero(){
    return numero;
};

void Carta::setClasse(std::string cl){
    classe = cl;
};
std::string Carta::getClasse(){
    return classe;
};

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

void Carta::setJogos(int jg){
    jogos = jg;
};
int Carta::getJogos(){
    return jogos;
};

void Carta::setVelocidade(int vel){
    velocidade = vel;
};
int Carta::getVelocidade(){
    return velocidade;
};

void Carta::setDrible(int dr){
    drible = dr;
};
int Carta::getDrible(){
    return drible;
};

void Carta::atribuir_valores(std::vector<int> carta1){
    setGols(carta1.at(0));
    setAssistencias(carta1.at(1));
    setJogos(carta1.at(2));
    setVelocidade(carta1.at(3));
    setDrible(carta1.at(4));
};
}
