//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void solve(int i, int j, int n, vector<vector<int>> &vis, vector<vector<int>> &mat, vector<string> &ans, string move){
        if(i==n-1 && j==n-1){
            ans.push_back(move);
            return;
        }
        
        //down
        if(i+1<n && !vis[i+1][j] && mat[i+1][j]==1){
            vis[i][j]=1;
            solve(i+1,j,n,vis,mat,ans,move+'D'); 
            vis[i][j]=0;
        }
        
        //left
        if(j-1>=0 && !vis[i][j-1] && mat[i][j-1]==1){
            vis[i][j]=1;
            solve(i,j-1,n,vis,mat,ans,move+'L'); 
            vis[i][j]=0;
        }
        
        //right
        if(j+1<n && !vis[i][j+1] && mat[i][j+1]==1){
            vis[i][j]=1;
            solve(i,j+1,n,vis,mat,ans,move+'R'); 
            vis[i][j]=0;
        }
        
        //up
        if(i-1>=0 && !vis[i-1][j] && mat[i-1][j]==1){
            vis[i][j]=1;
            solve(i-1,j,n,vis,mat,ans,move+'U'); 
            vis[i][j]=0;
        }
    }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        vector<vector<int>> vis(n,vector<int> (n,0)); //to make a visited array and mmark all the positions as 0 as we haven't visit and cell
        vector<string> ans;
        if(mat[0][0]==1) solve(0,0,n,vis,mat,ans,""); 
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
