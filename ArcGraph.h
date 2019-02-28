#include "IGraph.h"
#include <vector>

using std::vector;
using std::pair;
class ArcGraph : public IGraph {
public:
    ArcGraph(int nVertices);
    ArcGraph(const ArcGraph& other);
    ArcGraph(const IGraph* other);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    virtual void GetNextVertices(int vertex, vector<int>& vertices) const override;
    virtual void GetPrevVertices(int vertex, vector<int>& vertices) const override;
private:
    vector<pair<int,int>> edjes;
    int size;
};


