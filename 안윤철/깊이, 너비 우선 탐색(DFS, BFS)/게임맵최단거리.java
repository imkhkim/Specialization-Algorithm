import java.util.*;
class Solution {
    
    static int N;
    static int M;
    
    static class Point {
        int r;
        int c;
        
        Point(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
    
    public int solution(int[][] maps) {
        int answer = 0;
        N = maps.length;
        M = maps[0].length;
        
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (maps[r][c] == 1) maps[r][c] = 10001;
            }
        }
        maps[0][0] = 1;
        
        bfs(maps, new Point(0, 0));
        return maps[N-1][M-1] == 10001 ? -1: maps[N-1][M-1];
    }
    
    private static int[] dr = {0, 0, 1, -1};
    private static int[] dc = {1, -1, 0, 0};
    
    private static void bfs(int[][] maps, Point p) {
        Queue<Point> queue = new LinkedList<>();
        queue.offer(new Point(p.r, p.c));
        
        while (!queue.isEmpty()) {
            Point point = queue.poll();
            int r = point.r;
            int c = point.c;
            
            for (int i = 0; i < 4; i++) {
                int mr = r + dr[i];
                int mc = c + dc[i];
                
                if (mr >= 0 && mr < N && mc >= 0 && mc < M) {
                    if (maps[r][c] + 1 < maps[mr][mc]) {
                        maps[mr][mc] = maps[r][c] + 1;
                        queue.offer(new Point(mr, mc));
                    }
                }
            }
        }
    }
    
//     private static void recursive(int[][] maps, int r, int c) {
        
//         for (int i = 0; i < 4; i++) {
//             int mr = r + dr[i];
//             int mc = c + dc[i];
            
//             if (mr >= 0 && mr < N && mc >= 0 && mc < M) {
//                 if (maps[r][c] + 1 < maps[mr][mc]) {
//                     maps[mr][mc] = maps[r][c] + 1;
//                     recursive(maps, mr, mc);
//                 }
//             }
//         }
//     }
}