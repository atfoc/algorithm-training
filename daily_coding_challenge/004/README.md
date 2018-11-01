# Problem 4

*30.09.2018*

Given an array of integers, find the first missing positive integer in linear time and constant
space. In other words, find the lowest positive integer that does not exist in the array. The array
can contain duplicates and negative numbers as well.

For example, the input `[3, 4, -1, 1]` should give 2. The input `[1, 2, 0]` should give 3.

You can modify the input array in-place.

# Solution 1:Naive solution
### Complexity
+ Time O(![$n^2$]())
+ Memory O(1)

Try to find number 1, if you fail that is the solution, if you succeed then try to find number 2
and so on util you fail.

# Solution 2: Little bit smarter
### Complexity
+ Time O(n*log(n))
+ Memory O(1)

Sort array and then find first missing positive number

# Solution: Even more smart

### Complexity
+ Time O(n)
+ Memory O(1)

First take all negative numbers and move them to beginning of the array. Next start from first
positive number. Now we will look at only positive part of the array and act like that is the whole
array. So now at position 0 we have first positive number.
Go through array and for each positive number lets say `a` go to position `a-1` if it exists in
current array and make number at that position negative. If in this process you come across a
negative number(number that was positive but turned negative with this process) just take his
absolute value. After this process is done go and find first number that is not negative. Lets say
that number is at index `i` then the solution to the problem is `i+1`.

0. `3, 1, 5, -2, 2, 7`
1. `-2, 1, 5, 3, 2, 7`
2. `1, 5, 3, 2, 7`
3. `-1, 5, 3, 2, 7`
4. `-1, 5, 3, 2, -7`
5. `-1, 5, -3, 2, -7`
6. `-1, -5, -3, 2, -7`
7. `-1, -5, -3, 2, -7`
8. 2 is fist postive and its index is 3 so the solution is 4
