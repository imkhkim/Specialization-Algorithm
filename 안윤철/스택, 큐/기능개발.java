import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int length = progresses.length;
        int[] working = new int[length];
        List<Integer> answer_list = new ArrayList<>();
        
        for (int i = 0; i < length; i++) {
            int time = (100-progresses[i])/speeds[i];
            int key = (100-progresses[i])%speeds[i];
            
            if (key == 0) working[i] = time;
            else working[i] = time+1;
        }
                
        // 7 3 9
        // 5 10 1 10 1 20 1
        int count = 0;
        int s = working[0];
        for (int i = 1; i < length; i++) {
            count += 1;
            if (s < working[i]) {
                answer_list.add(count);
                count = 0;
                s = working[i];
            }
        }
        answer_list.add(count+1);
        
        int[] answer = new int[answer_list.size()];
        for (int i = 0; i < answer_list.size(); i++) {
            answer[i] = answer_list.get(i);
        }
        
        return answer;
    }
}