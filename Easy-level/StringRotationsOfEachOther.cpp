#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // Concatenate s1 with itself to cover all possible rotations.
        // If s2 is a rotation of s1, then it must be a substring of (s1 + s1)
        string s = s1 + s1;

        int cnt = 0; // Counts how many consecutive matching characters we found
        int j = 0;   // Pointer for s2

        // Traverse the concatenated string
        for(int i = 0; i < s.length(); i++){
            if(j == s2.length()){
                // If we have matched the entire s2, we can stop
                break;
            }
            if(s[i] == s2[j]){
                // Current characters match, move ahead in s2
                j++;
                cnt++;
            }
            else if(s[i] == s2[0]){
                // Reset and try matching from the beginning of s2
                j = 1;
                cnt = 1;
            }
            else{
                // No match, reset the counters
                j = 0;
                cnt = 0;
            }
        }

        // If we have matched all characters in s2, it is a valid rotation
        if(cnt == s2.length()) return true;

        // Otherwise, s2 is not a rotation of s1
        return false;
    }
};
