

#include "SetGraph.h"

SetGraph::SetGraph(int nVertices) :next(nVertices),prev(nVertices){}
SetGraph::SetGraph(const SetGraph &other) :next(other.next),prev(other.prev){}
SetGraph::SetGraph(const IGraph *other) {
    for(int i=0; i<other->VerticesCount();++i){
        vector<int> current;
        other->GetNextVertices(i,current);
        for(int verticle:current)
            next[i].insert(verticle);
        other->GetPrevVertices(i,current);
        for(int verticle:current)
            prev[i].insert(verticle);
    }
}
void SetGraph::AddEdge(int from, int to) {
    next[from].insert(to);
    prev[to].insert(from);
}
void SetGraph::GetPrevVertices(int vertex, vector<int> &vertices) const {
    vertices.clear();
    for(int verticle:prev[vertex]){
        vertices.push_back(verticle);
    }
}
void SetGraph::GetNextVertices(int vertex, vector<int> &vertices) const {
    vertices.clear();
    for(int verticle:next[vertex]){
        vertices.push_back(verticle);
    }
}
int SetGraph::VerticesCount() const { return next.size();}