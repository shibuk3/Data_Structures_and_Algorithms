### __K-th element of two sorted Arrays__

[Video Link](https://www.youtube.com/watch?v=nv7F4PiLUzo)


```md
 
 Length of Array 1(length of minimum array)= M
 Length of Array 2= N
 M<N
 for example:
 -----------------------------------------
 Case 1: when M > K 
 
 Array1=[1, 3, 4, 10]
 Array1=[2,5,6,8,9,11,34]

 low =0 , high =! 4
  as we cant pick 4 elements from array1 as we need only K element
  
  so low=0, high=k
  
 Case 2: when N < K 
 
 Array1=[1, 3, 4, 10]
 Array1=[2,5,6,8,9,11,34]

 low =!0 , high = 4
  as we cant pick 0 elements from array1 as at max we can pick N elements from array 2, so in this
  case we have to pick atleast one elment from array 1
  
  so low=1, high=4
```

```cpp

int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n > m) {
            return kthElement(arr2, arr1, m, n, k); 
        }
        
        int low = max(0,k-m), high = min(k,n);
        
        while(low <= high) {
            int cut1 = (low + high) >> 1; 
            int cut2 = k - cut1; 
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
            int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if (l1 > r2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1; 
            }
        }
        return 1; 
    }
```

