# Super Trunfo Copa do Mundo 2022
Trabalho de programação 3 - Pedro e André

# :hammer: Início do jogo:

Ao iniciar o jogo, os jogadores devem digitar o número de jogadores em um interavalo de 2 a 8 participantes, em seguida, digitar "Sim" caso 
queiram escolher o nome dos jogadores, qualquer string diferente de "Sim", vai designar nomes padrão aos jogadores - isso é, "jogador 1", "jogador 2", etc.

# Jogadas:
Em sequência, o jogo inicia criando as 32 cartas e embaralhando-as de forma que cada jogador receberá uma carta até que o baralho acabe. 
Após o fim da entrega de cartas, será informado qual jogador possui o trunfo e a primeira carta de seu deck será mostrada na tela para que seja 
feita a escolha do atribut. 

O jogador deve digitar o nome do atributo escolhido, na tela será mostrado o nome da carta de cada jogador e o atributo 
escolhido, juntamente com o resultado da rodada, o jogador que possuir a carta de maior atributo vence a rodada erecebe as cartas dos demais
jogadores, que são adicionadas ao final do seu deck. Também será mostrado quantas cartas cada jogador ainda possui no deck,
em seguida já será mostrada a próxima carta, para que o jogador que ganhou a rodada inicie uma nova jogada.

# Final do jogo
Quando as cartas de um jogador chegarem a 0, ele é eliminado, ao sobrar somente um jogador, ele então é declarado vencedor e é apresenteda todas as cartas
que ele tem na sequência.


# Caso Especial: Super-Trunfo
 - As cartas são numeradas de 1 a 8 e com classes de A a D. A carta 1A é o super-trunfo  e sempre que aparecer em uma rodada, será 
declarada vencedora, com exceção dos casos onde apareça outra carta classe A na rodada, caso mais de uma carta classe A conteste
o Super-Trunfo, a carta de menor numeração será declarada vencedora da rodada.

