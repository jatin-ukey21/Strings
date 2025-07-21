#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        // code here.
        int n = s.size();
        string str = "";
        str += s[0];
        int i = 0;
        for(int j = 1; j < n; j++){
            if(s[i] != s[j]){
                str += s[j];
                i = j;
            }
        }
        
        return str;
    }
};

/*
RECURSIVE LOGIC CODE:
void helper(string &s, int i, string &res) {
    // Base case: If we reach the end of the string
    if (i == s.size()) return;

    // If res is empty OR current char is different from last added
    if (res.empty() || res.back() != s[i]) {
        res += s[i];  // Add to result
    }

    // Recurse for the next index
    helper(s, i + 1, res);
}
string removeConsecutiveCharacter(string &s) {
    string res = "";
    helper(s, 0, res);
    return res;
}

*/