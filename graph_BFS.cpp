#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	public:
		Graph(int V);
		void addEdge(int v,int w);
		void BFS(int s);
};
Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}
void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}
void Graph::BFS(int s){
	bool *visit=new bool[V];
	for(int i=0;i<V;++i)	visit[i]=false;
	list<int> queue;
	queue.push_back(s);
	visit[s]=true;
	list<int>::iterator i;
	while(!queue.empty()){
		s=queue.front();
		cout<<s<<" ";
		queue.pop_front();
		for(i=adj[s].begin();i!=adj[s].end();++i){
			if(!visit[*i]){
				queue.push_back(*i);
				visit[*i]=true;
			}
		}
	}
}
int main(){
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(0,2);
	g.addEdge(3,4);
	g.addEdge(2,3);
	g.addEdge(1,3);
	g.BFS(0);
	return 0;
}
