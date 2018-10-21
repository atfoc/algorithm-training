# Problem 1

*27.09.2018*

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

# Solution 1

## Naive solution

### Complexity
+ Time: O($n^2$)
+ Memory: O(1)


First possible solution is naive solution. We can solve problem by taking
each pair $a,b \in A$ where A is given array and check if there sum gives
number k. We can optimize this a little by doing something like this
$\forall i, j | i < j$ check $A_i + A_j = k$ but this is also O($n^2$)
complexity.

# Solution 2

## Lets be smart

### Complexity
+ Time: O(n)
+ Memory: O(n)

We can approach problem differently instead of checking all pairs we can look
at problem like this. If a + b = k then k - a = b. This means if we subtract 
ith element of the array from k then we can check if result is in rest of the
array. $k - A_i \in A?$. This still is O($n^2$) complexity but we can notice
that our problem is symmetrical and if there are a and b in array that give 
sum of k, then k - a and k - b will be in array. This means that we can keep
elements we encountered in past in hash table (unordered set in c++). So
when we discusses $A_i$ element we can check if $k - A_i$ is in hash table 
we can do this in O(1) and if it is that means we found two number that give
sum of k and if it is not in hash table then we continue our search but
first we add $A_i$ to hash table. 