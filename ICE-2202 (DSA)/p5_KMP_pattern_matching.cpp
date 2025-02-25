
// KMP (Knuth-Morris-Pratt)  => O(M+N)

#include <iostream>
#include <vector>
using namespace std;

// Function to compute the Longest Prefix Suffix (LPS) array
void computeLPSArray(const string &pattern, vector<int> &lps)
{
    int m = pattern.length();
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0;  // lps[0] is always 0
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1]; // Reduce length to previous lps value
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to perform KMP pattern searching
void KMPSearch(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    // Create the LPS array
    vector<int> lps(m);
    computeLPSArray(pattern, lps);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; // Move to previous LPS position
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1]; // Move j to previous LPS value
            else
                i++; // Move to the next character in text
        }
    }
}

int main()
{
    string text = "ababcababcabcab";
    string pattern = "abcab";

    KMPSearch(text, pattern);

    return 0;
}
