### __Median of two Sorted Arrays of Different Sizes__
- [Video Link](https://www.youtube.com/watch?v=LPFhl65R7ww)
- [Question Link](https://leetcode.com/problems/median-of-two-sorted-arrays/)

__Method 1: TC=O(m+n), SC=O(1)__
```cpp
// A Simple Merge based O(n) solution to find
// median of two sorted arrays
#include <bits/stdc++.h>
using namespace std;
 
/* This function returns median of ar1[] and ar2[].
Assumption in this function:
Both ar1[] and ar2[] are sorted arrays */
int getMedian(int ar1[], int ar2[], int n, int m)
{
    int i = 0; /* Current index of input array ar1[] */
    int j = 0; /* Current index of input array ar2[] */
    int count;
    int m1 = -1, m2 = -1;
 
    // Since there are (n+m) elements,
    // There are following two cases
    // if n+m is odd then the middle
    //index is median i.e. (m+n)/2
    if((m + n) % 2 == 1)
    {
        for (count = 0; count <= (n + m)/2; count++)
        {
            if(i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if(i < n)
            {
                m1 = ar1[i++];
            }
            // for case when j<m,
            else
            {
                m1 = ar2[j++];
            }
        }
        return m1;
    }
     
    // median will be average of elements
    // at index ((m+n)/2 - 1) and (m+n)/2
    // in the array obtained after merging ar1 and ar2
    else
    {
        for (count = 0; count <= (n + m)/2; count++)
        {
            m2 = m1;
            if(i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if(i < n)
            {
                m1 = ar1[i++];
            }
            // for case when j<m,
            else
            {
                m1 = ar2[j++];
            }
        }
        return (m1 + m2)/2;
    }
}
 
/* Driver code */
int main()
{
    int ar1[] = {900};
    int ar2[] = {5, 8, 10, 20};
 
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    cout << getMedian(ar1, ar2, n1, n2);
    return 0;
}
```

### __Method 2: Optimal solution --> TC=O(log(min(m,n))), SC=O(1)__
```java
public class MedianOfTwoSortedArrayOfDifferentLength {

    public double findMedianSortedArrays(int input1[], int input2[]) {
        //if input1 length is greater than switch them so that input1 is smaller than input2.
        if (input1.length > input2.length) {
            return findMedianSortedArrays(input2, input1);
        }
        int x = input1.length;
        int y = input2.length;

        int low = 0;
        int high = x;
        while (low <= high) {
            int partitionX = (low + high)/2;
            int partitionY = (x + y + 1)/2 - partitionX;

            //if partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
            //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
            int maxLeftX = (partitionX == 0) ? Integer.MIN_VALUE : input1[partitionX - 1];
            int minRightX = (partitionX == x) ? Integer.MAX_VALUE : input1[partitionX];

            int maxLeftY = (partitionY == 0) ? Integer.MIN_VALUE : input2[partitionY - 1];
            int minRightY = (partitionY == y) ? Integer.MAX_VALUE : input2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                //We have partitioned array at correct place
                // Now get max of left elements and min of right elements to get the median in case of even length combined array size
                // or get max of left for odd length combined array size.
                if ((x + y) % 2 == 0) {
                    return ((double)Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY))/2;
                } else {
                    return (double)Math.max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) { //we are too far on right side for partitionX. Go on left side.
                high = partitionX - 1;
            } else { //we are too far on left side for partitionX. Go on right side.
                low = partitionX + 1;
            }
        }

        //Only we we can come here is if input arrays were not sorted. Throw in that scenario.
        throw new IllegalArgumentException();
    }

    public static void main(String[] args) {
        int[] x = {1, 3, 8, 9, 15};
        int[] y = {7, 11, 19, 21, 18, 25};

        MedianOfTwoSortedArrayOfDifferentLength mm = new MedianOfTwoSortedArrayOfDifferentLength();
        mm.findMedianSortedArrays(x, y);
    }
}
© 2021 GitHub, Inc.
```

