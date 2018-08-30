#ifndef GRAFOMATRIZADJ_H
#define GRAFOMATRIZADJ_H
#include "Grafo.h"

#include <iostream>

using namespace std;


class GrafoMatrizAdj : public Grafo
{
private:
    int numero_vertices;
    int numero_arestas;

    int* matriz_adj;

    int somaElementosPA(int qntde_elementos);
    int detInd(int id_vertice_1, int id_vertice_2); //determina o indice do vetor de acordo com os indices da matriz

public:
    GrafoMatrizAdj();
    GrafoMatrizAdj(int numero_vertices);
    ~GrafoMatrizAdj();

    void adicionarVertice(int ID);
    void removerVertice(int ID);

    void adicionarAresta(int id_vertice_1, int id_vertice_2);
    void removerAresta(int id_vertice_1, int id_vertice_2);

    int getGrau(int id_vertice);
    int getNumeroVertices();

    void imprimirVertices();
    void imprimirArestas(int id_vertice);
};

#endif // GRAFOMATRIZADJ_H
