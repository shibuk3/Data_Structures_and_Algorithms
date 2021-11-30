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


```

