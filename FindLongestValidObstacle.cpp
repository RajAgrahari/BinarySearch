//https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/description/
int helper(vector<int>& v,int x)
    {
        int s=0;
        int e=v.size()-1;
        while (s<=e)
        {
            int mid = (s+e)>>1;
            if (v[mid]<=x)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return s;
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles)
    {
        int n = obstacles.size();
        vector<int> a(n),v;
        for (int i = 0 ; i < n; ++i) 
        {
            int x = obstacles[i];
            int it = helper(v,x);
            a[i] = (it+1);
            if (it != v.size()) 
            v[it] = x;
            else 
            v.push_back(x);
        }
        return a;
    }
