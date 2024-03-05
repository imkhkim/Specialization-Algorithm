import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        
        List<Integer> list = new ArrayList<>();
        list.add(arr[0]);
        
        for (int e: arr) {
            if (list.get(list.size()-1) != e) list.add(e);
        }
        
        int[] answer = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        
        
        return answer;
    }
}