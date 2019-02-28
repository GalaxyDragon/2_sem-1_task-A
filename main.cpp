#include <iostream>
#include <string>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    IGraph* Dummy;
    cout<<"You wanna test:"<<endl<<"1) List Graph" << endl << "2) MatrixGraph"<< endl<<"3) SetGraph"<<endl<<"4) ArcGraph"<<endl;
    int n;
    cin>>n;
    if(n==1){
        Dummy = new ListGraph(6);
    }else if(n==2){
        Dummy = new MatrixGraph(6);
    } else if(n==3){
        Dummy = new SetGraph(6);
    }else if(n==4){
        Dummy = new ArcGraph(6);
    }
    cout<< "Start entering edjes" << endl;
    Dummy->AddEdge(0,1);
    Dummy->AddEdge(1,2);
    Dummy->AddEdge(1,3);
    Dummy->AddEdge(1,4);
    Dummy->AddEdge(0, 2);
    Dummy->AddEdge(1,5);
    cout << "Finish" << endl << "Get size" << endl;
    std::string answer = (Dummy->VerticesCount() == 6)?"YES":"NO";
    cout << answer ;
    cout << endl << "Next verticles"<<endl;
    std::vector<int> a;
    Dummy->GetNextVertices(1,a);
    for(int i:a)
        std::cout<<i<<" ";
    cout << endl << "Prev verticles"<<endl;
    Dummy->GetPrevVertices(2,a);
        std::cout << endl;
    for(int i:a)
        std::cout<<i<<" ";
    std::cout << endl << "Finish";
    return 0;
}