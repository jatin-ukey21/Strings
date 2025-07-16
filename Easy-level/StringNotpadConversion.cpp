#include<bits/stdc++.h>
using namespace std;

string printSequence(string S)
{
    // Mapping of each character A-Z to its corresponding sequence on a mobile keypad
    // For example: A -> 2, B -> 22, C -> 222, ..., Z -> 9999
    string keypad[] = {
        "2","22","222",       // A, B, C
        "3","33","333",       // D, E, F
        "4","44","444",       // G, H, I
        "5","55","555",       // J, K, L
        "6","66","666",       // M, N, O
        "7","77","777","7777",// P, Q, R, S
        "8","88","888",       // T, U, V
        "9","99","999","9999" // W, X, Y, Z
    };

    string ans = ""; // Stores the final numeric sequence

    // Traverse each character in the input string
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == ' ')
        {
            // For space character, use 0 as per traditional mobile keypad
            ans += '0';
        }
        else
        {
            // For alphabets, subtract 'A' to get the index (0 to 25) for keypad[]
            // Example: 'C' - 'A' = 2, so keypad[2] = "222"
            ans += keypad[S[i] - 'A'];
        }
    }

    // Return the final numeric string sequence
    return ans;
}

