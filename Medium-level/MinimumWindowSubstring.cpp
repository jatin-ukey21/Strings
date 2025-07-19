#include<bits/stdc++.h>
using namespace std;

//TC: O(n + m)
class Solution {
public:
    string minWindow(string s, string t) {
        // Edge case: if either string is empty, no valid window exists
        if (s.empty() || t.empty()) return "";

        // If s is shorter than t, it's impossible to contain all characters
        if (s.length() < t.length()) return "";

        // Hash array to store the frequency of characters needed from t
        vector<int> hash(256, 0); // ASCII range

        // Sliding window pointers
        int l = 0, r = 0;

        // To track the smallest window length found
        int minlen = INT_MAX;

        // Start index of the minimum window found
        int start = -1;

        // Count required characters from string t
        for (int i = 0; i < t.length(); i++) {
            hash[t[i]]++;  // Increment frequency for each character in t
        }

        // 'cnt' tracks how many required characters we've seen in current window
        int cnt = 0;

        // Total required characters to match = length of t
        int req = t.length();

        // Expand the window using right pointer 'r'
        while (r < s.length()) {
            // If the current character is still needed, increment matched count
            if (hash[s[r]] > 0) {
                cnt++;
            }

            // Decrease the need count for this character (even if not in t)
            hash[s[r]]--;

            // When all required characters are matched (cnt == req)
            while (cnt == req) {
                // Update minimum window if current one is smaller
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;  // Update length
                    start = l;           // Update starting index
                }

                // Try to shrink the window from the left (move l forward)
                hash[s[l]]++;  // Restore the frequency count for s[l]

                // If s[l] was a required character (hash becomes > 0), we’re now missing one
                if (hash[s[l]] > 0) {
                    cnt--;  // So reduce count of matched characters
                }

                l++;  // Move left boundary of the window forward
            }

            // Expand the window by moving right pointer
            r++;
        }

        // If no valid window was found, return empty string
        // Else return the smallest valid window
        return start == -1 ? "" : s.substr(start, minlen);
    }
};
/*
Ah! Got it — you're confused about this specific line and explanation:

--->hash[s[r]]--;
and particularly this part:

"Even if it's not in t, it will go negative — helps handle over-counting"

🧪 Example
Let’s say:

cpp
Copy
Edit
s = "ADOBECODEBANC"
t = "ABC"
Initial hash[] will look like:

cpp
Copy
Edit
hash['A'] = 1
hash['B'] = 1
hash['C'] = 1
Now we start sliding the window from left to right using r.

🚶‍♂️ Imagine r = 0 → s[0] = 'A'

if (hash['A'] > 0) cnt++;      // cnt becomes 1 ✅
hash['A']--;                   // hash['A'] becomes 0
We’ve found 1 required 'A' — perfect.

🧍Now r = 1 → s[1] = 'D'
'D' is not in t, so:

if (hash['D'] > 0) // FALSE — skipped
hash['D']--;       // hash['D'] becomes -1
So we decrease the count of 'D' even though it's not needed.

🟨 Why?
So that when we remove characters later (from the left using l), we can know:

If we are removing a character we didn’t care about (hash[c] becomes 0 or still < 0), don’t decrease cnt

If we remove a required character (hash[c] becomes > 0), we must decrease cnt
*/