//the intuition behind this solution is that we will take a set DS as it stores inly the unique elements
//in it. Then we will iterate though the set. For every element we check if there is an element just smaller to it present or not. Isse hum ye confirm kar lenge ki wo sequence ka starttung point hai ya ni
// for eg agar set m 102 101 4 100 1 3 2 hai to pehle 102 ke lie check karenge ki 101 present hai ya ni. agar present hai to hume ye pata chal gya ki sequence 102 se strt ni karega aur aage badenge. fir 101 me check karenge ki 100 h ya ni. kyuki 100 hai to forse aage badenge. fir 4 ke lie check karenge ki 3 hai ya ni aise aage badenge. jab 100 pe aaye tb dekhe ki 99 ni h set m. in this case we will find the length of the sequence agar wo exist kr rha hoga to. fir 1 pe jayenge aur check karenge ki 0 exist karta ya ni. kyuki theres no 0 so 1 should ne the startin gpoint and then we will look for the sequence and then funaaly find the length and then find the maximum amongst them.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=1;
        if(nums.size()==0) return 0;

        //taking a set as it stores only the unique elements in it.
        unordered_set<int> st;

        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(auto i:st){

            //emsuring that this is the starting point of the sequence
            if(st.find(i-1)==st.end()){
                int cnt=1;
                int ele=i;
                //checking if a consecutive element is presetn or not and then increasing the length of
                // the longest
                while(st.find(ele+1)!=st.end()){
                    cnt++;
                    ele=ele+1;
                }
                longest=max(longest,cnt);
            }
            else continue;
        }
        return longest;
    }
};