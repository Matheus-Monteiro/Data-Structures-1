#include <iostream>
using namespace std;

struct Cliente{
    string nome, cpf;
};

Cliente* criarPilha(int n, int &size){
    Cliente *pilha = (Cliente*)malloc(n*sizeof(Cliente));
    size = 0;
    return pilha;
}

void inserir(Cliente *pilha, int &size, Cliente cliente){
    for(int i = size; i > 0; i--)
        pilha[i] = pilha[i-1];
    pilha[0] = cliente;
    size++;
}

Cliente remover(Cliente *pilha, int &size){
    Cliente aux = pilha[0];
    for(int i = 0; i < size-1; i++)
        pilha[i] = pilha[i+1];
    size--;
    return aux;
}

void deletarPilha(Cliente *pilha, int &size){
    free(pilha);
    size = 0;
}

void show(Cliente *pilha, int size){
    cout << "size: " << size << '\n';
    cout << "elementos: " << '\n';
    for(int i = 0; i < size; i++)
        cout << "nome: " << pilha[i].nome << " --> " << " cpf: " << pilha[i].cpf << '\n';
    cout << '\n';
}

int main(){
    Cliente *pilha;
    int size;
    
    pilha = criarPilha(10, size);   
 
    Cliente aux;
    aux.nome = "Matheus";
    aux.cpf = "123456789";   
    inserir(pilha, size, aux);
    aux.nome = "sid";
    aux.cpf = "245789";
    inserir(pilha, size, aux);
    aux.nome = "gabriel";
    aux.cpf = "789654123";
    inserir(pilha, size, aux);
    show(pilha, size);
    aux = remover(pilha, size);
    cout << aux.nome << " removido com sucesso" << 'n' << '\n' << '\n';
    show(pilha, size);
    deletarPilha(pilha, size);
    
    return 0;
}
