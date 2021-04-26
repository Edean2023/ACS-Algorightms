// GraphTutorial.cpp : Creates a directed, unweighted graph.
//

#include "stdafx.h"
#include <time.h>
#include "CSC382Graph_NodeBased.h"
#include "CSC382Graph_AdjacencyList.h"

using namespace std;

bool Testing_NodeBased()
{
	cout << "\n\n\n---------------------------" << endl;
	cout << "Node Based Graph Test" << endl;
	cout << "---------------------------" << endl << endl;

	//create graph
	CSC382Graph_NodeBased<int> graph;
	
	//create 2 vertexes
	CSC382Graph_Vertex<int>* vertex_1 = new CSC382Graph_Vertex<int>(5);
	CSC382Graph_Vertex<int>* vertex_2 = new CSC382Graph_Vertex<int>(10);
	
	// insert the vertexes
	cout << "Inserting vertex_1 and vertex_2..." << endl;
	graph.Insert(vertex_1);
	graph.Insert(vertex_2);

	//connect the two vertexes with an edge
	cout << "Creating new edge between vertex_1 and vertex_2..." << endl;
	graph.AddEdge(vertex_1, vertex_2);
	
	//insert a vertex by value
	cout << "Creating new vertex with value of 7..." << endl;
	graph.Insert(7);

	//check if vertex_2 is a edge of vertex_1
	cout << "Vertex_2 is an edge of vertex_1: " << graph.IsEdge(vertex_1, vertex_2) << endl;

	//find the vertex with value of 7 that we added before
	cout << "Finder vertex with value of 7..." << endl;
	CSC382Graph_Vertex<int>* vertex_3 = graph.FindVertex(7);
	
	//remove the edge between vertex_1 and vertex_2
	cout << "Removing edge between vertex_1 and vertex_2..." << endl;
	graph.RemoveEdge(vertex_1, vertex_2);

	//remove vertex_1
	cout << "Removing vertex_1..." << endl;
	graph.RemoveVertex(vertex_3);

	//get the size of the graph, should be 2
	cout << "Graph Size (Should be 2): " << graph.Size() << endl; 

	cout << "Inserting 30 nodes and edges..." << endl;

	//pointer to previously generated vertex
	CSC382Graph_Vertex<int>* prev = vertex_2;

	for (int i = 0; i < 30; i++) {
		//generate a random value
		int value = rand() % 1000 + 1;

		//add the value to the list
		CSC382Graph_Vertex<int>* temp = graph.Insert(value);

		//connect the new value and the previous value
		graph.AddEdge(prev, temp);

		//set prev
		prev = temp;
	}

	cout << "Done adding nodes and edges, new graph size: " << graph.Size() << endl;

	return false;
}

bool Testing_AdjacencyList()
{
	cout << "\n\n\n---------------------------" << endl;
	cout << "Adjacency List Graph Test" << endl;
	cout << "---------------------------" << endl << endl;

	//create a graph
	CSC382Graph_AdjacencyList<int> graph;
	
	//insert 2 verticies and store their references
	cout << "Creating two new vertexes..." << endl;
	list<int>* vertex_1 = graph.AddVertex(3);
	list<int>* vertex_2 = graph.AddVertex(5);

	//add a edge
	cout << "Adding edge between vertex_1 and vertex_2... Result:";
	cout << (graph.AddEdge(vertex_1, vertex_2) ? "success" : "failure") << endl;

	//insert a third vertex
	cout << "Adding third vertex..." << endl;
	graph.AddVertex(7);

	//find the vertex of value 7
	cout << "Finding vertex with value 7..." << endl;
	list<int>* vertex_3 = graph.FindVertex(7);
	if (vertex_3 != nullptr) cout << "Found vertex with value 7." << endl;
	else cout << "Unable to find vertex with value 7." << endl;

	//checks if the edge was created between vertex_1 and vertex_2
	cout << "Checking if edge between vertex_1 and vertex_2 exists... Result:";
	cout << graph.IsEdge(vertex_1, 5) << endl;

	// checks if vertex_3 is still a vertex of the graph
	cout << "Checking if vertex_3 is in the graph... Result:" << graph.IsVertex(vertex_3) << endl;

	//check the numver of vertexes and edges for vertex_1
	cout << "The graph contains " << graph.GraphSize() << "verticies and " << graph.NumberOfEdges(vertex_1) << " edges for vertex_1." << endl;

	// create 30 nodes and edges
	cout << "Inserting 30 nodes and edges..." << endl;

	//pointer to previously generated vertex
	list<int>* prev = vertex_2;

	for (int i = 0; i < 30; i++) {
		//generate a random value
		int value = rand() % 1000 + 1;

		//add the value to the list
		list<int>* temp = graph.AddVertex(value);

		//connect the new value and the previous value
		graph.AddEdge(prev, temp);

		//set prev
		prev = temp;
	}

	//print the new size of the graph
	cout << "Done adding nodes and edges, new graph size: " << graph.GraphSize() << endl;

	//print the entire graph
	graph.PrintAdjacencyList();
	
	return false;
}

int main()
{
	//set rand seed
	srand(time(NULL));

	// Call testing functions
	Testing_NodeBased();
	Testing_AdjacencyList();
    return 0;
}

