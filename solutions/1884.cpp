#include <cmath>

class Solution {
    double successiveSumLessThan(int targetSum) {
        // n(n + 1) / 2 = targetSum
        // n^2 + n - targetSum * 2 = 0
        // (- 1 + sqrt(1 + targetSum * 8)) / 2
        return (-1 + sqrt(1 + targetSum * 8)) / 2;
    }
public:
    int twoEggDrop(int n) {
        auto dropGap = successiveSumLessThan(n);
        return dropGap == int(dropGap) ? dropGap : dropGap + 1;
    }
};