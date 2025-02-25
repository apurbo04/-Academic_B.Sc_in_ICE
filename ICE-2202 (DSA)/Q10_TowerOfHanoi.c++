#include <iostream>
using namespace std;

int steps = 0; // Global variable to count steps

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    // Base case: Move the last (smallest) disk directly
    if (n == 1)
    {
        cout << "Move disk 1 from " << from_rod << " to " << to_rod << endl;
        steps++; // Increment step counter
        return;
    }
    // Step 1: Move top n-1 disks from 'from_rod' to 'aux_rod' using 'to_rod' as auxiliary
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    // Step 2: Move the nth disk directly from 'from_rod' to 'to_rod'
    cout << "Move disk " << n << " from " << from_rod << " to " << to_rod << endl;
    steps++; // Increment step counter
    // Step 3: Move the n-1 disks from 'aux_rod' to 'to_rod' using 'from_rod' as auxiliary
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    // Call Tower of Hanoi function (A = source, C = destination, B = auxiliary)
    towerOfHanoi(n, 'A', 'C', 'B');

    // Print total steps taken
    cout << "Total steps required: " << steps << endl;
    return 0;
}
