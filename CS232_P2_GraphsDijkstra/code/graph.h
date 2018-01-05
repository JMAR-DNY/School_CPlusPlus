// FileName  : graph.h
// programmer Jeff Marron 
// definition of the graph class

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <fstream>
using namespace std;

// V is the vertex class; W is edge weight class
struct edgeRep
{
	string name;               // Vertex name
	int weight;             // Edge weight
	int visited = 666;
};


struct vertex           // Array cell structure for graph
{
string name;               // Vertex name
int visited = 0;          // Used during traversal, Breadth-First or Depth-First
vector<edgeRep> edgelist; 	// Pointer to edge list
};

class Graph
{

protected:

	int infinity = 99999;
	vector <vertex> adj_list;
	string inFilename;
	vector<vertex>::iterator Vit;
	vector<edgeRep>::iterator ERit;

public:
	string getFileName(ifstream&, string & inFilename);
	Graph();   // Constructor
			   // . . . other constructors
	~Graph();  // Destructor
			   //Predicates:

	void isVertex();  // Tests whether v is a vertex in the graph
	void isUniEdge(); // Tests whether edge <v1,v2> in graph
	void isBiDirEdge();// Tests whether edge (v1,v2) in graph
								  // The following functions return -1 for failure, non-neg for success
	void AddVertex();
	// Adds vertex with name v to the graph, if v is not already in 
	// graph, and returns the index where the vertex is stored.
	void DeleteVertex();
	// Deletes vertex with name v from the graph, if v is in the graph.
	// If there are any edges incident on the vertex, these edges
	// are deleted also.
	void AddUniEdge();
	// Adds the directed edge <v1,v2,wt> to the graph; adds the vertices
	// to the graph if the vertices are not already part of the graph    
	void  DeleteUniEdge();
	// Deletes the directed edge <v1,v2> (any weight) from the graph, if 
	// it is in the graph. The vertices are not deleted from the graph,
	// only the edge.
	void AddBiDirEdge();
	// Adds the bi-directional edge (v1,v2,wt) to the graph; adds the
	// vertices to the graph if the vertices are not already part of 
	// the graph
	void DeleteBiDirEdge();
	// Deletes the bi-directional edge (v1,v2) (any weight) from the 
	// graph, if it is in the graph. The vertices are not deleted from 
	// the graph, only the edge.
	void SimplePrintGraph();
	// Prints the list of vertices in the graph, and for each vertex,
	// prints the list of edges in proper parenthesized notation, namely
	// (v1,v2,wt) or <v1,v2,wt>.  NOTE: This is not a traversal.
	void ShortestDistance();
	//returns the shortest distance from vertex 1 to vertex 2
	// use Dijkstra
	void GetGraph();
	//Retrieves a graph from a special disk file and sets up the adjacency
	//list for the graph.  I am supplying 3 such files.
	void BFTraversal();
	// Performs Breadth First Traversal with trace information printed 
	void DFTraversal();
	//Performs a recursive Depth First Traversal of the graph starting at 
	//specified vertex(parameter); prints trace information.

};
#include "graph.t"
#endif