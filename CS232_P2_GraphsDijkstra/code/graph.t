// FileName  : graph.t
// programmer Jeff Marron 
// implementations of the graph class
#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <queue>
#include <deque>
#include <stack>
#include "graph.h"

using namespace std;

ifstream inFile;

Graph::Graph()
{}

Graph::~Graph()
{}


/***************************************************************************************************
*
*   Function Name     :		isVertex
*
*   Purpose           :		looks up a vertex in the graph to determine if it exists
*
*   Input Parameters  :		string temp
*
*	Output parameters  :	none
*
*   Return Value      :		none
*
***************************************************************************************************/
void Graph::isVertex()
{
	string temp;
	cout << "Enter name of vertex to lookup: " << endl;
	cin >> temp;

	for (Vit = adj_list.begin(); Vit != adj_list.end(); Vit++) {
		if (temp == (*Vit).name) {
			cout << temp << " is a valid vertex" << endl;
			return;
		}		
	}
	cout << temp << ": vertex does not exist" << endl;
}
///END isVertex///

/***************************************************************************************************
*
*   Function Name     :		isUniEdge
*
*   Purpose           :		looks up 2 verticies to determine if a uni-directional edge exists
*
*   Input Parameters  :		string temp1, temp2
*
*	Output parameters  :	none
*
*   Return Value      :		none
*
***************************************************************************************************/
void Graph::isUniEdge()
{
	string temp1, temp2;
	cout << "Find a uni-directional edge" << endl <<"Enter the starting vertex: " << endl;
	cin >> temp1;
	cout << "Enter the ending vertex: " << endl;
	cin >> temp2;

	for (Vit = adj_list.begin(); Vit != adj_list.end(); Vit++) {
		if (temp1 == (*Vit).name) {
			
			for (ERit = (*Vit).edgelist.begin(); ERit != (*Vit).edgelist.end(); ERit++) {
				if (temp2 == (*ERit).name) {
					cout << temp1 << " to " << temp2 << " is a unidirectional edge" << endl;
					return;
				}
			}
		}

	}
	cout << temp1 << " to " << temp2 << ": ERR - uni-directional edge does not exist" << endl;
}
///END isUniEdge///

/***************************************************************************************************
*
*   Function Name     :		isBiDirEdge
*
*   Purpose           :		looks up 2 verticies to determine if a bi directional edge exists
*
*   Input Parameters  :		string temp1, temp2
*
*	Output parameters  :	none
*
*   Return Value      :		none
*
***************************************************************************************************/
void Graph::isBiDirEdge()
{
	string temp1, temp2;
	int i = 0;
	cout << "Find a bi-directional edge" << endl << "Enter vertex 1: " << endl;
	cin >> temp1;
	cout << "Enter vertex 2: " << endl;
	cin >> temp2;

	for (Vit = adj_list.begin(); Vit != adj_list.end(); Vit++) {
		if (temp1 == (*Vit).name) {

			for (ERit = (*Vit).edgelist.begin(); ERit != (*Vit).edgelist.end(); ERit++) {
				if (temp2 == (*ERit).name) {
					i++;
				}
			}
		}

	}

	for (Vit = adj_list.begin(); Vit != adj_list.end(); Vit++) {
		if (temp2 == (*Vit).name) {

			for (ERit = (*Vit).edgelist.begin(); ERit != (*Vit).edgelist.end(); ERit++) {
				if (temp1 == (*ERit).name) {
					i++;
					if (i = 2) {
						cout << temp1 << " and " << temp2 << " form a bi-directional edge" << endl;
						return;
					}
				}
			}
		}

	}
	cout << temp1 << " to " << temp2 << ": ERR - bi-directional edge does not exist" << endl;
}
///END isBiDirEdge///

/***************************************************************************************************
*
*   Function Name     :		AddVertex
*
*   Purpose           :		adds a new vertex to the graph
*
*   Input Parameters  :		vertex tempVert, string temp
*
*	Output parameters  :	none
*
*   Return Value      :		none
*
***************************************************************************************************/
void Graph::AddVertex()
{
	vertex tempVert;
	string temp;
	cout << "Enter new Vertex Name: " << endl;
	cin >> temp;

	for (Vit = adj_list.begin(); Vit != adj_list.end(); Vit++) {
		if (temp == (*Vit).name) {
			cout << temp << " is already in the graph" << endl;
			return;
		}
	}
	tempVert.name = temp;
	adj_list.push_back(tempVert);
	cout << temp << ": added to graph" << endl;
}
///END AddVertex///

/***************************************************************************************************
*
*   Function Name     :		DeleteVertex
*
*   Purpose           :		looks up a vertex in the graph and deletes it
*
*   Input Parameters  :		string temp, vertex tempVert
*
*	Output parameters  :	none
*
*   Return Value      :		none
*
***************************************************************************************************/
void Graph::DeleteVertex()
{
	vertex tempVert;
	string temp;
	cout << "Enter Vertex to delete: " << endl;
	cin >> temp;

	for (Vit = adj_list.begin(); Vit != adj_list.end(); Vit++) {
		if (temp == (*Vit).name) {
			adj_list.erase(Vit);
			cout << temp << " was removed from the graph" << endl;
			return;
		}
	}
	cout << temp << ": ERR - unable to find Vertex" << endl;
}
///END deleteVertex///

/***************************************************************************************************
*
*   Function Name     :		AddUniEdge
*
*   Purpose           :		Adds a uni-directional edge to the graph
*
*   Input Parameters  :		string temp1, temp2, vertex tempVert, int weight, edgerep tempEdgeRep
*
*	Output parameters  :	none
*
*   Return Value      :		none
*
***************************************************************************************************/
void Graph::AddUniEdge()
{
	vertex tempVert;
	edgeRep tempEdgeRep;
	string temp1, temp2;
	int weight;
	cout << "Add a uni-directional edge" << endl << "Enter start vertex: " << endl;
	cin >> temp1;
	cout << "Enter end vertex: " << endl;
	cin >> temp2;
	cout << "Enter weight: " << endl;
	cin >> weight;

	//Tests to see if edge already exists
	for (Vit = adj_list.begin(); Vit != adj_list.end(); Vit++) {
		if (temp1 == (*Vit).name) {

			for (ERit = (*Vit).edgelist.begin(); ERit != (*Vit).edgelist.end(); ERit++) {
				if (temp2 == (*ERit).name) {
					cout << "Edge already exists" << endl;
					return;
				}
			}
			//Inserts edge at proper vertex vector
			tempEdgeRep.name = temp2;
			tempEdgeRep.weight = weight;
			(*Vit).edgelist.push_back(tempEdgeRep);
			cout << temp1 << " to " << temp2 << " " << weight << " was added to the graph" << endl;

			//now checking to see if vertex 2 is in the graph & adds when necessary
			for (Vit = adj_list.begin(); Vit != adj_list.end(); Vit++) {
				if (temp2 == (*Vit).name) {
					return;
				}				
			}
			tempVert.edgelist.clear();
			tempVert.name = temp2;
			adj_list.push_back(tempVert);
			cout << temp2 << ": new vertex added to graph" << endl;
			//return;
		}//
	}
	//Start Vertex not found
	tempVert.name = temp1;
	tempEdgeRep.name = temp2;
	tempEdgeRep.weight = weight;
	tempVert.edgelist.push_back(tempEdgeRep);
	adj_list.push_back(tempVert);
	cout << temp1 << ": new vertex added to graph" << endl;
	cout << temp1 << " to " << temp2 << " " << weight << " was added to the graph" << endl;

	//now checking to see if temp2 is a valid vertex and will create a new one if necessary

	for (Vit = adj_list.begin(); Vit != adj_list.end(); Vit++) {
		if (temp2 == (*Vit).name) {
			return;
		}
	}
	tempVert.edgelist.clear();
	tempVert.name = temp2;
	adj_list.push_back(tempVert);
	cout << temp2 << ": new vertex added to graph" << endl;
}
///END addUniEdge///

/***************************************************************************************************
*
*   Function Name     :		DeleteUniEdge
*
*   Purpose           :		deletes a unidirectional edge
*
*   Input Parameters  :		string temp1, temp2
*
*	Output parameters  :	none
*
*   Return Value      :		none
*
***************************************************************************************************/
void Graph::DeleteUniEdge()
{
	string temp1, temp2;
	cout << "Delete a uni-directional edge" << endl << "Enter start vertex: " << endl;
	cin >> temp1;
	cout << "Enter end vertex: " << endl;
	cin >> temp2;

	for (Vit = adj_list.begin(); Vit != adj_list.end(); Vit++) {
		if (temp1 == (*Vit).name) {

			for (ERit = (*Vit).edgelist.begin(); ERit != (*Vit).edgelist.end(); ERit++) {
				if (temp2 == (*ERit).name) {
					(*Vit).edgelist.erase(ERit);
					cout << temp1 << " to " << temp2 << " was removed from the graph" << endl;
					return;
				}
			}
		}

	}
	cout << temp1 << " to " << temp2 << ": ERR - Invalid Edge" << endl;
}
///END deleteUniEdge///

/***************************************************************************************************
*
*   Function Name     :		AddBiDirEdge
*
*   Purpose           :		adds a bidirectional edge
*
*   Input Parameters  :		string temp1, temp2, edgeRep tempEdgeRep, vertex tempVert
*
*	Output parameters  :	none
*
*   Return Value      :		none
*
***************************************************************************************************/
void Graph::AddBiDirEdge()
{
	bool v1= false, v2 = false, v122 = false, v221 = false;
	vertex tempVert;
	edgeRep tempEdgeRep;
	string temp1, temp2;
	int weight1, weight2, a, c;
	cout << "Add a bi-directional edge" << endl << "Enter vertex 1: " << endl;
	cin >> temp1;
	cout << "Enter vertex 2: " << endl;
	cin >> temp2;
	cout << "Enter weight from " << temp1 << " to " << temp2 << ":" << endl;
	cin >> weight1;
	cout << "Enter weight from " << temp2 << " to " << temp1 << ":" << endl;
	cin >> weight2;

	for (int i = 0; i < adj_list.size(); i++){
		if (temp1 == adj_list[i].name) {
			v1 = true; //vertex 1 exists
			a = i;
			for (int j = 0; j < adj_list[i].edgelist.size(); j++)
				if (temp2 == adj_list[i].edgelist[j].name) {
					v122 = true; //vertex 1 goes to vertex 2
				}
		}
	}
		for (int i = 0; i < adj_list.size(); i++)
{
			if (temp2 == adj_list[i].name) {
				v2 = true; //vertex 2 exists
				c = i;
				for (int j = 0; j < adj_list[i].edgelist.size(); j++)
					if (temp1 == adj_list[i].edgelist[j].name) {
						v221 = true; //vertex 2 goes to vertex 1
					}
			}
		}

	if (v122 && v221) {//if temp1 and temp2 are bidirectional:
		cout << "ERR - bi directional edge already exists between" << temp1 << " and " << temp2 << endl;
		return;
	}

	if (v122 && !v221) { //if theres an edge from 1 to 2 but not 2 to 1
		tempEdgeRep.name = temp1;
		tempEdgeRep.weight = weight1;
		adj_list[c].edgelist.push_back(tempEdgeRep);
		cout << temp2 << " to " << temp1 << " added.  Now bi-directional" << endl;
		return;
	}

	if (v221 && !v122) {//if theres an edge from 2 to 1 but not 1 to 2
		tempEdgeRep.name = temp2;
		tempEdgeRep.weight = weight2;
		adj_list[a].edgelist.push_back(tempEdgeRep);
		cout << temp1 << " to " << temp2 << " added.  Now bi-directional" << endl;
		return;
	}

	if (v1 && v2) { //if vertex 2 and vertex 1 exist
		tempEdgeRep.name = temp1;
		tempEdgeRep.weight = weight1;
		adj_list[c].edgelist.push_back(tempEdgeRep);

		tempEdgeRep.name = temp2;
		tempEdgeRep.weight = weight2;
		adj_list[a].edgelist.push_back(tempEdgeRep);
		cout << temp1 << " to " << temp2 << ": bi-directional edge created" << endl;
		return;
	}

	if (v1 && !v2) {//if vertex 1 exists but not vertex 2
		tempEdgeRep.name = temp2;
		tempEdgeRep.weight = weight1;
		adj_list[a].edgelist.push_back(tempEdgeRep);

		//create vector 2
		tempVert.name = temp2;
		tempEdgeRep.name = temp1;
		tempEdgeRep.weight = weight2;
		tempVert.edgelist.push_back(tempEdgeRep);
		adj_list.push_back(tempVert);
		cout << temp2 << " created." << endl;
		cout << temp1 << " to " << temp2 << ": bi-directional edge created" << endl;
		return;
	}

	if (v2 && !v1) {//if vertex 2 exists but not vertex 1
		tempEdgeRep.name = temp1;
		tempEdgeRep.weight = weight2;
		adj_list[c].edgelist.push_back(tempEdgeRep);

		//create vector 1
		tempVert.name = temp1;
		tempEdgeRep.name = temp2;
		tempEdgeRep.weight = weight1;
		tempVert.edgelist.push_back(tempEdgeRep);
		adj_list.push_back(tempVert);
		cout << temp1 << " created." << endl;
		cout << temp1 << " to " << temp2 << ": bi-directional edge created" << endl;
		return;
	}

	if (!v1 && !v2) { //if vertex 1 and vertex 2 dont exist
		tempVert.name = temp2;
		tempEdgeRep.name = temp1;
		tempEdgeRep.weight = weight2;
		tempVert.edgelist.push_back(tempEdgeRep);
		adj_list.push_back(tempVert);
		tempVert.edgelist.clear();

		tempVert.name = temp1;
		tempEdgeRep.name = temp2;
		tempEdgeRep.weight = weight1;
		tempVert.edgelist.push_back(tempEdgeRep);
		adj_list.push_back(tempVert);
		cout << temp1 << " and " << temp2 << "created." << endl;
		cout << temp1 << " to " << temp2 << ": bi-directional edge created" << endl;
		return;
	}
}
///END addBiDirEdge///

/***************************************************************************************************
*
*   Function Name     :		DeleteBiDirEdge
*
*   Purpose           :		deletes a bi directional edge
*
*   Input Parameters  :		string temp1, temp2, vertex tempVert, edgeRep tempEdgeRep
*
*	Output parameters  :	none
*
*   Return Value      :		none
*
***************************************************************************************************/
void Graph::DeleteBiDirEdge()
{
	vertex tempVert;
	edgeRep tempEdgeRep;
	bool v122 = false, v221 = false;
	string temp1, temp2;
	int a, b, c, d;
	cout << "Delete a bi-directional edge" << endl << "Enter vertex 1: " << endl;
	cin >> temp1;
	cout << "Enter vertex 2: " << endl;
	cin >> temp2;

	for (int i = 0; i < adj_list.size(); i++)
	{
		if (temp1 == adj_list[i].name) {
			a = i;
			for (int j = 0; j < adj_list[i].edgelist.size(); j++)
				if (temp2 == adj_list[i].edgelist[j].name) {
					v122 = true;
					b = j;
				}
		}
	}
	for (int i = 0; i < adj_list.size(); i++)
	{
		if (temp2 == adj_list[i].name) {
			c = i;
			for (int j = 0; j < adj_list[i].edgelist.size(); j++)
				if (temp1 == adj_list[i].edgelist[j].name) {
					v221 = true;
					d = j;
				}
		}
	}

	if (v122 && v221) {//if temp1 and temp2 are bidirectional:
		adj_list[a].edgelist.erase(adj_list[a].edgelist.begin() + b);
		adj_list[c].edgelist.erase(adj_list[c].edgelist.begin() + d);
		cout << "Bi-directional edge from " << temp1 << " to " << temp2 << " deleted" << endl;
		return;
	}
	cout << temp1 << " to " << temp2 << ": ERR - bi-directional edge does not exist" << endl;
}
///END deleteBiDirEdge///

/***************************************************************************************************
*
*   Function Name     :		SimplePrintGraph
*
*   Purpose           :		prints the graph
*
*   Input Parameters  :		none
*
*	Output parameters  :	none
*
*   Return Value      :		none
*
***************************************************************************************************/
void Graph::SimplePrintGraph()
{
	cout << "Graph Output: " << endl;
	
	for (Vit = adj_list.begin(); Vit != adj_list.end(); Vit++) {
		cout << (*Vit).name << " --->"<<endl;
		
		for (ERit = (*Vit).edgelist.begin(); ERit != (*Vit).edgelist.end(); ERit ++) {
			cout << " (" << (*ERit).name << ", " << (*ERit).weight <<") ";
		}
		cout << endl <<endl;
	}
}
///END SimplePrintGraph///

/***************************************************************************************************
*
*   Function Name     :		ShortestDistance
*
*   Purpose           :		performs Dijkstras algorithm to determine the shortest path
*
*   Input Parameters  :		string temp1, temp2, pick, vertex tempVert
*
*	Output parameters  :	none
*
*   Return Value      :		none
*
***************************************************************************************************/
void Graph::ShortestDistance()
{
	vector<edgeRep> Dijkstra;
	vertex tempVert;
	edgeRep tempEdgeRep;
	string temp1, temp2, pick;
	int tempw, counter = 1;
	cout << "Calculate shortest distance." << endl;
	cout << "Enter start Vertex" << endl;
	cin >> temp1;
	cout << "Enter end Vertex" << endl;
	cin >> temp2;
	cout << endl;

	//assigns values to dijkstra vector
	for (Vit = adj_list.begin(); Vit != adj_list.end(); Vit++) {
		tempEdgeRep.name = (*Vit).name;
		if (temp1 == (*Vit).name) {
			tempEdgeRep.weight = 0;
		}
		else {
			tempEdgeRep.weight = infinity;
		}
		cout << tempEdgeRep.name << " " << tempEdgeRep.weight << endl;
		Dijkstra.push_back(tempEdgeRep);
	}

	//walking down first vertex to assign initial values
	for (Vit = adj_list.begin(); Vit != adj_list.end(); Vit++) {
		if (temp1 == (*Vit).name) {
			
			(*Vit).visited = 666;//reuse this and forloop above to reset visited
			for (ERit = (*Vit).edgelist.begin(); ERit != (*Vit).edgelist.end(); ERit++) {
				for (int i = 0; i < Dijkstra.size(); i++) {
					if (Dijkstra[i].name == (*ERit).name) {
						
						if ((*ERit).weight < Dijkstra[i].weight){
							Dijkstra[i].weight = (*ERit).weight;
						}
					}
				}			
			}
		}
	}
//	cout << endl;
	//for (int i = 0; i < Dijkstra.size(); i++) {
//		cout << Dijkstra[i].name << " " << Dijkstra[i].weight << endl;}

	//walking down dijkstra
	tempw = infinity;
	for (int i = 0; i < Dijkstra.size(); i++) {
		if ((Dijkstra[i].weight < tempw) && (Dijkstra[i].weight != 0)) {
			tempw = Dijkstra[i].weight;
			pick = Dijkstra[i].name;			
		}
	}
	cout << endl << "pick is " << pick << endl;
	for (int i = 0; i < Dijkstra.size(); i++) {
		if (Dijkstra[i].name == pick) {
			Dijkstra[i].visited = 666;
		}
	}

	//main dijkstra NEEEEDS WORK
	while (counter != Dijkstra.size()) {
		for (Vit = adj_list.begin(); Vit != adj_list.end(); Vit++) {
			cout << (*Vit).name << endl;//spits out all names
			if (((*Vit).name == pick) && ((*Vit).visited == 0)) {
				cout << "test1" << endl;
				(*Vit).visited = 666;
				for (ERit = (*Vit).edgelist.begin(); ERit != (*Vit).edgelist.end(); ERit++) {
					for (int i = 0; i < Dijkstra.size(); i++) {
						if (Dijkstra[i].name == (*ERit).name) {
							if (((*ERit).weight + tempw) < Dijkstra[i].weight) {
								Dijkstra[i].weight = ((*ERit).weight + tempw);
								cout << "test2" << endl;
							}
						}
					}
				}

				tempw = infinity;
				for (int i = 0; i < Dijkstra.size(); i++) {
				if ((Dijkstra[i].weight < tempw) && (Dijkstra[i].weight != 0) && (Dijkstra[i].visited != 666)) {
						tempw = Dijkstra[i].weight;
						pick = Dijkstra[i].name;
						cout << " New Pick" << pick << endl;
					}
				}

				for (int i = 0; i < Dijkstra.size(); i++) {
					if (Dijkstra[i].name == pick) {
						Dijkstra[i].visited = 666;
					}
				}
			
			}
		}
		counter++;
	}


	for (int i = 0; i < Dijkstra.size(); i++) {
		if (Dijkstra[i].name == temp2) {
			cout << "Shortest distance from " << temp1 << " to " << 
				temp2 << " is: " << Dijkstra[i].weight << endl;
			return;
		}
	}
	cout << "Error" << endl;
}
///END ShortestDistance///


/***************************************************************************************************
*
*   Function Name     :		GetGraph
*
*   Purpose           :		parses the graph from the input file
*
*   Input Parameters  :		inFile
*
*	Output parameters  :	none
*
*   Return Value      :		none
*
***************************************************************************************************/
void Graph::GetGraph()
{
	if (!inFile)
		return;

	string VS, VE;
	int weight;
	edgeRep tempEdgeRep;
	vertex tempVert;

	inFile >> VS;

	while (!inFile.eof())
	{
		tempVert.name = VS;

		inFile >> VE;
		while (VE != "#")
		{
			inFile >> weight;

			tempEdgeRep.name = VE;
			tempEdgeRep.weight = weight;
			tempVert.edgelist.push_back(tempEdgeRep);

			//for debugging
			//cout << VS << " " << VE << " " << weight << endl;
			inFile >> VE;
		}
		adj_list.push_back(tempVert);
		tempVert.edgelist.clear();
		inFile >> VS;
	}
	inFile.close();
}
///END GetGraph///

/***************************************************************************************************
*
*   Function Name     :		BFTraversal
*
*   Purpose           :		performs a breadth first traversal
*
*   Input Parameters  :		none
*
*	Output parameters  :	none
*
*   Return Value      :		none
*
***************************************************************************************************/
void Graph::BFTraversal()
{
	queue<string> BFT;
	vector<edgeRep> visited;
	vertex tempVert;
	edgeRep tempEdgeRep;
	string temp1, target;
	int tempw, a;
	cout << "Breadth First Traversal" << endl;
	cout << "Enter start Vertex" << endl;
	cin >> temp1;
	cout << endl;

	//creates temporary vector to keep track of visited nodes
	for (int i = 0; i < adj_list.size(); i++) {
		tempEdgeRep.name = adj_list[i].name;
		visited.push_back(tempEdgeRep);
	}
	//resets adj list and finds starting vertex
	for (int i = 0; i < adj_list.size(); i++) {
		if (temp1 == adj_list[i].name && visited[i].visited != 1) {
			visited[i].visited = 1;
			BFT.push(adj_list[i].name);
			a = i;
		}
	}
		while (!BFT.empty()) {
			for (int j = 0; j < adj_list[a].edgelist.size(); j++) {

				for (int k = 0; k < visited.size(); k++) {
					if ((visited[k].name == adj_list[a].edgelist[j].name) && (visited[k].visited != 1)) {
						visited[k].visited = 1;//sets visited while iterating though a vertex edgelist
						BFT.push(adj_list[a].edgelist[j].name);
					}
				}
			}
				cout << BFT.front() << endl;
				BFT.pop();
				if (!BFT.empty()) {
					target = BFT.front();//new adj_list target is next in que
					for (int i = 0; i < adj_list.size(); i++) {
						if (target == adj_list[i].name) {
							visited[i].visited = 1;//sets visited while iterating through verticies
							a = i; //sets the value a to iterate through that vertex edgelist
						}
					}
				}
			}
}
///END BFTraversal///

/***************************************************************************************************
*
*   Function Name     :		DFTraversal
*
*   Purpose           :		performs a depth first traversal
*
*   Input Parameters  :		none
*
*	Output parameters  :	none
*
*   Return Value      :		none
*
***************************************************************************************************/
void Graph::DFTraversal()
{
	stack<string> DFT;
	vector<edgeRep> visited;
	vertex tempVert;
	edgeRep tempEdgeRep;
	string temp1, target;
	int tempw, a;
	cout << "Depth First Traversal" << endl;
	cout << "Enter start Vertex" << endl;
	cin >> temp1;
	cout << endl;

	//creates temporary vector to keep track of visited nodes
	for (int i = 0; i < adj_list.size(); i++) {
		tempEdgeRep.name = adj_list[i].name;
		visited.push_back(tempEdgeRep);
	}
	DFT.push(" ");//keeps a dummy node so that the empty check works in th while loop
	//resets adj list and finds starting vertex
	for (int i = 0; i < adj_list.size(); i++) {
		if (temp1 == adj_list[i].name && visited[i].visited != 1) {
			visited[i].visited = 1;
			DFT.push(adj_list[i].name);
			cout << DFT.top() << endl;
			DFT.pop();
			a = i;
		}
	}

	while (!DFT.empty()) {
		for (int j = 0; j < adj_list[a].edgelist.size(); j++) {

			for (int k = 0; k < visited.size(); k++) {
				if ((visited[k].name == adj_list[a].edgelist[j].name) && (visited[k].visited != 1)) {
					visited[k].visited = 1;//sets visited while iterating though a vertex edgelist
					DFT.push(adj_list[a].edgelist[j].name);
					k = visited.size();
				}
			}
		}
		target = DFT.top();//new adj_list target is next in stack
		cout << DFT.top() << endl;
		DFT.pop();
		if (!DFT.empty()) {		
			for (int i = 0; i < adj_list.size(); i++) {
				if (target == adj_list[i].name) {
					visited[i].visited = 1;//sets visited while iterating through verticies
					a = i; //sets the value a to iterate through that vertex edgelist
				}
			}
		}
	}
}
///END DFTraversal///

/***************************************************************************************************
*
*   Function Name     :		getFileName
*
*   Purpose           :		gets the filename from the user
*
*   Input Parameters  :		inFilename
*
*	Output parameters  :	none
*
*   Return Value      :		inFilename
*
***************************************************************************************************/
string Graph::getFileName(ifstream &, string & inFilename) {
	cout << "Enter the input file name: " << flush;
	getline(cin, inFilename);
	do {
		inFile.open(inFilename.c_str());
		if (inFile.is_open()) {
			cout << "'" << inFilename << "' open: success" << endl;
			return inFilename;
		}
		else {
			cout << "Invalid file, or file could not be opened, or does not exist. "
				<< endl;
			return inFilename;
		}
	} while (inFile.is_open());
	return inFilename;
}
///END getFileName ///

#endif