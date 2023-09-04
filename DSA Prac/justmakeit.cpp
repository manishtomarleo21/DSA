#include <set>
#include <iostream>
#include <algorithm>
#include<string>


//find all the connected components in a graph 
// its called forest where all the disconnected graphs are there

using namespace std;

vector<int> graph1[1000];
bool visited[1000];

vector<vector<int>> cc; //this two to store all the comonents individually
vector<int> curr;

void dfs(int vertex){

  curr.push_back(vertex);
  visited[vertex] = true;
  for(int child : graph1[vertex]){
    if(visited[child]) continue;

    dfs(child);
  }
}


int main()
{

    int n, m;
    cin>>n>>m;

    for (int i = 0; i < m; i++)
    {
      int v1, v2;
      cin>>v1>>v2;
      graph1[v1].push_back(v2);
      graph1[v2].push_back(v1);
    }

    //the number of times the dfs run it will gives the numnber of components
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
      if(visited[i]) continue;
      curr.clear();
      dfs(i); //i here is the node
      cc.push_back(curr);
      count++;
    }
    cout<<cc.size()<<endl; //will give the number of componets present in the vector

    //two print vector of vector
    for(auto c_cc: cc){
      for(int vertex : c_cc){
        cout<<vertex<<" ";
      }
      cout<<endl;
    }
    

    return 0;
}
/*

8 5
1 2
2 3
2 4
3 5
6 7


*/