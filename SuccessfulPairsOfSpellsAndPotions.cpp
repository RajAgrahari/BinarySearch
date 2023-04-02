//https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        int j=0;
        for(int i=0;i<spells.size();i++)
        {
            int l = 0;
            int r = potions.size()-1;
            while(l<=r)
            {
                int mid = l + (r-l)/2;
                long long x = spells[i];
                long long y = potions[mid];
                if((x*y)<success)
                l = mid+1;
                else
                r = mid-1;
            }
            ans.push_back(potions.size()-r-1);
        }
        return ans;

    }
