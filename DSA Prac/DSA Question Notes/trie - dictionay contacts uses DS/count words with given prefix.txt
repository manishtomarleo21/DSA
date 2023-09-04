#include <set>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int charCount; //this we use count for every charcter which says for how manys words its used as prefix

        TrieNode(char ch){
            data = ch;
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
            isTerminal = false;
            charCount = 0;
            
        }
};

class Trie
{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word){
            if(word.length()==0){
                root->isTerminal = true;
                return;
            }

            int index = word[0]-'a';
            TrieNode* child;
            

            if(root->children[index]!=NULL){
                child = root->children[index];
                child->charCount++;
            }
            else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
                child->charCount++;
            }

            
            insertUtil(child, word.substr(1));

        }
        
        void insertWord(string word){
            insertUtil(root, word);
        }

        int counterPrefixUtil(TrieNode* root, string key){
            TrieNode* temp = root;
            vector<int> ans;

            for (int i = 0; i < key.length(); i++) //if length doesnt end and it shows null chahrcter which
            {                                     //not presetn it will return 0 else                      
                int index = key[i]-'a';
                if(!temp->children[index]){
                    
                    return 0;
                }
                temp = temp->children[index];

            }
            return temp->charCount; //here it will return the count for it
            
        }

        int counterPref(string word){
            return counterPrefixUtil(root, word);
        }

};


int main()
{

    Trie* t = new Trie();
    vector<int> ans;
    // t->insertWord("hack");
    // t->insertWord("hackerrank");

    // int a = t->counterPref("hacker");
    // cout<<a<<endl;

    // int n; cin>>n;
    // string a,b;
    // while (n--)
    // {
    //     cin>>a;
    //     if(a =="add"){
    //         cin>>b;
    //         t->insertWord(b);
    //     }
    //     else{
    //         cin>>b;
    //         int res = t->counterPref(b);
    //         cout<<res<<endl;
    //     }
    // }

    vector<vector<string>> queries = {{"add", "ed"},{"add", "eddie"}, {"add", "edward"}, {"find", "ed"}};
        for (int i = 0; i < queries.size(); i++)
        {
            if(queries[i][0] =="add"){
                t->insertWord(queries[i][1]);
            }
            else{
                int res = t->counterPref(queries[i][1]);
                ans.push_back(res);
            }
        }
        

    // for(auto x: ans) cout<<x<<" ";
    

    return 0;
}
/*

add ed
add eddie
add edward
find ed
add edwina
find edw
find a


add hack        queries = ['add hack', 'add hackerrank', 'find hac', 'find hak']
add hackerrank
find hac
find hak


*/