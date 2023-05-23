# Cpp-Project - Sudoku Solver (Portuguese Version Only)

Jogo: Sudoku
Objetivo do programa: Colocar o Sudoku pretendido no programa e ele auto resolvê-lo.
Objetivo do jogo:
Sudoku é um puzzle lógico de números cujo objetivo é colocar números de 1 a 9 em quadrados de uma grelha 9X9, constituída por subgrelhas 3X3, que se chamam regiões.
A grelha está parcialmente preenchida com números e é preciso completá-la com os restantes. Em cada coluna ou bloco têm de constar os números de 1 a 9 sem repetições.

Requisitos:
•	O jogo tem que ter 9 x 9 quadrados.
•	O utilizador terá que colocar os números e locais certos para que o programa possa completar.
•	O programa deve verificar se os números introduzidos estão nos sítios certos e se é possível solução ou não. 
•	O programa deve completar o puzzle e retornar a resolução do Sudoku.
 
O Programa

O Programa começar por pedir ao utilizador que indique linha por linha os números presentes no Sudoku que pretende resolver, sendo que o O é colocado quando não há nenhum número no quadrado indicado.

 
Todos esses números irão ficar guardados no respetivo vetor.
Após isso, todos os números guardados em cada vetor são colocados na respetiva linha da matriz.
 
	
Depois o programa corre todos os quadrados ( ou células) e sempre que encontra um espaço vazio (O número 0), substitui por um número que seja possível colocar (tendo em conta a linha e a coluna), por exemplo:
Imaginemos que temos o seguinte problema de Sudoku:

	5	3	*0*	0	7	0	0	0	0
	6	0	0	1	9	5	0	0	0
	0	9	8	0	0	0	0	6	0
	8	0	0	0	6	0	0	0	3
	4	0	0	8	0	3	0	0	1
	7	0	0	0	2	0	0	0	6
	0	6	0	0	0	0	2	8	0
	0	0	0	4	1	9	0	0	5
	0	0	0	0	8	0	0	7	9


O programa chega à posição assinalada (entre 2 *) e corre todos os números do 1 ao 9 e coloca o primeiro número possível tendo em conta os números presentes na linha e na coluna.
Neste caso colocaria o 1 uma vez que não existe na linha nem na coluna.
Depois o programa verifica em cada conjunto de 3*3 como assinalado com umas linhas mais escuras, se o número colocado existe nesses quadrados ou não.
Caso não exista o programa continua a funcionar como se nada fosse.
Sempre que o programa chega a um ponto que não há possibilidades, significa que algum dos números colocados estão na posição errada e então volta ao início e faz de novo, agora com uma ordem de números diferentes. 


User Cases / Sugestões

Devido ao tempo escasso para fazermos este projeto, há melhorias de código que poderia fazer mas não houve tempo, pelo que coloco aqui as melhorias que seriam as próximas a serem implementadas:


1.	Criação de uma função para:
Em vez de ter escrito os ciclos for para todas as 9 linhas do Sudoku (no final), fazia um programa que corre-se automaticamente quando o chamasse.

2.	Sempre que o user se engana, não há forma de modificar.
Se o utilizador se tivesse enganado num numero, o programa não o consegue editar, o user teria que reiniciar o programa. Neste caso a melhor solução seria colocar uma opção ao fim de cada linha para aceitar, rejeitar ou alterar a mesma.

3.	Melhoria de design
Obviamente não nos podemos esquecer da melhoria de design, que foi algo que não me foquei para que conseguisse pelo menos colocar o código a funcionar. 

4.	Arranjar uma forma mais prática de colocar o Sudoku.
Como conseguimos ver pela imagem, é pedido um número 1 a 1. E torna-se exaustivo colocar os 81 números de que faz parte o Sudoku. E estamos sempre sujeitos a erros uma vez que é muita informação que estamos a colocar.




