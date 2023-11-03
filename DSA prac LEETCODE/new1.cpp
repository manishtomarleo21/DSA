#include<iostream>
#include<vector>
#include<map>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   
   vector<vector<int>> ans;

    int numRows = 5;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> vec(i+1, 1);

        for (int j = 1; j < i; j++)
        {
            vec[j] = ans[i-1][j]+ans[i-1][j-1];
        }
        ans.push_back(vec);    
    }

}   

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 1;
        for(int i = 1; i<nums.size(); i++){
           if(nums[i-1]!=nums[i]) nums[len++] = nums[i];
        }
        
        return len;
    }
};

   
