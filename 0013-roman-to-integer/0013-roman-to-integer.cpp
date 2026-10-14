class Solution {
public:
    int romanToInt(string s) {
        auto getVal = [](char c){
            switch(c){
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default : return 0;
            }
        };
        int total = 0;

        for(int i = 0; i < s.size(); i++) {
            int curr = getVal(s[i]);
            int next = (i + 1 < s.size()) ? getVal(s[i + 1]) : 0;

            if(curr < next)
                total -= curr;
            else
                total += curr;
        }

        return total;
    }
};