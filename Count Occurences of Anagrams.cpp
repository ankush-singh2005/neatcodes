//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool checkZero(vector<int>& txtFreq){
        for(int i=0;i<txtFreq.size();i++){
            if(txtFreq[i]!=0) return false;
        }
        return true;
    }

	int search(string pat, string txt) {
	    // code here
	    int n=txt.size();
	    vector<int> txtFreq(26,0);
	    for(auto ch:txt){
	        txtFreq[ch-'a']++;
	    }
	    
	    int i=0;
	    int j=0;
	    int res=0;
	    while(j<n){
	        txtFreq[txt[j]-'a']--;
	        if(j-i+1==pat.length()){
	            if(checkZero(txtFreq)) res++;
	            txtFreq[txt[i]-'a']++;
	            i++;
	        }
	        j++;
	    }
	    return res;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
