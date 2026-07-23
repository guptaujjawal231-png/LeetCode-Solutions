class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        freq = {}

     
        for ch in s:
            if ch in freq:
                freq[ch] += 1
            else:
                freq[ch] = 1

        for ch in t:
            if ch not in freq:
                return ch

            freq[ch] -= 1

            if freq[ch] < 0:
                return ch 
