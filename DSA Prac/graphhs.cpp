#include <set>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>
#include <cstring>
#include <string>

using namespace std;



int main() {

   vector<int> vec = {1, 2, 3, 4, 5, 10, 11, 12, 13};

    sort(vec.begin(), vec.end());
    int count = 1;
    int minV = vec[0];

    for (int i = 0; i < vec.size()-1; i++)
    {
        if(minV+4<vec[i+1]){
            minV=vec[i+1];
            count++;
        } 
            
    }

    cout<<count<<endl;


    
    
   
  

 

    return 0;
}
