#pragma once

#include <iostream>

#include "linked_queue.h"
#include "edge.h"

class Graph {

private:
	bool directed;
	int NULL_EDGE; // Constante para aresta nula.
	int maxVertices; // Número máximo de vértices.  
	int currentVertices; // Número de vértices existentes.

	struct GraphItem {
		bool mark;
		Vertex* vertex;
		LinkedQueue<Edge> edges;
		GraphItem() {
			mark = false;
			vertex = NULL;
			edges = LinkedQueue<Edge>();
		}
	};
	GraphItem* items;

public:
	Graph(bool isDirected = false, int max = 50, int null_edge = 0) {
		directed = isDirected;
		NULL_EDGE = null_edge;
		currentVertices = 0;
		maxVertices = max;
		items = new GraphItem[maxVertices];
	}

	~Graph() {
		//for (int i = 0; i < currentVertices; i++) {}
		delete[] items;
	}

	int numberOfVertices() {
		return currentVertices;
	}

	int indexOf(Vertex& vertex) {
		int index = 0;
		for (int i = 0; i < currentVertices; i++)
			if (vertex == *items[i].vertex)
				return i;
		return -1;
	}
	Edge* findEdge(Vertex& from, Vertex& to) {
		int fIndex = indexOf(from);
		if (fIndex < 0)
			return NULL;
		auto findFunc = [to](Edge& edge) -> bool { return edge.getTo() == to; };
		return items[fIndex].edges.find(findFunc);
	}

	GraphItem getItem(int index) {
		return items[index];
	}

	void addVertex(Vertex& vertex) {
		if (indexOf(vertex) < 0) {
			items[currentVertices].vertex = &vertex;
			currentVertices++;
		}
	}

	void addEdge(Vertex& from, Vertex& to, int weight = 1) {
		int fIndex = indexOf(from);
		int tIndex = indexOf(to);
		if (fIndex < 0 || tIndex < 0)
			return;

		items[fIndex].edges.enqueue(*new Edge(&to, weight));
		if (!directed && fIndex != tIndex)
			items[tIndex].edges.enqueue(*new Edge(&from, weight));
	}

	int getWeight(Vertex& from, Vertex& to) {
		Edge* edge = findEdge(from, to);
		if (edge == NULL)
			return NULL_EDGE;
		return edge->getWeight();
	}

	LinkedQueue<Edge> getAdjacents(Vertex& vertex) {
		int index = indexOf(vertex);
		if (index < 0)
			return LinkedQueue<Edge>();
		return items[index].edges.copy();
	}

	void clearMarks() {
		for (int i = 0; i < currentVertices; i++)
			items[i].mark = false;
	}

	void markVertex(Vertex& vertex) {
		int index = indexOf(vertex);
		if (index >= 0)
			items[index].mark = false;
	}

	bool isMarked(Vertex& vertex) {
		int index = indexOf(vertex);
		if (index >= 0)
			return items[index].mark;
		return false;
	}

	void print() {
		auto printEdge = [](Edge& edge) -> void {
			std::cout << edge.getTo().getName() << "(" << edge.getWeight() << ")" << ", ";
		};
		for (int i = 0; i < currentVertices; i++) {
			std::cout << items[i].vertex->getName() << ": ";
			items[i].edges.forEach(printEdge);
			std::cout << std::endl;
		}
	}

	float* generatePageRanks(float dFactor, int iterations = 52) {
		float* pageRank = new float[currentVertices];
		generatePageRanks(pageRank, dFactor, iterations);
		return pageRank;
	}

	void generatePageRanks(float* pageRank, float dFactor, int iterations = 52) {

		int* outputDegree = new int[currentVertices];
		float* pr_previous = new float[currentVertices];
		float onePart = 1.0f / currentVertices;
		for (int i = 0; i < currentVertices; i++) {
			outputDegree[i] = items[i].edges.count();
			pr_previous[i] = onePart;
		}

		int fromIndex;
		auto f2 = [this, &fromIndex, pageRank, pr_previous, outputDegree](Edge& edge) -> void {
			int toIndex = indexOf(edge.getTo());
			pageRank[toIndex] += pr_previous[fromIndex] / outputDegree[fromIndex];
		};

		onePart -= dFactor / currentVertices;
		for (int iteract = 0; iteract < iterations; iteract++) {

			for (int i = 0; i < currentVertices; i++)
				pageRank[i] = 0;

			for (int i = 0; i < currentVertices; i++) {
				fromIndex = i;
				items[i].edges.forEach(f2);
			}

			for (int i = 0; i < currentVertices; i++) {
				pageRank[i] = onePart + dFactor * pageRank[i];
				pr_previous[i] = pageRank[i];
			}
		}

		delete[] pr_previous;
		delete[] outputDegree;
	}

};

