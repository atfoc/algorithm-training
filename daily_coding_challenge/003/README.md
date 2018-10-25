# Problem 3

*29.09.2018*

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string,
and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

```python
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
```

The following test should pass:

```python
node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
```

# Solution 1: Array representation

Let's say our tree looks like this

![image of bst]()

Then array representation will look like this:

`5, 4, 7, X, X, 6, 8`

Where if we have node at index i(0-based indexing) then its children are at
`2*i+1` and `2*1+2`. We will use this to serialize and deserialize bst.