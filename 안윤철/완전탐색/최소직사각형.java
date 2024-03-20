import java.util.*;

class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;

        int length = sizes.length;

        int latMax = sizes[0][0];
        int lonMax = sizes[0][1];
        int area = latMax * lonMax;
        for (int i = 1; i < length; i++) {
            int lat = sizes[i][0];
            int lon = sizes[i][1];

            if (Math.max(latMax, lat) * Math.max(lonMax, lon) > Math.max(lonMax, lat) * Math.max(latMax, lon)) {
                area = Math.max(lonMax, lat) * Math.max(latMax, lon);
                lonMax = Math.max(lonMax, lat);
                latMax = Math.max(latMax, lon);
            } else {
                area = Math.max(latMax, lat) * Math.max(lonMax, lon);
                lonMax = Math.max(lonMax, lon);
                latMax = Math.max(latMax, lat);
            }
        }

        return area;
    }
}