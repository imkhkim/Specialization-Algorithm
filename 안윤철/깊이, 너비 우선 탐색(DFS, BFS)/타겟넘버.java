class Solution {
    
    private static int answer = 0;
    public int solution(int[] numbers, int target) {
        recursive(numbers, target, 0, 0);
        return answer;
    }
    
    private static void recursive(int[] numbers, int target, int current, int idx) {
        if (numbers.length == idx) {
            if (target == current) {
                answer += 1;
            }
            return;
        }
        
        recursive(numbers, target, current + numbers[idx], idx+1);
        recursive(numbers, target, current - numbers[idx], idx+1);  
    }
}