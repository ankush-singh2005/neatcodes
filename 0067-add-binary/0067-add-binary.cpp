class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        vector<int> arr;
        while (i >= 0 || j >= 0 || carry) {
            int rem1 = (i >= 0 ? a[i] - '0' : 0);
            int rem2 = (j >= 0 ? b[j] - '0' : 0);
            int sum = rem1 + rem2 + carry;
            if (sum == 0) {
                arr.push_back(0);
                carry = 0;
            } 
            else if (sum == 1) {
                arr.push_back(1);
                carry = 0;
            } 
            else if (sum == 2) {
                arr.push_back(0);
                carry = 1;
            } 
            else { // sum == 3
                arr.push_back(1);
                carry = 1;
            }

            i--;
            j--;
        }

        reverse(arr.begin(), arr.end());

        string ans = "";
        for (int k = 0; k < arr.size(); k++) {
            ans += char('0' + arr[k]);
        }
        return ans;
    }
};
