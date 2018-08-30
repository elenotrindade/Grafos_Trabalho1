#ifndef VERTICE_H
#define VERTICE_H
#include <iostream>
#include <list>
#include "Aresta.h"

using namespace std;


class Vertice
{
private:
    int ID; // id do vertice
    int grau; // grau do vertice

    list<Aresta> listaAresta; // lista de arestas que ligam a outros vertices

public:
    Vertice(); //contrutor sem parametros
    Vertice(int id); // contrutor passando o id do vertice
    ~Vertice(); // destrutor

    int getID(); // retorna o id do vertice
    int getGrau(); // retorna o grau do vertice

    void adicionaAresta(int id); // adiciona uma aresta na lista de aresta
    void removeAresta(int id_vertice_adjacente); // remove uma aresta da lista de aresta

    void imprimirArestas(); // imprime todas as arestas
};

#endif // VERTICE_H
