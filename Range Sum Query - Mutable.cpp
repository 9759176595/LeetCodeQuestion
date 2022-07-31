class NumArray {
public:
     vector<int> STree; // to store segment tree
    vector<int> nums; // to store given array
    int n; // size of given array
   NumArray(vector<int>& arr) {
        n = arr.size();
        nums = arr;
        STree.resize(4 * n, 0); // size of segment tree can be max 4*n
        BST(0,n-1,0); // creating segment tree
        
    }
    
    void update(int index, int val) {
        int diff = val-nums[index]; // get difference between old and new element values
        nums[index] = val; // do required changes in array
        updateST(index , diff , 0 , n-1 , 0); // update segment tree to reflect these changes
    }
    
    int sumRange(int left, int right) {
        return querySum(left,right,0,n-1,0);
    }
    
    int BST(int cS , int cE , int i){
        //Base Case
        if(cS==cE){
            STree[i]=nums[cS];
            return nums[cS];
        }
        //Recursive Case
        int mid = (cS + cE)/2;
        STree[i] = BST(cS , mid , 2*i+1) + BST(mid+1 , cE , 2*i+2);
        return STree[i];
    }
    
    int querySum(int qS , int qE , int cS , int cE , int i ){
        //Base cases
        // if current node range does not lie inside query range 
        if(qS > cE || qE < cS ){
            return 0;
        }
        // if current node range completely lie inside query range 
        if(qS <= cS && qE >= cE){
            return STree[i];;
        }
        //Recurive case
        int mid = (cS + cE)/2;
        return querySum(qS , qE , cS , mid , 2*i+1) + querySum(qS , qE , mid+1 , cE , 2*i+2);
        
    }
    
    void updateST(int idx , int diff , int cS , int cE , int i){
        //Base cases
        // If index lie between current node range 
        if(idx<cS || idx>cE){
            return;
        } 
        // else we add the difference to current node value 
        STree[i] += diff;
        //Recursive case
        if(cE > cS){
            int mid = (cS + cE)/2;
            updateST(idx,diff,cS,mid,2*i+1);
            updateST(idx,diff,mid+1,cE,2*i+2);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
