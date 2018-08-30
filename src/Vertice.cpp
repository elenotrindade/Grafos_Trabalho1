#include "Vertice.h"
#include <list>

Vertice::Vertice()
{
    this->grau = 0;
    //contrutor sem parâmetros, não é feito nada nele
}

Vertice::Vertice(int id) {
    this->grau = 0;
    this->ID = id;
    //contrutor passando o id do vertice
}

Vertice::~Vertice()
{
    //dtor
}

int Vertice::getID(){
    return this->ID; // retorna o id do vertice
}

int Vertice::getGrau(){
    return this->grau; // retorna grau do vertice
}

void Vertice::adicionaAresta(int id) {
    Aresta aresta = Aresta(id); //instacia novo objeto do tipo aresta
    this->grau++; //incrementa o numero de graus do vertice
    this->listaAresta.push_back(aresta); // adiciona a aresta criada na lista de arestas do vertice
}

void Vertice::removeAresta(int id_vertice_adjacente){
    list<Aresta>::iterator it; // iterator de uma lista de arestas

    for(it = this->listaAresta.begin(); it != this->listaAresta.end(); ++it){ // percorre toda a lista de arestas do vertice
        if(it->getIdVertice() == id_vertice_adjacente){ // compara o id do vertice armazenado na aresta com o id do vertice adjacente passado por parâmetro
            this->listaAresta.erase(it); //remove aresta da lista
            this->grau--; // subtrai -1 do valor do grau do vertice
            break; // termina laço de repetição
        }
    }
}

void Vertice::imprimirArestas(){ // imprime os ids dos vertice que esse vertice está ligado
    list<Aresta>::iterator it;
    cout << "Lista de arestas (vertice " << this->ID << "): ";
    for(it = this->listaAresta.begin(); it != this->listaAresta.end(); ++it){
        cout << it->getIdVertice() << " ";
    }
    cout << endl;
}













