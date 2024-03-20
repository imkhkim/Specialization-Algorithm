import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        
        String[] sNum = new String[numbers.length];
        for(int i=0; i<numbers.length; i++) {
            sNum[i] = Integer.toString(numbers[i]);
        }

        Arrays.sort(sNum, new Comparator<String>(){
            @Override
            public int compare(String o1, String o2){
                return (o2 + o1).compareTo(o1 + o2);
            }
        });
        
        if(sNum[0].equals("0"))  return "0";
                
        for(String ele : sNum) {
            answer += ele;
        }
        
        
        return answer;
    }
}