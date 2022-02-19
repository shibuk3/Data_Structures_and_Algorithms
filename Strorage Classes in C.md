- https://www.geeksforgeeks.org/storage-classes-in-c/
- https://www.geeksforgeeks.org/storage-classes-in-c-with-examples/
- https://www.geeksforgeeks.org/memory-layout-of-c-program/?ref=lbp
- https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/?ref=lbp
- https://www.geeksforgeeks.org/understanding-volatile-qualifier-c-set-1-introduction/?ref=rp
- https://www.geeksforgeeks.org/enumeration-enum-c/?ref=leftbar-rightbar
- https://www.javatpoint.com/typedef-in-c
- https://www.geeksforgeeks.org/function-pointer-in-c/
- geeksforgeeks.org/difference-between-dispatcher-and-scheduler/?ref=lbp
- https://www.geeksforgeeks.org/merge-sort/
- https://www.geeksforgeeks.org/difference-between-sram-and-dram/
- https://www.geeksforgeeks.org/write-memcpy/?ref=lbp
- https://aticleworld.com/how-to-use-atoi-and-how-to-make-own-atoi/
- implent iota
- https://www.quora.com/Why-is-cache-memory-faster-than-RAM
- [pointer arithmetic](https://aticleworld.com/pointer-arithmetic/)
- [what is priority inversion](https://www.geeksforgeeks.org/priority-inversion-what-the-heck/)
- [How to solve priority inversion](https://www.geeksforgeeks.org/difference-between-priority-inversion-and-priority-inheritance/)
- https://www.geeksforgeeks.org/union-c/
- https://pencilprogrammer.com/cpp-tutorials/call-by-value-reference-address/
- https://www.geeksforgeeks.org/pointers-vs-references-cpp/
```cpp

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int r = 3, c = 4, i, j, count;

	int* arr[r];
	for (i = 0; i < r; i++)
		arr[i] = malloc(c * sizeof(int));

	// Note that arr[i][j] is same as *(*(arr+i)+j)
	count = 0;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			arr[i][j] = ++count; // Or *(*(arr+i)+j) = ++count

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			printf("%d ", arr[i][j]);

	/* Code for further processing and free the
	dynamically allocated memory */

	for (int i = 0; i < r; i++)
		free(arr[i]);

	return 0;
}
```
- https://www.geeksforgeeks.org/pass-2d-array-parameter-c/?ref=lbp
```cpp
If compiler is not C99 compatible, then we can use following method to pass a variable sized 2D array.
4) Using a single pointer 
In this method, we must typecast the 2D array when passing to function.
#include <stdio.h>
void print(int *arr, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        printf("%d ", *((arr+i*n) + j));
}
 
int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m = 3, n = 3;
 
    // We can also use "print(&arr[0][0], m, n);"
    print((int *)arr, m, n);
    return 0;
}
Output
1 2 3 4 5 6 7 8 9 
```

```cpp
// The following program works only if your compiler is C99 compatible.
#include <stdio.h>
 
// n must be passed before the 2D array
void print(int m, int n, int arr[][n])
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        printf("%d ", arr[i][j]);
}
 
int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m = 3, n = 3;
    print(m, n, arr);
    return 0;
}

```
- Decimal to Hexadecimal

```cpp
// C++ program to convert a decimal
// number to hexadecimal number
 
#include <iostream>
using namespace std;
 
// function to convert decimal to hexadecimal
void decToHexa(int n)
{
    // char array to store hexadecimal number
    char hexaDeciNum[100];
 
    // counter for hexadecimal number array
    int i = 0;
    while (n != 0) {
        // temporary variable to store remainder
        int temp = 0;
 
        // storing remainder in temp variable.
        temp = n % 16;
 
        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + '0';
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 'A'-10;
            i++;
        }
 
        n = n / 16;
    }
 
    // printing hexadecimal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << hexaDeciNum[j];
}
 
// Driver program to test above function
int main()
{
    int n = 2545;
 
    decToHexa(n);
 
    return 0;
}


```
- designtiny url shortner from base 10 to base 62

```cpp
// C++ program to generate short url from integer id and
// integer id back from short url.
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
 
// Function to generate a short url from integer ID
string idToShortURL(long int n)
{
    // Map to store 62 possible characters
    char map[] = "abcdefghijklmnopqrstuvwxyzABCDEF"
                 "GHIJKLMNOPQRSTUVWXYZ0123456789";
 
    string shorturl;
 
    // Convert given integer id to a base 62 number
    while (n)
    {
        // use above map to store actual character
        // in short url
        shorturl.push_back(map[n%62]);
        n = n/62;
    }
 
    // Reverse shortURL to complete base conversion
    reverse(shorturl.begin(), shorturl.end());
 
    return shorturl;
}
 
// Function to get integer ID back from a short url
long int shortURLtoID(string shortURL)
{
    long int id = 0; // initialize result
 
    // A simple base conversion logic
    for (int i=0; i < shortURL.length(); i++)
    {
        if ('a' <= shortURL[i] && shortURL[i] <= 'z')
          id = id*62 + shortURL[i] - 'a';
        if ('A' <= shortURL[i] && shortURL[i] <= 'Z')
          id = id*62 + shortURL[i] - 'A' + 26;
        if ('0' <= shortURL[i] && shortURL[i] <= '9')
          id = id*62 + shortURL[i] - '0' + 52;
    }
    return id;
}
 
// Driver program to test above function
int main()
{
    int n = 12345;
    string shorturl = idToShortURL(n);
    cout << "Generated short url is " << shorturl << endl;
    cout << "Id from url is " << shortURLtoID(shorturl);
    return 0;
}
```
