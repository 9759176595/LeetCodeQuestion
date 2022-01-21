class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size()/2;
        vector<bool> red(10,false);
         vector<bool> green(10,false);
         vector<bool> blue(10,false);
        
        int count=0;
        int ringRod;
        for(int i=0;i<2*n;i++){
            ringRod=rings[i+1]-'0';
            if(rings[i]=='R')
                red[ringRod]=true;
             if(rings[i]=='G')
                green[ringRod]=true;
             if(rings[i]=='B')
                blue[ringRod]=true;
        }
        for(int i=0;i<10;i++){
            if(red[i] && green[i] && blue[i]){
                count++;
            }
           
        }
         return count;
    }
};
