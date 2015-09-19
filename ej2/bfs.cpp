#include <queue>


enum { 
    inf = std::numeric_limits<int>::max() 
};

enum Color {
    blanco,
    gris,
    negro
};

struct vertice {
    char id;

    // BFS
    Color color;
    int dist;
    vertice* padre;

};

struct grafo {
    std::vector<vertice> vertices;
    std::vector< std::vector<vertice*> > lista;
};

int bfs(grafo G, vertice* s)
{
	
	for (auto& v: G.vertices)
	{
		v.color = blanco;
		v.dist = inf;
		v.padre = NULL;
	}

	s.color = gris;
	s.dist = 0;
	s.padre = NULL;

	std::queue cola;
	cola.push(s);

	while (!cola.empty)
	{
		auto v = cola.front();
		cola.pop();

		for (auto& w: G.lista[v])
		{
			if (w.color == blanco)
			{
				w.color = gris;
				w.dist = v.dist + 1;
				w.padre = v;
				cola.push(v);
			}


		}
		v.color = negro;
	}

}