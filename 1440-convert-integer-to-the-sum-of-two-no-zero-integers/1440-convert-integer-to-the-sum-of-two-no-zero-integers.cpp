class Solution {
public:
    // Helper function to check if any digit in a number is zero
    bool hasZero(int num) {
        // We can't have a zero, so the number must be positive.
        if (num == 0) return true; 

        while (num > 0) {
            // If the last digit is 0, return true immediately.
            if (num % 10 == 0) {
                return true;
            }
            // Remove the last digit by integer division.
            num /= 10;
        }
        // If the loop finishes, no zeros were found.
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        
        for (int A = 1; A < n; ++A) {
            int B = n - A;

            // Use the helper function to check ALL digits of both A and B.
            if (!hasZero(A) && !hasZero(B)) {
                return {A, B};
            }
        }
        return {};
    }
};