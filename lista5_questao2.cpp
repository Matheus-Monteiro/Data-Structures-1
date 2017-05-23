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

Cliente* criar()
{
    Cliente *head = new Cliente();
    return head;
}

void inserir(Cliente *head, string nome, string cpf, int posicao)
{
    Cliente *aux;
    int i = 0;
    for(aux = head; aux->prox != nullptr and i < posicao; aux = aux->prox)
        i++;
    if(aux->prox == nullptr)
        aux->prox = new Cliente(nome, cpf);
    else
    {
        Cliente *k = new Cliente(nome, cpf);
        k->prox = aux->prox;
        aux->prox = k;
    }
}

Cliente remover(Cliente *head, int posicao)
{
    if(head->prox == nullptr)
    {
        Cliente *r = new Cliente("ninguem foi removido", "*");
        return *r;
    }
    Cliente *aux;
    int i = 0;
    for(aux = head; aux->prox != nullptr and i < posicao; aux = aux->prox)
        i++;
    Cliente *k = aux->prox, r = *k;
    aux->prox = aux->prox->prox;
    delete(k);
    return r;
}

int buscar(Cliente *head, string nome, string cpf)
{
    Cliente *aux;
    int p = 0;
    for(aux = head->prox; aux != nullptr; aux = aux->prox)
        if(aux->nome == nome and aux->cpf == cpf)
            break;
        else
            p++;
    if(aux == nullptr)
        return -1; // o elemento não está na lista
    return p;// a posicao do elemento na lista
}

void imprimir(Cliente *head){
    if(head->prox == nullptr)
    {
        cout << "LISTA VAZIA" << '\n' << '\n';
        return;
    }
    Cliente *aux = head->prox;
    cout << "LISTA: " << '\n';
    while(aux != nullptr)
        cout << aux->nome << ' ' << aux->cpf << '\n', aux = aux->prox;    
    cout << '\n';
}

void deletar(Cliente *head){
    Cliente *aux = head;
    while(aux != nullptr)
        aux = aux->prox, delete(head), head = aux;
}

int main(){
    Cliente *head = criar();   
    
    string nome, cpf; 
    nome = "matheus", cpf = "24569875";
    inserir(head, nome, cpf, 0);
    nome = "pedro", cpf = "2424587";
    inserir(head, nome, cpf, 1);
    nome = "sid", cpf = "27486245";
    inserir(head, nome, cpf, 0);
    
    imprimir(head);
    
    Cliente r = remover(head, 0);   
    cout << "cliente removido: " << r.nome << '\n' << '\n';
    
    imprimir(head);
    
    nome = "pedro", cpf = "2424587";
    cout << "a posicao de " << nome << " eh " << buscar(head, nome, cpf) << '\n';

    deletar(head);

    return 0;
}
