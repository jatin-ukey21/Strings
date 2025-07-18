#include <bits/stdc++.h>
using namespace std;

/*
You are given a string s and a list dictionary[] of words. Your task is to determine
whether the string s can be formed by concatenating one or more words from the dictionary[].

Note: From dictionary[], any word can be taken any number of times and in any order.

Examples :

Input: s = "ilike", dictionary[] = ["i", "like", "gfg"]
Output: true
Explanation: s can be breakdown as "i like".
Input: s = "ilikegfg", dictionary[] = ["i", "like", "man", "india", "gfg"]
Output: true
Explanation: s can be breakdown as "i like gfg".
Input: s = "ilikemangoes", dictionary[] = ["i", "like", "man", "india", "gfg"]
Output: false
Explanation: s cannot be formed using dictionary[] words.
*/

class Solution
{
public:
    // RECURSIVE APPROACH
    /*
    You're doing this using recursion — starting from index 0, and at each step, trying every possible prefix and then recursing on the rest.

🔍 Let’s take a simple example:
Input:
s = "applepenapple"
Let’s assume every prefix could be in the dictionary (worst case).

At index 0, you try splitting like:

'a' | pplepenapple
'ap' | plepenapple
'app' | lepenapple
'appl' | epenapple
'apple' | penapple
...
At every index, you're trying every possible cut (i.e., prefix), and then recursing on the remaining part of the string.

🔁 Now think recursively:
Let’s say your string has length n = 4, like abcd. Here’s what the recursive calls look like:

Start at index 0:
Try:
  - 'a' + solve("bcd")
      → 'b' + solve("cd")
          → 'c' + solve("d")
              → 'd' + solve("")
          → 'cd' + solve("")
      → 'bc' + solve("d")
  - 'ab' + solve("cd")
  - 'abc' + solve("d")
  - 'abcd' + solve("")
So you're making a tree of recursive calls.

💥 How many ways can you break a string of n characters?
Let’s say for string "abcd", you can break it like:

a + b + c + d
ab + c + d
a + bc + d
abc + d
a + bcd
abcd
...
There are roughly 2ⁿ ways to break it because:

For each position between characters, you decide: "break here or not?" There are n-1 breakpoints → 2^(n-1) combinations
So:

🔴 Total number of recursive calls = roughly O(2ⁿ) --- TIME COMPLEXITY 
    */
    bool wordBreakRec(int ind, string &s, int n, vector<string> &dictionary)
    {
        //AT EACH INDEX, I HAVE THE CHOICE TO EITHER BREAK THE STRING FROM THIS INDEX OR NOT, WHICH LEADS TO TWO CHOICES
        if (ind == n)
            return true;

        string prefix = "";

        for (int i = ind; i < s.size(); i++)
        {
            prefix += s[i];

            if (find(dictionary.begin(), dictionary.end(), prefix) != dictionary.end() &&
                wordBreakRec(i + 1, s, n, dictionary))
            {
                return true;
            }
        }

        return false;
    }
    bool wordBreak(string &s, vector<string> &dictionary)
    {

        return wordBreakRec(0, s, s.size(), dictionary);
    }
};

//APPROACH 2 - DP
//https://media.geeksforgeeks.org/wp-content/cdn-uploads/wordBreak1.png
/*
  TIME COMPLEXITY - O(N*N)
🧠 How many distinct recursive calls?
   You memoize results using dp[ind], so:

Only n distinct indices (ind = 0 to n-1) will be computed Once dp[ind] is filled, it’s reused
✅ So the number of unique recursive calls = O(n)

🔁 What happens inside each recursive call?
From each ind, you build prefixes:

for (int i = ind; i < s.size(); i++) {
    prefix += s[i];       // O(1) per char
    dict.count(prefix);   // O(1) on average (unordered_set)
}
The loop runs up to n - ind times In worst case, from each ind you do up to n operations
✅ So each call takes O(n) time

✅ Multiply both:
O(n) recursive calls (one for each starting index) Each does O(n) prefix building and lookup
✅ Final Time Complexity = O(n × n) = O(n²)
*/
class Solution {
  public:
    bool wordBreakRec(int ind,string &s,int n,vector<int> &dp,unordered_set<string> &dict){
        if(ind == n) return true;
        if(dp[ind] != -1) return dp[ind];
        
        string prefix = "";
        bool isPossible = false;
        for(int i = ind; i < s.size(); i++){
            prefix += s[i];
            
            if(dict.count(prefix) && wordBreakRec(i + 1,s,n,dp,dict)){
                isPossible = true;
                break;
            }
        }
        
        return dp[ind] = isPossible;
    }
    bool wordBreak(string &s, vector<string> &dictionary) {
        vector<int> dp(s.size(),-1);
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        return wordBreakRec(0,s,s.size(),dp,dict);
    }
};