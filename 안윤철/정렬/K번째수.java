import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length]; int answerNum = 0;
        int[] tempArr = new int[commands.length]; int temp = 0;

        for (int i = 0; i < commands.length; i++) {
            temp = 0;
            tempArr = new int[commands[i][1] - commands[i][0] + 1];
            for (int j = commands[i][0]; j < commands[i][1] + 1; j++) {

                tempArr[temp] = array[j - 1];
                temp++;
            }
            Arrays.sort(tempArr);
            answer[answerNum] = tempArr[commands[i][2] - 1];
            answerNum++;
            tempArr = new int[commands.length];
        }

        return answer;
    }
}