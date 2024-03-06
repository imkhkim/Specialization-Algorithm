import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        
        Map<String, List<String>> clothes_hash = new HashMap<>();
        
        for (String[] s_arr: clothes) {
            if (clothes_hash.containsKey(s_arr[1])) 
                clothes_hash.get(s_arr[1]).add(s_arr[0]);
            else {
                List<String> list = new ArrayList<>();
                list.add(s_arr[0]);
                clothes_hash.put(s_arr[1], list);
            }
                
        }
        
        for (String k: clothes_hash.keySet()) {
            answer *= (clothes_hash.get(k).size()+1);
        }
        
        return answer-1;
    }
}