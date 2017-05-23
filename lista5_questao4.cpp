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

struct Fila
{
    Cliente *head;
    Cliente *tail;
    Fila()
    {
        this->head = new Cliente();
        this->tail = head;
    }
};
    
Fila* criar()
{
    Fila *fila = new Fila();
    return fila;   
}
 
void inserir(Fila *fila, string nome, string cpf)
{
    fila->tail->prox = new Cliente(nome, cpf);
    fila->tail = fila->tail->prox;
}
    
Cliente remover(Fila *fila)
{
    if(fila->head->prox == nullptr)
    {
        Cliente *r = new Cliente("ningue", "*");
        return *r;
    }
    Cliente *aux = fila->head->prox, r = *aux;
    fila->head->prox = aux->prox;
    delete(aux);
    return r;
}

void deletar(Fila *fila)
{
    Cliente *aux = fila->head, *k = fila->head;
    while(aux != nullptr)
        aux = aux->prox, delete(k), k = aux;
}

void show(Fila *fila)
{
    if(fila->head->prox == nullptr)
    {
        cout << "fila vazia" << '\n';
        return;
    }
    cout << "FILA:" << '\n';
    Cliente *aux = fila->head->prox;
    while(aux != nullptr)
        cout << aux->nome << '\n', aux = aux->prox;
    cout << '\n';
}
    
int main()
{
    Fila *fila = criar();

    string nome, cpf;

    nome = "matheus", cpf = "12478";
    inserir(fila, nome, cpf);
    nome = "sid bernardino", cpf = "mariana botao";
    inserir(fila, nome, cpf);
    
    show(fila);

    cout << remover(fila).nome << " foi removido" << '\n' << '\n';
    show(fila);

    cout << remover(fila).nome << " foi removido" << '\n' << '\n';
    show(fila);

    deletar(fila);

    return 0;
}
