Intuition :-
1. Maintain a color vector ,initially all elements as -1. //it will keep track of the colors of all adjacent nodes.
2. If a node isn't colored ,then make dfs call & set its color to 1.
3. Now check if its adjacent node isn't colored, then color it as 1-col[start] ,i.e. 1-color of its adjacent node.
4. If its adjacent node is already colored then,check if color of both the nodes are same ,then return false .
5. else return true.
​
TC=O(N+E)
SC=O(N)
​
​
4
[[1,2],[1,3],[2,4]]
3
[[1,2],[1,3],[2,3]]
10
[[4,7],[4,8],[5,6],[1,6],[3,7],[2,5],[5,8],[1,2],[4,9],[6,10],[8,10],[3,6],[2,10],[9,10],[3,9],[2,3],[1,9],[4,6],[5,7],[3,8],[1,8],[1,7],[2,4]]
​