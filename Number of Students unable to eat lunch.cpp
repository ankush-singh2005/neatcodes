class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> res;
        for(int i=0;i<students.size();i++){
            res.push(students[i]);
        }
        int count=0;
        int i=0;
        while(res.size()>0 && count!=res.size()){
            if(res.front()!=sandwiches[i]){
                res.push(res.front());
                res.pop();
                count++;
            }
            else{
                i++;
                res.pop();
                count=0;
            }
        }
        return res.size();
    }
};
