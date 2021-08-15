//METHOD 1- BRUTE FORCE
//METHOD-2- HASH MAP,
/*
Given an array arr of N elements, the task 
is to find the length of the smallest subarray of
the given array that contains at least one duplicate
element. A subarray is formed from consecutive elements of
an array. If no such array exists, print “-1”.
link- https://www.geeksforgeeks.org/find-the-smallest-subarray-having-atleast-one-duplicate/ 
*/

unordered_map<int, int>u;
int len= INT_MAX;
for(int i=0;i<nums.size();i++)
{   
  if(u.find(nums[i])!=u.end())
  {if(len>i-nums[i]+1)
  {len=i-nums[i]+1;u[nums[i]]=i;}
   }
     else
     {u[nums[i]]=i;}
  
} if(len==INT_MAX) return -1
return len
//---------------------------------------------
//METHOD 3-  two pointer technique 
int start=0, end=0, len=INT_MAX;
unordered_map<int , int>u;int counter=0;
while(end<nums.size())
{   u[nums[end]]++;
  if(u[nums]>1){counter++;}
  while(counter>0)
  { if(len>end-start+1){len=end-start+1;}
    if(u[nums[start]]>1){ counter--;}
    start++;
  }
 
 end++;
} 
if(len==INT_MAX) return -1;
return len;
