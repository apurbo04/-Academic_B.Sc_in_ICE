def sum_of_subsets(S, target, subset=[], index=0):
    # Base Case: If the sum of subset equals target, print it
    if sum(subset) == target:
        print("Subset found:", subset)
        return

    # If sum exceeds target or all elements are considered, return
    if sum(subset) > target or index == len(S):
        return

    # Include the current element and recurse
    sum_of_subsets(S, target, subset + [S[index]], index + 1)

    # Exclude the current element and recurse
    sum_of_subsets(S, target, subset, index + 1)

# Example Input
S = [5, 10, 12, 13, 15, 18]
target_sum = 30

print("Subsets with sum", target_sum, "are:")
sum_of_subsets(S, target_sum)
