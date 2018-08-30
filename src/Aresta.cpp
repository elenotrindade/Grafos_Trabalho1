#include "Aresta.h"

Aresta::Aresta()
{
    //construtor sem nenhum parâmetro
}

Aresta::Aresta(int id_vertice_adjacente){
    this->id_vertice = id_vertice_adjacente;
}

Aresta::~Aresta()
{
    //destrutor
}

void Aresta::setIdVertice(int id){
    this->id_vertice = id;
}

int Aresta::getIdVertice(){
    return this->id_vertice;
}
