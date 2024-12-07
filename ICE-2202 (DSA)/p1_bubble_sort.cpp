#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
     for (auto it : v)
          cout << it << " ";
     cout << '\n';
}
void printPass(vector<int> &v, int pass)
{
     cout << "\nPass " << pass + 1 << ": " << '\n';
     for (auto it : v)
          cout << it << " ";
     cout << '\n';
}
void bubbleSort(vector<int> &v, int n)
{
     for (int i = 0; i < n - 1; i++)
     {
          printPass(v, i);
          for (int j = 0; j < n - i - 1; j++)
          {
               print(v);
               if (v[j] > v[j + 1])
               {
                    int temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                    cout << "Swapped: YES" << endl;
               }
               else
                    cout << "Swapped: NO" << endl;
               print(v);
          }
     }
}
int main()
{
     ios::sync_with_stdio(false);
     cin.tie(nullptr);

     int n;
     cin >> n;
     vector<int> v(n);
     for (int i = 0; i < n; i++)
     {
          cin >> v[i];
     }
     bubbleSort(v, n);
     cout<<"Final Array: ";
     print(v);

     return 0;
}
