### __Find first Duplicate__
[Problem Link](https://leetcode.com/problems/find-the-duplicate-number/)

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
![image](https://user-images.githubusercontent.com/51910127/132913135-7f82bec2-0b5b-4893-a9de-d2f266f5f368.png)
![image](https://user-images.githubusercontent.com/51910127/132913189-e9c32a18-a724-48b5-b0e8-fe04420f58bc.png)

### hash solution (not good)
```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> u;
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(u[nums[i]]==0) u[nums[i]]++;
            else
                return nums[i];
            
            
        }
        return -1;
    }
};
```
### 2ns soln- o(nlogn) binary serach based

This solution is based on binary search.

At first the search space is numbers between 1 to n. Each time I select a number mid (which is the one in the middle) and count all the numbers equal to or less than mid. Then if the count is more than mid, the search space will be [1 mid] otherwise [mid+1 n]. I do this until search space is only one number.

Let's say n=10 and I select mid=5. Then I count all the numbers in the array which are less than equal mid. If the there are more than 5 numbers that are less than 5, then by Pigeonhole Principle (https://en.wikipedia.org/wiki/Pigeonhole_principle) one of them has occurred more than once. So I shrink the search space from [1 10] to [1 5]. Otherwise the duplicate number is in the second half so for the next step the search space would be [6 10].

```py
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        low = 1
        high = len(nums)-1
        
        while low < high:
            mid = low+(high-low)/2
            count = 0
            for i in nums:
                if i <= mid:
                    count+=1
            if count <= mid:
                low = mid+1
            else:
                high = mid
        return low
```

### __3rd solution :

If there is no duplicate in the array, we can map each indexes to each numbers in this array. In other words, we can have a mapping function f(index) = number
For example, let's assume
nums = [2,1,3], then the mapping function is 0->2, 1->1, 2->3.
If we start from index = 0, we can get a value according to this mapping function, and then we use this value as a new index and, again, we can get the other new value according to this new index. We repeat this process until the index exceeds the array. Actually, by doing so, we can get a sequence. Using the above example again, the sequence we get is 0->2->3. (Because index=3 exceeds the array's size, the sequence terminates!)

However, if there is duplicate in the array, the mapping function is many-to-one.
For example, let's assume
nums = [2,1,3,1], then the mapping function is 0->2, {1,3}->1, 2->3. Then the sequence we get definitely has a cycle. 0->2->3->1->1->1->1->1->........ The starting point of this cycle is the duplicate number.
We can use Floyd's Tortoise and Hare Algorithm to find the starting point.

According to Floyd's algorithm, first step, if a cycle does exist, and you advance the tortoise one node each unit of time but the hare two nodes each unit of time, then they will eventually meet. This is what the first while loop does. The first while loop finds their meeting point.

*Second step, take tortoise or hare to the start point of the list (i.e. let one of the animal be 0) and keep the other one staying at the meeting point. Now, advance both of the animals one node each unit of time, the meeting point is the starting point of the cycle. This is what the second while loop does. The second while loop finds their meeting point.

*Proof of second step:

Distance traveled by tortoise while meeting = x + y

Distance traveled by hare while meeting = (x + y + z) + y = x + 2y + z

Since hare travels with double the speed of tortoise,

so 2(x+y)= x+2y+z => x+2y+z = 2x+2y => x=z

Hence by moving tortoise to start of linked list, and making both animals to move one node at a time, they both have same distance to cover .

They will reach at the point where the loop starts in the linked list

- There could be multiple cycles in our 'graph'. But the beauty of this problem is that nums[0] is always the entrance to the cycle which has duplicate numbers, because no one can jump back to nums[0]. See the example below. index = [0 1 2 3 4 5 6 7]; nums=[5 2 1 3 5 7 6 4]. nums[1] and nums[2] forms an isolated cycle. nums[3]=3 forms an isolated cycle. nums[6]=6 forms an isolated cycle. nums[5] nums[7] nums[4] forms a cycle and nums[0]=5 is an entrance to the cycle.

- To understand this solution, you just need to ask yourself these question.
Assume the distance from head to the start of the loop is x1
the distance from the start of the loop to the point fast and slow meet is x2
the distance from the point fast and slow meet to the start of the loop is x3

What is the distance fast moved? 2. What is the distance slow moved? 3. And their relationship? \
x1 + x2 + x3 + x2 \
x1 + x2 \
x1 + x2 + x3 + x2 = 2 (x1 + x2) \
Thus x1 = x3, that's the reason we reset fast to be 0. \

Finally got the idea.

![image](https://user-images.githubusercontent.com/51910127/132949548-696c17b0-3790-446d-b741-9f5e89197a88.png)
