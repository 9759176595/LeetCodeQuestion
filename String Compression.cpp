class Solution {
public:
    int compress(vector<char>& chars) {
       int size = chars.size(), count = 1, j = 0;
        // j is the first index
        // so we will increase j before set the new chars
        for(int i = 1; i < size; i++) {
            //if not equal to prev char, set the count in the j + 1 index
            if(chars[i] != chars[i - 1]) {
                //increase j to get the j + 1 index
                j++;
                if(count > 1) {
                    for(auto c : to_string(count)) {
                        // here the count is set and move the j to j + 1 index
                        chars[j++] = c;
                    }
                    //as j is increased, j is pointing wrong char
                    // need to set the right char
                    count = 1;
                }
                // here setting the right char
                // here the new char is set
                // need to set the right char for both count is greater than 1 or not.
                // that's why it's outside 'if' block
                chars[j] = chars[i];
            } else {
                // if duplicate chars then just count it
                count++;
            }
        }

        // if count > 1 means the count have not been set yet.
        if(count > 1) {
            //Need to increase the j cause j's index has the updated chars
            // So the count have to be set in the next position.
            j++;
            for(auto c : to_string(count)) {
                chars[j++] = c;
            }
            //back to last updated index otherwise j will point wrong index
            j--;
        }
        // j is the index of the chars
        // size will be index + 1
        return j + 1;
    }
};
