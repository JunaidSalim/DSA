#include <bits/stdc++.h>
using namespace std;

class Graph
{

	int V;

	vector<list<int>> adj;
	map<int, bool> visit;

public:
	Graph(int V);

	void addEdge(int v, int w);

	void BFS(int s);
	void DFS(int s);
	void BFS_2(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFS(int s)
{
	visit[s] = true;
	cout << s << " ";
	for (auto &&i : adj[s])
	{
		if (!visit[i])
		{
			DFS(i);
		}
	}
}

void Graph::BFS(int s)
{

	vector<bool> visited;
	visited.resize(V, false);

	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty())
	{

		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (auto adjacent : adj[s])
		{
			if (!visited[adjacent])
			{
				visited[adjacent] = true;
				queue.push_back(adjacent);
			}
		}
	}
}
void Graph::BFS_2(int s)
{
	vector<bool> visited;
	visited.resize(V, false);

	queue<int> q;

	visited[s] = true;
	q.push(s);

	while (!q.empty())
	{

		s = q.front();
		cout << s << " ";
		q.pop();
		for (auto adjacent : adj[s])
		{
			if (!visited[adjacent])
			{
				visited[adjacent] = true;
				q.push(adjacent);
			}
		}
	}
}

int main()
{
	Graph g(4);

	return 0;
}
