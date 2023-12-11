### __Left shift and Right shift operator__
__Left Shift operator__
```md
Takes two numbers, left shifts the bits of the first operand, the
second operand decides the number of places to shift. Or in other words
left shifting an integer “x” with an integer “y” denoted as ‘(x<<y)’ is 
equivalent to multiplying x with 2^y (2 raised to power y). 

Eg: N<<i (N: first operand, i: second operand)
eg: lets take N=22; which is 00010110 in Binary Form.

Now, if “N is left-shifted by 2” i.e N=N<<2 then N will become N=N*(2^2).
Thus, N=22*(2^2)=88 which can be wriiten as 01011000.
```
```cpp
/* C++ Program to demonstrate use of left shift 
   operator */
#include <iostream>
using namespace std;
  
int main()
{
    // a = 5(00000101), b = 9(00001001)
    unsigned char a = 5, b = 9; 
  
    // The result is 00001010 
    cout <<"a<<1 = "<< (a<<1) << endl;
    
    // The result is 00010010 
    cout <<"b<<1 = "<< (b<<1) << endl;  
    return 0;
}
  
a<<1 = 10
b<<1 = 18
```

__Right Shift operator__

```md
Takes two numbers, right shifts the bits of the first operand, the second operand
decides the number of places to shift. In other words right shifting an integer 
“x” with an integer “y” denoted as ‘(x>>y)‘ is equivalent to dividing x with 2^y. 

Eg: N>>i (N: first operand, i: second operand)

 Now, if “N is right-shifted by 2” i.e N=N>>2 then N will become N=N/(2^2). 
 Thus, N=32/(2^2)=8 which can be wriiten as 1000.
```

```cpp
/* C++ Program to demonstrate use of right
   shift operator */
#include <iostream>
using namespace std;
  
int main()
{
    // a = 5(00000101), b = 9(00001001)
    unsigned char a = 5, b = 9;
  
    // The result is 00000010
  
    cout <<"a>>1 = "<< (a >> 1)<< endl;
  
    // The result is 00000100
    cout <<"b>>1 = "<< (b >> 1) << endl;
    return 0;
}
  
Output
a>>1 = 2
b>>1 = 4
```

Important Points : 

- The left shift and right shift operators should not be used for negative numbers.
 The result of is undefined behaviour if any of the operands is a negative number.
 For example results of both 1 >> -1 and 1 << -1 is undefined.
 - If the number is shifted more than the size of integer, the behaviour is undefined.
For example, 1 << 33 is undefined if integers are stored using 32 bits. For bit shift
of larger values 1ULL<<62  ULL is used for Unsigned Long Long which is defined using 
64 bits which can store large values.
- The & operator can be used to quickly check if a number is odd or even. The value of expression
 (x & 1) would be non-zero only if x is odd, otherwise the value would be zero. 

```cpp
#include <iostream>
using namespace std;
  
int main() {
      // a = 5(00000101), b = 9(00001001)
    int a = 5, b = 9;
  
    // The result is 00000001
    cout<<"a = " << a <<","<< " b = " << b <<endl;
    cout << "a & b = " << (a & b) << endl;
  
    // The result is 00001101
    cout << "a | b = " << (a | b) << endl;
  
    // The result is 00001100
    cout << "a ^ b = " << (a ^ b) << endl;
  
    // The result is 11111010
    cout << "~(" << a << ") = " << (~a) << endl;
  
    // The result is 00010010
    cout<<"b << 1" <<" = "<< (b << 1) <<endl;
  
    // The result is 00000100
    cout<<"b >> 1 "<<"= " << (b >> 1 )<<endl;
  
    return 0;
}
```
- Question 1
```md
Given a set of numbers where all elements occur even a number of times except one number, find the odd occurring number
```

```cpp
#include <iostream>
using namespace std;
  
// Function to return the only odd
// occurring element
int findOdd(int arr[], int n)
{
    int res = 0, i;
    for (i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}
  
// Driver Method
int main(void)
{
    int arr[] = { 12, 12, 14, 90, 14, 14, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The odd occurring element is  "<< findOdd(arr, n);
    return 0;
}

Output: 
The odd occurring element is 90
```
Link 1 : https://www.geeksforgeeks.org/calculate-xor-1-n/

Link 2 : https://www.geeksforgeeks.org/program-to-find-whether-a-given-number-is-power-of-2/
```md
Concept 1:-
All power of two numbers has only a one-bit set. So count the no. of set bits
and if you get 1 then the number is a power of 2.
Please see Count set bits in an integer for counting set bits.

Concet 2:
f we subtract a power of 2 numbers by 1 then all unset bits after the only
set bit become set; and the set bit becomes unset.
For example for 4 ( 100) and 16(10000), we get the following after subtracting 1 
3 –> 011 
15 –> 01111

So, if a number n is a power of 2 then bitwise & of n and n-1 will be zero.
We can say n is a power of 2 or not based on the value of n&(n-1). 
The expression n&(n-1) will not work when n is 0. To handle this case
also, our expression will become n& (!n&(n-1))
```
```md
Question 3: find the rightmost set bit efficiently
Link 3: https://www.youtube.com/watch?v=Ztt-VtNyqL8

Question 4: Right most set bit Mask
link4 : https://www.youtube.com/watch?v=XcSr6TIMl7w

Question 5: check the kth bit is set or not ?
Link : https://www.geeksforgeeks.org/check-whether-k-th-bit-set-not/?ref=lbp

Question 6: Find position of the only set bit

f number is power of two then and then only its binary representation contains only one ‘1’. 
That’s why check whether the given number is a power of 2 or not. If given number
is not a power of 2, then print error message and exit.

Question 7: swap two numbers without using a temporary variable
https://www.geeksforgeeks.org/swap-two-numbers-without-using-temporary-variable/?ref=lbp

Question 8: Extract ith to jtj bit from a number
link: https://www.geeksforgeeks.org/extract-k-bits-given-position-number/

boradcomm interview : https://leetcode.com/discuss/interview-question/1287500/broadcom-interviews-questions-solutions
```
