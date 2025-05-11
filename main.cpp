#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


void salvarTarefas(const vector<string>& tarefas) {
    ofstream arquivo("tarefas.txt");
    for (const string& tarefa : tarefas) {
        arquivo << tarefa << endl;
    }
    arquivo.close();
}

void carregarTarefas(vector<string>& tarefas) {
    ifstream arquivo("tarefas.txt");
    string linha;
    while (getline(arquivo, linha)) {
        tarefas.push_back(linha);
    }
    arquivo.close();
}


void mostrarTarefas(const vector<string>& tarefas) {

    cout << "\n📋 Lista de Tarefas:\n";
    for (int i = 0; i < tarefas.size(); i++) {
        cout << i + 1 << ". " << tarefas[i] << endl;
    }

}




int main()
{

    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    
int op;
int excluir;
int alterar;
int tarefaConcluida;
string mensagemAlterada;
string apagarTudo;
vector<string> tarefas; // array de tamanho indefinido//
carregarTarefas(tarefas); 
string novaTarefa; // adicionar nova tarefa //

bool continuar = true; // deixar o loop rodando até escolher sair 


while (continuar)
{
   


    cout << endl;
    cout << "===== Tasklist =====" << endl;
    cout << "1. Adicionar tarefa" << endl;
    cout << "2. Remover tarefa" << endl;
    cout << "3. Listar tarefas" << endl;
    cout << "4. Marcar como concluída" << endl;
    cout << "5. Editar tarefa" << endl;
    cout << "6. Limpar todas as tarefas" << endl;
    cout << "7. Sair" << endl;
    cout << endl;


    cin >> op;    

    if (op < 1 || op > 7) {
        cout << "Opção inválida! Por favor, escolha uma opção entre 1 e 7." << endl;
        continue; 
    }
    

    switch (op)
    {
    case 1:
        //adiciona nova tarefa//
        cout << "Digite a nova tarefa: " << endl;
        cin.ignore(); //ignora caracter em nova linha//
        getline(cin, novaTarefa);   //le a linha inteira//

        tarefas.push_back(novaTarefa); // manda para novaTarefa
        cout << "Tarefa Adicionada!" << endl;

        break;
    case 2:

        cout << "Qual item deseja excluir?" << endl;

        mostrarTarefas(tarefas);

        cin >> excluir;

        if (excluir < 1 || excluir > tarefas.size()) {
            cout << "Número inválido!\n";
            break;
        }

        tarefas.erase(tarefas.begin() + (excluir - 1));

        
        break;
    case 3:

        mostrarTarefas(tarefas);

        break;
    case 4:

        cout << "Qual tarefa você concluiu:" << endl;

        mostrarTarefas(tarefas);

        cin >> tarefaConcluida;

        if (tarefaConcluida < 1 || tarefaConcluida > tarefas.size()) {
            cout << "Número inválido!\n";
            break;
        }


        cout << "\n🎉✨ PARABÉNS! ✨🎉\n";
        cout << "Você concluiu uma tarefa com sucesso! ✅\n";
        cout << "╔══════════════════════════╗\n";
        cout << "║     MISSÃO CUMPRIDA!     ║\n";
        cout << "╚══════════════════════════╝\n";
        cout << "Continue assim! 💪🧠\n";
        cout << "🥳👏👏👏 Você está cada vez mais perto de zerar sua lista!\n";

        tarefas.erase(tarefas.begin() + (tarefaConcluida - 1));


        break;
    case 5:


        cout << "Qual tarefa você deseja alterar? " << endl;

        mostrarTarefas(tarefas);
        cin >> alterar;


        if (alterar < 1 || alterar > tarefas.size()) {
            cout << "Número inválido!\n";
            break;
        }

        cout << "Escreva o que deseja alterar: " << endl;

        cin >> mensagemAlterada;
        cin.ignore();                      //ignora caracter em nova linha//
        getline(cin, mensagemAlterada);   //le a linha inteira//
        tarefas[alterar - 1] = mensagemAlterada;

        cout << "Tarefa Atualizada! " << endl;

        break;
    case 6:
        
        cout << "Você tem certeza?" << endl;
        cout << "isso apagará todas as tarefas:" << endl;
        cout << "Apagar(Sim) Cancelar(Não)" << endl;

        cin >> apagarTudo;

        if(apagarTudo == "Sim" || apagarTudo == "sim")
        {
            cout << "Itens excluidos!" << endl;
            tarefas.clear();

        }
        break;
    
    case 7:
        
        cout << "até a proxima!" << endl;
        salvarTarefas(tarefas);
        continuar = false;

        break;
    
    default:
        break;
    }

}
    return 0;
}


