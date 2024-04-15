#include <iostream>
using namespace std;

int main() {
  system("cls");
  cout << "\tBem vindo ao melhor jogo medieval de sua vida!\n ";
  system("pause");
  system("cls");

  cout << "\tVocê agora é Percival, um mestre de armas do reino"
       << " reino de Itajaí, um reino conhecido por seus \n"
       << "vástos rios, florestas, e, mais importante, pela"
       << "paz duradoura que lá havia.\n"
       << "No entanto, com a escassez de recursos o reino vizinho, acabou se tornando"
       << " rival.\n \n \tApós ter seu reino invadido e sua princesa capturada, você foi convocado pelo\n"
       << "rei para resgatar a princesa, você deseja partir para essa aventura?\n\n";

  char decisao;
  cout << "aperte (s) para sim e (n) para não:\n";

  cin >> decisao;

  switch (decisao) {
  case 's': {
    cout << "\nSeu cavalo já está te esperando na saída! " << endl;
    break;
  }
  case 'n': {
    cout << "\nPor ter se rebelado contra o rei, ele te condenou a morte.\n Fim de jogo. " << endl;
    return 0;
    break;
  }
  default:
    cout << "\nEscolha uma opção válida! " << endl;
    break;
  }

system("pause");
system("cls");
  cout << "\tDirija-se até o armazém do castelo para escolher a sua arma\n";
  int arma;
  cout << "\tDigite 1 para espada e 2 para machado.\n ";
  cin >> arma;

 switch (arma) {
 case 1:
    cout << "\nAgora com sua espada você está pronto para seguir viagem!" << endl;
    break;
    case 2:
 cout << "\nCom a posse de seu machado você está preparado para seguir viagem. " << endl;
 break;
 default:
 cout << "\nDigite uma opção válida. " << endl;
    break;
 }

system("pause");
system("cls");

cout<< "\t Com ânsia de informações e respostas, o herói vai ao melhor ponto de encontro entre os andarilhos, uma taverna.\n";
char falar;
cout << "\nApós a sua chegada na taverna, você escuta ao fundo\n"
<< "Um bêbado falando sobre o caso da princesa."
<< "\nVocê deseja falar com ele? digite (s) para sim e (n) para não.\n";
cin >> falar;
switch (falar) {
case 's':
char confiar;
  cout << "\nFalando com o bêbado, você descobre que ele é um contrabandista e que tem informações valiosas sobre o reino rival."
  << "\nEle te conta que conheçe as passagens secretas que podem te levar mais facilmente até a princesa.\n"
  << "Mas para te ajudar, ele quer que você o ajude a matar o mestre de armas deles para vingar a falecida filha dele."
<< "\nVocê deseja confiar nele ou não? Não se esqueça que ele é um mercenário.\n"
<< "Digite (s) para sim e (n) para não:";
cin >> confiar;
if (confiar == 's') {
  cout << "\n Com um gesto de amizade o contrabandista paga a sua cerveja e te convida para partir rumo ao castelo.\n" << endl;
} else {
  cout << "\nEle não te conta mais nada e você sai. Ao entrar na floresta, Percival é atacado por uma besta e morre." << endl;
  return 0;
}
  break;
  case 'n':
  cout << " O Taverneiro, sabendo que você é\n mestre de armas do rei, cansado dos impostos abusivos, te indica o caminho para o \n labirinto da morte, onde você se perde e nunca mais volta." << endl;
  cout <<"\t\n\n Fim de Jogo!";
  return 0;
break;
default:
cout << "\nDigite uma opção válida." << endl;
break;
}

system("pause");
system("cls");
cout << "\nOs dois sairam da taverna, eles atravessaram florestas e rios, chegaram até as redondezas do castelo.\n"
<< "Após analisar o local, eles avistaram uma carroça e se agarram embaixo dela, e assim entrando do reino";
int desisao;
cout << "\nentrar de dia ou de noite? (d) para dia e (n) para noite.";
cin >> decisao;
switch (decisao)
{
case 'd':
cout << "\nPor causa da claridade, eles foram vistos e morreram. Fim de jogo." << endl;
return 0;
  break;
case 'n':
cout << "\nVocês vem duas entradas, calabouço e estábulo.\n";
cout << "\ndigite c para calabouço e estábulo.";
cin >> decisao;
if (decisao == 'c') {
  cout << "\n vocês viram vários presos e um deles faz uma chantagem.\n"
  << "soltar e não soltar (s) ou n";
  cin >> decisao;
  if (decisao == 's') {
    cout << "Os guardas correm atrás dele e deixam o caminho livre para vocês." << endl;
  } else{
  cout << "\n ele gritou e vocês foram mortos. " << endl;
  return 0;
}
} else {
  cout << "\nderrubaram algo e vocês foram mortos." << endl;
}
break;
default:
cout << "\nDigite uma opção válida. " << endl;
  break;
}
system("pause");
system("cls");

cout << "\nvocês avistam uma escada que está cheia de guardas.\n"
<< "O contrabandista que tornou-se seu amigo durante a viagem fala que, irá lutar com todos sozinho e você pode ir salvar a princesa. "
<< "\nO que você faz? digite f para ficar e c para continuar.";
cin >> decisao;

if (decisao == 'f' && arma == 1) {
  cout << "\nCom sua destresa, Percival conseguiu lutar e matar os guardas. "
  << "\nApós matar os guardas, você vê que um deles está com uma chave amarrada ao corpo.\n"
  << "O que você faz? digite p para pegar e i para ignorar.\n";
  cin >> decisao;
  if (decisao == 'p') {
    cout << "\tvocê segue por um caminho e encontra uma porta em um corredor, e descobre que a chave abre a porta do quarto da princesa.\n" << endl;
  } else if (decisao == 'i') {
cout << "Você até que tentou arrombar a porta, mas não conseguiu e foi morto. Fim de Jogo." << endl;
return 0;
  } else {
    cout << "\nDigite uma opção válida. " << endl;
  }
} else if (decisao == 'c') {
cout << "\nVocê caminha por um corredor e encontra uma porta que parece ser frágil\n"
<< "o que você vai fazer? a para arrombar e i para ignorar.\n";
cin >> decisao;
if (decisao == 'a' && arma == 1) {
  cout << "\tComo a sua arma era uma espada, você demorou muito e foi morto. " << endl;
  return 0;
} else if (decisao == 'a' && arma == 2) {
  cout << "\nvocê consegue entrar. " << endl;
} else if (decisao == 'i') {
  cout << "você caminha até um corredor e é alvejado por arqueiros." << endl;
  return 0;
} else {
  cout << "\nDigite uma opção válida. " << endl;
}
} else if (decisao == 'f' && arma == 2) {
  cout << "\ncomo a sua arma era o machado, você não tinha agilidade necessária para lutar com varios inimigos ao mesmo tempo e foi morto."
  << "Fim de jogo! " << endl;
  return 0;
} else {
  cout << "\nDigite uma opção válida. " << endl;
}
system("pause");
system("cls");

cout << "\nVocê entra no quarto da princesa e se depara com o mestre de armas.\n"
<< "Graças a sua habilidade você o domina e desarma.\n"
<< "\nVocê tem a opção de matá-lo ou de tentar convencer a deixar você levar a princesa.\n"
<< "O que você faz? m para matar e c para convencer. ";
cin >> decisao;
switch (decisao) {
  case 'm':
  cout << "\nVocê o mata, e quando se aproxima da princesa ela fala que não quer voltar para o reino.."
  << "você pode fugir com ela para a floresta ou leva-la a força para o castelo."
  << "digite f para fugir e l para levá-la.\n";
  cin >> decisao;
  if (decisao == 'f') {
cout << "\nVocês vão para a floresta, e por conta disso, você acaba se tornando um caçador de recompenças para sobreviver." << endl;
  } else if (decisao == 'l') {
    cout << "\nVocê leva a princesa para o reino, o rei fica muito grato e te oferece a mão dela em casamento.\n" << endl;
  } else {
    cout << "Digite uma opção válida.\n" << endl;
  }

break;
case 'c':
cout << "\n o mestre de armas recupera a espada e te mata em um só golpe.\n"
<< "e em seguida o contrabandista e a princesa.\n" << endl;
break;
default:
cout << "Digite uma opção válida. " << endl;
}
  return 0;
}