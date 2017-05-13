#include <iostream>
using namespace std;

struct Cliente{
    string nome, cpf;
};

Cliente* criarLista(int n, int &size){
    Cliente *lista = (Cliente*)malloc(n*sizeof(Cliente));
    size = 0;
    return lista;
}

void inserir(Cliente *lista, int &size, int position, Cliente cliente){
    for(int i = size; i > position; i--)
        lista[i] = lista[i-1];
    lista[position] = cliente;
    size++;
}

Cliente remove(Cliente *lista, int  &size, int position){
    Cliente aux = lista[position];
    for(int i = position; i < size; i++)
        lista[i] = lista[i+1];
    size--;
    return aux;
}

int busca(Cliente *lista, int &size, Cliente cliente){
    for(int i = 0; i < size; i++)
        if(lista[i].nome == cliente.nome and lista[i].cpf == cliente.cpf)
            return i;
    return -1;
}

void deletaLista(Cliente *lista, int &size){
    free(lista);
    size = 0;
}

void show(Cliente *lista, int size){
    cout << "size: " << size << '\n';
    cout << "elementos: " << '\n';
    for(int i = 0; i < size; i++)
        cout << "nome: " << lista[i].nome << " --> " << " cpf: " << lista[i].cpf << '\n';
    cout << '\n';
}

int main(){
    Cliente *lista;
    int size;
    
    lista = criarLista(10, size);
    
    Cliente aux;
    aux.nome = "Matheus";
    aux.cpf = "123456789";   
    inserir(lista, size, 0, aux);
    aux.nome = "sid";
    aux.cpf = "245789";
    inserir(lista, size, 0, aux);
    aux.nome = "gabriel";
    aux.cpf = "789654123";
    inserir(lista, size, 2, aux);
    show(lista, size);
    aux.nome = "Matheus";
    aux.cpf = "123456789";
    cout << aux.nome << (busca(lista, size, aux) != -1 ? " esta na lista!" : " nao esta na lista") << '\n' << '\n';
    aux = remove(lista, size, 1);
    cout << aux.nome << " foi removido com sucesso" << '\n' << '\n';
    show(lista, size);
    aux.nome = "Matheus";
    aux.cpf = "123456789";
    cout << aux.nome << (busca(lista, size, aux) != -1 ? " esta na lista!" : " nao esta na lista") << '\n';
    deletaLista(lista, size);
       
    return 0;
}
