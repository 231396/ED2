#pragma once

#include "vertex.h"

class Edge {

private:
	Vertex* to;
	int weight;

public:
	Edge(Vertex* to, int weight = 0) {
		this->to = to;
		this->weight = weight;
	}

	Vertex& getTo() const {
		return *to;
	}
	int getWeight() const {
		return weight;
	}

	bool operator==(Edge& rhs) {
		return this->weight == rhs.weight && this->to == rhs.to;
	}
	bool operator==(const Edge& rhs) const {
		return this->weight == rhs.weight && this->to == rhs.to;
	}
	bool operator!=(Edge& rhs) {
		return this->weight != rhs.weight || this->to != rhs.to;
	}
	bool operator!=(const Edge& rhs) const {
		return this->weight != rhs.weight || this->to != rhs.to;
	}
};