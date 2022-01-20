class Solution {
public:
    int minEatingSpeed(vector<int>& pile, int h) 
    {
        int left = 1, right=*max_element(pile.begin(),pile.end());;
        while (left<right) 
        {
            int mid=(left+right)/2;
            int total=0;
            for(int p:pile) 
                total=total+(p+mid-1)/mid;
            if(total>hour) 
                left=mid+1; 
            else 
                right=mid;
        }
        return left;     
    }
};
