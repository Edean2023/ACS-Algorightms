#pragma once
template <typename T>
class CSC382Graph_AdjacencyList
{
public:
	// create the graph adjacency list
	CSC382Graph_AdjacencyList()
	{
		graph_adjacencylist = new vector<list<T>*>();
	}
	// deconstructor | removes data from the graph
	~CSC382Graph_AdjacencyList()
	{
		for (list<T>* iter : *graph_adjacencylist)
		{
			// if iter is not nullptr
			if (iter != nullptr)
			{
				delete iter; // delete
			}
		}
		// delete list
		delete graph_adjacencylist;
	}

	list <T>* AddVertex(T data)
	{
		// Attempt to find
		if (IsVertex(data))
		{
			// alert user if the vertex is in the graph
			cout << "Vertex is already in the graph. Duplicate NOT added." << endl;
			return nullptr;
		}
		else
		{

			list<T>* new_vertex = new list<T>();		// Create new list to house the vertex and its edges
			new_vertex->push_back(data);				// Data is added as the first element in the list
			graph_adjacencylist->push_back(new_vertex);	// list pointer is added to the graph
			return new_vertex;
		}
	}

	bool AddEdge(list<T>* vertex, T data)
	{
		if(!IsVertex(vertex))
		{
			// alert user if the vertex doesn't exist
			cout << "Vertex specified does not exist. Cannot add edge to a non-existant vertex."
			return false;
		}
		if (!IsVertex(data))		// Data must be an existing vertex or it will need to be created.
		{
			vertex->push_back(data);
			return true;
		}
		else
		{
			// add data to the vertex
			list<T>* new_vertex = AddVertex(data);
			new_vertex->push_back(data);
			return true;
		}
	}

	// Adds edge and prevents duplicating edges
	bool AddEdge(list<T>* starting_vertex, list<T>* ending_vertex)
	{
		if(!IsVertex(starting_vertex) || !IsVertex(ending_vertex))
		{
			// alert user that the vertices does not exist
			cout << "Cannot AddEdge because one of the specified vertices does not exist in the graph." << endl;
			// do not add edge
			return false;
		}
		if (!IsEdge(starting_vertex, ending_vertex->front()))		// Prevent adding duplicate edges
		{
			// add edge
			starting_vertex->push_back(ending_vertex->front());
			return true;
		}
		return false;
	}

	// is vertex bool
	bool IsVertex(T data)
	{
		for (list<T>* iter : *graph_adjacencylist)
		{
			// Check the first value in the list which is the primary vertex
			if (iter->front() == data)
			{
				return true;
			}
		}
		return false;
	}

	// finds vertex
	bool IsVertex(list<T>* vertex_to_find)
	{
		for (list<T>* iter : *graph_adjacencylist)
		{
			// checks if the iter is the correct vertex
			if (iter == vertex_to_find)
			{
				return true;
			}
		}
		return false;
	}

	// checks for the correct edge
	bool IsEdge(T edge_to_find)
	{
		for (list<T>* iter : *graph_adjacencylist)
		{
			// if it is the correct edge
			if (IsEdge(iter, edge_to_find))
			{
				return true;
			}
		}
		return false;
	}

	// edge verification
	bool IsEdge(list<T>* vertex, T edge_to_find)
	{
		// loop through all vertexes in list T
		for (T i : *vertex)
		{
			// skip checking the primary vertex and only check edges
			if (vertex->front() == i)
			{
				continue;
			}
			// if it is the edge to find
			if (i == edge_to_find)
			{
				return true;
			}
		}
		return false;
	}

	// find the vertex
	list<T>* FindVertex(T data)
	{
		// point to adjacency list
		for (list<T>* iter : *graph_adjacencylist)
		{
			// if iter ptr referenced from front == data
			if (iter->front() == data)
			{
				// return 
				return iter;
			}
		}
		return nullptr;
	}

	void PrintAdjacencyList()
	{
		// point to adjacency list
		for (list<T>* iter : *graph_adjacencylist)
		{
			for (T i : *iter)
			{
				// skip checking the primary vertex and only check edges
				if (iter->front() == i)		// Prints the Vertex 
				{
					cout << "Vertex = " << i << "   Edges = ";
				}
				else	// Prints the Edges
				{
					cout << i << " ";
				}
			}
			cout << endl;
		}
	}

	// finds number of edges
	int NumberOfEdges(T vertex_data)
	{
		list<T>* vertex = FindVertex(vertex_data);
		// if vertex is not null ptr
		if(vertex != nullptr)
		{
			// return the number of edges 
			return NumberOfEdges(vertex);
		}
		// no vertexes, graph is empty
		return -1;
	}

	// return the size of the vertex
	int NumberOfEdges(list<T>* vertex)
	{
		return vertex->size();
	}

	// return the size of the graph
	int GraphSize()
	{
		return graph_adjacencylist->size();
	}

private:
	vector<list<T>*>* graph_adjacencylist;
};