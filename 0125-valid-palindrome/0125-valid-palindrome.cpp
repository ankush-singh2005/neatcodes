class Solution {
public:
    bool isPalindrome(string s) {

        int i = 0;
        int j = s.size() - 1;

        while(i < j) {

            // Skip non-alphanumeric characters from the left
            if(!isalnum(s[i])) {
                i++;
                continue;
            }

            // Skip non-alphanumeric characters from the right
            if(!isalnum(s[j])) {
                j--;
                continue;
            }

            // Compare characters ignoring case
            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};