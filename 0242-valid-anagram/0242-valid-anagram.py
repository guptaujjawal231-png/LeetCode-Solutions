class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        freq={}
        for k in s:
            if k in freq:
                freq[k]=freq[k]+1
            else:
                freq[k]=1
        for k in t:
            if k  not in freq:
                return False
            
            freq[k]=freq[k]-1  
            if freq[k]<0:
                return False
        return True                  
     

        