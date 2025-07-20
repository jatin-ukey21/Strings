#include<bits/stdc++.h>
using namespace std;

//Given a string s of length n, find all the possible non-empty subsequences of the string s in lexicographically-sorted order.

class Solution {
  public:
    void f(int i,const string &ans,const string &s,vector<string> &pSet){
        if(i == s.size()){
            if (!ans.empty())
                pSet.push_back(ans);
            return;
        }
        
        //take
        f(i + 1,ans + s[i],s,pSet);
        
        //not take
        f(i + 1,ans,s,pSet);
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string> powerSet;
        f(0,"",s,powerSet);
        sort(powerSet.begin(),powerSet.end());
        return powerSet;
    }
};

/*
Input : s = "abc"
Output: 
a ab abc ac b bc c
Explanation : 
There are a total 7 number of subsequences possible for the given string, and they are mentioned above in lexicographically sorted order.
*/