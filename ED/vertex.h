#pragma once

#include <string>
#include "linked_queue.h"

using std::string;

class Vertex;

class Edge {

private:
	int weight;
	Vertex* vertex;

public:
	Edge(Vertex& vertex, int weight = 0);
	Vertex getVertex() const;
	int getWeight() const;
	string toString() const;

	bool operator==(Edge& rhs);
};

typedef LinkedQueue<Edge> EdgeQueue;

class Vertex {

private:
	string name;
	EdgeQueue edges; // Lista de adjacências

public:
	bool mark;
	Vertex(string name = "");
	string getName() const;
	EdgeQueue* getEdges();
	string toString() const;

	bool operator==(Vertex&);
	bool operator!=(Vertex& v);
	bool operator==(const Vertex&) const;
};




