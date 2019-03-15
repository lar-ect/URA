    Biblioteca ServoMotor.h:

    É a responsável pelos comandos de controle dos motores do carrinho.
Além de utilizar a arduino.h, o programa também usufrui do servo.h para realizar os comandos: de se manter parado, ir para frente, trás, direita e esquerda. 


    Função Setup:

    Nesse código temos a função setup como uma inicialização dos comandos a serem executados. Dentro dela
utilizamos as portas (5,4) como as responsáveis por mandar as informações configuradas para os motores (direito, esquerdo). Dentro da mesma função, estabelecemos o comando para calibragem dos motores e definimos uma faixa média para calibrá-los. A velocidade do carrinho é definida a partir de uma variável chamada intensidade. Todos os movimentos são executados a partir de operações aritméticas dadas por uma relação de tempo em microsegundos e a intensidade desejada. 
    Movimentos como o de viraDireita, viraEsquerda, frente, ré e parado são definidos a partir do momento
inerte do carrinho somado/subtraído do valor pré-definido de intensidade, ou simplesmente não há soma/subtração de intensidade. 


    Função loop: 

    Essa função é responsável por chamar todos os comandos do motor e executá-los de forma contínua.


    Definição de cada função:

1. sm.frente(); 
   O motor rotaciona para frente.
2. sm.re();
   O motor rotaciona para trás.
3. sm.parado();
   O motor permanece parado.
4. sm.viraDireita();
   O motor rotaciona para a direita.
5. sm.viraEsquerda();
   O motor rotaciona para a esquerda.
