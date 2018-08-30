#include "GrafoMatrizAdj.h"

GrafoMatrizAdj::GrafoMatrizAdj() // construtor sem parâmetros
{
    this->numero_arestas = 0;
    this->numero_vertices = 0;
}

GrafoMatrizAdj::GrafoMatrizAdj(int numero_vertices) // contrutor passando o número de vertices
{
    this->numero_vertices = numero_vertices;
    this->matriz_adj = new int[this->somaElementosPA(numero_vertices)]; // instancia o vetor de acordo com a soma dos elementos da PA do número de vértices
    for(int i=0; i < this->somaElementosPA(this->numero_vertices); i++){ // iterando sobre o vetor e setando valor 0 nas posições
        this->matriz_adj[i] = 0;
    }
}

GrafoMatrizAdj::~GrafoMatrizAdj() // destrutor
{
    delete[] matriz_adj;
}

int GrafoMatrizAdj::somaElementosPA(int qntde_elementos)
{
    return (qntde_elementos+1)*qntde_elementos/2;
}

int GrafoMatrizAdj::detInd(int id_vertice_1, int id_vertice_2)
{
    if(id_vertice_1 > id_vertice_2)
        return this->somaElementosPA(id_vertice_1 - 1) + id_vertice_2 - 1;
    else
        return this->somaElementosPA(id_vertice_2 - 1) + id_vertice_1 - 1;
}

void GrafoMatrizAdj::adicionarVertice(int id)
{
    int* matriz_temporaria = this->matriz_adj;
    this->matriz_adj = new int[this->somaElementosPA(this->numero_vertices + 1)];
    for(int i = 0; i < this->somaElementosPA(this->numero_vertices); i++){
        this->matriz_adj[i] = matriz_temporaria[i];
    }

    for(int i = this->somaElementosPA(this->numero_vertices); i < this->somaElementosPA(this->numero_vertices +1); i++){
        this->matriz_adj[i] = 0;
    }

    this->numero_vertices++;
    delete[] matriz_temporaria;
}

void GrafoMatrizAdj::removerVertice(int ID)
{
    int id_linha_vertice = this->somaElementosPA(ID - 1);
    int id_coluna_vertice = this->somaElementosPA(ID) + (ID -1); //primeira ocorrência da intersecao do vertice que se deseja excluir e um vertice com id maior que o do dele
    int* matriz_temporaria = this->matriz_adj;
    this->matriz_adj = new int[this->somaElementosPA(this->numero_vertices - 1)];

    for(int i = 0; i < id_linha_vertice; i++){
        this->matriz_adj[i] = matriz_temporaria[i];
    }

    int aux = 0;
    int j = id_linha_vertice + ID;
    for(int i = id_linha_vertice + ID; i < this->somaElementosPA(this->numero_vertices - 1); j++){
        if(j == id_coluna_vertice){
            id_coluna_vertice+= ID + aux;
            aux++;
            continue;
        }
        this->matriz_adj[i] = matriz_temporaria[j];
        i++;
    }

    //this->matriz_adj = matriz_temporaria;
    this->numero_vertices--;

    delete[] matriz_temporaria;
}

void GrafoMatrizAdj::adicionarAresta(int id_vertice_1, int id_vertice_2)
{
    int indice_vetor = this->detInd(id_vertice_1, id_vertice_2);
    this->matriz_adj[indice_vetor] = 1;
}


void GrafoMatrizAdj::removerAresta(int id_vertice_1, int id_vertice_2)
{
    int indice_vetor = this->detInd(id_vertice_1, id_vertice_2);
    this->matriz_adj[indice_vetor] = 0;
}

int GrafoMatrizAdj::getGrau(int id_vertice)
{
    int grau = 0;
    int posicao_inicial_vetor = somaElementosPA(id_vertice - 1); // retorna o indice da posicao inicial do vetor que representa
    for(int i = posicao_inicial_vetor; i < posicao_inicial_vetor + (id_vertice - 1); i++){
        if(matriz_adj[i] == 1)
            grau++;
    }

    return grau;
}

int GrafoMatrizAdj::getNumeroVertices()
{
    return this->numero_vertices;
}

void GrafoMatrizAdj::imprimirArestas(int id)
{

}

void GrafoMatrizAdj::imprimirVertices()
{
    cout << "matriz triangular inferior de adjacencias" << endl;
    int indice_proximo_vertice = 1, aux = 2;
    for(int i=0; i < this->somaElementosPA(this->numero_vertices); i++){
        if(i == indice_proximo_vertice) {
            cout << endl;
            indice_proximo_vertice = somaElementosPA(aux);
            aux++;
        }
        cout << this->matriz_adj[i] << " ";
    }
}








