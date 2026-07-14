class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans = []

        def f(node, path):
            path.append(node)

            if node == len(graph) - 1:
                ans.append(path[:])     
            else:
                for nei in graph[node]:
                    f(nei, path)

            path.pop()   

        f(0, [])         
        return ans    
        