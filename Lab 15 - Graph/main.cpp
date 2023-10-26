
#include <iostream>
#include "graphtype.cpp"
using namespace std;

void Print(bool b){
    if(b)
        cout << "There is an edge." << endl;
    else
        cout << "There is no edge." << endl;
}

int main() {

    GraphType<char> g;                         

    g.AddVertex('A');                           
    g.AddVertex('B');
    g.AddVertex('C');
    g.AddVertex('D');
    g.AddVertex('E');
    g.AddVertex('F');
    g.AddVertex('G');
    g.AddVertex('H');

    g.AddEdge('A', 'B', 1);                     
    g.AddEdge('A', 'C', 1);
    g.AddEdge('A', 'D', 1);

    g.AddEdge('B', 'A', 1);

    g.AddEdge('D', 'A', 1);
    g.AddEdge('D', 'E', 1);
    g.AddEdge('D', 'G', 1);

    g.AddEdge('G', 'F', 1);
    g.AddEdge('F', 'H', 1);
    g.AddEdge('H', 'E', 1);

    cout << g.OutDegree('D') << endl;            

    Print(g.FoundEdge('A', 'D'));                
    Print(g.FoundEdge('B', 'D'));                

    g.DepthFirstSearch('B', 'E');                
    g.DepthFirstSearch('E', 'B');                

    g.BreadthFirstSearch('B', 'E');              
    g.BreadthFirstSearch('E', 'B');              

    g.BreadthFirstSearch('B', 'E');              
    return 0;
}
