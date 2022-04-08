class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>minh;
    int currK;
    
    KthLargest(int k, vector<int>& nums) {
        currK=k;
        for(int i=0;i<nums.size();i++){
            add(nums[i]);
        }
    }
    
    int add(int val) {
        if(minh.size()<currK)
            minh.push(val);
        else{
            if(val>minh.top()){
                minh.pop();
                minh.push(val);
            }
        }
        return minh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
