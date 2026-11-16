## Aim

To solve the Tower of Hanoi puzzle for n disks using recursion and print every move.

## Test Case

```
number of disks = 3
```

## Expected Output

```
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
```

## Complexity

- Time: O(2ⁿ), as 2ⁿ - 1 moves are made
- Space: O(n) auxiliary space (recursion stack)