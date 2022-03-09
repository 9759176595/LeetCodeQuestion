class Solution {
public:
    double getArea(vector<int>a,vector<int>b, vector<int>c){
        return(a[0]*(b[1]-c[1])+ b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]))/2.0;
    }
    double largestTriangleArea(vector<vector<int>>& p) {
        double max=0;
        for(int i=0;i<p.size();i++){
            for(int j=i+1;j<p.size();j++){
                for(int k=j+1;k<p.size();k++){
                    double area=abs(getArea(p[i],p[j],p[k]));
                    
                    
                    if(area>max)
                        max=area;
                }
            }
        }
        return max;
    }
};
