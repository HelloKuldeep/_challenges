#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	bool DFScycle(int s,bool visit[],bool recStack[]);
	public:
		Graph(int V);
		void addEdge(int v,int w);
		bool DFS();
};
Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}
void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}
bool Graph::DFScycle(int s,bool visit[],bool recStack[]){
	if(visit[s]==false){
		visit[s]=true;
		recStack[s]=true;
		list<int>::iterator i;
		for(i=adj[s].begin();i!=adj[s].end();++i){
			if(!visit[*i] && DFScycle(*i,visit,recStack))
				return true;
			else if(recStack[*i]==true)
				return true;
		}
	}
	recStack[s]=false;
	return false;
}
bool Graph::DFS(){
	bool visit[V],recStack[V];
	for(int i=0;i<V;++i){
		visit[i]=false;
		recStack[i]=false;
	}
	for(int i=0;i<V;++i)
		if(DFScycle(i,visit,recStack))	return true;
	return false;
}
int main(){
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(2,1);
	g.addEdge(2,4);
	//g.addEdge(3,0);     //Uncomment this to obtain cycle.
	g.addEdge(4,1);
	if(g.DFS())	cout<<"Cycle";
	else cout<<"No Cycle";
	return 0;
}
