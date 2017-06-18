//Alunos                      Matricula
//Matheus Monteiro Silveira   1357484
//Humberto Pires Marques      1293295

#include <bits/stdc++.h>

using namespace std;

class Bucket
{
public:
	int bitmask;
	int arr[4];
	Bucket()
	{
		bitmask = 0;
	}
};

class Hash
{
public:
	int depth;
	vector<Bucket> buckets;
	Hash();
	int f1_hash(int n);
	int f2_hash(int n);
	void inserir(int n);
	void dobrar();
	void remover(int n);
	bool buscar(int n);
	string to_binary(int n);
	void imprimir();
};

int main()
{
	Hash h;
	bool flag = true;
	int o, v;
	
	while(flag)
	{
		cout << "(1) Adicionar novo valor" << '\n';
		cout << "(2) Remover valor" << '\n';
		cout << "(3) Buscar valor" << '\n';
		cout << "(4) Imprimir todos os valores" << '\n';
		cout << "(5) Sair" << '\n';
		cout << "Digite a operacao desejada:" << '\n';
		cin >> o;
	
		if(o == 1)
		{
			cout << "Digite o valor do elemento a ser inserido na hash" << '\n';
			cin >> v;
			h.inserir(v);
			cout << '\n';
		}
		else if(o == 2)
		{
			cout << "Digite o valor do elemento a ser removido da hash" << '\n';
			cin >> v;
			h.remover(v);
			cout << '\n';
		}
		else if(o == 3)
		{
			cout << "Digite o valor do elemento a ser buscado na hash" << '\n';
			cin >> v;
			cout << v << (h.buscar(v) ? " esta na tabela hash" : " nao esta na tabela hash" ) << '\n';
			cout << '\n';
		} 
		else if(o == 4)
		{
			cout << "TABELA HASH:" << '\n';
			h.imprimir();
			cout << '\n';
		}
		else
			flag = false;
	}
	cout << "END! THANK YOU :)" << '\n';
	
	return 0;
}

Hash::Hash()
{
	buckets.resize(2);
	depth = 1;
}

int Hash::f1_hash(int n)
{
	int p = 0;
	for(int i = 0; i < depth; i++)
		p |=  n & (1 << i);
	return p;	
}

int Hash::f2_hash(int n)
{
	for(int i = 0; i < 4; i++)
		if(!(n & (1 << i)))
			return i;
	return -1;
}

void Hash::inserir(int n)
{
	int t = f1_hash(n);
	int p = f2_hash(buckets[t].bitmask);
	if(p != -1)
	{
		buckets[t].arr[p] = n;
		buckets[t].bitmask |= (1 << p);
	}
	else
	{
		dobrar();
		inserir(n);		
	}
}

void Hash::dobrar()
{
	depth++;
	vector<int> aux;
	for(int i = 0; i < buckets.size(); i++)
		for(int j = 0; j < 4; j++)
			if(buckets[i].bitmask & (1 << j))
				aux.push_back(buckets[i].arr[j]);
	buckets.clear();
	buckets.resize(1 << depth);
	for(int i = 0; i < aux.size(); i++)
		inserir(aux[i]);
	aux.clear();
}


void Hash::remover(int n)
{
	int t = f1_hash(n);
	for(int i = 0; i < 4; i++)
	{
		if(buckets[t].arr[i] == n and buckets[t].bitmask & (1 << i))
		{
			buckets[t].bitmask ^= (1 << i);
			return;
		}	
	}
}

bool Hash::buscar(int n)
{
	int t = f1_hash(n);
	for(int i = 0; i < 4; i++)
		if(buckets[t].arr[i] == n and buckets[t].bitmask & (1 << i))
			return true;	
	return false;
}

string Hash::to_binary(int n)
{
	string p;
	for(int i = depth-1; i >= 0; i--)
		p += (n & (1 << i) ? '1' : '0');
	return p;
}

void Hash::imprimir()
{
	for(int i = 0; i < buckets.size(); i++)
	{
		cout << to_binary(i) << "-> ";
		for(int j = 0; j < 4; j++)
			if(buckets[i].bitmask & (1 << j))
				cout << buckets[i].arr[j] << ' ';
		cout << '\n';		
	}
}
