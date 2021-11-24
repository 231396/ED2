#include <iostream>

#include "graph.h"

using std::cout;
using std::endl;

void test(Graph& graph) {
	//graph->print();

	float* pageRanks = graph.generatePageRanks(0.85f, 52);

	float sum = 0;
	for (int i = 0; i < graph.numberOfVertices(); i++) {
		auto item = graph.getItem(i);
		cout << item.vertex->getName() << ": " << pageRanks[i] << "  " << (int)(pageRanks[i] * 100) << "%" << endl;
		sum += pageRanks[i];
	}
	cout << "SUM -> " << sum << endl << endl;
}

void case1() {
	Graph* graph = new Graph(true);

	Vertex a, b, c, d;
	graph->addVertex(a = Vertex("A"));
	graph->addVertex(b = Vertex("B"));
	graph->addVertex(c = Vertex("C"));
	graph->addVertex(d = Vertex("D"));

	graph->addEdge(a, b);
	graph->addEdge(a, c);
	graph->addEdge(b, d);
	graph->addEdge(c, a);
	graph->addEdge(c, b);
	graph->addEdge(c, d);
	graph->addEdge(d, c);

	test(*graph);
}

void case2() {
	Graph* graph = new Graph(true);

	Vertex wi, pr, ar, ro, wa, ne, ass, hu, kn, ni, so, my, tr, pa, sa;
	graph->addVertex(wi = Vertex("Wizard"));
	graph->addVertex(pr = Vertex("Priest"));
	graph->addVertex(ar = Vertex("Archer"));
	graph->addVertex(ro = Vertex("Rogue"));
	graph->addVertex(wa = Vertex("Warrior"));
	graph->addVertex(ne = Vertex("Necromancer"));
	graph->addVertex(ass = Vertex("Assasin"));
	graph->addVertex(hu = Vertex("Huntress"));
	graph->addVertex(kn = Vertex("Knight"));
	graph->addVertex(ni = Vertex("Ninja"));
	graph->addVertex(so = Vertex("Sorcerer"));
	graph->addVertex(my = Vertex("Mystic"));
	graph->addVertex(tr = Vertex("Trickster"));
	graph->addVertex(pa = Vertex("Paladin"));
	graph->addVertex(sa = Vertex("Samurai"));

	test(*graph);
}

void case3() {
	Graph* graph = new Graph(false);

	Vertex j, g, s, sj, coz, ce, c, l, q1, q2, q3, b;
	graph->addVertex(j = Vertex("Jardim"));
	graph->addVertex(g = Vertex("Garagem"));
	graph->addVertex(s = Vertex("Sala"));
	graph->addVertex(sj = Vertex("Sala de Jantar"));
	graph->addVertex(coz = Vertex("Cozinha"));
	graph->addVertex(ce = Vertex("Corredor Externo"));
	graph->addVertex(c = Vertex("Corredor"));
	graph->addVertex(l = Vertex("Lavabo"));
	graph->addVertex(q1 = Vertex("Quarto 1"));
	graph->addVertex(q2 = Vertex("Quarto 2"));
	graph->addVertex(q3 = Vertex("Quarto 3"));
	graph->addVertex(b = Vertex("Banheiro"));

	graph->addEdge(j, g);
	graph->addEdge(g, s);
	graph->addEdge(g, ce);
	graph->addEdge(s, sj);
	graph->addEdge(sj, coz);
	graph->addEdge(sj, c);
	graph->addEdge(coz, ce);
	graph->addEdge(ce, q3);
	graph->addEdge(q3, b);
	graph->addEdge(q3, c);
	graph->addEdge(c, b);
	graph->addEdge(c, q1);
	graph->addEdge(c, q2);
	graph->addEdge(c, l);

	test(*graph);
}

int main() {

	case1();
	case2();
	case3();

	auto x = getchar();
}



