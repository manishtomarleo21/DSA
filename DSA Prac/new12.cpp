#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;



void dijkstra(int source, vector<vector<pair<int, int>>> &graph1, int n){
    vector<int> visited(n+1, 0);
    vector<int> dist(n+1, 100);

    set<pair<int, int>> st; //weight, node
    //sort according to weight

    st.insert({0, source});
    dist[source] = 0;

    while (st.size()>0)
    {
        auto node = *st.begin();
        int vertex = node.second;
        int dis = node.first;
        st.erase(st.begin());
        if(visited[vertex]) continue;
        visited[vertex] = 1;
        
        for(auto child : graph1[vertex]){
            int child_v = child.first;
            int wt = child.second;

            if(dist[vertex]+wt < dist[child_v]){
                dist[child_v] = dist[vertex]+wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
    for (int i = 1; i < dist.size(); i++)
    {
        cout<<dist[i]<<" ";
    }
    
    
}


int main() {

   
    int n = 4, m = 4;
    vector<vector<int>> edges = {{1, 2, 24}, {1,4, 20}, {3, 1, 3}, {4,3,12}};

    vector<vector<pair<int, int>>> graph1(n+1);

    for (int i = 0; i < m; i++)
    {
        graph1[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        graph1[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    
   dijkstra(1, graph1, n);
   
    

    return 0;
}
