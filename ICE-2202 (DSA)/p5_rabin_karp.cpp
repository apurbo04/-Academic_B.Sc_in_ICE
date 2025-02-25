#include <iostream>
using namespace std;

#define d 256   // Number of characters in the input alphabet
#define q 101   // A prime number for hashing

// Rabin-Karp pattern searching function
void RabinKarpSearch(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();
    int p = 0;   // Hash value for pattern
    int t = 0;   // Hash value for text window
    int h = 1;   // Value of d^(m-1) used in rolling hash

    // Precompute h = d^(m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values for pattern and first text window
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over the text
    for (int i = 0; i <= n - m; i++)
    {
        // If hash values match, check characters one by one
        if (p == t)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for the next window in text
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // If hash becomes negative, convert it to positive
            if (t < 0)
                t += q;
        }
    }
}

int main()
{
    string text = "ababcabcabababd";
    string pattern = "abab";

    RabinKarpSearch(text, pattern);

    return 0;
}
