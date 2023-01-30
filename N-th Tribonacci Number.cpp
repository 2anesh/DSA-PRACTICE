class Solution {
public:
    int tribonacci(int n) {
        // If n is equal to 0, the function returns 0
        if (n == 0) return 0;
        // If n is equal to 1 or 2, the function returns 1
        if (n == 1 || n == 2) return 1;

        // Variables a, b, c and d are declared and initialized with 0, 1, 1 respectively
        int a = 0, b = 1, c = 1, d;
        // A for loop is used to loop from 3 to n
        for (int i = 3; i <= n; i++) {
            // The value of d is calculated as the sum of a, b, and c
            d = a + b + c;
            // The value of a is updated to b
            a = b;
            // The value of b is updated to c
            b = c;
            // The value of c is updated to d
            c = d;
        }
        // The function returns the value of c
        return c;
    }
};
