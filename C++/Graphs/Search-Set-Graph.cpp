#include <bits/stdc++.h>
using namespace std;

//set<int, greater<int>> sorts the
//Adjacency List in a descending order.

// set::begin(): Returns an iterator referring to the first element in the set container.
// set::end(): Returns an iterator referring to the past-the-end element in the set container.

// auto keyword helps in iterating through containers, sets here -> for(auto itr : 'set-name') cout<<itr;

struct Graph{
  int V;
  set<int, greater<int>> * adjList;
};
Graph * createGraph(int V){
  Graph * graph = new Graph;
  graph->V = V;
  graph->adjList = new set<int, greater<int>>[V];
  return graph;
}

void addEdge(Graph * graph, int src, int dest){
  graph->adjList[src].insert(dest);
  graph->adjList[dest].insert(src);
  /* to print the sources and destinations with every edge that's added*/
  // for(auto itr: graph->adjList[i])
  //   cout<<itr<<" ";
  // cout<<endl;
  //
  // for(auto itr: graph->adjList[i])
  //   cout<<itr<<" ";
  // cout<<endl;

}

void printGraph(Graph * graph){
  for(int i=0; i < graph->V; ++i){
    set<int, greater<int>> lst = graph->adjList[i];
    cout<<endl<<"Adjacency list of Vertex "<<i<<":";
    for(auto itr=lst.begin(); itr != lst.end(); ++itr)
      cout<<*itr<<" ";
    cout<<endl;
  }
}

void searchEdge(Graph * graph, int src, int dest){
  auto itr = graph->adjList[src].find(dest);
  if(itr == graph->adjList[src].end())
    cout<<"Edge from "<<src<<" to "<<dest<<" not found"<<endl;
  else
    cout<<"Edge from "<<src<<" to "<<dest<<" found"<<endl;
}

int main(){
  int V=5;
  struct Graph * graph = createGraph(V);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);

  // printGraph(graph);
  //
  // searchEdge(graph, 3,2);
  // searchEdge(graph, 4,1);
  // searchEdge(graph, 2,4);
  // searchEdge(graph, 2,4);

}
