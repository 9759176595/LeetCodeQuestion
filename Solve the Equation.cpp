class Solution {
public:
    string solveEquation(string eq) {
        int leftVar=0,leftNum=0,rightVar=0,rightNum=0;
        eq+='+';
        string var;
        int flag=0;
        for(int i=0;i<eq.size();i++)
        {
            
            if(var.size()>0 && (eq[i]=='+'||eq[i]=='-'||eq[i]=='='))
            {
                
                if(var[var.size()-1]=='x')
                {
                    int mul=1;
                    int start=0;
                    if(var[0]=='-')
                    {
                        mul=-1;
                        start=1;
                    }
                    string temp=var.substr(start,var.size()-start-1);
                    if(temp.size()==0)
                        temp="1";
                    
                    if(!flag)
                        leftVar+=(mul*stoi(temp));
                    else
                        rightVar+=(mul*stoi(temp));
                }
                else
                {
                    int mul=1;
                    int start=0;
                    if(var[0]=='-')
                    {
                        mul=-1;
                        start=1;
                    }
                    string temp=var.substr(start,var.size());
                    if(!flag)
                        leftNum+=(mul*stoi(temp));
                    else
                        rightNum+=(mul*stoi(temp));
                }
                if(eq[i]=='=')
                {
                    flag=1;
                    var="";
                }
                else if(eq[i]=='-')
                    var=eq[i];
                else
                    var="";
            }
            else{
                var+=eq[i];
            }
            
        }
        
        if(leftVar==rightVar)
        {   
            if(leftNum==rightNum)
                return "Infinite solutions";
            else
                return "No solution";
        }
        if(leftVar>rightVar)
        {
            int diff1=leftVar-rightVar;
            int diff2=rightNum-leftNum;
            int d=gcd(diff1,diff2);
            diff1/=d;diff2/=d;
            
            string temp=diff1>1?to_string(diff1):"";
            return temp+"x="+to_string(diff2);
        }
        else{
            
            int diff1=rightVar-leftVar;
            int diff2=leftNum-rightNum;
            int d=gcd(diff1,diff2);
            diff1/=d;diff2/=d;
            
            string temp=diff1>1?to_string(diff1):"";
            return temp+"x="+to_string(diff2);
        }
    }
};
