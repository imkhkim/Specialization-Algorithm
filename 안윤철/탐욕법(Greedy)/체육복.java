import java.util.*;
import java.util.stream.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {

        List<Integer> students = new ArrayList<>();
        students = IntStream.rangeClosed(1, n)
                .boxed()
                .collect(Collectors.toCollection(ArrayList::new));

        List<Integer> reserveList = new ArrayList<>();
        reserveList = Arrays.stream(reserve)
                .boxed()
                .sorted()
                .collect(Collectors.toList());

        for (int i: lost) {
            if (students.contains(Integer.valueOf(i))) {
                students.remove(Integer.valueOf(i));
            }
        }

        for (int i: reserve) {
            if (!students.contains(Integer.valueOf(i))) {
                students.add(i);
                reserveList.remove(Integer.valueOf(i));
            }
        }

        for (int i: reserveList) {

            if (i-1 > 0 && !students.contains(Integer.valueOf(i-1))) {
                students.add(i-1);
                continue;
            }

            if (i+1 <= n && !students.contains(Integer.valueOf(i+1))) {
                students.add(i+1);
                continue;
            }
        }

        return students.size();
    }
}