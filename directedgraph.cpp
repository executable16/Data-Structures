#include<bits/stdc++.h>
using namespace std;

class Graph{
private:

	int V,E;
	int visitedNodes;
	vector<vector<int>> graph;
	bool isDirected;
	unordered_map<int,int> incomingEdgesCount;
	queue<int> nodesWithZeroIncomingEdges;

public:

	Graph(int V){
		visitedNodes = 0;
		this->V = V;
		graph.resize(V);
		isDirected = true;
	}
	void addNewEdge(int source , int destination);
	bool cycleExistsAt(int node,vector<bool>&visited,vector<bool>&currentRecursiveState); // Based on recursive stack (typical DFS)
	bool cycleExistsAt(); // This method is based on incoming edge principle 

};


void Graph :: addNewEdge(int source,int destination){
	graph[source].push_back(destination);
	incomingEdgesCount[destination]++;
	if(!isDirected) graph[destination].push_back(source);
}

bool Graph :: cycleExistsAt(int source,vector<bool>&visited,vector<bool>&currentRecursiveState){
	if(currentRecursiveState[source] == true) return true;
	if(visited[source]) return false;

	visited[source] = true;
	currentRecursiveState[source] = true;
	
	for(int neighbor : graph[source]){
		if(cycleExistsAt(neighbor,visited,currentRecursiveState)) return true;
	}

	currentRecursiveState[source] = false;
	return false;

}

bool Graph :: cycleExistsAt(){
	for(auto info : incomingEdgesCount){
		if(info.second == 0){
			nodesWithZeroIncomingEdges.push(info.first);
		}
	}

	while(!nodesWithZeroIncomingEdges.empty()){
		visitedNodes++;
		int source = nodesWithZeroIncomingEdges.front();
		nodesWithZeroIncomingEdges.pop();

		for(int neighbors : graph[source]){
			incomingEdgesCount[neighbors]--;

			if(incomingEdgesCount[source] == 0)
				nodesWithZeroIncomingEdges.push(neighbors);
		} 
	}
	return visitedNodes != V;
}

int main(){
	Graph obj = Graph(8);
	// obj.isDirected = true;
	obj.addNewEdge(1,2);
	obj.addNewEdge(2,3);
	obj.addNewEdge(5,1);
	obj.addNewEdge(5,4);
	obj.addNewEdge(7,5);
	obj.addNewEdge(6,7);
	obj.addNewEdge(4,6);
	obj.addNewEdge(4,1);

	vector<bool> visited(8,false);
	vector<bool> currentRecursiveState(8,false);

	for(int i = 1 ; i <= 7 ; i++){
		if(obj.cycleExistsAt(i,visited,currentRecursiveState)) {cout<<true<<endl; break;}
		else continue;
	}

	cout<<obj.cycleExistsAt()<<endl;



}