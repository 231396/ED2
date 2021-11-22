#pragma once

#include "vertex.h"

class Edge {

private:
	Vertex* from;
	Vertex* to;
	int weight;

public:
	Edge(Vertex* from, Vertex* to, int weight = 0) {
		this->from = from;
		this->to = to;
		this->weight = weight;
	}

	Vertex& getFrom() const {
		return *from;
	}
	Vertex& getTo() const {
		return *to;
	}
	int getWeight() const {
		return weight;
	}
	std::string toString() const {
		return from->getName() + "->" + to->getName() + "(" + std::to_string(weight) + ")";
	}

	bool operator==(Edge& rhs) {
		return this->weight == rhs.weight && this->from == rhs.from && this->to == rhs.to;
	}
	bool operator==(const Edge& rhs) const {
		return this->weight == rhs.weight && this->from == rhs.from && this->to == rhs.to;
	}
	bool operator!=(Edge& rhs) {
		return this->weight != rhs.weight || this->from != rhs.from || this->to != rhs.to;
	}
	bool operator!=(const Edge& rhs) const {
		return this->weight != rhs.weight || this->from != rhs.from || this->to != rhs.to;
	}
};