class Solution {
    public int lengthOfLastWord(String s) {
        String[] st=s.split(" ");
        String fin="";
        for(String i:st){
            fin=i;
        }
        return fin.length();
    }
}
