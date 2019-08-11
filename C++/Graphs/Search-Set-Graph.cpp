#include <bits/stdc++.h>
using namespace std;

struct Graph{
  int V;
  set<int, greater<int>> * adjList;
};
Graph * createGraph(int V){
  Graph * graph = new Graph;
  graph->V = V;
  graph->adjList = new unordered_set<int>[V];
  return graph
}

void addEdge(Graph * graph, int src, int dest){
  graph->adjList[src].insert(dest);
  graph->adjList[dest].insert(src);
}

void printGraph(Graph * graph){
  for(int i=0; i < graph->V; ++i){
    unordered_set<int> lst = graph->adjList[i];
    cout<<endl<<"Adjacency list of Vertex "<<V<<":";
    for(auto itr=lst.begin(); itr != lst.end(); ++itr)
      cout<<*itr<<"";
    cout<<endl;
  }
}

void searchEdge(Graph * graph, int src, int dest){
  auto itr = graph->adjList[src].find(dest);
  if(itr == graph.adjList[src].end())
    cout<<"Edge from "<<src<<"to "<<dest<<" not found"<<endl;
  else
    cout<<"Edge from "<<src<<"to "<<dest<<" found"<<endl;
}

int main(){
  int V=5;
  struct Graph * graph = createGraph(V);
}
