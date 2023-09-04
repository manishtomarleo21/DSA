#include<iostream>
#include<map>
#include <unordered_map>
#include<vector>
#include <numeric>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> ans;

void solver(int i, vector<int>& candidates, vector<int>& temp, int target){

      if(target == 0){
        ans.push_back(temp);
        return;
      }  

      if(target<0){
        return;
      }

      if(i==candidates.size()) return;
    
      solver(i+1, candidates, temp, target);

      temp.push_back(candidates[i]);
      solver(i, candidates, temp, target-candidates[i]);

      temp.pop_back();  
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    ans.clear();

    vector<int> temp;
    solver(0, candidates, temp, target);
    return ans;
}

int main()
{

    // vector<vector<int>> vec = {{0,1,0}, {0,0,1}, {1,1,1}, {0,0,0}};
    vector<int> vec = {2,3,6,7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(vec, target);

    for(auto temp : ans){
        for(int x : temp) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}

