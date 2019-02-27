#include <algorithm>
#include <list>
#include "IGraph.h"
using std::vector;
class MatrixGraph : public IGraph {
public:
    MatrixGraph(int nVertices);
    MatrixGraph(const MatrixGraph& other);
    MatrixGraph(const IGraph* other);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    virtual void GetNextVertices(int vertex, vector<int>& vertices) const override;
    virtual void GetPrevVertices(int vertex, vector<int>& vertices) const override;
private:
    vector<vector<char>> adjacency_matrix;
};