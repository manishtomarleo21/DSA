#include <set>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>
#include <cstring>
#include <string>

 using namespace std;

   


int main()
{
    // vector <int> a = {0,0,1,1,1,2,2,3,3,4};
    int num = 5;

    vector<vector<int>> vec(num);

    for (int i = 0; i < num; i++)
    {
        vec[i].resize(i+1); // this will resize array for 1st row it will 1 size 2nd row 2 size nth row n size

        vec[i][0] = vec[i][i] = 1; // first val and last val 1 of coloums
        for (int j = 1; j < i; j++)
        {
            vec[i][j] = vec[i-1][j] + vec[i-1][j-1];
        }
        
    }
       
   for (int i = 0; i < vec.size(); i++)
   {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
   }
   
    
    


    
  
    

    return 0;
}