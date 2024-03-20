import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int s: scoville) {
            pq.offer(s);
        }

        while(true) {
            int min = pq.poll();
            if (min < K && !pq.isEmpty()) {
                pq.offer(min + pq.poll()*2);
                answer += 1;
            } else {
                pq.offer(min);
                break;
            }
        }

        if (!pq.isEmpty()) {
            if (pq.poll() < K)
                return -1;
        }

        return answer;
    }
}