#include "IGraph.h"
#include <vector>
#include <set>

using std::vector;
using std::set;

class SetGraph : public IGraph {
public:
    SetGraph(int nVertices);
    SetGraph(const SetGraph& other);
    SetGraph(const IGraph* other);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    virtual void GetNextVertices(int vertex, vector<int>& vertices) const override;
    virtual void GetPrevVertices(int vertex, vector<int>& vertices) const override;
private:
    vector<set<int>> next;
    vector<set<int>> prev;
};


