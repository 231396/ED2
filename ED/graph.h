#pragma once

#include <iostream>

#include "linked_queue.h"
#include "vertex.h"

class Graph {

private:
	bool directed;
	int NULL_EDGE; // Constante para aresta nula.
	int maxVertices; // Número máximo de vértices.  
	int currentVertices; // Número de vértices existentes.
	Vertex** vertices;

	int getIndex(Vertex& vertex) {
		int index = 0;
		for (int i = 0; i < currentVertices; i++)
			if (vertex == *vertices[i])
				return i;
		return -1;
	}

	bool vertexExist(Vertex& vertex) {
		return getIndex(vertex) >= 0;
	}
	bool vertexExist(Vertex& from, Vertex& to) {
		return vertexExist(from) && vertexExist(to);
	}

	Edge* getEdge(Vertex& from, Vertex& to) {
		auto findEdge = [to](Edge& edge) -> bool {
			return edge.getVertex() == to;
		};
		return from.getEdges()->find(findEdge);
	}

public:
	Graph(bool isDirected = false, int max = 50, int null_edge = 0) {
		directed = isDirected;
		NULL_EDGE = null_edge;
		currentVertices = 0;
		maxVertices = max;
		vertices = new Vertex*[maxVertices];
	}

	~Graph() {
		//for (int i = 0; i < currentVertices; i++) {}
		delete[] vertices;
	}

	int countVertices() {
		return currentVertices;
	}

	void addVertex(Vertex& vertex) {
		if (!vertexExist(vertex)) {
			vertices[currentVertices] = &vertex;
			currentVertices++;
		}
	}

	void addEdge(Vertex& from, Vertex& to, int weight = 1) {
		if (!vertexExist(from, to))
			return;
		from.getEdges()->enqueue(*new Edge(to, weight));
		if (!directed && from != to)
			to.getEdges()->enqueue(*new Edge(from, weight));
	}

	int getWeight(Vertex& from, Vertex& to) {
		if (!vertexExist(from, to))
			return NULL_EDGE;
		auto edge = getEdge(from, to);
		if (edge == NULL)
			return NULL_EDGE;
		return edge->getWeight();
	}

	EdgeQueue getAdjacents(Vertex& vertex) {
		if (!vertexExist(vertex))
			return EdgeQueue();
		return *vertex.getEdges();
	}

	void clearMarks() {
		for (int i = 0; i < currentVertices; i++)
			vertices[i]->mark = false;
	}

	void markVertex(Vertex& vertex) {
		int index = getIndex(vertex);
		vertices[index]->mark = true;
	}

	bool isMarked(Vertex& vertex) {
		int index = getIndex(vertex);
		return vertices[index]->mark;
	}

	void print() {
		auto printEdge = [](Edge& edge) -> void {
			std::cout << edge.toString() << "(" << edge.getWeight() << ")" << ", ";
		};
		for (int i = 0; i < currentVertices; i++) {
			std::cout << vertices[i]->getName() << " : ";
			getAdjacents(*vertices[i]).forEach(printEdge);
			std::cout << std::endl;
		}
	}

	void generatePageRanks(float* pageRank, float dFactor = 1.0f, int iterations = 52) {

		int* outputDegree = new int[currentVertices];
		float* pr_previous = new float[currentVertices];
		for (int i = 0; i < currentVertices; i++) {
			outputDegree[i] = getAdjacents(*vertices[i]).count();
			pr_previous[i] = 1.0f / currentVertices;
		}

		for (int iteract = 0; iteract < iterations; iteract++) {
			for (int i = 0; i < currentVertices; i++) {
				pageRank[i] = 0.0f;

				for (int j = 0; j < currentVertices; j++)
					pageRank[i] = pr_previous[j] / outputDegree[j];

				pageRank[i] = (1 - dFactor) / currentVertices + dFactor * pageRank[i];
			}

			for (int i = 0; i < currentVertices; i++)
				pr_previous[i] = pageRank[i];
		}

		delete[] pr_previous;
		delete[] outputDegree;
	}

};

