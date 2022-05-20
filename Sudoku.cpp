#include <iostream>
#include <vector>
#include <locale>
#include <list>



using namespace std;


// --------------------------------------- Função para dar print do board---------------------------------------

void printSudoku(int arr[9][9])
{
	cout << "----------------------------------" << endl;

	for (int r = 0; r < 9; r++) // por cada row
	{
		for (int pos = 0; pos < 9; pos++) // corre uma posição
		{
			cout << arr[r][pos] << " ";
		}
		cout << endl; // para separar as rows em diferentes linhas
	}

	cout << "----------------------------------" << endl;
}


//----------------------- Verificar se em cada posição (pos) posso colocar determinado numero ------------------------------

bool possoColocar(int arr[9][9], int row, int col, int x)
{
	// verificar se já tem um número preenchido (quando não tem, aparece 0)
	if (arr[row][col] != 0) return false; 

	//verificar cada row, col e pos
	bool status = true; // para posteriormente mudar para false se não conseguir colocar um numero

	int gridx = (col / 3) * 3; // a coluna a dividir por 3 para determinar cada celula, ou seja cada conjunto de 9 quadrados do sudoku.
	// sendo que se estivermos na coluna 5 ( 5/3 = 1.6666 = 1, logo faz parte da segunda célula (visto que a primeira = 0). A multiplicar por 3 porque são 3 linhas.
	int gridy = (row / 3) * 3; // a linha a dividir por 3 para determinar cada celula, ou seja cada conjunto de 9 quadadros do sudoku; A multiplicar por 3 porque são 3 linhas.

	for (int i = 0; i < 9; i++)
	{
		// se na row já se encontrar o numero x, o status é alterado para false e há um break
		if (arr[row][i] == x) { status = false; break; }
		// se na colun já se encontrar o numero x, o status é alterado para false e há um break
		if (arr[i][col] == x) { status = false; break; }

		if (arr[gridy + i / 3][gridx + i % 3] == x) { status = false; break; } // Vai correr todos os numeros de 0 a 9 na posição de i e retornar em que celula estamos no sudoku.
		// retorna valores como 00- primeira linha e primeira coluna
		//01 - primeira linha e segunda coluna
		// 02 - primeira linha e terceira coluna

	}
	return status;
}

// ------------------------Criar uma função para colocar num vetor os numeros possiveis de colocar numa determinada celula ---------------------------------------


vector<int> numerosPossiveis(int arr[9][9], int r, int pos)
{
	vector<int> cps = {};
	for (int i = 1; i <= 9; i++)
	{
		if (possoColocar(arr, r, pos, i))
			cps.push_back(i);
	}
	return cps;
}

// -------------------------------------------------------Função para copiar o Arr [9][9] --------------------------------------------------------------------


void copiarArr(int arr[9][9], int arrCopia[9][9])
{
	for (int k = 0; k < 9; k++)
		for (int l = 0; l < 9; l++)
			arrCopia[k][l] = arr[k][l]; // desta forma vai copiar todos os numeros que o array tem para uma cópia
}
// se a solução resolver o sudoku copiamos o array copia para o original- desta forma não alteramos diretamente no original, mas numa copia que depois passará para
//o original assim que esteja finalizado



// ----------------------------------------------------- Função para descobrir a proxima Row e proxima Col que defini anteriormente---------------------------------------

void proximoVazio(int arr[9][9], int row, int col, int& proxRow, int& proxCol)
// utilizamos as referencias para que as variavies sejam modificadas e não as copias que chamamos para esta função.
{
	int index = 9 * 9; // isto para tratarmos de cada celula isoladamente (cada quadradinho) - que vai de 0 a 80
	// o resultado 81 é propositado porque significa que o programa ja acabou de correr todas as celulas.

	// loop para correr todas as posições segundo as linhas e colunas e ver onde está o proximo 0:
	for (int i = row * 9 + col + 1; i < 9 * 9; i++)
	{
		if (arr[i / 9][i % 9] == 0) // i/9 para o numero da linha e i%9 para o numero da coluna
		{
			index = i;
			break;
		}
	}
	proxRow = index / 9;
	proxCol = index % 9;
}



// --------------------------------------------------------- Ver se dá para resolver todo o Sudoku ou não -------------------------------------------------

bool resolve(int arr[9][9], int row, int col) // retorna True se estiver resolvido, e False se não.
// É uma função recursiva que se vai chamar a ela própria de forma a que consiga ver todas as possibilidades
{
	if (row > 8) return true; // isto quando o sudoku está resolvido, porque programa ja resolveu todas as rows
	// esta linha é para que o programa não caia num loop infinito, e esta é a linha para parar.

	if (arr[row][col] != 0)
	{
		int proxCol; // ainda preciso de uma função para os descobrir. está a seguir
		int proxRow;

		proximoVazio(arr, row, col, proxRow, proxCol);
		return resolve(arr, proxRow, proxCol);
	}

	vector<int> possibilidades = numerosPossiveis(arr, row, col);

	// Verificar se temos de facto algum numeros possivel:
	if (possibilidades.size() == 0) return false; // se não tivermos, retorna falso.

	//defenir o status como falso para que possamos fazer os if's ao contrário
	bool status = false;

	for (int i = 0; i < possibilidades.size(); i++) // enquanto o i for menor que a quantidade dos numeros possiveis:
	{
		int n = possibilidades[i]; // introduzimos um numero n que irá correr todos os numeros do vector possibilidades

		int arrCopia[9][9];
		copiarArr(arr, arrCopia);
		arrCopia[row][col] = n;

		int proxCol; // ainda preciso de uma função para os descobrir. está a seguir
		int proxRow;

		proximoVazio(arrCopia, row, col, proxRow, proxCol);

		if (resolve(arrCopia, proxRow, proxCol))
		{
			copiarArr(arrCopia, arr); // se a solução resolver o sudoku copiamos o array copia para o original.
			status = true; // mudamos o status para true para finalmente indicar que o sukodu está resolvido
			break; // e damos break para sair do loop
		}
	}
	
	return status;
}




int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	cout << "BEM-VINDO AO SUDOKU" << endl;
	
	cout << "Para colocar o Sudoku deve escrever cada linha da seguinte forma:" << endl;
	cout << "{5,3,0,0,7,0,0,0,0}" << endl;
	cout << "em que o O é um espaço vazio" << endl;

	
	//int arr[9 linha1, linha2, linha3, linha4, linha5, linha6, linha7, linha8, linha9;

	/*int arr[9][9] =
	{
		{list<int> linha1},
		{linha2},
		{linha3},
		{linha4},
		{linha5},
		{linha6},
		{linha7},
		{linha8},
		{linha9},
	};
	*/

	vector<int> linha1;
	vector<int> linha2;
	vector<int> linha3;
	vector<int> linha4;
	vector<int> linha5;
	vector<int> linha6;
	vector<int> linha7;
	vector<int> linha8;
	vector<int> linha9;

	int board[9][9];

	const int cinTerminator = -1;
	int size = 9;
	int data;

	//------------------------  Linha 1  --------------------------
	
	cout << "Por favor, insira a linha 1 do Sudoku que pretende resolver\n" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Coloque o número: ";
		cin >> data;
		linha1.push_back(data); // para colocar todos os numeros num vector
	}

	for (int i = 0; i < 9; i++) // correr todos os numeors do vector
	{
		board[0][i] = linha1[i]; // e colocá-los no respetivo quadrado do Sudoku
	}

	//------------------------  Linha 2  --------------------------

	cout << "Insira a linha 2 do Sudoku que pretende resolver\n" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Coloque o número: ";
		cin >> data;
		linha2.push_back(data);
	}

	for (int i = 0; i < 9; i++)
	{
		board[1][i] = linha2[i];
	}

	//------------------------  Linha 3  --------------------------

	cout << "Insira a linha 3 do Sudoku que pretende resolver\n" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Coloque o número: ";
		cin >> data;
		linha3.push_back(data);
	}

	for (int i = 0; i < 9; i++)
	{
		board[2][i] = linha3[i];
	}

	//------------------------  Linha 4  --------------------------

	cout << "Iinsira a linha 4 do Sudoku que pretende resolver\n" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Coloque o número: ";
		cin >> data;
		linha4.push_back(data);
	}
	
	for (int i = 0; i < 9; i++)
	{
		board[3][i] = linha4[i];
	}

	//------------------------  Linha 5  --------------------------

	cout << "Insira a linha 5 do Sudoku que pretende resolver\n" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Coloque o número: ";
		cin >> data;
		linha5.push_back(data);
	}

	for (int i = 0; i < 9; i++)
	{
		board[4][i] = linha5[i];
	}

	//------------------------  Linha 6  --------------------------

	cout << "Insira a linha 6 do Sudoku que pretende resolver\n" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Coloque o número: ";
		cin >> data;
		linha6.push_back(data);
	}

	for (int i = 0; i < 9; i++)
	{
		board[5][i] = linha6[i];
	}

	//------------------------  Linha 7  --------------------------

	cout << "Insira a linha 7 do Sudoku que pretende resolver\n" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Coloque o número: ";
		cin >> data;
		linha7.push_back(data);
	}
	for (int i = 0; i < 9; i++)
	{
		board[6][i] = linha7[i];
	}

	//------------------------  Linha 8  --------------------------

	cout << "Insira a linha 8 do Sudoku que pretende resolver\n" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Coloque o número: ";
		cin >> data;
		linha8.push_back(data);
	}

	for (int i = 0; i < 9; i++)
	{
		board[7][i] = linha8[i];
	}

	//------------------------  Linha 9  --------------------------

	cout << "Insira a linha 9 do Sudoku que pretende resolver\n" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Coloque o número: ";
		cin >> data;
		linha9.push_back(data);
	}

	for (int i = 0; i < 9; i++)
	{
		board[8][i] = linha9[i];
	}

	printSudoku(board);

	cout << "A resolução para este Sudoku é:" << endl;
	resolve(board, 0, 0);
	printSudoku(board);
	


	// criar o board; hard code para saber se funciona
	/*
	int board[9][9] =
	{
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9},
	};
	
	printSudoku(board);
	resolve(board, 0, 0);
	printSudoku(board);
	
	*/
}