#pragma once
#include <vector>

struct IGraph {
    IGraph() {}
    IGraph(const IGraph* other){
        for (int i = 0; i < other->VerticesCount(); ++i){
            std::vector<int> vertices;
            other->GetNextVertices(i, vertices);
            for (auto vertex = vertices.begin(); vertex != vertices.end();++vertex) {
                AddEdge(i, *vertex);
            }
        }
    }
    virtual ~IGraph(){}
    virtual void AddEdge(int from, int to){};
    virtual int VerticesCount() const = 0;
    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const = 0;
    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const = 0;
};