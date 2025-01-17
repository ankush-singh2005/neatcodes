class Solution {
public:
    int minimumLength(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<r){

            //yaha pe check kare rhe ki left aur right dono same h ki ni
            if(s[l]==s[r]){

                //character utha liye taaki check kar paaaye ki left suffix aur right suffix
                //bn paa rha ki ni
                char ch=s[l];

                //yaha pe prefix bana rhe ye check karke ki samne wale elements ch ke equal
                //hai ki ni
                while(l<=r&&s[l]==ch) l++;
                while(l<=r&&s[r]==ch) r--;

            }
            else{
                break;
            }
        }
        return r-l+1;
    }
};
