class Solution {
public:
    bool recur(vector<int>& nums,int player1,int player2,int x,int i,int j){
        if(i>j){
            return player1>=player2;
        }
        if(x%2==0){
            bool first=recur(nums,player1,player2+nums[i],x+1,i+1,j);
            bool last=recur(nums,player1,player2+nums[j],x+1,i,j-1);
            return first && last;
        }else{
            bool first=recur(nums,player1+nums[i],player2,x+1,i+1,j);
            bool last=recur(nums,player1+nums[j],player2,x+1,i,j-1);
            return first||last;
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        return recur(nums,0,0,1,0,n-1);
    }
};