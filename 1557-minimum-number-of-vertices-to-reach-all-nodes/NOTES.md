Intuition :- Add all the vertices that has indegree 0 to answer array, because those vertices won't be reached from any other vertices and we'll have to make a dfs call for them to reach them.
​
- Time Complexity = O(max(V,E))
- Space Complexity = O(V), for storing the indegree