#include <bits/stdc++.h>
using namespace std;
#define FOR(n) for(int i = 0; i < n; i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

void print(ofstream& arq, const string& s){
    cout << s << '\n';

    if(arq.is_open()){
        arq << s << '\n';
    }
}

int main(){
    cout << "Digite o nome: ";
    string nome; getline(cin, nome);
    ofstream arq("C:/Users/playe/Documents/PerfilGrupoGeral_" + nome + ".txt", ios::app);
    
    // Corrigido o item 27 para 47 no quad2 de acordo com a folha de sumário
    set<int> psico = {3,7,10,13,16,21,22,25,29,32,36,39,42,54};
    set<int> ext = {8,11,23,27,31,34,44,45,50,52,56,60}; 
    set<int> neu = {2,5,9,12,15,18,20,24,28,35,38,41,47,49,51,53,58,59};
    set<int> sin = {1,4,6,14,17,19,26,30,33,37,40,43,46,48,55,57};

    set<int> maisumifnao = {21,54,4,6,17,26,33,40,43,46,55};
    
    int sumPsico{0}, sumExt{0}, sumNeu{0}, sumSin{0};
    
    cout << "Digite as 60 respostas:\n";
    vector<char> respostas(60);
    
    // 1. Apenas coleta as respostas (com a lógica de voltar funcionando perfeitamente)
    for(int i = 0; i < 60; i++){
        print(arq, (string)"Preenchendo agora a pergunta " + to_string(i+1) + ". Responda 's' ou 'n'. Aperte '0' para corrigir o anterior.");
        char x; cin >> x;
        
        if(x != 'n' && x != 's') { 
            i -= 2; // Volta a pergunta
            if(i < -1) i = -1; // Evita que o índice fique negativo caso o erro seja na 1ª pergunta
            continue; 
        }
        respostas[i] = x;
        print(arq, (string)"Pergunta " + to_string(i+1) + " respondeu " + x);
    }

    // 2. Processa as pontuações DEPOIS de coletar tudo
    for(int i = 0; i < 60; i++){
        char x = respostas[i];
        
        if(psico.find(i+1) != psico.end()){
            if(!(x == 'n' ^ maisumifnao.find(i+1) != maisumifnao.end())) sumPsico++;
        }
        if(ext.find(i+1) != ext.end()){
            if(!(x == 'n' ^ maisumifnao.find(i+1) != maisumifnao.end())) sumExt++;
        }
        if(neu.find(i+1) != neu.end()){
            if(!(x == 'n' ^ maisumifnao.find(i+1) != maisumifnao.end())) sumNeu++;
        }
        if(sin.find(i+1) != sin.end()){
            if(!(x == 'n' ^ maisumifnao.find(i+1) != maisumifnao.end())) sumSin++;
        }
    }
    
    print(arq, "\n=== RESULTADOS PARA: " + nome + "===");
    int percPsico = 5, percExt = 5, percNeu = 5, percSin = 5;
    string bai = "Baixo", med = "Médio", alt = "Alto", muialt = "Muito Alto";
    string clasPsico = "Muito Baixo", clasExt = clasPsico, clasNeu = clasExt, clasSin = clasPsico;
    if(sumPsico == 1){
        percPsico = 20; clasPsico = bai;
    }
    else if(sumPsico == 2){
        percPsico = 40; clasPsico = med;
    }
    else if(sumPsico == 3){
        percPsico = 60; clasPsico = med;
    }
    else if(sumPsico == 4){
        percPsico = 70; clasPsico = med;
    }
    else if(sumPsico == 5 || sumPsico == 6){
        clasPsico = alt; percPsico = 80;
    }
    else if(sumPsico == 7){
        clasPsico = alt; percPsico = 90;
    }
    else if(sumPsico >= 8){
        percPsico = 99; clasPsico = muialt;
    }

    print(arq, "\n Psicoticismo: percentil " + to_string(percPsico) + "%; classificação: " + clasPsico + '\n');

    if(sumExt == 6 || sumExt == 7){
        clasExt = bai; percExt = 10;
    }
    else if(sumExt == 8){
        clasExt = bai; percExt = 20;
    }
    else if(sumExt == 9){
        clasExt = med; percExt = 40;
    }
    else if(sumExt == 10){
        clasExt = med; percExt = 50;
    }
    else if(sumExt == 11){
        percExt = 70; clasExt = med;
    }
    else if(sumExt == 12){
        percExt = 90; clasExt = alt;
    }

    print(arq, "\n Extroversão: percentil " + to_string(percExt) + "%; classificação: " + clasExt + '\n');

    if(sumNeu == 3 || sumNeu == 4){
        clasNeu = bai; percNeu = 10;
    }
    else if(sumNeu == 5 || sumNeu == 6){
        clasNeu = bai; percNeu = 20;
    }
    else if(sumNeu >= 7 && sumNeu <= 12){
        clasNeu = med;
        if(sumNeu == 7) percNeu = 30;
        else if(sumNeu == 8) percNeu = 40;
        else if(sumNeu == 9) percNeu = 50;
        else if(sumNeu == 10) percNeu = 60;
        else if(sumNeu == 11 || sumNeu == 12) percNeu = 70;
    }
    else if(sumNeu == 13){
        clasNeu = alt; percNeu = 80;
    }
    else if(sumNeu == 14 || sumNeu == 15){
        clasNeu = alt; percNeu = 90;
    }
    else if(sumNeu >= 16){
        clasNeu = muialt; percNeu = 99;
    }

    print(arq, "\n Neuroticismo: percentil " + to_string(percNeu) + "%; classificação: " + clasNeu + '\n');

    if(sumSin == 5){
        clasSin = bai; percSin = 10;
    }
    else if(sumSin == 6 || sumSin == 7){
        clasSin = bai; percSin = 20;
    }
    else if(sumSin >= 8 && sumSin <= 13){
        clasSin = med;
        if(sumSin == 8) percSin = 30;
        if(sumSin == 9) percSin = 40;
        if(sumSin == 10) percSin = 50;
        if(sumSin == 11 || sumSin == 12) percSin = 60;
        if(sumSin == 13) percSin = 70;
    }
    else if(sumSin == 14){clasSin = alt; percSin = 80;}
    else if(sumSin == 15){clasSin = alt; percSin = 90;}
    else if(sumSin == 16){percSin = 99; clasSin = muialt;}

    print(arq, "\n Sinceridade: percentil " + to_string(percSin) + "%; classificação: " + clasSin + '\n');

    print(arq, "\nProcessamento concluido.\n");
    arq.close();
    return 0;
}