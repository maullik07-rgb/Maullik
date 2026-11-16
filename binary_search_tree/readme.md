## Aim

To implement a binary search tree with insertion, searching, deletion and inorder, preorder and postorder traversals.

## Test Case

```
insert = 50 30 70 20 40 60 80
search = 40
delete = 30
```

## Expected Output

```
Inorder: 20 30 40 50 60 70 80
Preorder: 50 30 20 40 70 60 80
Postorder: 20 40 30 60 80 70 50

Searching for 40: Found
Inorder after deleting 30: 20 40 50 60 70 80
```

## Complexity

- Time: O(h) per insert, search and delete; O(n) per traversal (h = O(log n) average, O(n) worst case)
- Space: O(n) to store the tree (O(h) recursion stack)