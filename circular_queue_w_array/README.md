## Aim

To implement a circular queue using an array and show how the rear index wraps around.

## Test Case

```
enqueue(10), enqueue(20), enqueue(30), enqueue(40)
display()
dequeue(), dequeue()
enqueue(50), enqueue(60)
display()
```

## Expected Output

```
10 20 30 40
Removed: 10
Removed: 20
After wrap-around: 30 40 50 60
```

## Complexity

- Time: O(1) for enqueue and dequeue, O(n) for display
- Space: O(1) auxiliary space (fixed array of capacity 5)