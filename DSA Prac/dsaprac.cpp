#include <bits/stdc++.h>

using namespace std;

void makeSet(int v, vector<int> &parent, vector<int> &sizes){
    parent[v] = v;
    sizes[v] = 1;
}

int findParent(int v, vector<int> &parent){
    if(v == parent[v]) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int> &parent, vector<int> &sizes){
    a = findParent(a, parent);
    b = findParent(b, parent);

    if(a!=b){
        if(sizes[a]<sizes[b]) swap(a,b);
        parent[b] = a;
        sizes[a]+=sizes[b];
    }
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {

    vector<int> parent(g_nodes+1);
    vector<int> sizes(g_nodes+1);

    vector<pair<int, pair<int,int>>> edges;

    for (int i = 0; i < g_from.size(); i++)
    {
        edges.push_back({g_weight[i], {g_from[i], g_to[i]}});
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= g_nodes; i++)
    {
        makeSet(i, parent, sizes);
    }
    
    int total_cost = 0;
    for(auto &edge: edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if(findParent(u, parent) == findParent(v, parent)) continue;
        unionSet(u, v, parent, sizes);
        total_cost+=wt;


    }
    return total_cost;  

}


int main()
{
    int g_nodes = 5;
    vector<int> g_from = {1, 1, 1, 1, 2, 3, 4};
    vector<int> g_to = {2, 3, 4, 5, 3, 4, 5};
    vector<int> g_weight = {20, 50, 70, 90, 30, 40, 60};

    int ans = kruskals(g_nodes, g_from, g_to, g_weight);
    cout<<ans<<endl;

    return 0;
}
