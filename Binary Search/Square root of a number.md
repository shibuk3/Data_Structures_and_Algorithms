### __Square root of a number__
```md
__Concept:__ This problem's key point is that we want to find the largest number, which num*num <= x, 
therefore we should use the binary search to find the upper bound within the range(1,x).
Different people may have their own way handling the boundaries, but I figure we'd better
think clearly what we want to find through binary search.
Below is my code, just a typical template of using upper bound of binary search
```


```cpp
class Solution {
    public int mySqrt(int x) {
        int i = 1;
        int j = x;
        int ans = 0;
        while (i <=j){
            int mid = i + (j-i)/2;
            // upper bound
            if (mid <= x/mid){
                i = mid +1;
                ans = mid;
            }
            else
                j = mid-1;
        }
        
        return ans;
    }
}
```
### __Nth root of a number__

```cpp
#include <bits/stdc++.h>
using namespace std;
double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

double getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-6; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; // we cant use mid+1 here
                      // as we have set the precision to 6 decimal places so we cant incresae by 1
                      // remember that
        }
        else {
            high = mid; 
        }
    }
    
    cout << low << " " << high << endl; 
    
    // just to check
    cout << pow(m, (double)(1.0/(double)n)); 
}
int main() {
	int n, m;
	cin >> n >> m; 
	getNthRoot(n, m); 
	return 0;
}
``
