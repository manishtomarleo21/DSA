#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

//To avpoid passing the whole matrix i m defining globally so we can access it from anywhere
static int t[10+1][10+1];

//longest common subsequences
//With part two for explaination check one part

//LCS with recursion and memoisation 2 part

//Here we will create a matris and save the results so we can save the over work of recursion and can 
//optimize the code

int lcs(string x, string y, int m, int n){
    //Base condion where the recursion should stop
    //This will return 0 when string lenth become zero
    if (m == 0 || n == 0)
    {
        return 0;
    }

    
    if (t[m][n]!=-1)
    {
        return t[m][n];
    }

    //choice digrame situatuin 
    //This will add one in lcs if find maths and remove the last elements in strings to check ahead
    //as we are checeking the string from the last
    if(x[m-1] == y[n-1]){
        return t[m][n] = 1+(lcs(x, y, m-1, n-1));
    }
    else{
        //breaking in smaller parts
        //If match milte nhi then we run two recursoin seperate in one we decrease x string lenght 
        // and in other we decrease y length and find the max from both of them as 
        // both are chechking the same again some
        return t[m][n] = max(lcs(x, y, m, n-1), lcs(x, y, m-1, n));
    }
    
}


int main()
{

    //This is included<cstring>
    //memset puri table m -1 dal dega and takes three args 
    //1where to fill, 2whhat to fill, 3or kitna th size de do
    memset(t, -1, sizeof(t));

    string x = "abcdefg";
    string y = "abcmdej";

    //swcond string chars will match above one but mathicng only forward line will not intersect if character aage piche

    //declaring lcs func which return the int length two strings x and y and length of both the strings
    int val = lcs(x, y, x.length(), y.length());

    cout<<val<<endl;

    //Now check the LCS with memoization 2 part which is optimized for the less work 

    return 0;
}
