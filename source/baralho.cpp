#include <baralho/baralho.h>

namespace trabalho{
void Baralho::criarCartas(){

std::vector<std::vector<int>> c1 = {{56, 24, 96 , 91, 96}, //1A
                                    {10, 16, 24 , 96, 94}, //1B
                                    {24, 17, 25 , 82, 82}, //1C
                                    {11, 8 , 56 , 65, 73}, //1D
                                    {73, 50, 168, 81, 97}, //2A
                                    {19, 7 , 120, 77, 92}, //2B
                                    {3 , 3 , 23 , 73, 79}, //2C
                                    {15, 6 , 16 , 74, 75}, //2D
                                    {72, 26, 72 , 97, 95}, //3A
                                    {36, 25, 88 , 59, 71}, //3B
                                    {2 , 14, 40 , 95, 91}, //3C
                                    {32, 23, 104, 78, 68}, //3D
                                    {64, 13, 176, 83, 83}, //4A
                                    {25, 11, 8  , 92, 85}, //4B
                                    {16, 5 , 7  , 94, 89}, //4C
                                    {14, 4 , 87 , 79, 66}, //4D
                                    {26, 19, 13 , 90, 90}, //5A
                                    {13, 12, 36 , 76, 70}, //5B
                                    {12, 18, 27 , 84, 76}, //5C
                                    {1 , 2 , 78 , 86, 72}, //5D
                                    {20, 15, 122, 75, 93}, //6A
                                    {23, 10, 55 , 71, 88}, //6B
                                    {48, 32, 112, 88, 87}, //6C
                                    {6 , 9 , 15 , 80, 78}, //6D
                                    {80, 48, 146, 70, 80}, //7A
                                    {21, 36, 32 , 69, 81}, //7B
                                    {17, 22, 10 , 72, 67}, //7C
                                    {5 , 20, 9  , 85, 84}, //7D
                                    {7 , 30, 83 , 68, 77}, //8A
                                    {4 , 21, 82 , 93, 86}, //8B
                                    {9 , 1 , 17 , 89, 74}, //8C
                                    {8 , 0 , 22 , 87, 69}};//8D
    std::vector<std::string> nomes_cartas = {"Neymar Jr (Super-Trunfo)", "Vinicius Jr", "Richarlison", "Casemiro", //1A 1B 1C 1D
                                             "Lionel Messi","Angel Di Maria","Rodrigo De Paul","Julian Alvarez",   //2A 2B 2C 2D
                                              "Kylian Mbappé","Olivier Giroud","Ousmane Dembele","Antoine Griezmann", //3A 3B 3C 3D
                                              "Cristiano Ronaldo","Gonçalo Ramos","Rafael Leao","Pepe", //4A 4B 4C 4D
                                              "Alvaro Morata","Gavi","Ferran Torres","Jordi Alba", //5A 5B 5C 5D
                                              "Luka Modric","Andrej Kramaric","Ivan Perisic","Marko Livaja", //6A 6B 6C 6D
                                              "Thomas Muller","Mario Gotze", "Niclas Fullkrug","Kai Havertz", //7A 7B 7C 7D
                                              "Harry Kane","Raheem Sterling", "Marcus Rashford","Bukayo Saka"}; //8A 8B 8C 8D
    std::vector<std::string> classes = {"A", "B", "C", "D"};
    for (long unsigned int i = 0; i < c1.size(); i++){
        long unsigned int j = i % 4;
        Carta cq1(c1.at(i));
        cq1.setClasse(classes.at(j));
        cq1.setNome(nomes_cartas.at(i));
        Sequencia_de_Cartas.push_back(cq1);
    }
    for (long unsigned int i = 0; i < nomes_cartas.size()/classes.size(); i++){
        for(long unsigned int j = i*classes.size(); j<classes.size()*(1 + i); j++){
            Sequencia_de_Cartas.at(j).setNumero(i+1);
        }
    }
};


void Baralho::embaralhar(){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(Sequencia_de_Cartas.begin(), Sequencia_de_Cartas.end(), generator);

};

void Baralho::status(){
    for (long unsigned int i=0;  i<Sequencia_de_Cartas.size(); i++){
        std::cout<<"    "<<Sequencia_de_Cartas.at(i).getNumero();
        std::cout<<Sequencia_de_Cartas.at(i).getClasse();
        std::cout<<" - "<<Sequencia_de_Cartas.at(i).getNome()<<'\n';
        std::cout<<"    Gols: "<<Sequencia_de_Cartas.at(i).getGols()<<' ';
        std::cout<<"    Assistências: "<<Sequencia_de_Cartas.at(i).getAssistencias()<<' ';
        std::cout<<"    Jogos: "<<Sequencia_de_Cartas.at(i).getJogos()<<' ';
        std::cout<<"    Velocidade: "<<Sequencia_de_Cartas.at(i).getVelocidade()<<' ';
        std::cout<<"    Drible: "<<Sequencia_de_Cartas.at(i).getDrible()<<'\n';
    }
    std::cout << '\n';
};

void Baralho::mostrar_topo(){
    std::cout<<"    "<<Sequencia_de_Cartas.at(0).getNumero();
    std::cout<<Sequencia_de_Cartas.at(0).getClasse();
    std::cout<<" - "<<Sequencia_de_Cartas.at(0).getNome()<<'\n';
    std::cout<<"    Gols: "<<Sequencia_de_Cartas.at(0).getGols()<<' ';
    std::cout<<"    Assistências: "<<Sequencia_de_Cartas.at(0).getAssistencias()<<' ';
    std::cout<<"    Jogos: "<<Sequencia_de_Cartas.at(0).getJogos()<<' ';
    std::cout<<"    Velocidade: "<<Sequencia_de_Cartas.at(0).getVelocidade()<<' ';
    std::cout<<"    Drible: "<<Sequencia_de_Cartas.at(0).getDrible()<<'\n';
    std::cout << '\n';
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

Carta Baralho::primeira_carta(){
    return show_carta(0);
}

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
};

void Baralho :: apagar_primeira(){
    Sequencia_de_Cartas.erase(Sequencia_de_Cartas.begin());
};

}