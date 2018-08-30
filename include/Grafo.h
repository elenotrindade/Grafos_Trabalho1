#ifndef GRAFO_H
#define GRAFO_H
#include <list>
#include "Vertice.h"

/*
*
*@Author João Victor Lopes Fam
*
*
*/
class Grafo
{
public:
    virtual void adicionarVertice(int ID) = 0; //adiciona um vertice na lista de vertices
    virtual void removerVertice(int ID) = 0; //remove um vertice da lista procurando-o por seu id

    virtual void adicionarAresta(int id_vertice_1, int id_vertice_2) = 0; // adiciona uma ligação entre dois vertices
    virtual void removerAresta(int id_vertice_1, int id_vertice_2) = 0; // remove a ligação entre dois vertices

    virtual int getGrau(int id_vertice) = 0; // retorna o grau de um vertice
    virtual int getNumeroVertices() = 0; // retorna o numero de vertices

    virtual void imprimirVertices() = 0; // imprime a lista de vertices existentes
    virtual void imprimirArestas(int id_vertice) = 0; // imprime a lista de arestas de um dado vertice
};

#endif // GRAFO_H
