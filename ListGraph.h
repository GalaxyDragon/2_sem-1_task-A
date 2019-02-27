#include <vector>
#include <list>
#include <algorithm>
#include "IGraph.h"

using std::vector;
using std::list;
class ListGraph : public IGraph {
public:
    ListGraph(int nVertices);
    ListGraph(const ListGraph& other);
    ListGraph(const IGraph* other);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    virtual void GetNextVertices(int vertex, vector<int>& vertices) const override;
    virtual void GetPrevVertices(int vertex, vector<int>& vertices) const override;
private:
    vector<list<int>> next;
    vector<list<int>> prev;
};