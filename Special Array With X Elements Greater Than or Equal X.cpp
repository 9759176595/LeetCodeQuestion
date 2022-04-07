class Solution {
public:
    int specialArray(vector<int>& nums) {
        //------------M1
        for(int i=1;i<1001;i++){
            int count=0;
            for(int num:nums){
                if(num>=i)
                    count++;
            }
            if(i==count)
                return i;
        }
        return -1;
        
        //---------M2 (in java)
        
//        int[] bucket=int new[1001];
//         for(int num:nums){
//             bucket[num]++;
//         }
//         int total =nums.size();
//         for(int i=0;i<1001;i++){
//             if(i==total)
//                 return i;
//             total -=bucket[i];
            
//         }
//         return -1;
    }
};
