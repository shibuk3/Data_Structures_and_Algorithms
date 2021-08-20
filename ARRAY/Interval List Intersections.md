### __Interval List Intersections__ 
[Problem link](https://leetcode.com/problems/interval-list-intersections/) \
You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] \
and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a < b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented \ 
as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

 

Example 1:


Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]] \
Example 2:

Input: firstList = [[1,3],[5,9]], secondList = []
Output: [] \
Example 3:

Input: firstList = [], secondList = [[4,8],[10,12]]
Output: [] \
Example 4:

Input: firstList = [[1,7]], secondList = [[3,10]]
Output: [[3,7]]
 

Constraints:

0 <= firstList.length, secondList.length <= 1000 \
firstList.length + secondList.length >= 1 \
0 <= starti < endi <= 109 \
endi < starti+1 \
0 <= startj < endj <= 109 \
endj < startj+1 

```cpp
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i=0,j=0;
        
        while(i<firstList.size() && j<secondList.size())
        {
            int a=firstList[i][0],b=firstList[i][1];
            int x=secondList[j][0],y=secondList[j][1];
            
            if(a<=y&&x<=b)
                ans.push_back({max(a,x),min(b,y)});
            if(b<y) i++;
            else j++;
        }
        
        return ans;
    }
};
```
### __Solution Explaination: Credits [Leetcode discuss](https://leetcode.com/problems/interval-list-intersections/discuss/647482/Python-Two-Pointer-Approach-%2B-Thinking-Process-Diagrams)__

![image](https://user-images.githubusercontent.com/51910127/130283353-8e8f4134-9f7e-4745-aa59-f8081d53cb95.png)
![image](https://user-images.githubusercontent.com/51910127/130283441-cc4d8cd4-492b-42eb-9131-f2844ae04842.png)
![image](https://user-images.githubusercontent.com/51910127/130283480-7895e51a-f169-494a-b9c8-c4b002960b81.png)

__Second Part: Incrementing the pointers__
The idea behind is to increment the pointer based on the end values of two ranges. Let's say the\
current range in A has end value smaller than to equal to end value of the current range in B, that\
essentially means that you have exhausted that range in A and you should move on to the next range.\
Let's try to visually think about this. When you are going through the images, keep track of end values\
of the ranges and how the little pointer triangles progess.

![image](https://user-images.githubusercontent.com/51910127/130283679-1298b707-71d6-4545-9d02-e510534040df.png)
![image](https://user-images.githubusercontent.com/51910127/130283800-ace9ac4b-b668-4c11-816c-f60d22aebf77.png)
![image](https://user-images.githubusercontent.com/51910127/130283894-f4f663dc-f5f7-4d0b-a566-98f84f70dc8a.png)

