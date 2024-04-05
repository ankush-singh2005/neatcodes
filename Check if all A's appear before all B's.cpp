class Solution {
    public boolean checkString(String s) {
        for(int i=0;i<s.length()-1;i++){
            String st=s.charAt(i)+""+s.charAt(i+1);
            if(st.equals("ba"))
            return false;
        }
        return true;
    }
}
