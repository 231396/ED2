#include <iostream>
#include "linked_queue.h"
#include "graph.h"
#include "vertex.h"

using std::cout;
using std::endl;

int main() {
	Graph graph = Graph(true);

	//FAKE

	//Vertex a, b, c, d;
	//graph.addVertex(a = Vertex("A"));
	//graph.addVertex(b = Vertex("B"));
	//graph.addVertex(c = Vertex("C"));
	//graph.addVertex(d = Vertex("D"));
	//graph.addEdge(a, b, 1);
	//graph.addEdge(b, b, 2);
	//graph.addEdge(b, c, 3);

	//REAL

	Vertex wi, pr, ar, ro, wa, ne, ass, hu, kn, ni, so, my, tr, pa, sa;
	graph.addVertex(wi = Vertex("Wizard"));
	graph.addVertex(pr = Vertex("Priest"));
	graph.addVertex(ar = Vertex("Archer"));
	graph.addVertex(ro = Vertex("Rogue"));
	graph.addVertex(wa = Vertex("Warrior"));

	graph.addVertex(ne = Vertex("Necromancer"));
	graph.addVertex(ass = Vertex("Assasin"));
	graph.addVertex(hu = Vertex("Huntress"));
	graph.addVertex(kn = Vertex("Knight"));
	graph.addVertex(ni = Vertex("Ninja"));

	graph.addVertex(so = Vertex("Sorcerer"));
	graph.addVertex(my = Vertex("Mystic"));
	graph.addVertex(tr = Vertex("Trickster"));
	graph.addVertex(pa = Vertex("Paladin"));
	graph.addVertex(sa = Vertex("Samurai"));

	graph.addEdge(wi, pr);
	graph.addEdge(pr, ar);
	graph.addEdge(ar, ro);
	graph.addEdge(ro, wa);
	graph.addEdge(wi, ne);
	graph.addEdge(wi, ass);
	graph.addEdge(pr, ne);
	graph.addEdge(ar, hu);
	graph.addEdge(ro, ass);
	graph.addEdge(ro, hu);
	graph.addEdge(ro, ni);
	graph.addEdge(wa, kn);
	graph.addEdge(wa, ni);
	graph.addEdge(ne, so);
	graph.addEdge(ass, so);
	graph.addEdge(ne, my);
	graph.addEdge(hu, my);
	graph.addEdge(ass, tr);
	graph.addEdge(pa, tr);
	graph.addEdge(pr, pa);
	graph.addEdge(kn, pa);
	graph.addEdge(kn, sa);
	graph.addEdge(ni, sa);

	graph.print();
	auto x = getchar();
}



