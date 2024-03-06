import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        
        // KEY - VALUE
        Set<String> set = new HashSet<>();
        
        for (String phone: phone_book) {
            set.add(phone);
        }
        
        for (String number: phone_book) {
            for (int i = 0; i < number.length(); i++) {
                String subStr = number.substring(0, i);
                if (set.contains(subStr)) return false;
            }
        }
        
        return true;
    }
}