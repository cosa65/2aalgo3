#include <queue>
#include <limits>

class ej2
{


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

	public:
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
			v.padre = nullptr;
		}

		s->color = gris;
		s->dist = 0;
		s->padre = nullptr;

		std::queue<vertice*> cola;
		cola.push(s);

		while (!cola.empty())
		{
			auto v = cola.front();
			cola.pop();

			for (auto& w: G.lista[v->id])
			{
				if (w->color == blanco)
				{
					w->color = gris;
					w->dist = v->dist + 1;
					w->padre = v;
					cola.push(v);
				}


			}
			v->color = negro;
		}

	}

}; //class ej2

int main(int argc, char const *argv[])
{

	return 0;
}