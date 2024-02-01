class Solution {
    public String defangIPaddr(String address) {
        String res = "";
        int n = address.length();
        for(int i = 0; i < n; i++){
            if(address.charAt(i) != '.'){
                res += address.charAt(i);
            }
            else{
                res += "[.]";
            }
        }

        return res;
    }
}