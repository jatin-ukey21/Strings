#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Helper function to generate all permutations
    void f(int ind, string &s, set<string> &sperm) {
        // Base Case: If we've fixed all characters, add current permutation to set
        if (ind == s.size()) {
            sperm.insert(s);  // Insert to set to ensure uniqueness
            return;
        }

        // Recursive case: Try fixing each character at current index
        for (int i = ind; i < s.size(); i++) {
            // Swap current character with character at position i
            // This places s[i] at index 'ind' — we treat it as fixed for this recursive call
            swap(s[ind], s[i]);

            // Recurse to fix the next index (ind + 1)
            f(ind + 1, s, sperm);

            // Backtrack: undo the swap to restore the original string
            // This is crucial to explore other permutations correctly
            swap(s[ind], s[i]);
        }
    }

    // Main function to return all unique permutations of a string
    vector<string> findPermutation(string &s) {
        set<string> sperm;  // Stores unique permutations in sorted order
        f(0, s, sperm);     // Begin recursive permutation generation
        return vector<string>(sperm.begin(), sperm.end());  // Convert set to vector
    }
};
