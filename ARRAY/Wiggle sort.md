### __Wiggle Sort 1__

- [Pepcoding question link](https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/arrays-and-strings/wiggle-sort-1/ojquestion)
- Can you solve it in TC=O(n), SC=O(1)

```md
1. Given an unsorted array 'arr'.
2. Reorder it in-place such that :  arr[0] <= arr[1] >= arr[2] <= arr[3] . . . .
3. Please sort the array in place and do not define additional arrays.
4. Allowed Time Complexity : O(n)
Input Format
Input: [3, 5, 2, 1, 6, 4]
Output Format
Output: [1, 6, 2, 5, 3, 4]
```

Solution 1: TC=nlogn, SC=O(1)
```cpp
#include<iostream>
#include<algorithm>
using namespace std;
 
// A utility method to swap two numbers.
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
// This function sorts arr[0..n-1] in wave form, i.e.,
// arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= arr[5]..
void sortInWave(int arr[], int n)
{
    // Sort the input array
    sort(arr, arr+n);
 
    // Swap adjacent elements
    for (int i=0; i<n-1; i += 2)
        swap(&arr[i], &arr[i+1]);
}
 //arr[0] <= arr[1] >= arr[2] <= arr[3] . . . .
 void sortInWave(int arr[], int n)
{
    // Sort the input array
    sort(arr, arr+n);
   arr.reverse();
 
    // Swap adjacent elements
    for (int i=0; i<n-1; i += 2)
        swap(&arr[i], &arr[i+1]);
}
 
// Driver program to test above function
int main()
{
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortInWave(arr, n);
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}
```
### __Solution 2: TC=O(n), SC=O(1)__

```cpp
// arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= arr[5]..
void sortInWave(int arr[], int n)
{
    // Traverse all even elements
    for (int i = 0; i < n; i+=2)
    {
        // If current even element is smaller than previous
        if (i>0 && arr[i-1] > arr[i] )
            swap(&arr[i], &arr[i-1]);
 
        // If current even element is smaller than next
        if (i<n-1 && arr[i] < arr[i+1] )
            swap(&arr[i], &arr[i + 1]);
    }
}

//arr[0] <= arr[1] >= arr[2] <= arr[3] . . . .
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
       
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i=i+2)
        {
            
            if(i>0&&nums[i]>nums[i-1])swap(nums[i], nums[i-1]);
            if(i<nums.size()-1&&nums[i]>nums[i+1])swap(nums[i], nums[i+1]);
            
            
            
        }
        return ;
    }
};
```
## __Wiggle Sort 2__

- [Question Link](https://leetcode.com/problems/wiggle-sort-ii/)
- [Explaination video of TC=(nlogn), SC=O(n) solution](https://www.youtube.com/watch?v=mwsjU6CHOb4)
- [Leetcode discuss blog for TC=(n), SC=O(1)](https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)%2BO(1)-after-median-Virtual-Indexing)



![image](https://user-images.githubusercontent.com/51910127/145410254-fdc9797f-b5a3-4589-8170-ff90c0d35de0.png)
![image](https://user-images.githubusercontent.com/51910127/145410314-96151db7-69ef-4e27-817e-2735a1cddbbd.png)


```cpp
void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    
    // Find a median.
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;
    
    // Index-rewiring.
    #define A(i) nums[(1+2*(i)) % (n|1)]

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        if (A(j) > mid)
            swap(A(i++), A(j++));
        else if (A(j) < mid)
            swap(A(j), A(k--));
        else
            j++;
    }
}
```

```md
 my understanding
here. (n|1) is related to n being even or odd. When n is even, we only need nums[1 + 2i % (n+1)]
instead of nums[1 + 2i % (n|1)]; when n is odd, we need nums[1 + 2i % n] instead of nums[1 + 2i % (n|1)]. 
To combine the two cases together(n being either even or odd), we can simply use one formula nums[1 + 2*i % (n|1)].


Let's say nums is [10,11,...,19]. Then after nth_element and ordinary partitioning,
we might have this (15 is my median):

index:     0  1  2  3   4   5  6  7  8  9
number:   18 17 19 16  15  11 14 10 13 12
I rewire it so that the first spot has index 5, the second spot has index 0, etc,
so that I might get this instead:

index:     5  0  6  1  7  2  8  3  9  4
number:   11 18 14 17 10 19 13 16 12 15
And 11 18 14 17 10 19 13 16 12 15 is perfectly wiggly. And the whole partitioning-to-wiggly-arrangement
(everything after finding the median) only takes O(n) time and O(1) space.

If the above description is unclear, maybe this explicit listing helps:

Accessing A(0) actually accesses nums[1].
Accessing A(1) actually accesses nums[3].
Accessing A(2) actually accesses nums[5].
Accessing A(3) actually accesses nums[7].
Accessing A(4) actually accesses nums[9].
Accessing A(5) actually accesses nums[0].
Accessing A(6) actually accesses nums[2].
Accessing A(7) actually accesses nums[4].
Accessing A(8) actually accesses nums[6].
Accessing A(9) actually accesses nums[8].

```
