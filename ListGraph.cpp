#include "ListGraph.h"


ListGraph::ListGraph(int nVertices) :next(nVertices), prev(nVertices) {};

ListGraph::ListGraph(const ListGraph& other) : next(other.next), prev(other.prev){};

ListGraph::ListGraph(const IGraph* other) {
    for (int i = 0; i < other->VerticesCount(); ++i) {
        std::vector<int> vertices;
        other->GetNextVertices(i, vertices);
        for (int vertex: vertices)
        AddEdge(i, vertex);
    }
};

void ListGraph::AddEdge(int from, int to) {
    if(find(next[from].begin(), next[from].end(), to) == next[from].end()) {
        next[from].push_back(to);
        prev[to].push_back(from);
    }
};

int ListGraph::VerticesCount() const  {return next.size();};

void ListGraph::GetNextVertices(int vertex, vector<int>& vertices) const {
    vertices.clear();
    vertices = {next[vertex].begin(), next[vertex].end()};
};

void ListGraph::GetPrevVertices(int vertex, vector<int>& vertices) const {
    vertices.clear();
    vertices = {prev[vertex].begin(), prev[vertex].end()};
};


