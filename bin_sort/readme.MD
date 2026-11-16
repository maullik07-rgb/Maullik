## Aim

To sort an array of non-negative integers in ascending order using bin sort, where each bin is a linked list.

## Test Case

```
array = 4 2 7 2 3 5 0 6
```

## Expected Output

```
sorted array -
0
2
2
3
4
5
6
7
```

## Complexity

- Time: O(n + k) average, O(n²) worst case (when many elements fall in the same bin), where k = largest value
- Space: O(n + k) auxiliary space (bins and linked list nodes)