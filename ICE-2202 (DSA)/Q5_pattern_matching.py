# Function to find the starting index of a substring (case) in a given string (text)
def pattern(text, case):
    n, m = len(text), len(case)  # Get the lengths of the text and the case (pattern)

    # Loop through the text to check for a match
    for i in range(n - m + 1):  # Ensure we don't go out of bounds
        if text[i : i + m] == case:  # Check if substring matches the case
            return i  # Return the starting index of the match

    return -1  # Return -1 if no match is found


# Example usage
text = "this is a simple example"
case = "simple"

# Print the index where the pattern is found
result = pattern(text, case)

if result == -1:
    print("not found")
else:
    print("Pattern found at index :", pattern(text, case))
