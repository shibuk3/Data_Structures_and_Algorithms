
-- [quiz on pointers and imp concepts ]https://www.geeksforgeeks.org/c-language-2-gq/pointers-gq/
### __Function pointer in C++__

- __Example 1__
```cpp

// C++ program to implementation
// Function Pointer
#include <iostream>
using namespace std;

int multiply(int a, int b) { return a * b; }

int main()
{
	int (*func)(int, int);

	// func is pointing to the multiplyTwoValues function

	func = multiply;

	int prod = func(15, 2);
	cout << "The value of the product is: " << prod << endl;

	return 0;
}


```


- __Example 2__
```cpp
// C++ Program for demonstrating
// function pointer as pointer
#include <iostream>
using namespace std;

const int a = 15;
const int b = 2;

// Function for Multiplication
int multiply(int a , int b) { return a * b; }

// Function containing function pointer
// as parameter --> pass function parameter as a seprate
void print(int (*funcptr) (int a , int b), int a, int b)
{
	cout <<"The value of the product is: " << funcptr(a,b)
		<< endl;
}

// Driver Function
int main()
{
	print(multiply,a,b);
	return 0;
}


```

- __Example 3__
```cpp
// C++ Program for demonstrating
// function pointer as pointer
#include <iostream>
using namespace std;

const int a = 15;
const int b = 2;

// Function for Multiplication
int multiply() { return a * b; }

// Function containing function pointer
// as parameter
void print(int (*funcptr)())
{
	cout << "The value of the product is: " << funcptr()
		<< endl;
}

// Driver Function
int main()
{
	print(multiply);
	return 0;
}

```
