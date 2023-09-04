#include<iostream>
#include<map>
#include <unordered_map>
#include<vector>
#include <numeric>
#include <set>
#include <algorithm>

using namespace std;
int maxScore(vector<int>& cardPoints, int k) {
    
   int len = cardPoints.size();
   vector<int> vec(len, 0);

   int ans = 0, score= 0, runSum = 0, j;

  for (int i = 0; i < len; i++)
  {
    runSum+=cardPoints[i];
    vec[i]= runSum;
  }

  if(len == k ) return runSum;

  for (int i = 0; i <= k; i++)
  {
    j = i+len-k-1;
    if(i==0) ans = vec[j];
    else ans = vec[j]-vec[i-1];

    score = max(score, runSum-ans);

  }

  return score;
     
 
}

int main()
{

   // vector<vector<int>> vec = {{0,1,0}, {0,0,1}, {1,1,1}, {0,0,0}};
    vector<int> vec = {1,2,3,4,5,6,1};
    int target = 3;
    int ans = maxScore(vec, target);

    cout<<ans<<endl;
 
  return 0;
}

