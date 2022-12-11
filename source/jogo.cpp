#include <jogo/jogo.h>

namespace trabalho{
void Jogo::distribuir_cartas(){
    std::cout << "Informe o número de jogadores (2 a 8): ";
    std::cin >> numero_de_jogadores;
    std::string resposta;
    std::cout << "Deseja informar os nomes dos jogadores? (Sim ou não) ";
    std::cin >> resposta;
    std::transform(resposta.begin(), resposta.end(),resposta.begin(), ::toupper);
    if (!resposta.compare("SIM")){
        for (long unsigned int i = 0; i < numero_de_jogadores; i++){
            std::string nome;
            std::cout << "Informe o nome do jogador " << i+1 << ": ";
            std::cin >> nome;
            Nomes_dos_jogadores.push_back(nome);
        }
        //std::random_device rd;
        //std::mt19937 generator(rd());
        //std::shuffle(Nomes_dos_jogadores.begin(), Nomes_dos_jogadores.end(), generator);
    }
    else nomes();
    Cartas_Super_trunfo.criarCartas();
    Cartas_Super_trunfo.embaralhar();
    Cartas_dos_jogadores.resize(numero_de_jogadores);
    long unsigned int c = 0;
    while (Cartas_Super_trunfo.numero_de_cartas() > 0){
        long unsigned int jogador = c % numero_de_jogadores;
        Cartas_dos_jogadores.at(jogador)+= Cartas_Super_trunfo.ultima_carta();
        c += 1;
        --Cartas_Super_trunfo;
    }
};


void Jogo::inicio(){
    qtd_cartas_jogadores();
    for (long unsigned int i=0; i<numero_de_jogadores; i++){
        for (long unsigned int j=0; j<Cartas_dos_jogadores.at(i).numero_de_cartas(); j++){
            if (Cartas_dos_jogadores.at(i).show_carta(j).getNumero() == 1 && Cartas_dos_jogadores.at(i).show_carta(j).getClasse() == "A"){
                std::cout<< Nomes_dos_jogadores.at(i) << " começa o jogo!\n";
                Cartas_dos_jogadores.at(i).mostrar_topo();
            }
        }
    }
    
    while (!fim_do_jogo){
        jogada();
    }
};


void Jogo::jogada(){
    
    std::cout << "Informe um parâmetro desejado: ";
    long unsigned int caso = 8;
    while (caso == 8){
        std::string lance;
        std::vector<std::string> l = {"GOLS", "ASSISTêNCIAS", "JOGOS", "VELOCIDADE", "DRIBLE"};
        std::cin >> lance;
        std::transform(lance.begin(), lance.end(),lance.begin(), ::toupper);
        
        
        for (long unsigned int i = 0; i < l.size(); i++){
            if (!lance.compare(l.at(i))) { 
                caso = i;
                break;}
        }
        if (caso == 8) std::cout << "Informe um parâmetro válido! ";
    }

    std::cout << "###########################################" <<std::endl;
    if(trunfo()){
        bool outro = false;
        std::vector<std::string> outros;
        std::vector<long unsigned int> pos_outros;
        long unsigned int vencedor = 0;
        for (long unsigned int i = 0; i < numero_de_jogadores; i++){
            if(Cartas_dos_jogadores.at(i).primeira_carta().getNumero() == 1 && Cartas_dos_jogadores.at(i).primeira_carta().getClasse() == "A"){
                std::cout << Nomes_dos_jogadores.at(i) << " tem o Trunfo!" << std::endl;
                vencedor = i;
            }
            if(Cartas_dos_jogadores.at(i).primeira_carta().getClasse() == "A" && Cartas_dos_jogadores.at(i).primeira_carta().getNumero() != 1){
                outro = true;
                outros.push_back(Nomes_dos_jogadores.at(i));
                pos_outros.push_back(i);
            }
        }
        if(outro){
            long unsigned int menor = 9;
            
            std::cout << "Entretanto, o(s) jogador(es) : ";
            for (long unsigned int j = 0; j < outros.size(); j++) std::cout << outros.at(j) << " ";
            std::cout << "possue(m) carta(s) A!" << std::endl;
            for (long unsigned int c = 0; c < outros.size(); c++){ 
                mostrar_carta_jogador(pos_outros.at(c));
                std::cout << std::endl;
                if (Cartas_dos_jogadores.at(pos_outros.at(c)).primeira_carta().getNumero() < menor){
                    menor = Cartas_dos_jogadores.at(pos_outros.at(c)).primeira_carta().getNumero();
                    vencedor = pos_outros.at(c);
                }  
            }
        }
        decisao(vencedor);
    }
    else{
    int maior = 0;
    long unsigned int j = 0;

    switch (caso){    
    case 0:
        std::cout << "Os gols de cada carta são: " << std::endl ;
        maior = Cartas_dos_jogadores.at(0).primeira_carta().getGols();
        
        for (long unsigned int i = 0; i < numero_de_jogadores; i++){
            int valor = Cartas_dos_jogadores.at(i).primeira_carta().getGols();
            mostrar_carta_jogador(i);
            std::cout << valor << std::endl;
            if (valor > maior) {
                j = i;
                maior = valor;
            }
        }
        std::cout << "###########################################" <<std::endl;
        decisao(j);
        break;

    case 1:
        std::cout << "As assistências de cada carta são: " << std::endl ;
        maior = Cartas_dos_jogadores.at(0).primeira_carta().getAssistencias();
       
        for (long unsigned int i = 0; i < numero_de_jogadores; i++){
            int valor = Cartas_dos_jogadores.at(i).primeira_carta().getAssistencias();
            mostrar_carta_jogador(i);
            std::cout << valor << std::endl;
            if (valor > maior) {
                j = i;
                maior = valor;
            }
        }
        std::cout << "###########################################" <<std::endl;
        decisao(j);
        break;
    
    case 2:
        std::cout << "Os jogos de cada carta são: " << std::endl ;
        maior = Cartas_dos_jogadores.at(0).primeira_carta().getJogos();
       
        for (long unsigned int i = 0; i < numero_de_jogadores; i++){
            int valor = Cartas_dos_jogadores.at(i).primeira_carta().getJogos();
            mostrar_carta_jogador(i);
            std::cout<< valor << std::endl;
            if (valor > maior) {
                j = i;
                maior = valor;
            }
        }
        std::cout << "###########################################" <<std::endl;
        decisao(j);
        break;

    case 3:
        std::cout << "As velocidades de cada carta são: " << std::endl ;
        maior = Cartas_dos_jogadores.at(0).primeira_carta().getVelocidade();
       
        for (long unsigned int i = 0; i < numero_de_jogadores; i++){
            int valor = Cartas_dos_jogadores.at(i).primeira_carta().getVelocidade();
            mostrar_carta_jogador(i);
            std::cout<< valor << std::endl;
            if (valor > maior) {
                j = i;
                maior = valor;
            }
        }
        std::cout << "###########################################" <<std::endl;
        decisao(j);
        break;
    case 4:
        std::cout << "Os dribles de cada carta são: " << std::endl ;
        maior = Cartas_dos_jogadores.at(0).primeira_carta().getDrible();

        for (long unsigned int i = 0; i < numero_de_jogadores; i++){
            int valor = Cartas_dos_jogadores.at(i).primeira_carta().getDrible();
            mostrar_carta_jogador(i);
            std::cout<< valor << std::endl;
            if (valor > maior) {
                j = i;
                maior = valor;
            }
        }
        std::cout << "###########################################" <<std::endl;
        decisao(j);
        break;
    }
    }
};

void Jogo::mostrar_carta_jogador(long unsigned int pos){
    std::cout << Nomes_dos_jogadores.at(pos) << " : ";
    std::cout<< Cartas_dos_jogadores.at(pos).primeira_carta().getNumero();
    std::cout<< Cartas_dos_jogadores.at(pos).primeira_carta().getClasse() <<" - ";
    std::cout<< Cartas_dos_jogadores.at(pos).primeira_carta().getNome() << " ";
};



void Jogo::decisao(long unsigned int vencedor){
    long int beg = 0;
    std::cout << Nomes_dos_jogadores.at(vencedor) << " venceu a rodada!" << std::endl;
        for (long unsigned int i = 0; i < numero_de_jogadores; i++){
            Cartas_dos_jogadores.at(vencedor)+=Cartas_dos_jogadores.at(i).primeira_carta();
            Cartas_dos_jogadores.at(i).apagar_primeira();
            if (Cartas_dos_jogadores.at(i).numero_de_cartas() == 0){
                Cartas_dos_jogadores.erase(Cartas_dos_jogadores.begin() + beg);
                std::cout << Nomes_dos_jogadores.at(i) << " foi eliminado!" << std::endl;
                Nomes_dos_jogadores.erase(Nomes_dos_jogadores.begin() + beg);
                numero_de_jogadores--;
                if (vencedor > i) {
                    vencedor--;
                }
                i--;
                beg--;
            }
            beg++;
        }
    std::cout << "###########################################" <<std::endl;
    
    if (Nomes_dos_jogadores.size() == 1){
        std::cout << "\n#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#1#!#!#!#!#!#!#!#!#!#!#!#!#!#" <<std::endl;
        std::cout << std::endl;
        std::cout << Nomes_dos_jogadores.at(0) << " venceu o jogo!" << std::endl;
        Cartas_dos_jogadores.at(0).status();
        std::cout << "#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#1#!#!#!#!#!#!#!#!#!#!#!#!#!#" <<std::endl;
        fim_do_jogo = true;
    }
    else{
        qtd_cartas_jogadores();
        std::cout << "\nCarta de " << Nomes_dos_jogadores.at(vencedor) <<" :"<< std::endl;
        Cartas_dos_jogadores.at(vencedor).mostrar_topo();
    }
};

void Jogo::qtd_cartas_jogadores(){
    std::cout<<"\n----------------------------------------------------------"<<std::endl;
    std::cout<<"Quantidade de cartas de cada jogador : "<<std::endl;
    for (long unsigned int j = 0; j < numero_de_jogadores; j++){
        std::cout<<"    "<<Nomes_dos_jogadores.at(j)<<" : ";
        std::cout<<Cartas_dos_jogadores.at(j).numero_de_cartas()<<std::endl;
    }
    std::cout<<"----------------------------------------------------------"<<std::endl;
};

void Jogo::nomes(){
    for(long unsigned int i = 0; i < numero_de_jogadores; i++){
        if (i == 0) Nomes_dos_jogadores.push_back("Jogador 1");
        if (i == 1) Nomes_dos_jogadores.push_back("Jogador 2");
        if (i == 2) Nomes_dos_jogadores.push_back("Jogador 3");
        if (i == 3) Nomes_dos_jogadores.push_back("Jogador 4");
        if (i == 4) Nomes_dos_jogadores.push_back("Jogador 5");
        if (i == 5) Nomes_dos_jogadores.push_back("Jogador 6");
        if (i == 6) Nomes_dos_jogadores.push_back("Jogador 7");
        if (i == 7) Nomes_dos_jogadores.push_back("Jogador 8");
    }
};

void Jogo::status(){
    for(long unsigned int i = 0; i<numero_de_jogadores; i++){
        std::cout << Nomes_dos_jogadores.at(i) << ": \n";
        Cartas_dos_jogadores.at(i).status(); 
    }
};

bool Jogo::trunfo(){
    for(long unsigned int i = 0; i<numero_de_jogadores; i++){
        if(Cartas_dos_jogadores.at(i).primeira_carta().getNumero() == 1 && Cartas_dos_jogadores.at(i).primeira_carta().getClasse() == "A"){
            return true;
        }
    }
    return false;
};

}

