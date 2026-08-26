class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {

                int ones = 0;

                for (int x = i; x <= j; x++) {
                    if (s[x] == '1')
                        ones++;
                }
                if (ones == k) {
                    string curr = s.substr(i, j - i + 1);

                    if (ans == "" ||
                        curr.size() < ans.size() ||
                        (curr.size() == ans.size() && curr < ans)) {
                        ans = curr;
                    }
                }
            }
        }
        return ans;
    }
};