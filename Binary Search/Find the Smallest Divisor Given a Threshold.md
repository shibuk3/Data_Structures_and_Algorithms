### __Find the Smallest Divisor Given a Threshold__

![image](https://user-images.githubusercontent.com/51910127/134771245-2f8f12fa-6d1d-47e0-9d92-b68f6c045936.png)
![image](https://user-images.githubusercontent.com/51910127/134771268-c1eb22e6-26c2-4d47-bf3c-5d5fb6cc3643.png)
![image](https://user-images.githubusercontent.com/51910127/134771276-742cc124-a697-4ff6-97f1-6409225f1f2d.png)

__Follow up question ?__
- How you decided value of __j__ ?

```cpp
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
         int dl=0;
        
        int i=1; int j=10e6;
     //  int dv=0;
        int ans=0;
        while(i<=j)
        {
         int dv=i+(j-i)/2;
            
            int sum=0;
            for(int f=0 ;f<nums.size();f++)
            { if(nums[f]%dv==0){
                    sum+=(nums[f]/dv);
                } else{
                    sum+=(nums[f]/dv)+1;
                }
            }
            
            if(sum>t)
                i=dv+1;
            else
                j=dv-1,ans=dv;
       
            
        }
     return ans ;  
        
    }
};
```
