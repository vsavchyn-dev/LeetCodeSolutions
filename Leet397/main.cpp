#include <iosream>
#include <math.h>

class Solution {
public:
    int integerReplacement(int n) {
        int noOfOperations = 0;

        if (n == INT_MAX) {
            n = n - 1;
        }

        while (n > 1) {
            if (n % 2 == 0) {
                n = n / 2;
            }
            else if ((n + 1) % 4 == 0 && (n - 1) != 2) {
                n = n + 1;
            }
            else {
                n = n - 1;
            }
            cntr++;
        }
        return noOfOperations;
    }
};
