class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans = []

        def f(node, path):
           
            if node == len(graph) - 1:
                ans.append(path[:])     
            else:
                for k in graph[node]:
                    f(k, path+[k])

             

        f(0, [0])         
        return ans    
        