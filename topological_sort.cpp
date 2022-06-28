//2016054011_±èÁö¿¬_508 

#include <iostream>
#include <list>
#include <stack>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

class Graph
{
private:
   int N;            // number of verticies
   list<int> *adj;      //adjacency matrix containing listsList

   void sort(int v, bool visited[], stack<int> &Stack);

public:
   //constructor
   Graph(int N);

   // member functions
   void addEdge(int x, int y);

   void topologicalSort();
};

Graph::Graph(int N) {
   this->N = N;
   adj = new list<int>[N];
}

void Graph::addEdge(int x, int y) {
   adj[x].push_back(y);
}

void Graph::sort(int v, bool visited[], stack<int> &Stack) {
   visited[v] = true;

   list<int>::iterator i;
   for (i = adj[v].begin(); i != adj[v].end(); ++i)
      if (!visited[*i])
         sort(*i, visited, Stack);

   // Push current vertex to stack which stores result
   Stack.push(v);
}

void Graph::topologicalSort() {
   stack<int> Stack;
   bool *visited = new bool[N];

   for (int i = 0; i < N; i++)
      visited[i] = false;

   for (int i = 0; i < N; i++)
      if (visited[i] == false)
         sort(i, visited, Stack);

   while (!Stack.empty())
   {
      if (Stack.top() != 0)
         cout << Stack.top() << " ";
      Stack.pop();
   }
   cout << endl;
}


int main()
{
   int N, x, y, DAG = 1;
   //int count = 0;
   cin >> N;

   Graph graph(N+1);

   while(scanf("%d %d", &x, &y) != EOF); 
   {
        //cin >> x >> y;
		if (x == y){
			DAG = 0;
        }
        if (DAG == 1)
			graph.addEdge(x, y);
        //count++;
   }
   cout << DAG << endl;

   if (DAG == 1)
      graph.topologicalSort();

    return 0;
}

