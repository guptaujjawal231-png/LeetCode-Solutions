class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m = len(word1)
        n = len(word2)

        memo = {}

        def f(i, j):
            if i == m:
                return n - j

            if j == n:
                return m - i

            if (i, j) in memo:
                return memo[(i, j)]

            if word1[i] == word2[j]:
                memo[(i, j)] = f(i + 1, j + 1)
            else:
                memo[(i, j)] = 1 + min(
                    f(i, j + 1),      # Insert
                    f(i + 1, j),      # Delete
                    f(i + 1, j + 1)   # Replace
                )

            return memo[(i, j)]

        return f(0, 0)           
        