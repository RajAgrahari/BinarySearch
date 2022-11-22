//https://practice.geeksforgeeks.org/problems/peak-element/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=peak-element
if(n==1)
    return 0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(arr[0]>=arr[1])
            return 0;
        }
        else if(i==n-1)
        {
            if(arr[n-1]>=arr[n-2])
            return n-1;
        }
        else {
            if(arr[i-1]<=arr[i] && arr[i]>=arr[i+1])
            return i;
        }
    }
