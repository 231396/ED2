#include <iostream>
#include "graph.h"
#include "linked_queue.h"
#include "vertex.h"

void printItem(Vertex* t) {
	std::cout << t->getNome() << std::endl;
}

int main() {
	Graph graph;
	Vertex a, b, c, d, e; 
	graph.addVertex(a = Vertex("A"));
	graph.addVertex(b = Vertex("B"));
	graph.addVertex(c = Vertex("C"));
	graph.addVertex(d = Vertex("D"));
	graph.addVertex(e = Vertex("E"));

	graph.addEdge(a, b, 2);  
	graph.addEdge(a, c, 1);
	graph.addEdge(b, c, 3);  
	graph.addEdge(c, e, 4);
	graph.addEdge(d, e, 5);

	graph.printMatrix();

	auto x = getchar();
}
