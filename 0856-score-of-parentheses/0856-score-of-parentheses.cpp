class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int count = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                count++;
            }
            else {
                count--;

                // Found "()"
                if (s[i - 1] == '(') {
                    score += (1 << count);  // 2^count
                }
            }
        }

        return score;
    }
};