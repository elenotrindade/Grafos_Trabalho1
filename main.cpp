#include <iostream>
#include <Grafo.h>
#include <GrafoMatrizAdj.h>
#include <GrafoListaAdj.h>
#include <fstream>
#include <cstdlib>


using namespace std;

void gerarGrafoPorArquivo(std::string nome_arquivo ,Grafo* grafo) // aceita como parâmetro o nome do arquivo na pasta e o grafo que se deseja popular
{
    string caminhoArquivo = "instancias_grafos/" + nome_arquivo + ".txt";
    ifstream inFile(caminhoArquivo.c_str());
    int numero_vertices;
    int vertice_1, vertice_2;
    //inFile.open(caminhoArquivo); // abre o arquivo

    //instancias_grafos/grafo_1000_1
    if(!inFile) {        //verifica se o arquivo foi encontrado
        cerr << "incapaz de ler o arquivo";
        exit(1);
    }

    inFile >> numero_vertices; // adiciona o primeiro número encontrado no arquivo como inteiro em numero_vertices
    //grafo = new Grafo(numero_vertices);
    for(int i=1; i<=numero_vertices; i++){ //itera sobre o número de vertices para adicionar os vertices no grafo
        grafo->adicionarVertice(i); // é adicionado um vertice no grafo com o id = i
    }
    while(inFile >> vertice_1 && inFile >> vertice_2){ //enquanto encontrar os pares de valores no arquivo, é adicionada uma aresta ao grafo
        grafo->adicionarAresta(vertice_1, vertice_2);
    }

    inFile.close(); // fechando leitor
}

int main()
{
    cout << "Trabalho 1 de grafos: " << endl;

    cout << "qual tipo de estrutura deseja usar, digite (1) para matriz de adjacência ou (2) para lista de adjacências: ";
    int tipoEstrutura;
    cin >> tipoEstrutura;

    cout << "digite o nome do arquivo que se deseja usar (nao inclua .txt ao escrever o nome): ";
    string nomeArquivo;
    cin >> nomeArquivo;

    if(tipoEstrutura== 1){
        GrafoMatrizAdj grafo;
        gerarGrafoPorArquivo(nomeArquivo, &grafo); // popula o grafo através do arquivo
        int num_vertices = grafo.getNumeroVertices();
        cout << "Número de vertices: " << num_vertices << endl;
        grafo.imprimirVertices();
        grafo.removerAresta(1, 2);
        grafo.removerVertice(1);
        grafo.imprimirVertices();
        for(int i=0; i <= num_vertices; i++){
            grafo.imprimirArestas(i);
        }
    }
    else if(tipoEstrutura == 2){
        GrafoListaAdj grafo;
        gerarGrafoPorArquivo(nomeArquivo, &grafo); // popula o grafo através do arquivo
        int num_vertices = grafo.getNumeroVertices();
        grafo.removerAresta(1, 2);
        cout << "Número de vertices: " << num_vertices << endl;
        grafo.imprimirVertices();
        for(int i=0; i <= num_vertices; i++){
            grafo.imprimirArestas(i);
        }
    }

    return 0;
}
