![image](https://user-images.githubusercontent.com/51910127/143620424-d9badff9-d67f-4e50-82af-506111a780dc.png)
![image](https://user-images.githubusercontent.com/51910127/143620476-accdd3c3-6cbf-4eee-a0d8-211231f1234d.png)


- [Question Link](https://leetcode.com/problems/permutation-sequence/)
- [Explaination Video](https://www.youtube.com/watch?v=wT7gcXLYoao)

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1; 
        vector<int> numbers; 
        for(int i = 1;i<n;i++) {
            fact = fact * i; 
            numbers.push_back(i); 
        }
        numbers.push_back(n); 
        string ans = ""; 
        k = k - 1; 
        while(true) {
            ans = ans + to_string(numbers[k / fact]); 
            numbers.erase(numbers.begin() + k / fact); 
            if(numbers.size() == 0) {
                break; 
            }
            
            k = k % fact; 
            fact = fact / numbers.size();
        }
        return ans; 
    }
};
```
