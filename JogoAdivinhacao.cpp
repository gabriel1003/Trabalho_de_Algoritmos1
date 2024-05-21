#include <iostream>
#include <ctime>

using namespace std;

int main() {
    system("cls");
    cout << "\tBem-vindo ao jogo de advinhação mais casca grossa que você já jogou.";
    system("pause");
    system("cls");

    char desisao;
    cout << "\tEste jogo consiste em três fazes, a cada faze ele se torna mais difícil trazendo,\n"
    << "desafios mais arriscados.\n"
    << "O objetivo é descobrir qual é a senha criada pelo jogo. Se você estiver preparado\n"
    << "vamos começar a jogar.\n"
    << "\tDigite (s) para sim e (n) para não.";
    cin >> desisao;

    switch (desisao) {
        case 's':
        cout << "\nParabens por sua coragen" << endl;
        break;
        case 'n':
        cout << "\nQue pena, até a próxima " << endl;
        return 0;
        break;
        default :
        cout << "\nDigite uma opção válida! " << endl;
        break;
    }

    system("pause");
    system("cls");

    int opcao, dificuldade, numDigitos, tentativas, i, posicaoCorreto, digitosCorretos;
    bool jogoAtivo = false;

    // Variáveis para armazenar dígitos individualmente
    int codigo1, codigo2, codigo3, codigo4, codigo5;
    int palpite1, palpite2, palpite3, palpite4, palpite5;

    while (true) {
        //Menu de opções
        cout << "\tDigite\n"
        << "\t(1) para jogar\n"
        << "\t(2) para escolher o nível de dificuldade do jogo\n"
        << "\t(3) para entrar  na seção sobre\n"
        << "\t(4) para finalisar o jogo.\n"
        << "\tQual é a sua opção? ";
        cin >> opcao;

        switch (opcao) {
         case 1: // Jogar
            if (!jogoAtivo) {
                // Geração do código secreto (usando variáveis individuais)
                srand(time(NULL));
                switch (dificuldade) {
                    case 1: 
                        numDigitos = 3;
                        tentativas = 8;

                        // Geração de 3 dígitos distintos
                        do {
                            codigo1 = rand() % 6 + 1;
                            codigo2 = rand() % 6 + 1;
                            codigo3 = rand() % 6 + 1;
                        } while (codigo1 == codigo2 || codigo1 == codigo3 || codigo2 == codigo3);
                        break;
                    case 2:
                        // ... (lógica semelhante para dificuldade média com 4 dígitos)
                        numDigitos = 4;
                        tentativas = 10;

                        do {
                          codigo1 = rand() % 6 + 1;
                            codigo2 = rand() % 6 + 1;
                            codigo3 = rand() % 6 + 1;
                            codigo4 = rand() % 6 + 1;
                        } while (codigo1 == codigo2 || codigo1 == codigo3 || codigo1 == codigo4 || codigo2 == codigo3 || codigo2 == codigo4 || codigo3 == codigo4);
                        break;
                    case 3: 
                        // ... (lógica semelhante para dificuldade difícil com 5 dígitos)
                        numDigitos = 5;
                        tentativas = 12;
                        
                        do {
                          codigo1 = rand() % 6 + 1;
                            codigo2 = rand() % 6 + 1;
                            codigo3 = rand() % 6 + 1;
                            codigo4 = rand() % 6 + 1;
                            codigo5 = rand() % 6 + 1;
                        } while (codigo1 == codigo2 || codigo1 == codigo3 || codigo1 == codigo4 || codigo1 == codigo5 || codigo2 == codigo3 || codigo2 == codigo4 || codigo2 == codigo5 || codigo3 == codigo4 || codigo3 == codigo5 || codigo4 == codigo5);
                        
                        break;
                        default :
                        cout << "\nDigite uma opção válida! " << endl;
                        break;
                }

                jogoAtivo = true;
            }

            while (jogoAtivo) {
                // Entrada do palpite (usando variáveis individuais)
                cout << "Digite seu palpite de " << numDigitos << " digitos: ";

    cout << "\tDigite o primeiro dígito! ";
    cin >> palpite1;
    while (palpite1 < 1 || palpite1 > 6) {
        cout << "\tDigite um dígito válido. ";
        cin >> palpite1;
}
    
cout << "\tDigite o segundo dígito. ";
cin >> palpite2;

while (numDigitos >= 2 && (palpite2 < 1 || palpite2 == palpite1 || palpite2 > 6)) {
    cout << "\tDigite um dígito válido! ";

} 

cout << "\tDigite o terceiro dígito! ";
cin >> palpite3;
while (numDigitos >= 3 && (palpite3 < 1 || palpite3 == palpite1 || palpite3 == palpite2 || palpite3 > 6)) {
    cout << "\tDigite um dígito válido! ";
;
} 

cout << "\tDigite o quarto dígito! ";
cin >> palpite4;

while (numDigitos >= 4 && (palpite4 < 1 || palpite4 == palpite1 || palpite4 == palpite2 || palpite4 == palpite3 || palpite4 > 6)) {
    cout << "\tDigite um dígito válido! ";
 
} 

cout << "\tDigite o quinto dígito! ";
cin >> palpite5;

while (numDigitos >= 5 && (palpite5 < 1 || palpite5 == palpite1 || palpite5 == palpite2 || palpite5 == palpite3 || palpite5 == palpite4 || palpite5 > 6)) {
    cout << "\tDigite um dígito válido! ";
 
}

//                        if (numDigitos >= 1) cin >> palpite1;
//        if (numDigitos >= 2) cin >> palpite2;//
//        if (numDigitos >= 3) cin >> palpite3;
//        if (numDigitos >= 4) cin >> palpite4;
//        if (numDigitos >= 5) cin >> palpite5;

                // Verificação do palpite 
posicaoCorreto = 0; //Reinicia a variável como zero a cada interação
digitosCorretos = 0; //Reinicia a variável a cada interação para verificar quantos números digitados estão corretos.

        if (palpite1 == codigo1) posicaoCorreto++;
        if (numDigitos >= 2 && palpite2 == codigo2) posicaoCorreto++;
        if (numDigitos >= 3 && palpite3 == codigo3) posicaoCorreto++;
        if (numDigitos >= 4 && palpite4 == codigo4) posicaoCorreto++;
        if (numDigitos >= 5 && palpite5 == codigo5) posicaoCorreto++;

//Código para verificar quais números digitados estão corretos
if (palpite1 == codigo2 || palpite1 == codigo3 || palpite1 == codigo4 || palpite1 == codigo5) digitosCorretos++;
if (numDigitos >= 2 && (palpite2 == codigo1 || palpite2 == codigo3 || palpite2 == codigo4 || palpite2 == codigo5)) digitosCorretos++;
if (numDigitos >= 3 && (palpite3 == codigo1 || palpite3 == codigo2 || palpite3 == codigo4 || palpite3 == codigo5)) digitosCorretos++;
if (numDigitos >= 4 && (palpite4 == codigo1 || palpite4 == codigo2 || palpite4 == codigo3 || palpite4 == codigo5)) digitosCorretos++;
if (numDigitos >= 5 && (palpite5 == codigo1 || palpite5 == codigo2 || palpite5 == codigo3 || palpite5 == codigo4)) digitosCorretos++;

        if (posicaoCorreto == numDigitos) {
            cout << "Parabéns! Você venceu!\n";
            jogoAtivo = false;
        } else {
            cout << "\nvocê acertou: " << digitosCorretos << " dígitos.\n"
            <<  "e " << posicaoCorreto << " esta na posição correta.\n";
            tentativas--;
            cout << "E você tem: " << tentativas << " tentativas." << endl;

            if (tentativas == 0) {
                cout << "Você perdeu! O código era: ";
                cout << codigo1 << " ";
                if (numDigitos >= 2) cout << codigo2 << " ";
                if (numDigitos >= 3) cout << codigo3 << " ";
                if (numDigitos >= 4) cout << codigo4 << " ";
                if (numDigitos >= 5) cout << codigo5 << " ";
                cout << endl;
                jogoAtivo = false;
            }
        }
            }

            break;
case 2:
//Codigo para averiguar o nível desejado pelo jogador
cout << "\t(1) nível fácil \n"
<<"\t(Este nível consiste em acertar uma senha de 3 dígitos e você tem somente 8 tentativas para isso.)\n"
<< "\t(2) nível intermediario\n"
<< "\t(Este nível consiste em ter que acertar uma cenha de 4 dígitos e você tem somente 10 tentativas para isso.)\n"
<< "\t(3) dificil (Recomendado para jogadores experientes.)"
<< "\t(Este nível consiste em ter que acertar uma senha de 5 dígitos e você tem somente 12 tentativas para isso.)\n"
<< "\tEscolha a sua opção:";
cin >> dificuldade;
break;
case 3:
cout << "\tJogo criado por Gabriel Merçoni\n"
<< "\tData: (Maio/2024)\n"
<< "\tDisciplina: (Algoritmos d programação/Professor Eduardo Alves da Silva)." << endl;
break;
case 4:
cout << "\nJogo finalisado!" << endl;
return 0;
break;
default :
cout << "\nDigite uma opção válida! " << endl;
break;
        }
        false;
    } 

    return 0;
}