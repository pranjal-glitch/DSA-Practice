class Solution {
public:
    int start = 0;
    int maxLen = 1;

    void expand(string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {

            int currentLen = right - left + 1;

            if (currentLen > maxLen) {
                maxLen = currentLen;
                start = left;
            }

            left--;
            right++;
        }
    }
    string longestPalindrome(string s) {
        int n = s.length();

        if (n <= 1)
            return s;

        start = 0;
        maxLen = 1;

        for (int i = 0; i < n; i++) {

            // Odd length palindrome
            expand(s, i, i);

            // Even length palindrome
            expand(s, i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};
