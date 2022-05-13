class Solution {
public:
    int totalMoney(int n) {
       int base = ( 7*(7+1) )/2; // CONSTANT Amount added to BANK EVERY WEEK
		// 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28
		//**// RAW LOGIC**
		// FOR EVERY NEW WEEK WE ADD 1 TO EACH DAY i.e. 
		// for 2ND WEEK = 28 + 1 + 1 + 1 + 1 + 1 + 1 + 1  = 28 + ( **7* (2-1)** )
		// for 3RD WEEK = 28 + 2 + 2 + 2 + 2 + 2 + 2 + 2 = 28 + (**7* (3-1)** ) 
		
        int total=0;  // final saving amount
        int complete_week = (n /7); // TOTAL COMPLETE WEEKS 
		
        total = complete_week * base + ((complete_week)*(0+ 7*(complete_week-1)))/2;
		// complete_week * base = BASE AMOUNT ADDED EVERY WEEK 
		
		//Adding all the incremented value separately for each week
        //((complete_week)*(0+ 7*(complete_week-1)))/2; = N/2 (A + L)  SIMPLE Geometric Progression 
		// 7* (1-1) + 7* (2-1) +  7* (3-1) + 7* (4-1)..... = = 0 + 7 + 14 + 21 .... == **SUM OF GP **== n/2 ( first_term + last_term)  
		
        int remainder = n %7;  // for remaining days of incomplete week
        total += (remainder*(remainder+1))/2 + remainder*(complete_week);
		//                base part ( 1+2+3+.. n)            incremented part 
        
        return total;
            
    }
};
