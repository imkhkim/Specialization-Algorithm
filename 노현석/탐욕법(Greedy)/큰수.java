class Solution {
    public String solution(String number, int k) {
        String answer = "";
        
        int idx = 0;
        for(int i=0; i<number.length() - k; i++) {
            int max = 0;
            for(int j=idx; j<=k + i; j++) {
                if(max < number.charAt(j) - '0') {
                    max = number.charAt(j)-'0';
                    idx = j+1;
                }
            }
            answer+=max;
        }
        
        return answer;
    }
}