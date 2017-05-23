#include <iostream>
using namespace std;

struct Cliente
{
    string nome, cpf;
    Cliente *prox;
    Cliente(Cliente *head, string nome, string cpf)
    {
        this->nome = nome;
        this->cpf = cpf;
        this->prox = head;
    }
    Cliente(){
        this->prox = nullptr;
    }
};

Cliente* criar()
{
    Cliente *head = new Cliente();
    head->prox = head;
    return head;
}

void inserir(Cliente *head, string nome, string cpf, int posicao)
{
    Cliente *aux;
    int i = 0;
    for(aux = head; aux->prox != head and i < posicao; aux = aux->prox)
        i++;
    if(aux->prox == head)
        aux->prox = new Cliente(head, nome, cpf);
    else
    {
        Cliente *k = new Cliente(head, nome, cpf);
        k->prox = aux->prox;
        aux->prox = k;
    }
}

Cliente remover(Cliente *head, int posicao)
{
    if(head->prox == head)
    {
        Cliente *r = new Cliente(head, "ninguem foi removido", "*");
        return *r;
    }
    Cliente *aux;
    int i = 0;
    for(aux = head; aux->prox != head and i < posicao; aux = aux->prox)
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
    for(aux = head->prox; aux != head; aux = aux->prox)
        if(aux->nome == nome and aux->cpf == cpf)
            break;
        else
            p++;
    return p;
}

void imprimir(Cliente *head){
    if(head->prox == head)
    {
        cout << "LISTA VAZIA" << '\n' << '\n';
        return;
    }
    Cliente *aux = head->prox;
    cout << "LISTA: " << '\n';
    while(aux != head)
        cout << aux->nome << ' ' << aux->cpf << '\n', aux = aux->prox;    
    cout << '\n';
}

void deletar(Cliente *head){
    Cliente *aux1 = head->prox, *aux2 = head->prox;
    while(aux1 != head)
        aux1 = aux1->prox, delete(aux2), aux2 = aux1;
    delete(aux2);
}

int main(){
    Cliente *head = criar();
    
    string nome, cpf;
  /*  
    nome = "matheus", "1234567";
    inserir(head, nome, cpf, 0);
    nome = "sidcley", "242469";
    inserir(head, nome, cpf, 1);
    nome = "1berto", "17424";
    inserir(head, nome, cpf, 2);

    imprimir(head);
*/
    cout << remover(head, 0).nome << " foi removido" << '\n';
    nome = "matheus", "1234567";
    cout << "posico de " << nome << " eh " << buscar(head, nome, cpf) << '\n' << '\n';

    imprimir(head);

    deletar(head);

    return 0;
}
