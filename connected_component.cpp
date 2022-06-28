// 2016054011_±èÁö¿¬_508 

#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
   int N;         // number of verticies
   vector<int> *adj; // pointer to adjacency vector

   void search(int v, bool visited[], int arr[], const int count)
   {
      visited[v] = true;
      arr[v] = count;

      // recursive for all verticies adjacent to vertex
      vector<int>::iterator i;
      for (i = adj[v].begin(); i != adj[v].end(); ++i)
         if (!visited[*i])
            search(*i, visited, arr, count);
   }
public:
   Graph(int N) { 
      this->N = N;
      adj = new vector<int>[N];
   }
   void addEdge(int x, int y) { 
      adj[x].push_back(y); 
      adj[y].push_back(x);
   }

   void connectedComponents()
   {
      int count = 0;
      bool *visited = new bool[N];
      int *arr = new int[N];

      for (int v = 0; v < N; v++)
         visited[v] = false;      // reset the array

      for (int v = 0; v < N; v++)
      {
         if (visited[v] == false)
         {
            search(v, visited, arr, count);
            ++count;
         }
      }
      cout << count - 1 << endl;
      for (int i = 1; i < N; i++)
         cout << arr[i] << endl;

   }

};


int main()
{
   int N, x, y;
   cin >> N;

   Graph graph(N+1);
   
   while (cin >> x >> y)
      graph.addEdge(x, y);

   graph.connectedComponents();


    return 0;
}

