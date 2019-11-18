#include<bits/stdc++.h>
#include <cassert>

using namespace std;
const int oo = 1e9 + 5;
using iPair = pair<int, int>;
// finds SSSP to all the nodes from given source
// can be modified to find shortest path to a single destination
// see Single Destination comment below
template<class T>
void Dijkstra(T & G, int source, vector<int>& dist) {
    // min priority_queue of vertices that need to be processed
    // stores pair of <weight, vertex>
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    dist.resize(G.nodeCount());
    fill(dist.begin(), dist.end(), INT_MAX);
    vector<bool> visited(G.nodeCount(), false);
    dist[source] = 0;
    pq.push({0, source}); // {weight, vertex}
    while (! pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        // Single Destination:
        // if interested to find the path to one destination
        // check here if u == dest node; break if so
        if (visited[u]) continue;
        visited[u] = true;
        for(auto p: G.neighbors(u)) {
            int v = p.first;
            if (visited[v]) continue;
            int w = p.second;
            // if there's a shorter path to v through u
            int d = dist[u] + w;
            if (d < dist[v]) {
                dist[v] = d;
                pq.push({d, v});
                // update parent vector if path needs to be recorded
                //parent[v] = u;
            }
        }
    }
}
// Directed Graph using Adjacency List
// updae addEdge() for Undirected Graph
class Graph {
    private:
        vector<list<iPair> > graph; // list stores pair of neighbor id and weight

    public:
        Graph(size_t n) {
            for (int i=0; i<n; i++) {
                list<iPair> v; // create an empty list of int, int pair type
                graph.push_back(v);
            }
        }

        // return the number of vertices/nodes
        size_t nodeCount() {
            return graph.size();
        }

        // add a new edge from node u to node v, with weight w
        // assumes nodes are numbered from 0 to n-1
        void addEdge(int u, int v, int w) {
            graph[u].push_back({v, w});
            // if undirected graph must add edge from v to u
            // graph[v].push_bck({u, w});
        }

        // returns list of pairs containing neighbors of u, and weight
        list<iPair> neighbors(int u) {
            return graph[u];
        }
};
void kattis()
{
  int i,n,m,s,q,t;
  while(cin >> n >> m >> q >> s, n || m || q || s)
  {
    if(t++) {
        cout << "\n";
    }
    Graph graph(n);
    vector<int> dist;
    for (i=0; i < m; i++)
    {
      int u,v,w;
      cin >> u >> v >> w;
      graph.addEdge(u,v,w);
    }

    Dijkstra<Graph>(graph, s, dist);

    for (i=0; i < q; i++)
    {
      int req,disval;
      cin >> req;
      disval = dist[req];
      if (disval >= oo)
      {
        cout << "Impossible" << endl;
      }
      else
      {
        cout << disval << endl;
      }
    }
  }
}
void test()
{
    int testing;
    vector<int> Uno;
    Graph grafica(4);
    grafica.addEdge(0, 1, 1);
    grafica.addEdge(0, 2, 2);
    grafica.addEdge(1, 3, 3);
    grafica.addEdge(2, 3, 1);
    Dijkstra<Graph>(grafica, 0, Uno);
    testing = Uno[3];
    assert(testing == 3);

    vector<int>Dos;
    Graph grafica2(5);
    grafica2.addEdge(0, 1, 10);
    grafica2.addEdge(0, 2, 3);
    grafica2.addEdge(0, 3, 20);
    grafica2.addEdge(1, 3, 5);
    grafica2.addEdge(2, 1, 2);
    grafica2.addEdge(2, 4, 15);
    grafica2.addEdge(3, 4, 11);
    Dijkstra<Graph>(grafica2, 0, Dos);
    testing = Dos[4];
    assert(testing == 18);

    vector<int>Tres;
    Graph grafica3(4);
    grafica3.addEdge(0, 1, 10);
    grafica3.addEdge(0, 2, 3);
    grafica3.addEdge(0, 3, 20);
    grafica3.addEdge(1, 3, 5);
    Dijkstra<Graph>(grafica3, 2, Tres);
    testing = Tres[3];
    assert(testing >= oo);

cout << "All test cases passed" << endl;
}
int main(int argc, char* argv[])
{
  if (argc > 1 && strncmp(argv[1], "test", 4) == 0)
      test();
  else
      kattis();
  return 0;
}
