class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
       // if the length of the input is odd, then return {}
        // because doubled array must have even length
        if (changed.size() & 1) return {};
        vector<int> ans;
        // put all the elements to a multiset
        multiset<int> s(changed.begin(), changed.end());
        // keep doing the following logic when there is an element in the multiset
        while (s.size()) {
            // get the smallest element
            int smallest = *s.begin();
            ans.push_back(smallest);
            // remove the smallest element in multiset
            s.erase(s.begin());
            // if the doubled value of smallest doesn't exist in the multiset
            // then return {}
            if (s.find(smallest * 2) == s.end()) return {};
            // otherwise we can remove its doubled element
            else s.erase(s.find(smallest * 2));   
        }
        return ans;
    }
};
