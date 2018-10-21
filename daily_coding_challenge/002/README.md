# Problem 2

*28.09.2018*

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?


# Solution 1

## Naive solution

### Complexity
+ Time: O(![$n^2$]())
+ Memory: O(1)

Solution is simple just loop over array and multiply all numbers except the 
number at the current position.

# Solution 2

## Lets be smart

### Complexity
+ Time: O(n)
+ Memory: O(1)
  
Idea is simple if we have array of element `A = [a,b,c,d]`. We can say
`accum  = a * b * c * d` so that then the array that we are looking for is
`result = [accum/a, accum/b, accum/c, accum/d]`. This apples for larger
dimensions easily


## Discussion
For follow up we can't use division so we can't use solution 2. I don't have
any smart ideas now about how to solve that except solution 1.