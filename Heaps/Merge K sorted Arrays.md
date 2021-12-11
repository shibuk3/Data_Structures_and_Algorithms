### __Merge K sorted Arrays__

```md
Given k sorted arrays of size n each, merge them and print the sorted output.

Input: 
k = 3, n = 4 
arr[][] = { {1, 3, 5, 7}, 
{2, 4, 6, 8}, 
{0, 9, 10, 11}} ;
Output: 0 1 2 3 4 5 6 7 8 9 10 11 
Explanation: The output array is a sorted array that contains all the elements of the input matrix. 

Input: 
k = 4, n = 4 
arr[][] = { {1, 5, 6, 8}, 
{2, 4, 10, 12}, 
{3, 7, 9, 11}, 
{13, 14, 15, 16}} ;
Output: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
Explanation: The output array is a sorted array that contains all the elements of the input matrix


Naive Approach: The very naive method is to create an output array of size n * k
and then copy all the elements into the output array followed by sorting. 

Algorithm: 
- Create a output array of size n * k.
- Traverse the matrix from start to end and insert all the elements in output array.
- Sort and print the output array.

Complexity Analysis: 
- Time Complexity :O(n*k*log(n*k)). 
- since resulting array is of N*k size.
- Space Complexity :O(n*k), The output array is of size n*k.
```

### __Solution 2:Merge sort__
```md
Efficient Approach The process might begin with merging arrays into groups of two
. After the first merge, we have k/2 arrays. Again merge arrays in groups, now we have k/4 arrays.
This is similar to merge sort. Divide k arrays into two halves containing an equal number of arrays
until there are two arrays in a group. This is followed by merging the arrays in a bottom-up manner. 

Algorithm: 
- Create a recursive function which takes k arrays and returns the output array.

- In the recursive function, if the value of k is 1 then return the array else if
the value of k is 2 then merge the two arrays in linear time and return the array.

- If the value of k is greater than 2 then divide the group of k elements into two 
equal halves and recursively call the function, i.e 0 to k/2 array in one recursive
function and k/2 to k array in another recursive function.
Print the output array.

```

```cpp
// C++ program to merge k sorted arrays of size n each.
#include<bits/stdc++.h>
using namespace std;
#define n 4
 
// Merge arr1[0..n1-1] and arr2[0..n2-1] into
// arr3[0..n1+n2-1]
void mergeArrays(int arr1[], int arr2[], int n1,
                             int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
   
    // Traverse both array
    while (i<n1 && j <n2)
    {
        // Check if current element of first
        // array is smaller than current element
        // of second array. If yes, store first
        // array element and increment first array
        // index. Otherwise do same with second array
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
   
    // Store remaining elements of first array
    while (i < n1)
        arr3[k++] = arr1[i++];
   
    // Store remaining elements of second array
    while (j < n2)
        arr3[k++] = arr2[j++];
}
 
// A utility function to print array elements
void printArray(int arr[], int size)
{
   for (int i=0; i < size; i++)
       cout << arr[i] << " ";
}
 
// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them together
// and prints the final sorted output.
void mergeKArrays(int arr[][n],int i,int j, int output[])
{
    //if one array is in range
    if(i==j)
    {
        for(int p=0; p < n; p++)
        output[p]=arr[i][p];
        return;
    }
     
    //if only two arrays are left them merge them
    if(j-i==1)
    {
        mergeArrays(arr[i],arr[j],n,n,output);
        return;
    }
     
    //output arrays
    int out1[n*(((i+j)/2)-i+1)],out2[n*(j-((i+j)/2))];
     
    //divide the array into halves
    mergeKArrays(arr,i,(i+j)/2,out1);
    mergeKArrays(arr,(i+j)/2+1,j,out2);
     
    //merge the output array
    mergeArrays(out1,out2,n*(((i+j)/2)-i+1),n*(j-((i+j)/2)),output);
     
}
  
  
// Driver program to test above functions
int main()
{
    // Change n at the top to change number of elements
    // in an array
    int arr[][n] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
    int k = sizeof(arr)/sizeof(arr[0]);
    int output[n*k];
    mergeKArrays(arr,0,2, output);
  
    cout << "Merged array is " << endl;
    printArray(output, n*k);
  
    return 0;
}
```
```md

Output: 
Merged array is 
1 2 6 9 12 20 23 34 34 90 1000 2000

Complexity Analysis:  

Time Complexity: O( n * k * log k). 
- There are log k levels as in each level the k arrays are divided in
half and at each level the k arrays are traversed. So time Complexity is O( n * k ).
- Space Complexity: O( n * k * log k). 
- In each level O( n*k ) space is required So Space Complexity is O( n * k * log k).
```
### Solution 3: Min Heap based__

```md

Alternative Efficient Approach: The idea is to use Min Heap. This MinHeap based solution
has the same time complexity which is O(NK log K). But for a different and particular
sized array, this solution works much better. The process must start with creating a
MinHeap and inserting the first element of all the k arrays. Remove the root element 
of Minheap and put it in the output array and insert the next element from the array 
of removed element. To get the result the step must continue until there is no element
in the MinHeap left. 

MinHeap: A Min-Heap is a complete binary tree in which the value in each internal node
is smaller than or equal to the values in the children of that node. Mapping the elements 
of a heap into an array is trivial: if a node is stored at index k, then its left child is stored at index 2k + 1 and its right child at index 2k + 2. 

Algorithm: 
A simple solution is to create an output array and and one by one copy all arrays to it.
Finally, sort the output array using. This approach takes O(N Logn N) time where N is
count of all elements.
An efficient solution is to use heap data structure. The time complexity of heap based
solution is O(N Log k).
1. Create an output array. 
2. Create a min heap of size k and insert 1st element in all the arrays into the heap 
3. Repeat following steps while priority queue is not empty. 
…..a) Remove minimum element from heap (minimum is always at root) and store it in output array. 
…..b) Insert next element from the array from which the element is extracted. If the
array doesn’t have any more elements, then do nothing.
```
