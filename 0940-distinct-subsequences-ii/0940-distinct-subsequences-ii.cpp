class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
       
        vector<long long> last(26, 0);

        for (char ch : s) {
            int idx = ch - 'a';
           
            long long current_total = 1;
            for (int i = 0; i < 26; ++i) {
                current_total = (current_total + last[i]) % MOD;
            }
            
            last[idx] = current_total;
        }

        long long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + last[i]) % MOD;
        }

        return ans;
    }
};