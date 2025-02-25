#include <iostream>
#include <vector>
using namespace std;

// Function to check if placing a queen at (row, col) is safe
bool is_safe(int row, int col, vector<int> &board)
{
   for (int i = 0; i < row; i++)
   {
      if (board[i] == col ||           // Same column
          board[i] - i == col - row || // Same main diagonal
          board[i] + i == col + row)
      { // Same anti-diagonal
         return false;
      }
   }
   return true;
}

// Recursive function to solve the N-Queens problem
void solve(int row, int n, vector<int> &board, vector<vector<int>> &solutions)
{
   if (row == n)
   {                              // If all queens are placed
      solutions.push_back(board); // Store the solution
      return;
   }

   for (int col = 0; col < n; col++)
   {
      if (is_safe(row, col, board))
      {                                       // Check if it's safe
         board[row] = col;                    // Place the queen
         solve(row + 1, n, board, solutions); // Move to the next row
         board[row] = -1;                     // Backtrack
      }
   }
}

// Function to solve N-Queens and return all solutions
vector<vector<int>> solve_n_queens(int n)
{
   vector<vector<int>> solutions; // Store all valid solutions
   vector<int> board(n, -1);      // Initialize board with -1 (no queen placed)
   solve(0, n, board, solutions); // Start solving from row 0
   return solutions;
}

// Function to print all solutions
void print_solutions(vector<vector<int>> &solutions, int n)
{
   cout << "Number of solutions for " << n << "-Queens: " << solutions.size() << endl;
   for (auto solution : solutions)
   {
      cout << "Solution vector: ";
      for (int col : solution)
      {
         cout << col << " ";
      }
      cout << endl;
   }
}

// Main function
int main()
{
   int n;
   cout << "Enter the number of queens: ";
   cin >> n;
   vector<vector<int>> solutions = solve_n_queens(n);
   print_solutions(solutions, n);
   return 0;
}
