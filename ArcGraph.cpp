
#include "ArcGraph.h"
#include <set>
using std::make_pair;
ArcGraph::ArcGraph(const ArcGraph &other) : edjes(other.edjes), size(other.size){}
ArcGraph::ArcGraph(int nVertices) : size(nVertices) {}
ArcGraph::ArcGraph(const IGraph *other) :size(other->VerticesCount()){
    for(int i=0; i<other->VerticesCount();++i){
        vector<int> current;
        other->GetNextVertices(i,current);
        for(int vertex:current)
            edjes.push_back(make_pair(i,vertex));
    }
}
int ArcGraph::VerticesCount() const { return size;}
void ArcGraph::AddEdge(int from, int to) {
    edjes.push_back(make_pair(from,to));
}
void ArcGraph::GetNextVertices(int vertex, vector<int> &vertices) const {
    vertices.clear();
    for(auto edje: edjes){
        if(edje.first == vertex){
            vertices.push_back(edje.second);
        }
    }
}
void ArcGraph::GetPrevVertices(int vertex, vector<int> &vertices) const {
    vertices.clear();
    for(auto edje: edjes){
        if(edje.second == vertex){
            vertices.push_back(edje.first);
        }
    }
}