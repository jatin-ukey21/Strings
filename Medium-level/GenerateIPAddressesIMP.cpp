#include<bits/stdc++.h>
using namespace std;
//💡💡💡💡💡💡💡💡💡💡💡💡💡💡💡MUST CHECK THIS (HARD LEVEL)
/*    PROBLEM DESCRIPTION
Given a string s containing only digits, your task is to restore it by returning all possible valid IP address combinations.
 You can return your answer in any order.

A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255(inclusive).

Note: The numbers cannot be 0 prefixed unless they are 0. For example, 1.1.2.11 and 0.11.21.1 are valid IP
 addresses while 01.1.2.11 and 00.11.21.1 are not.
*/
/*complete the Function*/

class Solution {
    public:
    void solve(int ind,int segmentNumber,string currentIP,string &s,vector<string>& res){
        if(segmentNumber == 4){
            if(ind == s.size()){
                res.push_back(currentIP);
            }
            return;
        }
        
        //try segments from 1 to 3
        for(int len = 1; len <= 3 && ind + len <= s.size(); len++){
            string part = s.substr(ind,len);
            
            //skip invalid segments
            if(len > 1 && part[0] == '0') continue;
            if(stoi(part) > 255) continue;
            
            //build nextpart of IP
            string nextIp = currentIP.empty() ? part : currentIP + "." + part;
            
            //recurse
            solve(ind + len,segmentNumber + 1,nextIp,s,res);
        }
    }
    vector<string> generateIp(string s) {
        // code here
        vector<string> ans;
        solve(0,0,"",s,ans);
        return ans;
    }
};
/*
Absolutely, let me simplify it step-by-step for you so you really grasp why it's 3^4.

🎯 Goal:
We are trying to split the input string into exactly 4 segments (because an IP has 4 parts: A.B.C.D).

🤔 At each segment, what are your options?
From any position in the string:

You can choose 1 character Or 2 characters Or 3 characters
👉 So, you have up to 3 choices at each segment.

📐 Levels of Recursion
Each segment you form takes you one level deeper in recursion.

So:

At segment 1, you try 1/2/3 digits → 3 choices At segment 2, again try 1/2/3 → 3 choices At segment 3,
 same → 3 choices At segment 4, same → 3 choices
⏱ So total maximum recursive calls in worst case:

3 × 3 × 3 × 3 = 3^4 = 81
📊 Tree View (Conceptual)
Segment 1:   [1][2][3]
              / | \
Segment 2:  [1][2][3] ... and so on
                ...
Up to Segment 4
So it’s a recursion tree of height 4, with up to 3 branches at each level.

✅ Real Example
Take s = "25525511135"

At index 0, you can choose:

"2" → recurse

"25" → recurse

"255" → recurse

Each of those paths goes on to form next segment — same logic repeats.

🧠 So Why Only Up to 4 Levels?
Because once you've selected 4 valid segments, you stop. You never build more than 4 parts in an IP.

That’s why the maximum depth is 4 And at each level: 3 choices max

✅ Final Time Complexity:
3 choices per level 4 levels → 3^4 = 81 paths maximum So: O(3^4) = O(81) = O(1) in practical terms
It's a very limited, fixed-size decision tree — that’s why it’s fast even for 12-digit strings.

Let me know if you want me to draw a small recursion tree for clarity — I’d be happy to!
*/

