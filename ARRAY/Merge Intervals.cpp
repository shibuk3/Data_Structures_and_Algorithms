/*
56. Merge Intervals
Medium


Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

*/
// MY STUPID CODE MY SOLUTION 1

bool comp(vector<int> a, vector<int> b)
{   if(a[0] != b[0])
    return a[0] < b[0];
     else
         return a[1]<b[1];
    
    
}


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> ans; int mn=INT_MAX;
        for(int i=0;i<intervals.size();i++)
        {    int start=intervals[i][0]; int end= intervals[i][1];
            while(i<intervals.size()-1&&end>=intervals[i+1][0]){ end= max(end,intervals[i+1][1]);i++;}
          // end= intervals[i][1];
            ans.push_back({start,end});
            
            
            
        }

        
        return ans;
    }
};
// METHOD -2  ----------------------------------------------------------------------------------------------------------------
// link - https://leetcode.com/problems/merge-intervals/discuss/21222/A-simple-Java-solution
class Solution {
	public int[][] merge(int[][] intervals) {
		if (intervals.length <= 1)
			return intervals;

		// Sort by ascending starting point
		Arrays.sort(intervals, (i1, i2) -> Integer.compare(i1[0], i2[0]));

		List<int[]> result = new ArrayList<>();
		int[] newInterval = intervals[0];
		result.add(newInterval);
		for (int[] interval : intervals) {
			if (interval[0] <= newInterval[1]) // Overlapping intervals, move the end if needed
				newInterval[1] = Math.max(newInterval[1], interval[1]);
			else {                             // Disjoint intervals, add the new interval to the list
				newInterval = interval;
				result.add(newInterval);
			}
		}

		return result.toArray(new int[result.size()][]);
	}
}
//METHOD 3---------------------------------SOLVE WITH THIS ONE           ---------------------------------------------------------------------------
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            if(output.back()[1] >= intervals[i][0]) output.back()[1] = max(output.back()[1] , intervals[i][1]);
            else output.push_back(intervals[i]); 
        }
        return output;
    }
