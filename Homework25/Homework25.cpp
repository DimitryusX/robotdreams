#include <iostream>
#include "Graph.h"

int main()
{
	std::cout << "Homework 25!" << std::endl;

	GraphAdjList graph(11);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 3);

	graph.addEdge(1, 4);
	graph.addEdge(2, 5);
	graph.addEdge(2, 6);
	graph.addEdge(3, 7);

	graph.addEdge(4, 8);
	graph.addEdge(5, 9);
	graph.addEdge(7, 10);

	std::cout << "DFS algorithm" << std::endl;
	graph.DFS(0);

	std::cout << std::endl;

	std::cout << "BFS algorithm" << std::endl;
	graph.BFS();

	std::cout << std::endl;

	unsigned level = 2;
	std::cout << "Node size is " << graph.numberOfNodesInLevel(level) << " on level " << level << std::endl;

	level = 3;
	std::cout << "Node size is " << graph.numberOfNodesInLevel(level) << " on level " << level << std::endl;

	level = 1;
	std::cout << "Node size is " << graph.numberOfNodesInLevel(level) << " on level " << level << std::endl;

	level = 0;
	std::cout << "Node size is " << graph.numberOfNodesInLevel(level) << " on root level" << std::endl;

	std::cout << "Graph is" << (graph.isStronglyConnected() ? " " : " not ") << "strongly connected !" << std::endl;

	// New graph with 5 vertexes
	GraphAdjList graph2(5);
	graph2.addEdge(0, 1);
	graph2.addEdge(1, 2);
	graph2.addEdge(2, 3);
	graph2.addEdge(3, 4);

	std::cout << "Graph2 is" << (graph2.isStronglyConnected() ? " " : " not ") << "strongly connected !" << std::endl;

	// New graph with 5 vertexes
	GraphAdjList graph3(8);
	graph3.addEdge(0, 1);
	graph3.addEdge(1, 2);
	graph3.addEdge(2, 3);
	graph3.addEdge(3, 4);

	std::cout << "Graph3 is" << (graph3.isStronglyConnected() ? " " : " not ") << "strongly connected !" << std::endl;
}
