#include "GrafoListaAdj.h"
#include <list>


GrafoListaAdj::GrafoListaAdj()
{
    //construtor
}

GrafoListaAdj::GrafoListaAdj(int num_vertices) // construtor passando o numero de vertices do grafo
{
    for(int i = 0; i < num_vertices; i++) { // itera sobre o numero de vertices passado
        Vertice vertice = Vertice(i); // instancia um objeto do tipo vertice passando i como id
        this->vertices.push_back(vertice); // adiciona o veertice instanciado na lista de vertices do grafo
    }
}

GrafoListaAdj::~GrafoListaAdj()
{
    //dtor
}

void GrafoListaAdj::adicionarVertice(int id) { // adiciona um vertice com o d passado por parametro
    Vertice vertice = Vertice(id); // instancia o objeto
    vertices.push_back(vertice); // adiciona o vertice na lista de vertices do grafo
}

void GrafoListaAdj::removerVertice(int id) { // remove um vertice da lista de acordo com id passado por parametro
    list <Vertice>::iterator it; // iterador de uma lista de vertices

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it) { // itera sobre a lista de vertices do grafo
        if(it->getID() == id){ // compara o id dos vertices com o id passado por parametro
            this->vertices.erase(it); // apaga o vertice da lista
            break; // finaliza o laço de repetição
        }
    }
}

void GrafoListaAdj::adicionarAresta(int id_vertice_1, int id_vertice_2) { // adiciona nas listas de arestas dos dois vertices o id um no outro
    list <Vertice>::iterator it; // iterador de uma lista de vertices

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it){ // itera sobre a lista de vertices do grafo
        if(it->getID() == id_vertice_1) // compara o id do vertice com o id 1
            it->adicionaAresta(id_vertice_2); // adiciona uma aresta na lista de vertices do vertice 1, uma aresta que representa o vertice 2
        if(it->getID() == id_vertice_2) // compara o id do vertice com o id 2
            it->adicionaAresta(id_vertice_1); // adiciona uma aresta na lista de vertices do vertice 2, uma aresta que representa o vertice 1
    }
}

void GrafoListaAdj::removerAresta(int id_vertice_1, int id_vertice_2){ // remove nas listas de arestas dos vertices a aresta que relacionam esses dois vertices
    list <Vertice>::iterator it; // iterador

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it){ // itera sobre a lista de vertces do grafo
        if(it->getID() == id_vertice_1) // compara o id do vertice com o id 1
            it->removeAresta(id_vertice_2); // remove a aresta do vertice 1 que representa o vertice 2
        if(it->getID() == id_vertice_2) // compara o id do vertice com o id 2
            it->removeAresta(id_vertice_1); // remove a aresta do vertice 2 que representa o vertice 1
    }
}

int GrafoListaAdj::getGrau(int id_vertice){ // retorna o grau de um vertice com o id passado por parametro
    list <Vertice>::iterator it; // iterador

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it){ // itera sobre a lista de vertices do grafo
        if(it->getID() == id_vertice){ // procura o vertice que tem o id igual ao passado por parâmetro
            return it->getGrau(); // retorna o grau desse vertice
        }
    }
}

int GrafoListaAdj::getNumeroVertices(){ // retorna o tamanho da lista de vertices
    return this->vertices.size();
}

void GrafoListaAdj::imprimirVertices() { // imprime uma listagem com os id dos vertices presentes no grafo
    list <Vertice>::iterator it;

    cout << "Vertices do grafo: ";
    for(it = this->vertices.begin(); it != this->vertices.end(); ++it){
        cout << it->getID() << " ";
    }
    cout << endl;
}

void GrafoListaAdj::imprimirArestas(int id_vertice){ // imprime uma listagem da arestas de um vertice que tem id igual ao passado por parametro
    list <Vertice>::iterator it;

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it){
        if(it->getID() == id_vertice){
            it->imprimirArestas();
        }
    }
}
