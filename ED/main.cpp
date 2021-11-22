#include <iostream>
#include "linked_queue.h"
#include "graph.h"
#include "vertex.h"

using std::cout;
using std::endl;

int main() {
	Graph graph = Graph(true);

	Vertex a, b, c, d;
	graph.addVertex(a = Vertex("A"));
	graph.addVertex(b = Vertex("B"));
	graph.addVertex(c = Vertex("C"));
	graph.addVertex(d = Vertex("D"));

	graph.addEdge(a, b);
	graph.addEdge(a, c);
	graph.addEdge(b, d);
	graph.addEdge(c, a);
	graph.addEdge(c, b);
	graph.addEdge(c, d);
	graph.addEdge(d, c);

	//Vertex wi, pr, ar, ro, wa, ne, ass, hu, kn, ni, so, my, tr, pa, sa;
	//graph.addVertex(wi = Vertex("Wizard"));
	//graph.addVertex(pr = Vertex("Priest"));
	//graph.addVertex(ar = Vertex("Archer"));
	//graph.addVertex(ro = Vertex("Rogue"));
	//graph.addVertex(wa = Vertex("Warrior"));

	//graph.addVertex(ne = Vertex("Necromancer"));
	//graph.addVertex(ass = Vertex("Assasin"));
	//graph.addVertex(hu = Vertex("Huntress"));
	//graph.addVertex(kn = Vertex("Knight"));
	//graph.addVertex(ni = Vertex("Ninja"));

	//graph.addVertex(so = Vertex("Sorcerer"));
	//graph.addVertex(my = Vertex("Mystic"));
	//graph.addVertex(tr = Vertex("Trickster"));
	//graph.addVertex(pa = Vertex("Paladin"));
	//graph.addVertex(sa = Vertex("Samurai"));

	//graph.addEdge(wi, pr);
	//graph.addEdge(pr, ar);
	//graph.addEdge(ar, ro);
	//graph.addEdge(ro, wa);
	//graph.addEdge(wi, ne);
	//graph.addEdge(wi, ass);
	//graph.addEdge(pr, ne);
	//graph.addEdge(ar, hu);
	//graph.addEdge(ro, ass);
	//graph.addEdge(ro, hu);
	//graph.addEdge(ro, ni);
	//graph.addEdge(wa, kn);
	//graph.addEdge(wa, ni);
	//graph.addEdge(ne, so);
	//graph.addEdge(ass, so);
	//graph.addEdge(ne, my);
	//graph.addEdge(hu, my);
	//graph.addEdge(ass, tr);
	//graph.addEdge(pa, tr);
	//graph.addEdge(pr, pa);
	//graph.addEdge(kn, pa);
	//graph.addEdge(kn, sa);
	//graph.addEdge(ni, sa);

	//int len = graph.countVertices();
	//float* pageRanks = new float[len];

	//graph.generatePageRanks(pageRanks);

	//for (int i = 0; i < len; i++)
	//	cout << pageRanks[i] << " , ";

	graph.print();

	auto x = getchar();
}



