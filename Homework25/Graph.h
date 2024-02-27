#pragma once
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

class Graph
{
public:
	enum class ConnectionType
	{
		undirected,
		directed
	};

	Graph(int vertixes, ConnectionType type = ConnectionType::undirected)
		: m_vertixes(vertixes), m_connectionType(type) {}

	virtual void addEdge(int v, int w) = 0;
	virtual void BFS(unsigned vertex = 0) {};
	virtual void DFS(unsigned vertex = 0) {};

protected:
	unsigned int m_vertixes;
	ConnectionType m_connectionType;
};

class GraphAdjList : public Graph
{
public:
	GraphAdjList(int vertixes, ConnectionType type = ConnectionType::undirected);
	void addEdge(int v, int w) override;

	void DFS(unsigned vertex = 0) override;
	void BFS(unsigned vertex = 0) override;
	std::size_t numberOfNodesInLevel(unsigned level);

	GraphAdjList getTranspose();
	bool isStronglyConnected();

private:
	std::vector<std::list<int> > m_list;
	void DFSUtil(unsigned v, std::vector<bool>& visited);
	void DFSPrintUtil(unsigned v, std::vector<bool>& visited);
};

class GraphAdjMatrix : public Graph
{
	using Graph::Graph;

	void addEdge(int v, int w) override {};
	void DFS(unsigned vertex = 0) override {};
};