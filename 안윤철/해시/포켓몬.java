import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        
        Set<Integer> set = new HashSet<>();
        for (int n: nums) {
            set.add(n);
        }
        
        for (int n: set) {
            answer += 1;
        }
        
        if (answer > nums.length/2) answer = nums.length/2;
        
        return answer;
    }
    
    private static void pick() {
        Set<Integer> set = new HashSet<>();
    }
}