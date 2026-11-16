## Aim

To implement a self-balancing AVL tree with insertion, deletion, searching and tree traversals using rotations.

## Test Case

```
insert = 10 20 30 40 50 25
traversals = Inorder, Preorder
search = 25
delete = 40, then Inorder and Preorder
```

## Expected Output

```
Inorder: 10 20 25 30 40 50
Preorder: 30 20 10 25 40 50
Value found.
Deletion completed.
Inorder: 10 20 25 30 50
Preorder: 30 20 10 25 50
```

## Complexity

- Time: O(log n) per insert, delete and search; O(n) per traversal
- Space: O(n) to store the tree (O(log n) recursion stack)