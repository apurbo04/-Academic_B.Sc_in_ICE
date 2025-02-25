def solve_n_queens(n):
    # Helper function to check if placing a queen at (row, col) is safe
    def is_safe(row, col, board):
        # Check all previous rows
        for i in range(row):
            # Check if the queen is in the same column or diagonal
            if (board[i] == col or board[i] - i == col - row or board[i] + i == col + row):
                return False  # Unsafe if in the same column or diagonal
        return True  # Safe if no conflicts

    # Recursive function to solve the N-Queens problem
    def solve(row, board, solutions):
        # If all queens are placed, save the current solution
        if row == n:
            solutions.append(board[:])  # Store a copy of the current solution
            return

        # Try to place a queen in each column of the current row
        for col in range(n):
            if is_safe(row, col, board):  # Check if placing the queen is safe
                board[row] = col  # Place the queen in the current row and column
                solve(row + 1, board, solutions)  # Move to the next row
                board[row] = -1  # Backtrack: remove the queen

    # Initialize the list to store all valid solutions
    solutions = []
    # Initialize the board with -1 (indicating no queen placed)
    board = [-1] * n
    # Start solving from the first row
    solve(0, board, solutions)
    return solutions

# Example usage of the solve_n_queens function
n = 8  # The size of the board (5x5 grid)
solutions = solve_n_queens(n)  # Get all solutions for placing 5 queens

# Print the number of solutions
print(f"Number of solutions for {n}-Queens: {len(solutions)}")

# Print each solution
for solution in solutions:
    print("Solution vector:", solution)
