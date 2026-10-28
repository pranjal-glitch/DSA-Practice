#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int best[10][2];

        // Initialize with -1
        for (int i = 0; i < 10; i++) {
            best[i][0] = -1;
            best[i][1] = -1;
        }

        int ans = -1;

        // Traverse all numbers
        for (int num : nums) {
            int maxDigit = getMaxDigit(num);

            if (num > best[maxDigit][0]) {
                best[maxDigit][1] = best[maxDigit][0];
                best[maxDigit][0] = num;
            } 
            else if (num > best[maxDigit][1]) {
                best[maxDigit][1] = num;
            }
        }

        // Find maximum pair sum
        for (int i = 0; i < 10; i++) {
            if (best[i][1] != -1) {
                ans = max(ans, best[i][0] + best[i][1]);
            }
        }

        return ans;
    }

private:
    int getMaxDigit(int num) {
        int maxDigit = 0;
        while (num > 0) {
            maxDigit = max(maxDigit, num % 10);
            num /= 10;
        }
        return maxDigit;
    }
};