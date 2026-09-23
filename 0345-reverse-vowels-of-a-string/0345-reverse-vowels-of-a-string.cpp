class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;

        string vowels = "aeiouAEIOU";

        while (left < right) {

            // Move left until it finds a vowel
            while (left < right && vowels.find(s[left]) == string::npos)
                left++;

            // Move right until it finds a vowel
            while (left < right && vowels.find(s[right]) == string::npos)
                right--;

            // Swap the vowels
            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};