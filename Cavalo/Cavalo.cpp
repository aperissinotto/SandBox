#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <iomanip>

using std::setw;

int main() {
	// cria tabuleiro
	char tabuleiro[8][8];
	int passeio[8][8];

	// heuristica
	int tabMov[8][8];

	// cria movimentos
	int horizontal[8];
	int vertical[8];

	// inicializa movimentos horizontais
	horizontal[0] = 2;
	horizontal[1] = 1;
	horizontal[2] = -1;
	horizontal[3] = -2;
	horizontal[4] = -2;
	horizontal[5] = -1;
	horizontal[6] = 1;
	horizontal[7] = 2;
	// inicializa movimentos verticais
	vertical[0] = -1;
	vertical[1] = -2;
	vertical[2] = -2;
	vertical[3] = -1;
	vertical[4] = 1;
	vertical[5] = 2;
	vertical[6] = 2;
	vertical[7] = 1;

	int linha, coluna;
	// inicializa tabuleiro
	for (linha = 0; linha <= 7; linha++) {
		for (coluna = 0; coluna <= 7; coluna++) {
			tabuleiro[linha][coluna] = 'N';
			passeio[linha][coluna] = 0;
		}
	}

	for (linha = 0; linha <= 7; linha++) {
		for (coluna = 0; coluna <= 7; coluna++) {
			if (linha == 0 || linha == 7) {
				if (coluna == 0 || coluna == 7) {
					tabMov[linha][coluna] = 2;
				}
				else {
					if (coluna == 1 || coluna == 6) {
						tabMov[linha][coluna] = 3;
					}
					else {
						tabMov[linha][coluna] = 4;
					}
				}
			}
			else {
				if (linha == 1 || linha == 6) {
					if (coluna == 0 || coluna == 7) {
						tabMov[linha][coluna] = 3;
					}
					else {
						if (coluna == 1 || coluna == 6) {
							tabMov[linha][coluna] = 4;
						}
						else {
							tabMov[linha][coluna] = 6;
						}
					}
				}
				else {
					if (coluna == 0 || coluna == 7) {
						tabMov[linha][coluna] = 4;
					}
					else {
						if (coluna == 1 || coluna == 6) {
							tabMov[linha][coluna] = 6;
						}
						else {
							tabMov[linha][coluna] = 8;
						}
					}
				}
			}
		}
	}

	int qtdMov = 1;
	int newPosL, newPosC;
	int posL = 1;
	int posC = 0;
	int varreMovimentos = 0;
	int proxMovimento = 0;
	int workTabMov = 9;

	// posiciona o cavalo 
	tabuleiro[posL][posC] = 'C';
	// atualiza a heuristica
	tabMov[posL][posC] = 0;

	while (qtdMov < 64) {
		workTabMov = 9;
		for (varreMovimentos = 0; varreMovimentos <= 7; varreMovimentos++) {
			newPosL = posL + vertical[varreMovimentos];
			newPosC = posC + horizontal[varreMovimentos];
			if (newPosL >= 0 && newPosL <= 7 && newPosC >= 0 && newPosC <= 7 && tabuleiro[newPosL][newPosC] != 'C') {
				if (tabMov[newPosL][newPosC] > 0 && tabMov[newPosL][newPosC] < workTabMov) {
					workTabMov = tabMov[newPosL][newPosC];
					proxMovimento = varreMovimentos;

				}
			}
		}

		if (workTabMov == 9) { break; }

		newPosL = posL + vertical[proxMovimento];
		newPosC = posC + horizontal[proxMovimento];

		tabuleiro[newPosL][newPosC] = 'C';
		tabMov[newPosL][newPosC] = 0;
		tabMov[posL][posC] = 0;
		posL = newPosL;
		posC = newPosC;
		passeio[posL][posC] = qtdMov;
		qtdMov++;
	}

	cout << "Quantidade de movimentos=" << qtdMov << endl;

	for (linha = 0; linha <= 7; linha++) {
		for (coluna = 0; coluna <= 7; coluna++) {
			cout << tabuleiro[linha][coluna] << " ";
		}
		cout << "\n";
	}

	for (linha = 0; linha <= 7; linha++) {
		for (coluna = 0; coluna <= 7; coluna++) {
			cout << setw(3) << passeio[linha][coluna] << " ";
		}
		cout << "\n";
	}
}