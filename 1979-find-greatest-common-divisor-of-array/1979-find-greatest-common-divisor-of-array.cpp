class Solution {
public:
    int findGCD(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        for(int i=1;i<=nums[0];i++){
            if(nums[0]%i==0&&nums[n]%i==0){
                ans=i;
            }
           
        }
    
        return ans;
    }
};