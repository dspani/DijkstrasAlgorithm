#include "pch.h"
#include "Dijkstra.h"
#include <iostream>


/*
use 
*/

using namespace std;

int main()
{
	Dijkstra Graph;

	Graph.addEdge(0, 1, 8);Graph.addEdge(0, 2, 8);
	Graph.addEdge(0, 7, 4);Graph.addEdge(0, 14, 4);
	Graph.addEdge(0, 20, 8);Graph.addEdge(1, 5, 8);
	Graph.addEdge(4, 5, 7);Graph.addEdge(2, 3, 5);
	Graph.addEdge(2, 6, 2);Graph.addEdge(5, 6, 8);
	Graph.addEdge(5, 25, 6);Graph.addEdge(4, 7, 3);
	Graph.addEdge(4, 8, 5);Graph.addEdge(5, 8, 1);
	Graph.addEdge(3, 17, 1);Graph.addEdge(7, 11, 1);
	Graph.addEdge(8, 11, 8);Graph.addEdge(12, 8, 7);
	Graph.addEdge(12, 11, 2);Graph.addEdge(13, 9, 3);
	Graph.addEdge(9, 12, 9);Graph.addEdge(10, 9, 6);
	Graph.addEdge(13, 10, 5);Graph.addEdge(10, 17, 2);
	Graph.addEdge(30, 10, 4);Graph.addEdge(12, 13, 2);
	Graph.addEdge(11, 14, 6);Graph.addEdge(12, 15, 8);
	Graph.addEdge(12, 16, 6);Graph.addEdge(13, 9, 9);
	Graph.addEdge(15, 35, 7);Graph.addEdge(16, 17, 1);
	Graph.addEdge(22, 23, 8);Graph.addEdge(20, 21, 1);
	Graph.addEdge(20, 34, 1);Graph.addEdge(20, 27, 5);
	Graph.addEdge(20, 24, 3);Graph.addEdge(21, 24, 1);
	Graph.addEdge(22, 25, 1);Graph.addEdge(22, 26, 8);
	Graph.addEdge(23, 26, 2);Graph.addEdge(23, 37, 2);
	Graph.addEdge(24, 27, 2);Graph.addEdge(24, 28, 6);
	Graph.addEdge(25, 28, 1);Graph.addEdge(25, 29, 6);
	Graph.addEdge(25, 26, 7);Graph.addEdge(26, 29, 9);
	Graph.addEdge(26, 30, 5);Graph.addEdge(27, 28, 5);
	Graph.addEdge(29, 30, 1);Graph.addEdge(27, 34, 7);
	Graph.addEdge(28, 31, 5);Graph.addEdge(28, 32, 1);
	Graph.addEdge(29, 33, 5);Graph.addEdge(30, 37, 4);
	Graph.addEdge(31, 34, 3);Graph.addEdge(31, 35, 9);
	Graph.addEdge(31, 32, 4);Graph.addEdge(32, 36, 1);
	Graph.addEdge(32, 33, 4);Graph.addEdge(33, 36, 7);
	Graph.addEdge(35, 36, 4);Graph.addEdge(35, 37, 1);
	
	//Graph.printVertices();
	//Graph.printEdges();
	
	Graph.path(1, 37);
	cout << "Shortest path from 1 to 37: " << Graph.getRoute(1, 37) << endl;
	cout << "Shortest path from 14 to 23: " << Graph.getRoute(14, 23) << endl;
}