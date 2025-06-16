#include <iostream> // For input/output operations
#include <vector>   // For std::vector
#include <numeric>  // For std::iota (to initialize the vector efficiently)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large inputs.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N; // Length of the sequence
    int Q; // Number of queries
    std::cin >> N >> Q;

    std::vector<int> A(N); // The underlying vector to store the sequence elements
    // Initialize A: A[i] = i+1. std::iota fills the range [first, last)
    // with sequentially increasing values, starting with value.
    std::iota(A.begin(), A.end(), 1);

    long long current_offset = 0; // Represents the logical start of the sequence.
                                  // Use long long because k can be large,
                                  // potentially causing overflow with int.

    for (int q = 0; q < Q; ++q) {
        int type; // Type of query (1, 2, or 3)
        std::cin >> type;

        if (type == 1) {
            int p; // Logical position to update (1-indexed)
            int x; // New value
            std::cin >> p >> x;
            // Calculate the physical index in the underlying vector:
            // (current_offset + (p - 1)) ensures we map the logical p to
            // its correct position considering the rotation.
            // % N ensures we wrap around the vector bounds correctly.
            long long physical_idx = (current_offset + (p - 1)) % N;
            A[physical_idx] = x; // Perform the update
        } else if (type == 2) {
            int p; // Logical position to query (1-indexed)
            std::cin >> p;
            // Calculate the physical index, same logic as Type 1
            long long physical_idx = (current_offset + (p - 1)) % N;
            // Output the value at the calculated physical index, followed by a newline
            std::cout << A[physical_idx] << "\n";
        } else { // type == 3
            long long k; // Number of rotations
            std::cin >> k;
            // Update the offset: each rotation effectively moves the logical start.
            // (current_offset + k) could be very large, so ensure it's calculated
            // using long long before taking modulo N.
            current_offset = (current_offset + k) % N;
        }
    }

    return 0; // Program finished successfully
}