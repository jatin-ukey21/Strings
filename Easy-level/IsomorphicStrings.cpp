#include<bits/stdc++.h>
using namespace std;

/*
✅ 🔹 Intuition (Short Explanation):
We want to check if each character in s1 maps uniquely and consistently to a character in s2,
 and that no two characters from s1 map to the same character in s2.

So we:
1.Use a map to store the mapping s1[i] → s2[i]
2.Use a visited array to make sure no character in s2 is reused for two different characters from s1
*/

class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // Map to store the mapping from characters in s1 to characters in s2
        unordered_map<char, char> map;

        // Array to mark if a character in s2 has already been mapped to (to ensure one-to-one mapping)
        vector<int> visited(256, 0); // Assuming ASCII characters

        int n = s1.size(); // Both strings are of equal length

        // Traverse each character of both strings
        for(int i = 0; i < n; i++) {

            // Case 1: If s1[i] is already mapped
            /*
            map[s1[i]] will return default value '\0' if key is not present, so if(map[s1[i]]) works 
            */
            if(map[s1[i]]) {
                // Check if the previously mapped character is the same as current s2[i]
                if(map[s1[i]] != s2[i]) return false; // Mismatch → Not isomorphic
            }

            // Case 2: s1[i] is not mapped yet, but s2[i] is already used for some other s1 char
            else if(visited[s2[i]]) {
                return false; // Another character already mapped to s2[i] → Not isomorphic
            }

            // Case 3: s1[i] and s2[i] both are unused → safe to map
            else {
                map[s1[i]] = s2[i];      // Create mapping from s1[i] to s2[i]
                visited[s2[i]] = 1;      // Mark s2[i] as already used
            }
        }

        // If all characters were mapped consistently → strings are isomorphic
        return true;
    }
};
