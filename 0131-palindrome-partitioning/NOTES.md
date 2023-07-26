Intuition :-
1. For a given string of length n we are having total n-1 possibilities , i.e. we can either nake a cut after 0-th index,1-st index,2-nd index,.......upto n-1 index.
2. Now, we'll make a cut only when our left part is a pallindrome.
3. After making a cut check if its left part is a palindrome or not, if its a pindrome then add it to current answer and update the start index as i+1 (where i is the index upto which we have considered as a valid palindrome).
4. Since we can have other possibilities too,therefore after making the recursive call backtrack by poping out the subtring entered in current answer.
5. If start >= s.size() , then this implies that we have proccessed one complete string hence we have got a valid combination so add it to answer and return.
​
Time complexity = O(exponential)
Space Complexity = O(N)