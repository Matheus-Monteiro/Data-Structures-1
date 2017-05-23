#include <iostream>
using namespace std;

struct Cliente
{
    string nome, cpf;
    Cliente *prox;
    Cliente(string nome, string cpf)
    {
        this->nome = nome;
        this->cpf = cpf;
        this->prox = nullptr;
    }
    Cliente(){
        this->prox = nullptr;
    }
};

Cliente* criarPilha()
{
    Cliente *pilha = new Cliente();
    return pilha;
}

void inserir(Cliente *pilha, string nome, string cpf)
{
    Cliente *aux = new Cliente(nome, cpf);
    aux->prox = pilha->prox;
    pilha->prox = aux;
    return;
}

Cliente remover(Cliente *pilha)
{
    if(pilha->prox == nullptr)
    {
        Cliente *r = new Cliente("ninguem foi removido", "*");
        return *r;
    }
    Cliente *aux = pilha->prox, r = *aux;
    pilha->prox = pilha->prox->prox;
    delete(aux);
    return r;
}

void deletar(Cliente *pilha)
{
    Cliente *aux = pilha;
    while(pilha != nullptr)
        aux = aux->prox, delete(pilha), pilha = aux;
}

void show(Cliente *pilha)
{
    if(pilha->prox == nullptr)
    {
        cout << "pilha vazia" << '\n';
        return;
    }
    cout << "PILHA:" << '\n';
    Cliente *aux = pilha->prox;
    while(aux != nullptr)
        cout << aux->nome << '\n', aux = aux->prox;
    cout << '\n';
}

int main()
{
    Cliente *pilha = criarPilha();
    
    string nome, cpf;

    nome = "1berto", cpf = "25698";
    inserir(pilha, nome, cpf);
    nome = "matheus", cpf = "4582";
    inserir(pilha, nome, cpf);
    nome = "gabriel berbardino", cpf = "pericles sidcley pires";
    inserir(pilha, nome, cpf);

    show(pilha);

    cout << remover(pilha).nome << " foi removido" << '\n';

    deletar(pilha);   

    return 0;
}
