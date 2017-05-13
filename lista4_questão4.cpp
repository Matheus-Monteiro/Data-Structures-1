#include <iostream>
using namespace std;

struct Cliente{
    string nome, cpf;
};

Cliente* criarFila(int n, int &size){
    Cliente *fila = (Cliente*)malloc(n*sizeof(Cliente));
    size = 0;
    return fila;
}

void inserir(Cliente *fila, Cliente cliente, int &size){
    fila[size] = cliente;
    size++;
}

Cliente remover(Cliente *fila, int &size){
    Cliente aux;
    aux = fila[0];
    for(int i = 0; i < size; i++)
        fila[i] = fila[i+1];
    size--;
    return aux;
}

void deletarFila(Cliente *fila, int &size){
    free(fila);
    size = 0;
}

void show(Cliente *fila, int size){
    cout << "size: " << size << '\n';
    cout << "elementos: " << '\n';
    for(int i = 0; i < size; i++)
        cout << "nome: " << fila[i].nome << " --> " << " cpf: " << fila[i].cpf << '\n';
    cout << '\n';
}

int main(){
    Cliente *fila;
    int size;
 
    fila = criarFila(10, size);
 
    Cliente aux;
    aux.nome = "Matheus";
    aux.cpf = "123456789";   
    inserir(fila, aux, size);
    aux.nome = "sidiney";
    aux.cpf = "245789";
    inserir(fila, aux, size);
    aux.nome = "gabriel";
    aux.cpf = "789654123";
    inserir(fila, aux, size);
    show(fila, size);
    aux = remover(fila, size);
    cout << aux.nome << " foi removido com sucesso" << '\n';
    deletarFila(fila, size);
 
    return 0;
}
