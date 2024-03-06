import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Map<String, Integer> map = new HashMap<>();
        
        for (String s: participant) {
            if (!map.containsKey(s)) {
                map.put(s, 1);
            } else {
                map.put(s, map.get(s)+1);
            }
        }
        
        for (String c: completion) {
            if (map.containsKey(c)) {
                map.put(c, map.get(c)-1);
            }
        }
        
        for (String k: map.keySet()) {
            if (map.get(k) > 0) answer = k;
        }
        
        // System.out.println(map);
        
        return answer;
    }
}