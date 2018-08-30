#ifndef GRAFOLISTAADJ_H
#define GRAFOLISTAADJ_H
#include <list>
#include "Grafo.h"
#include "Vertice.h"

class GrafoListaAdj : public Grafo
{
private:
    list <Vertice> vertices; //lista de vertices que compoem o grafo

public:
    GrafoListaAdj(); //contrutor
    GrafoListaAdj(int num_vertices); // construtor passando o numero de vertices
    ~GrafoListaAdj(); // destrutor

    void adicionarVertice(int ID); //adiciona um vertice na lista de vertices
    void removerVertice(int ID); //remove um vertice da lista procurando-o por seu id

    void adicionarAresta(int id_vertice_1, int id_vertice_2); // adiciona uma ligação entre dois vertices
    void removerAresta(int id_vertice_1, int id_vertice_2); // remove a ligação entre dois vertices

    int getGrau(int id_vertice); // retorna o grau de um vertice
    int getNumeroVertices(); // retorna o numero de vertices

    void imprimirVertices(); // imprime a lista de vertices existentes
    void imprimirArestas(int id_vertice); // imprime a lista de arestas de um dado vertice
};

#endif // GRAFO_H
