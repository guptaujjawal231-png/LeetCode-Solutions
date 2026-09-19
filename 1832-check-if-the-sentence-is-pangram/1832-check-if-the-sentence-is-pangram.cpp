class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>alpha(26,false);
        for(int i=0;i<sentence.size();i++){
            alpha[sentence[i]-'a']=true;
        }
        for(int i=0;i<26;i++){
            if(alpha[i]==0){
                return false;
            }
        }
        return true;
    }
};