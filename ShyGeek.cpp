//https://practice.geeksforgeeks.org/problems/59dfb26eb6c659e6e5f60869ac335f450f97165a/1
Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k){
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'.
        int r = n-1;
        int l = 0;
        long long ch=0;
        while(k>0)
        {
            int cost=-1;
            while(l<=r)
            {
                int mid = l + (r-l)/2;
                int num = shop.get(mid);
                if(num<=k)
                {
                    cost = num;
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            if(cost==-1)
            break;
            ch += k/cost;
            k = k%cost;
            l=0;
        }
        return ch;
    }
