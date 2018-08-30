#ifndef ARESTA_H
#define ARESTA_H

/*
*
*@Author João Victor Lopes Fam
*
*
*/

using namespace std;


class Aresta
{
private:
    int id_vertice; // armazena o valor do id em que o grafo que contém essa aresta está ligado

public:
    Aresta(); //contrutor
    Aresta(int id_vertice_adjacente); // contrutor com parametros
    ~Aresta(); // destrutor

    int getIdVertice(); // retorna o id do vertice

    void setIdVertice(int id); // define o id do vertice
};

#endif // ARESTA_H
