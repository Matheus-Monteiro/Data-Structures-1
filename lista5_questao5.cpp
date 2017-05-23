#include <iostream>
using namespace std;

struct Cliente
{
    string nome, cpf;
    Cliente *prox, *ante;
    Cliente(string nome, string cpf)
    {
        this->nome = nome;
        this->cpf = cpf;
        this->prox = nullptr;
        this->ante = nullptr;
    }
    Cliente()
    {
        this->prox = nullptr;
        this->ante = nullptr;
    }
};

Cliente* criar()
{
    Cliente *head = new Cliente();
    return head;
}

void inserir(Cliente *head, string nome, string cpf, int posicao)
{
    int i = 0;
    Cliente *aux, *k = new Cliente(nome, cpf);
    for(aux = head; aux->prox != nullptr and i < posicao; aux = aux->prox)
        i++;
    if(aux->prox == nullptr)
    {
        k->ante = aux;
        aux->prox = k;
    }
    else
    {
        k->prox = aux->prox;
        aux->prox->ante = k;
        aux->prox = k;
        k->ante = aux;
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
    if(k->prox != nullptr)
        k->prox->ante = aux;
    aux->prox = k->prox; 
    delete(k);
    return r;
}

void imprimir(Cliente *head)
{
    if(head->prox == nullptr)
    {
        cout << "lista vazia" << '\n';
        return;
    }
    Cliente *aux = head->prox;
    cout << "LISTA:" << '\n';
    while(aux != nullptr)
        cout << aux->nome << '\n', aux = aux->prox;
    cout << '\n';
}

int buscar(Cliente *head, string nome, string cpf)
{
    int p = 0;
    Cliente *aux;
    for(aux = head->prox; aux != nullptr; aux = aux->prox)
        if(aux->nome == nome and aux->cpf == cpf)
            break;
        else
            p++;
    return p;
}

void deletar(Cliente *head)
{
    Cliente *aux = head, *k = head;
    while(aux != nullptr)
        aux = aux->prox, delete(k), k = aux;
}

int main()
{
    Cliente *head = criar();
    
    string nome, cpf;
    
    nome = "matheus", cpf = "1256347";
    inserir(head, nome, cpf, 0);   
    nome = "peador", cpf = "14789547";
    inserir(head, nome, cpf, 0);   

    nome = "peador", cpf = "14789547"; 
    cout << nome << " esta na posicao " << buscar(head, nome, cpf) << '\n'; 
    nome = "matheus", cpf = "1256347"; 
    cout << nome << " esta na posicao " << buscar(head, nome, cpf) << '\n' << '\n';
    
    imprimir(head);
    
    cout << remover(head, 0).nome << " foi removido"<< '\n' << '\n';
    imprimir(head);
    cout << remover(head, 0).nome << " foi removido"<< '\n' << '\n';
    imprimir(head);
    cout << remover(head, 0).nome << " foi removido"<< '\n' << '\n';   

    deletar(head);
    
    return 0;
}
