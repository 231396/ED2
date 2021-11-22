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
		LinkedQueue<Edge> edges;
		Vertex* vertex;
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

	Edge* findEdge(Vertex& from, Vertex& to, int itemIndex) {
		auto findFunc = [from, to](Edge& edge) -> bool {
			return edge.getFrom() == from && edge.getTo() == to;
		};
		return items[itemIndex].edges.find(findFunc);
	}

	int indexOf(Vertex& vertex) {
		int index = 0;
		for (int i = 0; i < currentVertices; i++)
			if (vertex == *items[i].vertex)
				return i;
		return -1;
	}
	int indexOfEdge(Vertex& from, Vertex& to) {
		int index = 0;
		for (int i = 0; i < currentVertices; i++)
			if (findEdge(from, to, i) != NULL)
				return i;
		return -1;
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

		Edge newEdge = Edge(&from, &to, weight);
		items[fIndex].edges.enqueue(newEdge);
		if (!directed && from != to) {
			newEdge = Edge(&to, &from, weight);
			items[fIndex].edges.enqueue(newEdge);
		}
	}

	int getWeight(Vertex& from, Vertex& to) {
		Edge* edge;
		for (int i = 0; i < currentVertices; i++)
			edge = findEdge(from, to, i);
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
			std::cout << edge.getFrom().() << "(" << edge.getWeight() << ")" << ", ";
			std::cout << edge.getTo().getName() << "(" << edge.getWeight() << ")" << ", ";
		};
		for (int i = 0; i < currentVertices; i++) {
			std::cout << items[i].vertex->getName() << " : ";
			items[i].edges.forEach(printEdge);
			std::cout << std::endl;
		}
	}

	void generatePageRanks(float* pageRank, float dFactor, int iterations = 52) {

		int* outputDegree = new int[currentVertices];
		float* pr_previous = new float[currentVertices];
		for (int i = 0; i < currentVertices; i++) {
			outputDegree[i] = vertices[i]->getEdges()->count();
			pr_previous[i] = 1.0f / currentVertices;
		}

		auto f = [pr_previous, outputDegree](Edge& edge, float last, int count) -> float {
			return last + pr_previous[count] / outputDegree[count];
		};

		auto f2 = [pageRank, pr_previous, outputDegree](Edge& edge, int count) -> void {

			edge.getVertex();
			return last + pr_previous[count] / outputDegree[count];
		};


		for (int iteract = 0; iteract < iterations; iteract++) {
			//for (int i = 0; i < currentVertices; i++) {
				//float sum = vertices[i]->getEdges()->reduce<float>(f);
			//	for (int j = 0; j < currentVertices; j++)
			//		if(existEdge(*vertices[i], *vertices[j]))
			//			pageRank[i] += pr_previous[j] / outputDegree[j];
			//	pageRank[i] = (1 - dFactor) / currentVertices + dFactor * pageRank[i];
			//}

			for (int i = 0; i < currentVertices; i++) {
				vertices[i]->getEdges()->forEach(f2);
			}


			for (int i = 0; i < currentVertices; i++)
				pr_previous[i] = pageRank[i];
		}

		delete[] pr_previous;
		delete[] outputDegree;
	}

};

