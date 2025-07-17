#include<bits/stdc++.h>
using namespace std;

//Example Scenario based problem description
/*
💼 Scenario: Autocomplete System at a Search Engine
Problem Title: "Search Prefix Engine"

You have just joined the engineering team at QuickFind, a search engine startup. One of your first tasks is
to help improve the autocomplete feature for the search bar.

Every time a user begins typing, the system shows suggestions based on popular queries that start with the same prefix.

To implement this, you need to write a function that takes a list of past search queries (strings)
and finds the longest common prefix that appears at the beginning of all search queries.

🔍 Function Specification:
string longestCommonPrefix(vector<string>& queries);
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*
            🔍 Intuition Behind This Approach:

            When we sort the array of strings lexicographically,
            the most dissimilar strings (in terms of prefix) will end up
            at the first and last positions.
            Means,it will save our time bcoz first and last strings will have minimal
            starting prefix characters to be matched (dictionary order)

            The longest common prefix (LCP) of the entire array will always
            be a prefix of both the first and last strings.

            So instead of comparing every string, we just compare the first
            and last strings after sorting, and find their common prefix.
            This is more efficient and avoids unnecessary comparisons.
        */

        // Edge case: if list is empty, return empty string
        if (strs.size() == 0) return "";

        // If only one string, it's the common prefix by default
        if (strs.size() == 1) return strs[0];

        // If the first string is empty, prefix will be empty
        if (strs[0].empty()) return "";

        // Step 1: Sort the array lexicographically
        sort(strs.begin(), strs.end());

        // Step 2: After sorting, the LCP of the whole array must be common
        // between the first and last strings
        string first = strs[0];
        string last = strs[strs.size() - 1];
        string result = "";

        // Step 3: Compare characters of first and last strings
        for (int i = 0; i < first.length(); i++) {
            // If characters mismatch at any point, break the loop
            if (first[i] != last[i])
                break;

            // If matched, add the character to result
            result.push_back(first[i]);
        }

        // Step 4: Return the accumulated prefix
        return result;
    }
};
/*
Quick Summary of Logic in Code:
1.Sort the array → brings most different strings to ends
2.Compare only first and last → gives minimal shared prefix
3.Return matching portion → that’s the LCP for all
*/