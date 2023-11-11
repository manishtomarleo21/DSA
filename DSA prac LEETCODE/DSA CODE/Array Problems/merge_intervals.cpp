#include<iostream>
#include <bits/stdc++.h>

using namespace std;

// bool compare(const vector<int>& a, vector<int>& b){
//     return a[0] < b[0];
// }

int main()
{
    
    // vector<vector<int>> vec = {{1,3}, {2,6}, {8, 15}, {16,18}};
    vector<vector<int>> vec = {{1,4}, {2,3}};
    sort(vec.begin(), vec.end());
    vector<vector<int>> ans;
    stack<vector<int>> st;
    int temp;

    st.push(vec[0]);
    
    for (int i = 1; i < vec.size(); i++)
    {
        
       if(st.top()[1] >= vec[i][0] && st.top()[1] < vec[i][1]){
            st.top()[1] = vec[i][1];
       } 
       if(st.top()[0] < vec[i][0] && st.top()[1] < vec[i][1]){
            st.push(vec[i]);
       }
       
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    for(auto v : ans){
        for(int a : v){
            cout<<a<<" ";
        }
        cout<<endl;
    }

    return 0;
}
