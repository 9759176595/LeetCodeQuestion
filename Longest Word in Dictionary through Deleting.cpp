class Solution {
public:
    bool issub(string s1 , string s2)
    {
            int l1 = s1.length() ;
            int l2 = s2.length() ;
            int j = 0;
            for(int i=0 ; i<l2 && j<l1 ; i++)
            {
                    if(s1[j] == s2[i]) //using 2 pointers
                            j++;
            }
            
            return (j == l1);//check wether the word from the string is a substring of the given string or not.
    }
    string findLongestWord(string s, vector<string>& dict) {
         if(s.length() == 0)
                    return "";
            
            // to maintain the lexiographical order we need to sort the words in the dictionary.
            sort(dict.begin() , dict.end());
            
            string max_str = "";//empty string
            int max_length = 0;
            
            for(auto word : dict)
            {
                    int size = word.length();
                    
                    //check if the word from the dict is a substring of s and also check for the max length.
                    if((max_length < size) && (issub(word , s)))
                    {
                            max_str = word;
                            max_length = size;
                    }
                       
            }
            return max_str;
    }
};
