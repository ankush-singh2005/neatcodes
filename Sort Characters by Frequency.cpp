class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        map<int,vector<char>> m2;

      //finding the frequency of each character in the string
        for(auto value:s){
            m[value]++;
        }

      //making a new array and making the key if m and the value of m2 and value of m as the key of m2
      // First map : {'a':2,'b':1,'c':2};
      // Second map : {-2 : {'a','c'} , -1 : {'b}};
        for(auto value:m){
            m2[-value.second].push_back(value.first);
        }

        string res="";
      
        for(auto value:m2){
          //taking the array that is present in the second map
            for(auto value1:value.second){
                string temp="";
                for(int i=0;i<-value.first;i++){
                    temp+=value1;
                }
                res=res+temp;
            }
        }
        return res;
    }
};
