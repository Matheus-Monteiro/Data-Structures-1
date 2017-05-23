/*
test case:

6 3
matheusa jr
1berto
sidcley pericles
gabriel botao
bernardino xavier
bernardina pires
    
deve gerar como saida: matheusa jr 
*/
#include <iostream>
using namespace std;

struct No
{
    string nome;
    No *prox;
    No(No *head, string nome)
    {
        this->nome = nome;
        this->prox = head;
    }
    No(){
        this->prox = nullptr;
    }
};

No* criar()
{
    No *head = new No();
    head->prox = head;
    return head;
}

void inserir(No *head, string nome, int posicao)
{
    No *aux;
    int i = 0;
    for(aux = head; aux->prox != head and i < posicao; aux = aux->prox)
        i++;
    if(aux->prox == head)
        aux->prox = new No(head, nome);
    else
    {
        No *k = new No(head, nome);
        k->prox = aux->prox;
        aux->prox = k;
    }
}

No remover(No *head, int posicao)
{
    No *aux;
    int i = 0;
    for(aux = head; aux->prox != head and i < posicao; aux = aux->prox)
        i++;
    No *k = aux->prox, r = *k;
    aux->prox = aux->prox->prox;
    delete(k);
    return r;
}

void deletar(No *head){
    No *aux1 = head->prox, *aux2 = head->prox;
    while(aux1 != head)
        aux1 = aux1->prox, delete(aux2), aux2 = aux1;
    delete(aux2);
}

string josephus(No *head, int n, int m)
{
    int c = 0, i;
    No *aux = head;
    while(n != 1)
    {
        if(aux == head)
        {
            i = -1;
            aux = aux->prox;
        }       
        else
        {
            i++, c++;
            if(c == m)
            {
                No r = remover(head, i);
                n--;
                i--;
                c = 0;
                aux = r.prox;
            }else
                aux = aux->prox;
        }
    }
    return head->prox->nome;
}

int main(){
    No *head = criar();
    string str;
    int n, m;

    cin >> n >> m;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        getline(cin, str);
        inserir(head, str, i);
    }   

    cout << josephus(head, n, m) << '\n';

    deletar(head);

    return 0;
}
