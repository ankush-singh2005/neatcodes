class Solution {
    boolean check(char ch){
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
            return true;
        }
        return false;
    }

    public boolean isPalindrome(String s) {
        String temp="";
        for(int i=0;i<s.length();i++){
            if(check(s.charAt(i))){
                temp=temp+s.charAt(i);
            }
        }
        temp=temp.toLowerCase();
        int st=0;
        int e=temp.length()-1;
        while(st<=e){
            if(temp.charAt(st)!=temp.charAt(e)){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
}
