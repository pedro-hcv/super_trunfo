#include <jogo/jogo.h>

void Jogo::distribuir_cartas(){
    std::cout << "Informe o número de jogadores (2 a 8): ";
    std::cin >> numero_de_jogadores;
    
    Cartas_Super_trunfo.criarCartas();
    Cartas_Super_trunfo.embaralhar();
    Cartas_dos_jogadores.resize(numero_de_jogadores);
    long unsigned int c = 0;
    while (Cartas_Super_trunfo.numero_de_cartas() > 0){
        long unsigned int jogador = c % numero_de_jogadores;
        long unsigned int n = Cartas_Super_trunfo.numero_de_cartas() - 1;
        Cartas_dos_jogadores.at(jogador)+=Cartas_Super_trunfo.show_carta(n);
        c += 1;
        --Cartas_Super_trunfo;
    }
    /* for (long unsigned int i = 0; i<numero_de_jogadores; i++){
        Baralho b;
        b += Cartas_Super_trunfo.show_carta(i);
        Cartas_dos_jogadores.push_back(b);
    } */
};


void Jogo::inicio(){
    for (long unsigned int i=0; i<numero_de_jogadores; i++){
        for (long unsigned int j=0; j<Cartas_dos_jogadores.at(i).numero_de_cartas(); j++){
            if (Cartas_dos_jogadores.at(i).show_carta(j).getNome() == "1A"){
                std::cout<< "Jogador " << i+1 << " começa o jogo!\n";
            }
        }
    }
    jogada();
    for (long unsigned int i = 0; i < numero_de_jogadores; i++){
        if (Cartas_dos_jogadores.at(i).numero_de_cartas() == 2){
            std::cout << "#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#1#!#!#!#!#!#!#!#!#!#!#!#!#!#" <<std::endl;
            std::cout << std::endl;
            std::cout << "O Jogador " << i + 1 << " venceu o jogo!" << std::endl;
            std::cout << std::endl;
            std::cout << "#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#1#!#!#!#!#!#!#!#!#!#!#!#!#!#" <<std::endl;

        } 
    }
};


void Jogo::jogada(){
    std::cout << "Informar um parâmetro desejado: ";
    //std::string lance;
    int lance;
    std::cin >> lance;
    int maior = 0;
    long unsigned int j = 0;
    //std::cout << "###########################################" <<std::endl;
    switch (lance){    
    case 1:
        std::cout << "As assistências de cada carta são: " << std::endl ;
        maior = Cartas_dos_jogadores.at(0).ultima_carta().getAssistencias();
        
        for (long unsigned int i = 0; i < numero_de_jogadores; i++){
            int valor = Cartas_dos_jogadores.at(i).ultima_carta().getAssistencias();
            std::cout << "Jogador " << i + 1 << " : " << valor << std::endl;
            if (valor > maior) j = i;
        }
        std::cout << "###########################################" <<std::endl;
        std::cout << "Jogador " << j + 1 << " venceu a rodada!" << std::endl;
        for (long unsigned int i = 0; i < numero_de_jogadores; i++){
            Cartas_dos_jogadores.at(j)+=Cartas_dos_jogadores.at(i).ultima_carta();
            --Cartas_dos_jogadores.at(i);
        }
        break;
    case 2:
        std::cout << "As forças de cada carta são: " << std::endl ;
        maior = Cartas_dos_jogadores.at(0).ultima_carta().getForca();
       
        for (long unsigned int i = 0; i < numero_de_jogadores; i++){
            int valor = Cartas_dos_jogadores.at(i).ultima_carta().getForca();
            std::cout << "Jogador " << i + 1 << " : " << Cartas_dos_jogadores.at(i).ultima_carta().getForca() << std::endl;
            if (valor > maior) j = i;
        }
        std::cout << "Jogador " << j + 1 << " venceu a rodada!" << std::endl;
        for (long unsigned int i = 0; i < numero_de_jogadores; i++){
            Cartas_dos_jogadores.at(j)+=Cartas_dos_jogadores.at(i).ultima_carta();
            --Cartas_dos_jogadores.at(i);
        }
        break;
    }
    /* std::transform(lance.begin(), lance.end(), lance.begin(), ::toupper);

    switch (lance){
    case "Força";
        break;
    

    } */
};

void Jogo::status(){
    for(long unsigned int i = 0; i<numero_de_jogadores; i++){
        std::cout << "Jogador " << i+1 << ": \n";
        Cartas_dos_jogadores.at(i).status(); 
    }
};
