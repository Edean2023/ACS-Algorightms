#pragma once

#include "stdafx.h"
#include <vector>
#include <list>
#include <iostream>


using namespace std;

// create template
template <typename T>
// class for the Graph Vertex
class CSC382Graph_Vertex
{
private:
	T data;
	// create list for connected vertices
	list<CSC382Graph_Vertex<T>*>* connected_vertices;
public:
	// constructor
	CSC382Graph_Vertex()
	{
		// set connected vertices equal to a new graph vertex list
		connected_vertices = new list<CSC382Graph_Vertex<T>*>();
		data = NULL; // data is null
	}

	CSC382Graph_Vertex(T node_data)
	{
		// set connected vertices equal to a new graph vertex list
		connected_vertices = new list<CSC382Graph_Vertex<T>*>();
		data = node_data; // data set to node data
	}

	// deconstructor
	~CSC382Graph_Vertex()
	{
		delete connected_vertices;
	}

	// adds edge
	void AddEdge(CSC382Graph_Vertex<T>* vertex_connection)
	{
		// check if the passed vertex is not this vertex
		if (vertex_connection != this)
		{
			// add edge to vertex
			connected_vertices->push_back(vertex_connection);
		}
	}

	// check if the vertex is connected
	bool VertexConnected(CSC382Graph_Vertex<T>* vertex_to_find)
	{
		// loop to find connected vertices
		for(CSC382Graph_Vertex<T>* i : *connected_vertices)
		{
			// check if the correct vertex is found
			if(i == vertex_to_find)
			{
				// return
				return true;
			}
		}
		// return
		return false;
	}

	// removes edges
	void RemoveEdge(CSC382Graph_Vertex<T>* edge_to_remove)
	{
		// check if the edge needing to be remove is not nullptr
		if (edge_to_remove != nullptr)
		{
			// remove edge
			connected_vertices->remove(edge_to_remove);
		}
	}

	// Get the data
	T GetData()
	{
		return data;
	}

	// set data to data_param
	void SetData(T data_param)
	{
		data = data_param;
	}

};

// create template
template <typename T>
// class for the node based graph
class CSC382Graph_NodeBased
{
private:
	// create graph
	list<CSC382Graph_Vertex<T>*>* graph;

public:
	// constructor
	CSC382Graph_NodeBased()
	{
		// set graph to a new graph vertex list
		graph = new list<CSC382Graph_Vertex<T>*>;
	}


	CSC382Graph_NodeBased(CSC382Graph_Vertex<T>* initial_vertex)
	{
		// set graph to a new graph vertex list
		graph = new list<CSC382Graph_Vertex<T>*>;
		Insert(initial_vertex); // insert initial vertex
	}

	// deconstructor 
	~CSC382Graph_NodeBased()
	{
		// for iters in the graph T
		for (CSC382Graph_Vertex<T>* iter : *graph)
		{
			// if the iter is not nullptr and not null
			if (iter != nullptr && iter != NULL)
			{
				// delete it
				delete iter;
			}
		}
		// then delete graph
		delete graph;
	}

	// insert a new vertex by giving it an existing vertex
	CSC382Graph_Vertex<T>* Insert(CSC382Graph_Vertex<T>* vertex)
	{
		graph->push_back(vertex);
		return vertex;
	}

	// insert a new node
	CSC382Graph_Vertex<T>* Insert(T data)
	{
		CSC382Graph_Vertex<T>* new_node = new CSC382Graph_Vertex<T>(data);
		return Insert(new_node);
	}

	// removes vertex
	void RemoveVertex(T data)
	{
		// find vertex to remove
		CSC382Graph_Vertex<T>* vertex_to_remove = FindVertex(data);
		// remove the vertex
		RemoveVertex(vertex_to_remove);
	}

	// remove vertex
	void RemoveVertex(CSC382Graph_Vertex<T>* vertex_to_remove)
	{
		graph->remove(vertex_to_remove); // remove
	}

	// handles the start and end vertex of AddEdge
	void AddEdge(CSC382Graph_Vertex<T>* start_vertex, CSC382Graph_Vertex<T>* end_vertex)
	{
		// connect the start vertex to the end vertex
		start_vertex->AddEdge(end_vertex);
	}

	// handles the start and end vertex of RemoveEdge
	void RemoveEdge(CSC382Graph_Vertex<T>* start_vertex, CSC382Graph_Vertex<T>* end_vertex)
	{
		// connect the start vertex to the end vertex
		start_vertex->RemoveEdge(end_vertex);
	}

	// checks IsEdge vertex to search and the edge to check for
	bool IsEdge(CSC382Graph_Vertex<T>* vertex_to_search_in, CSC382Graph_Vertex<T>* edge_to_check_for)
	{
		// return connected vertex 
		return vertex_to_search_in->VertexConnected(edge_to_check_for);
	}

	// find the data_to_find for FindVertex
	CSC382Graph_Vertex<T>* FindVertex(T data_to_find)
	{
		// loop to find data
		for (CSC382Graph_Vertex<T>* iter : *graph)
		{
			// check if the data to find is the correct data
			if (iter->GetData() == data_to_find)
			{
				// return
				return iter;
			}
		}
		// return
		return nullptr;
	}

	// finds the node_to_find for FindVertex
	CSC382Graph_Vertex<T>* FindVertex(CSC382Graph_Vertex<T>* node_to_find)
	{
		// loop to find the node
		for(CSC382Graph_Vertex<T>* iter : *graph)
		{
			// check if it is the correct node
			if(iter == node_to_find)
			{
				// return
				return iter;
			}
		}
		// return
		return nullptr;
	}

	// graph size
	int Size()
	{
		return graph->size();
	}
};
