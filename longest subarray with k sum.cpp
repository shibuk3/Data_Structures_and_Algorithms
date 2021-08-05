/*
find the longest subbary with sum k,
k can also be zero, return -1 if no array with sum k is present


*/
  unordered_map<int, int>u;
  int len=INT_MIN;
 for(int i=0;i<nums.size();i++)
      {
          temp+=nums[i];
          
          if(temp==k) len=i+1;
          
          if(u.find(temp-k)!=u.end())
          len=max(len,i-u[temp-need]);
          
              if(u.find(temp)==u.end())
                u[temp]=i;
              
          
          
      }
   if(len==INT_MIN) return -1;
     else return len;
