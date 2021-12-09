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
