
#include<bits/stdc++.h>
using namespace std;
using iPair = pair<int, int>;

// general Parent-Pointer Tree implementation for UNION/FIND
class ParPtrTree {
  private:
    vector<int> parents; // parent pointer vector
    vector<int> weights; // weights for weighted union
  public:
    // constructor
    ParPtrTree(size_t size) {
        parents.resize(size); //create parents vector
        fill(parents.begin(), parents.end(), -1); // each node is its own root to start
        weights.resize(size);
        fill(weights.begin(), weights.end(), 1);// set all base weights to 1
    }
    // Return the root of a given node with path compression
    // recursive algorithm that makes all ancestors of the current node
    // point to the root
    int FIND(int node) {
        if (parents[node] == -1) return node;
        parents[node] = FIND(parents[node]);
        return parents[node];
    }

    // Merge two subtrees if they are different
    void UNION(int node1, int node2) {
        int root1 = FIND(node1);
        int root2 = FIND(node2);
        // MERGE two trees
        if (root1 != root2) {
            if (weights[root1] < weights[root2]) {
                parents[root1] = root2;
                weights[root2] += weights[root1];
            }
            else {
                parents[root2] = root1;
                weights[root1] += weights[root2];
            }
        }
    }

    string toString() {
        string nodes = "nodes:\t";
        string prts = "parents:\t";
        for (int i=0; i < this->parents.size(); i++) {
            prts += to_string(this->parents[i]) + '\t';
            nodes += " \t " + to_string(i);
        }
        return prts + "\n" + nodes;
    }
};

// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
    // for min priority queue
     bool operator<(const Edge &other) const {
        return this->weight > other.weight;
    }
};
// a structure to represent undirected
// and weighted graph
struct Graph
{
    // V -> Number of vertices, E -> Number of edges
    int V, E;
    // graph is stored in a min heap priority_queue
    // Kruskal algo requires working with edges with smallest to highest weight
    priority_queue<Edge, vector<Edge> > edges;
    // constructor
    Graph(int v, int e) {
        V = v;
        E = e;
    }

    void addEdge(int u, int v, int w) {
        edges.push({u, v, w});
    }
};
// function to construct MST using Kruskal's algorithm
// returns the total weight of MST
// edges forming MST are stored in MST vector
int KruskalMST(Graph& graph, vector<iPair> & MST)
{
    if (graph.E == 0)
        return 0;

    int numMST = graph.V;  // initially V disjoint classes
    ParPtrTree unionfind(graph.V);
    int weight = 0;

    while (numMST > 1 && !graph.edges.empty())
    {
        // pick the smallest edge
        Edge edge = graph.edges.top();
        graph.edges.pop();
        int x = unionfind.FIND(edge.src); // root of src
        int y = unionfind.FIND(edge.dest); // root of dest
        // if src and dest nodes are in different sets
        if (x != y)
        {
            int u = edge.src;
            int v = edge.dest;
            // add weight
            weight += edge.weight;
            // the ordering is not required, but...
            if (u > v) swap(u, v);
            // add u->v edge to MST
            MST.push_back({u, v});
            // combine equiv classes
            unionfind.UNION(u, v);
            numMST--; // one less MST
        }
    }
    return weight;
}
void kattis()
{
  int n, m, u, v, w, i;
  while(cin >> n && cin >> m && n != 0)
  {
    Graph graph(n,m);
    vector<iPair> MST;
    for (i=0; i < m; i++)
    {
      int u,v,w;
      cin >> u >> v >> w;
      graph.addEdge(u,v,w);
    }
    int wt;
    wt = KruskalMST(graph, MST);
    if (MST.size() == n-1)
    {
      sort(MST.begin(), MST.end());
      cout << wt << endl;
      for(auto &p:MST){
      cout << int(p.first) <<  " " << int(p.second) << '\n';
      }
    }
    else
    {
      cout << "Impossible" << endl;
    }
  }
};
void test()
{
  int testing, wt;
  vector<iPair> MST;
  Graph graph(6,8);
  graph.addEdge(0, 2, 7);
  graph.addEdge(0, 4, 9);
  graph.addEdge(1, 2, 5);
  graph.addEdge(1, 5, 6);
  graph.addEdge(2, 3, 1);
  graph.addEdge(2, 5, 2);
  graph.addEdge(3, 5, 2);
  graph.addEdge(4, 5, 1);
  wt = KruskalMST(graph, MST);
  testing = 16;
  assert(testing == wt);

  int testing2, wt2;
  Graph graph2(3,3);
  graph2.addEdge(0, 1, 4);
  graph2.addEdge(0, 2, 1);
  graph2.addEdge(1, 2, 3);
  wt2 = KruskalMST(graph2, MST);
  testing2 = 4;
  assert(testing2 == wt2);

  int wt3, testing3;
  Graph graph3(2,1);
  graph3.addEdge(0, 1, 3);
  wt3 = KruskalMST(graph3, MST);
  testing3 = 3;
  assert(testing3 == wt3);

  cout << "All test cases passed..." << endl;
}
int main(int argc, char* argv[])
{
  if (argc > 1 && strncmp(argv[1], "test", 4) == 0)
      test();
  else
      kattis();
  return 0;
}
