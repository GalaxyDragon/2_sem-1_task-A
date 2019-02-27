#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int nVertices) :adjacency_matrix(nVertices,vector<char>(nVertices)) {};

MatrixGraph::MatrixGraph(const MatrixGraph& other) :adjacency_matrix(other.adjacency_matrix){};

MatrixGraph::MatrixGraph(const IGraph *other) {
    adjacency_matrix = vector<vector<char>>(other->VerticesCount(),vector<char>(other->VerticesCount()));
    for(int i=0; i<other->VerticesCount();++i){
        std::vector<int> verticles;
        other->GetNextVertices(i,verticles);
        for(auto vertex = verticles.begin();vertex != verticles.end();++i){
            adjacency_matrix[i][*vertex]=1;
        }
    }
};

int MatrixGraph::VerticesCount() const {return adjacency_matrix.size();};

void MatrixGraph::AddEdge(int from, int to) {adjacency_matrix[from][to]=1;};

void MatrixGraph::GetNextVertices(int vertex, vector<int> &vertices) const {
    vertices.clear();
    for(int counter = 0;counter <adjacency_matrix.size();++counter){
        if(adjacency_matrix[vertex][counter]){
            vertices.push_back(counter);
        }
    }
}
void MatrixGraph::GetPrevVertices(int vertex, vector<int> &vertices) const {
    vertices.clear();
    for(int counter = 0;counter <adjacency_matrix.size();++counter){
        if(adjacency_matrix[counter][vertex]){
            vertices.push_back(counter);
        }
    }
}
