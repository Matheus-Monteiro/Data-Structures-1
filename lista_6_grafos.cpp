//armazene grafos de 0 a n-1 vertices
#include <iostream>
using namespace std;

struct No
{
    int val;
    No *prox;
    No(int val)
    {
        this->val = val;
        this->prox = nullptr;
    }
    No()
    {
        this->val = 0;
        this->prox = nullptr;
    }
};

struct Cabeca
{
    No *adj;//a cabeca de cada lista de adjacencia é adj, o valor armazanado em head[i].adj->val é a quantidade de elementos adjacente ao vertice i
    No *fim;//um ponteiro que aponta sempre para o fim da lista de adjacencia do vertice i pra conseguir fazer inserção em O(1)
    bool flag;//flag para rodar o dfs no grafo
};

Cabeca* criar(int n)
{
    Cabeca *head = new Cabeca[n];
    for(int i = 0; i < n; i++)
        head[i].adj = new No(), head[i].flag = false, head[i].fim = head[i].adj;
    return head;
}
    
void inserir(Cabeca *head, int v, int w)
{
    head[v].fim->prox = new No(w);
    head[v].fim = head[v].fim->prox;
    head[v].adj->val++;
    return;
}

void dfs(Cabeca *head, int v)
{
    head[v].flag = true;
    for(No *aux = head[v].adj->prox; aux != nullptr; aux = aux->prox)
        if(!head[aux->val].flag)
            dfs(head, aux->val); 
}

void deletar(Cabeca *head, int n)
{
    No *aux, *k;
    for(int i = 0; i < n; i++){
        aux = head[i].adj;
        while(aux != nullptr)
            k = aux->prox, delete(aux), aux = k;
    }
    delete[] head;
}

void imprimir(Cabeca *head, int n)
{
    cout << "LISTA DE ADJACENCIA:" << '\n';
    for(int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for(No *aux = head[i].adj->prox; aux != nullptr; aux = aux->prox)
            cout << aux->val << ' ';
        cout << '\n';
    }
}

int main()
{
    int n, m, v, w;

    cin >> n >> m;
    Cabeca *head = criar(n);

    while(m--)
    {
        cin >> v >> w;
        inserir(head, v, w);
        inserir(head, w, v);
    }
    
    imprimir(head, n);
    
    cout << '\n';
    
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(!head[i].flag)
            dfs(head, i), ans++;
            
    cout << "a quantidade de componentes conexas do grafo eh " << ans <<'\n';        
     
    deletar(head, n);
     
    return 0;
}
