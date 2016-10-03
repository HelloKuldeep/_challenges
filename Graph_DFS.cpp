#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	void DFSutil(int s,bool visit[]);
	public:
		Graph(int V);
		void addEdge(int v,int w);
		void DFS(int s);
};
Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}
void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}
void Graph::DFSutil(int s,bool visit[]){
	cout<<s<<" ";
	visit[s]=true;
	list<int>::iterator i;
	for(i=adj[s].begin();i!=adj[s].end();++i){
		if(!visit[*i]){
			DFSutil(*i,visit);
		}
	}
}
void Graph::DFS(int s){
	bool visit[V];
	for(int i=0;i<V;++i)	visit[i]=false;
	DFSutil(s,visit);
}
int main() {
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(0,2);
	g.addEdge(3,4);
	g.addEdge(2,3);
	g.addEdge(1,3);
	g.DFS(0);
	return 0;
}
