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
-If the number is shifted more than the size of integer, the behaviour is undefined.
For example, 1 << 33 is undefined if integers are stored using 32 bits. For bit shift
of larger values 1ULL<<62  ULL is used for Unsigned Long Long which is defined using 
64 bits which can store large values.
