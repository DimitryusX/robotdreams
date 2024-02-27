#include "Graph.h"
#include <algorithm>

GraphAdjList::GraphAdjList(int Vertixes, ConnectionType type)
	: Graph(Vertixes, type)
{
	m_list.resize(Vertixes);
}

void GraphAdjList::addEdge(int v, int w)
{
	m_list[v].push_back(w);
	if (m_connectionType == ConnectionType::undirected)
	{
		m_list[w].push_back(v);
	}
}

void GraphAdjList::DFS(unsigned vertex)
{
	std::vector<bool> visited;
	visited.resize(m_vertixes, false);

	visited[vertex] = true;
	std::cout << vertex << " ";

	for (auto node : m_list[vertex]) {
		DFSPrintUtil(node, visited);
	}
}

void GraphAdjList::DFSPrintUtil(unsigned vertex, std::vector<bool>& visited)
{
	visited[vertex] = true;
	std::cout << vertex << " ";

	for (unsigned node : m_list[vertex]) {
		if (!visited[node]) {
			DFSPrintUtil(node, visited);
		}
	}
}

void GraphAdjList::BFS(unsigned vertex)
{
	// Mark all the vertices as not visited
	std::vector<bool> visited;
	visited.resize(m_vertixes, false);

	std::list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[vertex] = true;
	queue.push_back(vertex);

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		int currentVertex = queue.front();

		std::cout << currentVertex << " ";

		queue.pop_front();

		// Get all adjacent vertices
		for (int adjacent : m_list[currentVertex])
		{
			if (!visited[adjacent])
			{
				visited[adjacent] = true;
				queue.push_back(adjacent);
			}
		}
	}
}

std::size_t GraphAdjList::numberOfNodesInLevel(unsigned level)
{
	unsigned currentLevel = 0;
	std::size_t nodesInCurrentLevel = 0;

	// Create vector with false values (later set true if visited)
	std::vector<bool> visited;
	visited.resize(m_vertixes, false);

	std::list<int> queue;

	// First node
	queue.push_back(0);
	visited[0] = true;

	while (!queue.empty() && currentLevel <= level) {
		// Get nodes count
		nodesInCurrentLevel = queue.size();

		// Return if found
		if (currentLevel == level) {
			return nodesInCurrentLevel;
		}

		for (unsigned i = 0; i < nodesInCurrentLevel; i++) {
			int currentVertex = queue.front();
			queue.pop_front();

			for (int adjacent : m_list[currentVertex]) {
				if (!visited[adjacent]) {
					visited[adjacent] = true;
					queue.push_back(adjacent);
				}
			}
		}

		currentLevel++;
	}

	return 0;
}

bool GraphAdjList::isStronglyConnected()
{
	if (m_vertixes <= 1) {
		return true;
	}

	for (unsigned i = 0; i < m_vertixes; i++) {
		std::vector<bool> visited(m_vertixes, false);
		DFSUtil(i, visited);

		for (bool v : visited) {
			if (!v) {
				return false;
			}
		}
	}

	GraphAdjList transposedGraph = getTranspose();
	for (unsigned i = 0; i < m_vertixes; i++) {
		std::vector<bool> visited(m_vertixes, false);
		transposedGraph.DFSUtil(i, visited);

		for (bool v : visited) {
			if (!v) {
				return false;
			}
		}
	}

	return true;
}

void GraphAdjList::DFSUtil(unsigned v, std::vector<bool>& visited)
{
	visited[v] = true;

	for (unsigned adj : m_list[v]) {
		if (!visited[adj]) {
			DFSUtil(adj, visited);
		}
	}
}

GraphAdjList GraphAdjList::getTranspose() {
	GraphAdjList transposedGraph(m_vertixes, m_connectionType);

	for (unsigned i = 0; i < m_vertixes; i++) {
		for (unsigned adj : m_list[i]) {
			transposedGraph.addEdge(adj, i);
		}
	}

	return transposedGraph;
}