class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Count characters of s
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Try changing target from right to left
        for (int i = n - 1; i >= 0; i--) {

            // We need characters used by target[0...i-1]
            vector<int> temp = cnt;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                temp[x]--;

                if (temp[x] < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible)
                continue;

            // Find smallest character > target[i]
            int cur = target[i] - 'a';
            int bigger = -1;

            for (int c = cur + 1; c < 26; c++) {
                if (temp[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger == -1)
                continue;

            // Put the bigger character
            string ans = target.substr(0, i);
            ans += char('a' + bigger);

            temp[bigger]--;

            // Put remaining characters in sorted order
            for (int c = 0; c < 26; c++) {
                while (temp[c] > 0) {
                    ans += char('a' + c);
                    temp[c]--;
                }
            }

            return ans;
        }

        return "";
    }
};