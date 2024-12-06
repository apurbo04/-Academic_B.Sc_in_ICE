#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n;
     cin >> n;
     vector<int> arr(n);
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }
     int target;
     cin >> target;
     bool flag = 0;
     for (int i = 0; i < n; i++)
     {
          if (arr[i] == target)
          {
               cout << "Posision: " << i + 1 << endl;
               flag = 1;
          }
     }
     if (flag == 0)
          cout << "Not Found" << endl;
     return 0;
}