#include <iostream>
#include <ctime>
#include <cstdlib> // Para usar a função rand()
using namespace std;

const int LINHAS = 6;
const int COLUNAS = 6;

// Função para imprimir a matriz do jogo
void imprimir_matriz(int m[LINHAS][COLUNAS], int qtdLinhas, int qtdColunas) {
    for (int i = 0; i < qtdColunas; i++) {
        cout << '\t' << i;
    }
    cout << endl;
    for (int l = 0; l < qtdLinhas; l++) {
        cout << l;
        for (int c = 0; c < qtdColunas; c++) {
            if (m[l][c] == 100) {
                cout << "\t#";
            } else if (m[l][c] == 200) {
                cout << "\tx";
            } else {
                cout << '\t' << m[l][c];
            }
        }
        cout << endl;
    }
}

int main() {
    cout << "\tBem-vindo ao nosso jogo da velha!";
    system("pause");
    system("cls");

    int desisao;
    cout << "\tcaso você se sinta avontade digite (1) para jogar mas se não quiser digite (2) para sair."
         << "\tO que você deseja?";

    cin >> desisao;

    switch (desisao) {
    case 1:
        cout << "Obaa!! bora lá!!" << endl;
        break;
    case 2:
        cout << "Que pena. até a próxima!" << endl;
        return 0;
    }

    system("pause");
    system("cls");

    int m[LINHAS][COLUNAS] = {0};
    int qtd_linhas, qtd_colunas, opcao = 0;
    int jogador1 = 100, jogador2 = 200;
    int jogador_atual;
    bool jogo_terminou = false;
    bool computador_defensivo = false; // Flag para postura defensiva do computador

    do {
        cout << "\tDigite (1) para jogar em dupla;\n"
             << "\tDigite (2) para jogar contra o computador;\n"
             << "\tDigite (3) para ir até a seção sobre;\n"
             << "\tE digite (0) para encerrar o jogo.\n"
             << "\tQual é a sua opção?";
        cin >> opcao;

        int l = 0, c = 0;

        switch (opcao) {
        case 1: // Jogar em dupla
            cout << "\tDigite 1 para ser o jogador (#) e 2 para ser o (x)\n"
                 << "\tqual jogador você quer ser?";
            cin >> opcao;

            if (opcao == 1) {
                cout << "\nParabens você o jogador (#) e seu amigo é o (x)\n"
                     << "No jogo você sera representado pelo número 100 e seu amigo pelo 200." << endl;
            } else if (opcao == 2) {
                cout << "\tParabens você é o jogador (x) e seu amigo é o (#)\n"
                     << "\tVocê sera representado no jogo pelo número 200 e seu amigo sera o número 100" << endl;
            } else {
                cout << "\tDigite uma opção válida." << endl;
                break; // Sai do case 1 se a opção for inválida
            }

            // Escolher o tamanho do tabuleiro
            cout << "\tAgora escolha o tabuleiro.\n"
                 << "\tDigite um para tabuleiro simples com (3) linhas e (3) colunas;\n"
                 << "\tDigite 2 para tabuleiro intermediario com 6 linhas e colunas;\n"
                 << "\tE digite 3 para tabuleiro ampliado que é 9 x 9.\n"
                 << "\tQual é a sua opção?";
            cin >> opcao;

            switch (opcao) {
            case 1:
                qtd_linhas = 3;
                qtd_colunas = 3;
                break;
            case 2:
                qtd_linhas = 6;
                qtd_colunas = 6;
                break;
            case 3:
                qtd_linhas = 9;
                qtd_colunas = 9;
                break;
            default:
                cout << "\nDigite uma opção válida." << endl;
                break; // Sai do case 1 se a opção for inválida
            }

            // Escolher jogador inicial aleatoriamente
            srand(time(0));
            jogador_atual = (rand() % 2) + 1;
            cout << "O jogador " << jogador_atual << " começa!" << endl;

            // Loop principal do jogo em dupla
            while (!jogo_terminou) {
                imprimir_matriz(m, qtd_linhas, qtd_colunas);

                // Jogada do jogador atual
                if (jogador_atual == 1) {
                    cout << "Jogador #, digite a linha e coluna que você deseja (separadas por espaço): ";
                    cin >> l >> c;

                    // Validar a posição
                    while (l < 0 || l >= qtd_linhas || c < 0 || c >= qtd_colunas || m[l][c] != 0) {
                        cout << "Posição inválida. Tente novamente: ";
                        cin >> l >> c;
                    }

                    m[l][c] = jogador1;
                } else {
                    cout << "Jogador x, digite a linha e coluna que você deseja (separadas por espaço): ";
                    cin >> l >> c;

                    // Validar a posição
                    while (l < 0 || l >= qtd_linhas || c < 0 || c >= qtd_colunas || m[l][c] != 0) {
                        cout << "Posição inválida. Tente novamente: ";
                        cin >> l >> c;
                    }

                    m[l][c] = jogador2;
                }

                // Verificar se o jogo terminou (linha, coluna, diagonais)
                for (int i = 0; i < qtd_linhas; i++) {
                    // Verificar linhas
                    if (m[i][0] == m[i][1] && m[i][1] == m[i][2] && m[i][0] != 0) {
                        jogo_terminou = true;
                        if (m[i][0] == jogador1) {
                            cout << "Jogador # venceu!" << endl;
                        } else {
                            cout << "Jogador x venceu!" << endl;
                        }
                    }
                    // Verificar colunas
                    if (m[0][i] == m[1][i] && m[1][i] == m[2][i] && m[0][i] != 0) {
                        jogo_terminou = true;
                        if (m[0][i] == jogador1) {
                            cout << "Jogador # venceu!" << endl;
                        } else {
                            cout << "Jogador x venceu!" << endl;
                        }
                    }
                }
                // Verificar diagonais
                if ((m[0][0] == m[1][1] && m[1][1] == m[2][2] && m[0][0] != 0) ||
                    (m[0][2] == m[1][1] && m[1][1] == m[2][0] && m[0][2] != 0)) {
                    jogo_terminou = true;
                    if (m[1][1] == jogador1) {
                        cout << "Jogador # venceu!" << endl;
                    } else {
                        cout << "Jogador x venceu!" << endl;
                    }
                }

                // Verificar empate
                if (!jogo_terminou) {
                    int contador = 0;
                    for (int i = 0; i < qtd_linhas; i++) {
                        for (int j = 0; j < qtd_colunas; j++) {
                            if (m[i][j] != 0) {
                                contador++;
                            }
                        }
                    }
                    if (contador == qtd_linhas * qtd_colunas) {
                        jogo_terminou = true;
                        cout << "Empate!" << endl;
                    }
                }

            }
            break; // Sai do case 1 após o jogo terminar
        case 2: // Jogar contra o computador
            cout << "\tDigite 1 para ser o jogador (#) e 2 para ser o (x)\n"
                 << "\tqual jogador você quer ser?";
            cin >> opcao;

            if (opcao == 1) {
                cout << "\nParabens você o jogador (#) e o computador será o (x)\n"
                     << "No jogo você sera representado pelo número 100 e o coputador pelo 200." << endl;
                computador_defensivo = true; // O computador será defensivo
            } else if (opcao == 2) {
                cout << "\tParabens você é o jogador (x) e o computador o (#)\n"
                     << "\tVocê sera representado no jogo pelo número 200 e o computador sera o número 100" << endl;
            } else {
                cout << "\tDigite uma opção válida." << endl;
                break; // Sai do case 2 se a opção for inválida
            }

            // Escolher o tamanho do tabuleiro
            cout << "\tAgora escolha o tabuleiro.\n"
                 << "\tDigite um para tabuleiro simples com (3) linhas e (3) colunas;\n"
                 << "\tDigite 2 para tabuleiro intermediario com 6 linhas e colunas;\n"
                 << "\tE digite 3 para tabuleiro ampliado que é 9 x 9.\n"
                 << "\tQual é a sua opção?";
            cin >> opcao;

            switch (opcao) {
            case 1:
                qtd_linhas = 3;
                qtd_colunas = 3;
                break;
            case 2:
                qtd_linhas = 6;
                qtd_colunas = 6;
                break;
            case 3:
                qtd_linhas = 9;
                qtd_colunas = 9;
                break;
            default:
                cout << "\nDigite uma opção válida." << endl;
                break; // Sai do case 2 se a opção for inválida
            }

            // Escolher jogador inicial aleatoriamente
            srand(time(0));
            jogador_atual = (rand() % 2) + 1;
            cout << "O jogador " << jogador_atual << " começa!" << endl;

            // Loop principal do jogo contra o computador
            while (!jogo_terminou) {
                imprimir_matriz(m, qtd_linhas, qtd_colunas);

                // Jogada do jogador atual
                if (jogador_atual == 1) {
                    cout << "Jogador #, digite a linha e coluna que você deseja (separadas por espaço): ";
                    cin >> l >> c;

                    // Validar a posição
                    while (l < 0 || l >= qtd_linhas || c < 0 || c >= qtd_colunas || m[l][c] != 0) {
                        cout << "Posição inválida. Tente novamente: ";
                        cin >> l >> c;
                    }

                    m[l][c] = jogador1;
                } else {
                    // Lógica do computador
                    cout << "Computador jogando..." << endl;
                    if (computador_defensivo) {
                        // Lógica defensiva
                        // Buscar posição válida para bloquear
                        for (int i = 0; i < qtd_linhas; i++) {
                            for (int j = 0; j < qtd_colunas; j++) {
                                if (m[i][j] == 0) {
                                    // Bloqueio de Linha
                                    if ((i > 0 && m[i - 1][j] == jogador1 && m[i + 1][j] == jogador1) ||
                                        (i > 0 && m[i - 1][j] == jogador1 && m[i][j + 1] == jogador1) ||
                                        (i > 0 && m[i - 1][j] == jogador1 && m[i][j - 1] == jogador1) ||
                                        (i < qtd_linhas - 1 && m[i + 1][j] == jogador1 && m[i][j + 1] == jogador1) ||
                                        (i < qtd_linhas - 1 && m[i + 1][j] == jogador1 && m[i][j - 1] == jogador1) ||
                                        (j > 0 && m[i][j - 1] == jogador1 && m[i][j + 1] == jogador1)) {
                                        l = i;
                                        c = j;
                                        m[l][c] = jogador2;
                                        goto fim_jogada_computador; // Sai do loop
                                    }
                                    // Bloqueio de Coluna
                                    if ((j > 0 && m[i][j - 1] == jogador1 && m[i][j + 1] == jogador1) ||
                                        (j > 0 && m[i][j - 1] == jogador1 && m[i + 1][j] == jogador1) ||
                                        (j > 0 && m[i][j - 1] == jogador1 && m[i - 1][j] == jogador1) ||
                                        (j < qtd_colunas - 1 && m[i][j + 1] == jogador1 && m[i + 1][j] == jogador1) ||
                                        (j < qtd_colunas - 1 && m[i][j + 1] == jogador1 && m[i - 1][j] == jogador1) ||
                                        (i > 0 && m[i - 1][j] == jogador1 && m[i + 1][j] == jogador1)) {
                                        l = i;
                                        c = j;
                                        m[l][c] = jogador2;
                                        goto fim_jogada_computador; // Sai do loop
                                    }
                                    // Bloqueio de Diagonal Principal
                                    if ((i > 0 && j > 0 && m[i - 1][j - 1] == jogador1 && m[i + 1][j + 1] == jogador1) ||
                                        (i < qtd_linhas - 1 && j < qtd_colunas - 1 && m[i + 1][j + 1] == jogador1 && m[i - 1][j - 1] == jogador1) ||
                                        (i > 0 && j < qtd_colunas - 1 && m[i - 1][j + 1] == jogador1 && m[i + 1][j - 1] == jogador1) ||
                                        (i < qtd_linhas - 1 && j > 0 && m[i + 1][j - 1] == jogador1 && m[i - 1][j + 1] == jogador1)) {
                                        l = i;
                                        c = j;
                                        m[l][c] = jogador2;
                                        goto fim_jogada_computador; // Sai do loop
                                    }
                                    // Bloqueio de Diagonal Secundaria
                                    if ((i > 0 && j < qtd_colunas - 1 && m[i - 1][j + 1] == jogador1 && m[i + 1][j - 1] == jogador1) ||
                                        (i < qtd_linhas - 1 && j > 0 && m[i + 1][j - 1] == jogador1 && m[i - 1][j + 1] == jogador1) ||
                                        (i > 0 && j > 0 && m[i - 1][j - 1] == jogador1 && m[i + 1][j + 1] == jogador1) ||
                                        (i < qtd_linhas - 1 && j < qtd_colunas - 1 && m[i + 1][j + 1] == jogador1 && m[i - 1][j - 1] == jogador1)) {
                                        l = i;
                                        c = j;
                                        m[l][c] = jogador2;
                                        goto fim_jogada_computador; // Sai do loop
                                    }
                                }
                            }
                        }
                        // Se nenhuma posição válida for encontrada para bloquear, escolher uma aleatoriamente
                        srand(time(0));
                        l = rand() % qtd_linhas;
                        c = rand() % qtd_colunas;
                        while (m[l][c] != 0) {
                            l = rand() % qtd_linhas;
                            c = rand() % qtd_colunas;
                        }
                        m[l][c] = jogador2;
                    } else {
                        // Lógica ofensiva
                        // Escolha aleatória para o computador
                        srand(time(0));
                        l = rand() % qtd_linhas;
                        c = rand() % qtd_colunas;
                        while (m[l][c] != 0) {
                            l = rand() % qtd_linhas;
                            c = rand() % qtd_colunas;
                        }
                        m[l][c] = jogador2;
                    }
fim_jogada_computador: ; // Rótulo para sair do loop
                }

                // Verificar se o jogo terminou (linha, coluna, diagonais)
                for (int i = 0; i < qtd_linhas; i++) {
                    // Verificar linhas
                    if (m[i][0] == m[i][1] && m[i][1] == m[i][2] && m[i][0] != 0) {
                        jogo_terminou = true;
                        if (m[i][0] == jogador1) {
                            cout << "Jogador # venceu!" << endl;
                        } else {
                            cout << "Jogador x venceu!" << endl;
                        }
                    }
                    // Verificar colunas
                    if (m[0][i] == m[1][i] && m[1][i] == m[2][i] && m[0][i] != 0) {
                        jogo_terminou = true;
                        if (m[0][i] == jogador1) {
                            cout << "Jogador # venceu!" << endl;
                        } else {
                            cout << "Jogador x venceu!" << endl;
                        }
                    }
                }
                // Verificar diagonais
                if ((m[0][0] == m[1][1] && m[1][1] == m[2][2] && m[0][0] != 0) ||
                    (m[0][2] == m[1][1] && m[1][1] == m[2][0] && m[0][2] != 0)) {
                    jogo_terminou = true;
                    if (m[1][1] == jogador1) {
                        cout << "Jogador # venceu!" << endl;
                    } else {
                        cout << "Jogador x venceu!" << endl;
                    }
                }

                // Verificar empate
                if (!jogo_terminou) {
                    int contador = 0;
                    for (int i = 0; i < qtd_linhas; i++) {
                        for (int j = 0; j < qtd_colunas; j++) {
                            if (m[i][j] != 0) {
                                contador++;
                            }
                        }
                    }
                    if (contador == qtd_linhas * qtd_colunas) {
                        jogo_terminou = true;
                        cout << "Empate!" << endl;
                    }
                }

                // Mudar o jogador
                jogador_atual = (jogador_atual == 1) ? 2 : 1;
            }
            break; // Sai do case 2 após o jogo terminar
        case 3:
            cout << "\tJogo desenvolvido por gabriel Samersla merçoni para a matéria de algoritmos 1 do professor Eduardo Alves da Silva." << endl;
            break;
        case 0:
            cout << "\tAté a próxima!";
            return 0;
        default:
            cout << "\tDigite uma opção válida." << endl;
            break;
        }
    } while (opcao != 0);

    return 0;
}