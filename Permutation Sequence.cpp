class Solution {
public:
    string getPermutation(int n, int k) {
       vector<int> a;
	for(int i=1;i<=n;i++) a.push_back(i);
	string ans="";
	int i=1;
	while(i!=k){
		next_permutation(a.begin(),a.end());
		i++;
	}
	for(auto i:a){
		string s = to_string(i);
		ans+=s;
	}
	return ans; 
    }
};
