#include <vector>
#include <unordered_map>

class Solution {
public:
    int findPairs(std::vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int count = 0;
        
        for (auto& [num, count_freq] : freq) {
            if (k == 0) {
                
                if (count_freq > 1) {
                    count++;
                }
            } else {

                if (freq.count(num + k)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};