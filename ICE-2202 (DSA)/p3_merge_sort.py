def merge_sort(arr):
    # Base case: if the array has more than one element
    if len(arr) > 1:
        # Finding the middle of the array
        mid = len(arr) // 2

        # Dividing the array into two halves
        left_half = arr[:mid]  # Left subarray
        right_half = arr[mid:]  # Right subarray

        # Recursively sorting the left and right halves
        merge_sort(left_half)
        merge_sort(right_half)

        # Initializing pointers for the left half (i), right half (j), and merged array (k)
        i = j = k = 0

        # Merging the two sorted halves into the original array
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:  # If element in left is smaller
                arr[k] = left_half[i]
                i += 1
            else:  # If element in right is smaller or equal
                arr[k] = right_half[j]
                j += 1
            k += 1  # Move to the next position in the merged array

        # If any elements are left in the left half, add them to the merged array
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        # If any elements are left in the right half, add them to the merged array
        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

    return arr  # Return the sorted array


# Taking input as a space-separated string
arr = list(
    map(int, input("Enter the elements of the array separated by space: ").split())
)
print("Sorted Array:", merge_sort(arr))
