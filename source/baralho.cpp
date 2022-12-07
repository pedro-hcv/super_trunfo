#include <baralho/baralho.h>

void Baralho::criarCartas(){
    std::vector<int> c1 = {1, 2, 4, 5, 5};
    std::vector<int> c2 = {3, 4, 5, 5, 6};
    //std::vector<std::vector<int>> = {{1, 2, 3}, {1,3 4}}
  //  std::vector<std::string> = {"Neymar", "Messi"};
    /* for (int i=0; i < 2 ; i++){
        Carta cq1;
        cq1.setNome("1A");
        cq1.setForca(c1.at(0));
        cq1.setAssistencias(c1.at(1));
        cq1.setGols(c1.at(2));
        cq1.setTrofeus(c1.at(3));
        cq1.setVelocidade(c1.at(4));
        Sequencia_de_Cartas.push_back(cq1);
    } */
    Carta cq1;
    cq1.setNome("1A");
    cq1.setForca(c1.at(0));
    cq1.setAssistencias(c1.at(1));
    cq1.setGols(c1.at(2));
    cq1.setTrofeus(c1.at(3));
    cq1.setVelocidade(c1.at(4));
    Sequencia_de_Cartas.push_back(cq1);
    /* for (int i=0; i<4; i++){
        cq1.setNome("iA")
    } */

    //Carta cq;
    cq1.setNome("1B");
    cq1.setForca(c2.at(0));
    cq1.setAssistencias(c2.at(1));
    cq1.setGols(c2.at(2));
    cq1.setTrofeus(c2.at(3));
    cq1.setVelocidade(c2.at(4));
    Sequencia_de_Cartas.push_back(cq1);

    
};


void Baralho::embaralhar(){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(Sequencia_de_Cartas.begin(), Sequencia_de_Cartas.end(), generator);

};

void Baralho::status(){
    for (long unsigned int i=0;  i<Sequencia_de_Cartas.size(); i++){
        std::cout<<"    "<<Sequencia_de_Cartas.at(i).getNome()<<' ';
        std::cout<<"    "<<Sequencia_de_Cartas.at(i).getAssistencias()<<' ';
        std::cout<<"    "<<Sequencia_de_Cartas.at(i).getForca()<<' ';
        std::cout<<"    "<<Sequencia_de_Cartas.at(i).getTrofeu()<<' ';
        std::cout<<"    "<<Sequencia_de_Cartas.at(i).getGols()<<' ';
        std::cout<<"    "<<Sequencia_de_Cartas.at(i).getVelocidade()<<'\n';
    }
    std::cout << '\n';
    //std::cout<<Sequencia_de_Cartas.size()<<'\n';
};

long unsigned int Baralho::numero_de_cartas(){
    return Sequencia_de_Cartas.size();
};

void Baralho::inserir_carta(Carta c1){
    Sequencia_de_Cartas.push_back(c1);
};

Carta Baralho::show_carta(long unsigned int pos){
    return Sequencia_de_Cartas.at(pos);
};

Carta Baralho::ultima_carta(){
    return Sequencia_de_Cartas.at(numero_de_cartas() - 1);
};

/* Baralho & Baralho::operator +(const Carta c1){
    Sequencia_de_Cartas.push_back(c1);
    return *this;
}

Baralho & Baralho::operator = (const Baralho Atr){
    this->Sequencia_de_Cartas = Atr.Sequencia_de_Cartas;
    return *this;
} */
Baralho & Baralho::operator +=(const Carta c1){
    Sequencia_de_Cartas.push_back(c1);
    return *this;
};


Baralho & Baralho::operator--(){
    Sequencia_de_Cartas.pop_back();
    return *this;
}