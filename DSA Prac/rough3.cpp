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
    vector <int> a = {7,1,5,3,6,4};
    int min = 10000;
    int max = 0;
    int indMin, indMax;
    for (int i = 0; i < a.size(); i++)
    {
        if(min>a[i]){
            min = a[i];
            indMin = i;
        }
        if(indMin<i){
            if(max<a[i]){
                max = a[i];
                indMax = i;
            }
        }
    }
    
    if(indMax < indMin && max-min < 0) cout<<0<<endl;
    else{
        cout<<max-min<<endl;
    }
  
    return 0;
}



