#include "vertex.h"


//EDGE

bool Edge::operator==(Edge& rhs) {
	bool w = this->weight == rhs.weight;
	bool v = this->vertex == rhs.vertex;
	return w && v;
}

Edge::Edge(Vertex& vertex, int weight) {
	this->vertex = &vertex;
	this->weight = weight;
}

Vertex Edge::getVertex() const {
	return (*vertex);
}

int Edge::getWeight() const {
	return weight;
}

string Edge::toString() const {
	return this->vertex->getName();
}

//VERTEX

bool Vertex::operator==(Vertex& v) {
	return this->name == v.name;
}
bool Vertex::operator==(const Vertex& v) const {
	return this->name == v.name;
}
bool Vertex::operator!=(Vertex& v) {
	return this->name != v.name;
}

Vertex::Vertex(string name) {
	this->name = name;
	this->edges = EdgeQueue();
}

string Vertex::getName() const {
	return name;
}

EdgeQueue* Vertex::getEdges() {
	return &edges;
}

string Vertex::toString() const {
	return name + " " + std::to_string(edges.count());
}