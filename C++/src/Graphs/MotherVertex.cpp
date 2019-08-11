#include <bits/stdc++.h>
using namespace std;

class Graph{
  int V;
  list<int> *adjList;
  void DFSUtil(int, vector<bool> &);

public:
  Graph(int);
  void addEdge(int, int);
  int findMother();
};

Graph::Graph(int V){
  this->V = V;
  adjList = new list<int>[V];
}

void Graph::DFSUtil(int V, vector<bool> &visited){
  visited[V] = true;
  list<int>::iterator i;
  for(i=adjList[V].begin(); i != adjList[V].end(); ++i)
    if(!visited[*i])
      DFSUtil(*i, visited);
}

void Graph::addEdge(int V, int W){
  adjList[V].push_back(W);//appends vector with elements
}

int Graph::findMother(){
  vector <bool> visited(V, false);
  int v=0;
  for(int i=0; i<V; i++){
    if(visited[i] == false){
      DFSUtil(i, visited);
      v=i;
    }
  }
  fill(visited.begin(), visited.end(), false);
  DFSUtil(v, visited);
  for(int i=0; i<V; i++)
    if(visited[i] == false)
      return -1;
  return v;
}

int main(){
  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(4, 1);
  g.addEdge(6, 4);
  g.addEdge(5, 6);
  g.addEdge(5, 2);
  g.addEdge(6, 0);

  cout<<"Mother Vertex: "<<g.findMother()<<endl;
  return 0;
}
