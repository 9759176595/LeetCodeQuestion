///----------METHOD 1-----------
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(p.length()> s.length())
            return result;
        
        vector<int> pchars(26,0);
        for(char c: p)
            pchars[c-'a']+=1;
        int start=0;
        for(int i=0;i<p.length();i++)
            pchars[s[i]-'a']-=1;
        
        bool match=true;
        for(int pc: pchars){
            if(pc!=0){
                match=false;
                break;
            }
        }
        if(match)
            result.push_back(start);
        start++;
        
        while(start<=s.length()-p.length()){
            int idx1=s[start-1]-'a';
            int  idx2=s[start+p.length()-1]-'a';
            pchars[idx1]+=1;
            pchars[idx2]-=1;
            
            match=true;
            for(int pc: pchars){
            if(pc!=0){
                match=false;
                break;
            }
        }
        if(match)
            result.push_back(start);
        start++;
        }
        return result;
    }
};

//////////-----------METHOD2
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(p.length()> s.length())
            return result;
        
        vector<int> pchars(26,0);
        for(char c: p)
            pchars[c-'a']+=1;
        int start=0;
        for(int i=0;i<p.length();i++)
            pchars[s[i]-'a']-=1;
        
        int mismatch_count=0;
        for(int pc: pchars){
            if(pc!=0)
               mismatch_count+=1;
        }
        if(mismatch_count==0)
            result.push_back(start);
        start++;
        
        while(start<=s.length()-p.length()){
            int idx1=s[start-1]-'a';
            int  idx2=s[start+p.length()-1]-'a';
            pchars[idx1]+=1;
            if(pchars[idx1]==1)
                mismatch_count+=1;
            else if(pchars[idx1]==0)
                mismatch_count-=1;
            
            pchars[idx2]-=1;
             if(pchars[idx2]==-1)
                mismatch_count+=1;
            else if(pchars[idx2]==0)
                mismatch_count-=1;
            
          
            
            
        if(mismatch_count==0)
            result.push_back(start);
        start++;
        }
        return result;
    }
};
