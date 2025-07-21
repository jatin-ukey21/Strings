/*
Given a list of word lists of size  M * N. The task is to return all sentences
 possible taking one word from a list at a time via recursion. 
*/
#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
    // Time Complexity: O(M^N)
    // Where:
    // N = number of lists (depth of recursion)
    // M = average number of words in each list
    //
    // At each of the N levels, we try up to M options
    // So total combinations (recursive paths) = M × M × ... N times = M^N
    //
    // Example:
    // list = {{"I", "You"}, {"love", "like"}, {"pizza", "burger"}}
    // M = 2, N = 3 ⇒ Total sentences = 2^3 = 8

    void f(int ind,const string& res,vector<vector<string>>& ans,vector<vector<string>>& list){
        if(ind == list.size()){
            ans.push_back({res});
            return;
        }
        
        //recur the current word index list
        for(int i = 0; i < list[ind].size(); i++){
            string toAppend = (res.empty() ? "" : " ") + list[ind][i];
            f(ind + 1, res + toAppend, ans, list);
        }
    }
    vector<vector<string>> sentences(vector<vector<string>>& list) {
        // Write your code here
        vector<vector<string>> ans;
        
        f(0,"",ans,list);
        
        
        return ans;
    }
};
