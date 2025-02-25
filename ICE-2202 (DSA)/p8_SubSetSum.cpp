#include <bits/stdc++.h>
using namespace std;

// Function to find subsets with the given target sum
void sum_of_subsets(vector<int> &S, int target, vector<int> subset, int index)
{
   // Base Case: If the sum of subset equals target, print it
   int sum = 0;
   for (int num : subset)
      sum += num;

   if (sum == target)
   {
      cout << "Subset found: ";
      for (int num : subset)
         cout << num << " ";
      cout << endl;
      return;
   }

   // If sum exceeds target or all elements are considered, return
   if (sum > target || index == S.size())
      return;

   // Include the current element and recurse
   subset.push_back(S[index]);
   sum_of_subsets(S, target, subset, index + 1);

   // Exclude the current element and recurse
   subset.pop_back();
   sum_of_subsets(S, target, subset, index + 1);
}

int main()
{
   vector<int> S = {5, 10, 12, 13, 15, 18};
   int target_sum = 30;

   cout << "Subsets with sum " << target_sum << " are:" << endl;
   sum_of_subsets(S, target_sum, {}, 0);

   return 0;
}
