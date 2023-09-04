#include<iostream>
#include<vector>

using namespace std;

int lcs(string x, string y, int m, int n){
    
    vector<vector<int>> lcs_table(m+1, vector<int>(n+1));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i-1] == y[j-1])
            {
                lcs_table[i][j] = lcs_table[i-1][j-1]+1;
            }
            else{
                lcs_table[i][j] = max(lcs_table[i][j-1], lcs_table[i-1][j]);
            }
            
        }
        
    }
    return lcs_table[m][n];
    

}

int main()
{
    string x = "abcdefg";
    string y = "abcmdej";


    int res = lcs(x, y, x.length(), y.length());
    cout<<res<<endl;
    return 0;
}
