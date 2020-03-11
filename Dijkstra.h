#pragma once
/*
Duncan Spani
Dijkstras algorithm
uses vertex nodes and edges with two pointers,
a to and from node with a weight to calculate 
the shortest distance to each node
bug ::: doesnt correctly update the distance
enters infinite loop when getting path

*/
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <cassert>
//shortest path form 1 to 37: 22

using namespace std;

class Dijkstra
{
private:

	class Vertex
	{
	public:
		int id;
		bool known;
		int distance;
		Vertex * previous;
		Vertex(int newId) : known{ false }, distance{ 0 }, previous{ nullptr }, id{ newId } 
		{
		}

		const bool operator < (const Vertex &r) const
		{
			return (distance < r.distance);
		}


		~Vertex()
		{
		}

	};

	class Edge
	{
	public:
		Vertex * from;
		Vertex * to;
		int weight;

		Edge(Vertex * newFrom, Vertex * newTo, int newWeight) : from{ newFrom }, to{ newTo }, weight{ newWeight }
		{
		}

		~Edge()
		{
		}

	};

	struct compareEdges : public binary_function<Edge*, Edge*, bool>
	{
		bool operator() (const Edge* p1, const Edge* p2)
		{
			return p1->weight > p2->weight;
		}
	};

	vector<Vertex *> vertices;
	vector<Edge *> edges;
	
	void path(Vertex * from, Vertex * to)// TODO
	{
		/*
		bug : not correctly updateing distacne from starting point
		*/
		string route;
		//priority queue of edges
		priority_queue<Edge *, vector<Edge *>, compareEdges > nodes;
		Edge * edge;
		Vertex * vertex;
		//loading  edges from start point into priority queue
		for (unsigned int i = 0; i < edges.size(); i++)//bug : loading only one edge first
		{
			if (edges[i]->from->id == from->id)
			{
				nodes.push(edges[i]);
			}
		}
		edge = nodes.top();//edge = starting edge in priority queue
		nodes.pop();//get rid of top node in priority queue
		vertex = edge->to;//vertex = end edge node
		vertex->distance = edge->weight;
		vertex->previous = from;
		vertex->known = true;
		
		while (!nodes.empty())
		{
			//cout << vertex->distance << " \n" << edge->from->distance + edge->weight << endl;
			if (vertex->known == false)//if vertex hasnt been touched
			{
				vertex->known = true;
				vertex->previous = edge->from;
				vertex->distance = (vertex->previous->distance + edge->weight);
			}
			else//if vertex is known
			{
				if (vertex->distance >= (vertex->previous->distance + edge->weight))//if current path is better than previous
				{
					vertex->distance = vertex->previous->distance + edge->weight;
					vertex->previous = edge->from;//update previous vertex
				}
			}

			for (unsigned int i = 0; i < edges.size(); i++)//pushback edges that start at vertex
			{
				if (edges[i]->from->id == vertex->id && edges[i]->to->known == false)
				{
					nodes.push(edges[i]);
				}
			}
			edge = nodes.top();//edge = starting edge in priority queue
			nodes.pop();//get rid of top node in priority queue
			vertex = edge->to;//vertex = end edge node
		}
	}

	string reverseRoute(string backwards)
	{
		string forward;
		for (unsigned int i = 0; i < backwards.size(); i++)
		{
			forward.push_back(backwards[i]);
		}
		return forward;
	}



	/*
	if vertex is known check if distance is smaller possibly update previous if it is

	if vertex is not known
	now vertex is know, update distance, previous 
	*/


public:

	Dijkstra()
	{
		
	}

	~Dijkstra()
	{
	}

	void path(int from, int to)
	{
		//f and t refer to from and to pointers
		//find vertices with from and to id
		Vertex * f = nullptr;
		Vertex * t = nullptr;
		for (unsigned int i = 0; i < vertices.size(); i++)
		{
			if (vertices[i]->id == from)
			{
				f = vertices[i];
				f->known = true;
			}
			if (vertices[i]->id == to)
			{
				t = vertices[i];
			}
		}
		path(f, t);//call of private function with start and end points
	}

	void updateVertex(Vertex * from, int dist, Vertex * prev)
	{
		//f is vertex to be updated,
		//dist is weight from edge,
		//prev is preious vertex 
		from->known = true;
		from->distance = dist;
		from->previous = prev;
	}

	void addEdge(int from, int to, int weight)
	{
		Vertex * temp1 = new Vertex(from);
		if (!vertexExists(from))
		{
			vertices.push_back(temp1);
		}

		Vertex * temp2 = new Vertex(to);
		if (!vertexExists(to))
		{
			vertices.push_back(temp2);
		}

		edges.push_back(new Edge(temp1, temp2, weight));
		edges.push_back(new Edge(temp2, temp1, weight));
	}

	bool vertexExists(int id)
	{
		for (unsigned int i = 0; i < vertices.size(); i++)
		{
			if (vertices[i]->id == id)
			{
				return true;
			}
		}
		return false;
	}

	//getting route
	string getRoute(int startID, int endID)
	{
		string route;
		Vertex * temp = nullptr;
		for (unsigned int i = 0; i < vertices.size(); i++)
		{
			if (vertices[i]->id == endID)
			{
				temp = vertices[i];
			}
		}
		assert(temp != nullptr);
		while (temp->id != endID)
		{
			route.push_back(temp->id);
			route.push_back(' ');
			temp = temp->previous;
		}
		return reverseRoute(route);
	}
};