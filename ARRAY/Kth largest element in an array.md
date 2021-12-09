### __Kth largest element in an array__

- [Leetcodee link](https://leetcode.com/problems/kth-largest-element-in-an-array/)
- Solution 1: sort it , and then return n-k element, TC=O(nlogn), SC=O(1)
- Solution 2: Heap based, TC=(Nlogk), DC=O(k)
- Solution 3: Below , TC= O(n) in average, O(n^2) in worst case , but randomising can make it O(n)

 ```md
 Quickselect is a selection algorithm to find the k-th smallest
 element in an unordered list. It is related to the quick sort sorting algorithm.
 
 
// Standard partition process of QuickSort().
// It considers the last element as pivot
// and moves all smaller element to left of
// it and greater elements to right
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
 ```
```cpp
public int findKthLargest(int[] nums, int k) {

        shuffle(nums);
        k = nums.length - k;
        int lo = 0;
        int hi = nums.length - 1;
        while (lo < hi) {
            final int j = partition(nums, lo, hi);
            if(j < k) {
                lo = j + 1;
            } else if (j > k) {
                hi = j - 1;
            } else {
                break;
            }
        }
        return nums[k];
    }

private void shuffle(int a[]) {

        final Random random = new Random();
        for(int ind = 1; ind < a.length; ind++) {
            final int r = random.nextInt(ind + 1);
            exch(a, ind, r);
        }
    }
```
