import java.util.*;
import java.util.stream.*;

class Solution {
    public String solution(String number, int k) {

        String answer = "";
        char[] chars = number.toCharArray();

        List<Integer> list = new String(chars)
                .chars()
                .mapToObj(c->Character.getNumericValue((char) c))
                .collect(Collectors.toList());

        // 4177252841
        // 477252841
        // 77252841
        // 775841

        int size = list.size();
        int i = 0;
        while (k-- > 0) {
            while (true) {

                // if (list.size() == i+1) {
                //     list.remove(i+1);
                //     i -= 1;
                //     break;
                // }

                // 8 9
                if (i >= list.size() - 1) {
                    list.remove(list.size() - 1);
                    i -= 1;
                    break;
                }

                if (list.get(i) < list.get(i+1)) {
                    list.remove(i);
                    if (i != 0) i -= 1;
                    break;
                }
                i++;
            }
        }

        return list.stream()
                .map(Object::toString)
                .collect(Collectors.joining());
    }
}