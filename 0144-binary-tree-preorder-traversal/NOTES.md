**RECURSIVE APPROACH**
intuition :- in PREORDER traversal first process the root then the left child and after that the right child.
​
1. Time complexity = O(n)
Since we are processing all the n nodes.
​
2. Space Complexity = O(n)
since we are storing all the n elements in the resultant vector.
​
first add the root node to the resultant vector then move to its left sub-tree and now add the root of the left sub-tree and now again go to its left sub-tree and add its root to the resultant vector now again go to its left sub-tree , if its root is null then return and now move to the right sub-tree and add the root of the right sub-tree, and then go to its left sub-tree and add its root ,if root is NULL then return and go to the right sub-tree and do the same .
​
**ITERATIVE APPROACH**
Intuition:-
1. Take a stack and push the root in it.
2. Now untill the stack isn't empty pop the element and store it inside the resultant vector.
3. Since we want to process the left side before the right side ,therefore first push the right nodde in the stack and then push the left node.
​
Time Complexity= O(n) ,since we are iterating over all the n nodes
Space Complexity = O(n) ,the stack space
​