/*
149. Max Points on a Line
Hard
Given an array of points where points[i] = [xi, yi] represents a point 
on the X-Y plane, return the maximum number of points that lie on the
same straight line.
 
Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3
Example 2:
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 
Constraints:
1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.
*/














class Solution {
public:
    int getGcd(const int a, const int b)
    {
        if(a==0) return b;
        return getGcd(b%a, a);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int v, res=0,len=points.size();
        if(len<3) return len;
        for(int i=0;i+res<len;i++)
        {
            unordered_map<string,int> m;
            int x1 = points[i][0], y1 = points[i][1], v=0, maxv=0, dups=0;
            int nIdentical=0;
            // start with i+1, since if any previous point is on the same line,
            // then this was already calculated then that point was a starting point
            for(int j=i+1;j<len;j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x2-x1, dy = y2-y1;

                if(dx==0 && dy==0)
                {
                    dups++;
                }
                else
                {
                    // we need the slope: dx/dy. but float rounds up the end and produces slightly different results,
                    // so instead we keep both dx and dy as the key.
                    // to make them identical for the identical slope, use GCD: greatest common divisor
                    int gcd = getGcd(dx,dy);
                    dy/=gcd; dx/=gcd;

                    // dx and dy define the slope.
                    // we keep the map for the current point i, so the full key is point[i]+slope excludes parallel lines.
                    // vertical line: dx==0, horizontal line: dy==0. GCD will set vertical: dx=0, dy=1, horizontal: dx=1, dy=0 
                    string key = to_string(dx) + '/'+ to_string(dy);
                    if(m.find(key) != m.end()) {m[key]++; v=m[key]; }
                    else { m[key]=1; v=1; }
                }
                // duplicates should increase our best result found with point[i]
                if(maxv < v) maxv = v;
                if(res < dups + maxv + 1) res = dups + maxv + 1;
            } 
        }
        return res;
    }
};
