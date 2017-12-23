package io.imsure.solutions;

import io.imsure.common.UnionFind;

import java.util.*;

public class _305 {

    // Brute Force (TLE)
    public static class Solution1 {
        void dfs(char[][] grid, int r, int c, boolean[][] visited) {
            int nr = grid.length;
            int nc = grid[0].length;

            if (r < 0 || c < 0 || r >= nr || c >= nc || grid[r][c] == '0' || visited[r][c]) {
                return;
            }

            visited[r][c] = true;
            dfs(grid, r - 1, c, visited);
            dfs(grid, r + 1, c, visited);
            dfs(grid, r, c - 1, visited);
            dfs(grid, r, c + 1, visited);
        }

        public int numIslands(char[][] grid) {
            if (grid == null || grid.length == 0) {
                return 0;
            }

            int nr = grid.length;
            int nc = grid[0].length;
            boolean[][] visited = new boolean[nr][nc];
            for (boolean[] row : visited) {
                Arrays.fill(row, false);
            }
            int num_islands = 0;
            for (int r = 0; r < nr; ++r) {
                for (int c = 0; c < nc; ++c) {
                    if (grid[r][c] == '1' && !visited[r][c]) {
                        ++num_islands;
                        dfs(grid, r, c, visited);
                    }
                }
            }

            return num_islands;
        }

        public List<Integer> numIslands2(int m, int n, int[][] positions) {
            List<Integer> ans = new ArrayList<>();
            char[][] grid = new char[m][n];
            for (char[] row : grid) {
                Arrays.fill(row, '0');
            }
            for (int[] pos : positions) {
                grid[pos[0]][pos[1]] = '1';
                ans.add(numIslands(grid));
            }
            return ans;
        }
    }

    // Ad hoc
    public static class Solution2 {
        public List<Integer> numIslands2(int m, int n, int[][] positions) {
            List<Integer> ans = new ArrayList<>();
            HashMap<Integer, Integer> land2id = new HashMap<Integer, Integer>();
            int num_islands = 0;
            int island_id = 0;

            for (int[] pos : positions) {
                int r = pos[0], c = pos[1];
                Set<Integer> overlap = new HashSet<Integer>();

                if (r - 1 >= 0 && land2id.containsKey((r-1) * n + c)) {
                    overlap.add(land2id.get((r-1) * n + c));
                }
                if (r + 1 < m && land2id.containsKey((r+1) * n + c)) {
                    overlap.add(land2id.get((r+1) * n + c));
                }
                if (c - 1 >= 0 && land2id.containsKey(r * n + c - 1)) {
                    overlap.add(land2id.get(r * n + c - 1));
                }
                if (c + 1 < n && land2id.containsKey(r * n + c + 1)) {
                    overlap.add(land2id.get(r * n + c + 1));
                }

                if (overlap.isEmpty()) {
                    ++num_islands;
                    land2id.put(r * n + c, island_id++);
                } else if (overlap.size() == 1) {
                    land2id.put(r * n + c, overlap.iterator().next());
                } else {
                    int root_id = overlap.iterator().next();
                    for (Map.Entry<Integer, Integer> entry : land2id.entrySet()) {
                        int k = entry.getKey();
                        int id = entry.getValue();
                        if (overlap.contains(id)) {
                            land2id.put(k, root_id);
                        }
                    }
                    land2id.put(r * n + c, root_id);
                    num_islands -= (overlap.size() - 1);
                }
                ans.add(num_islands);
            }

            return ans;
        }
    }

    public static class Solution3 {
        public List<Integer> numIslands2(int m, int n, int[][] positions) {
            List<Integer> ans = new ArrayList<>();
            UnionFind uf = new UnionFind(m * n);

            for (int[] pos : positions) {
                int r = pos[0], c = pos[1];
                List<Integer> overlap = new ArrayList<>();

                if (r - 1 >= 0 && uf.isValid((r-1) * n + c)) overlap.add((r-1) * n + c);
                if (r + 1 < m && uf.isValid((r+1) * n + c)) overlap.add((r+1) * n + c);
                if (c - 1 >= 0 && uf.isValid(r * n + c - 1)) overlap.add(r * n + c - 1);
                if (c + 1 < n && uf.isValid(r * n + c + 1)) overlap.add(r * n + c + 1);

                int index = r * n + c;
                uf.setParent(index);
                for (int i : overlap) uf.union(i, index);
                ans.add(uf.getCount());
            }

            return ans;
        }
    }

    public static void main(String[] args) {
        int[][] positions1 = new int[][] {
                {0,0}, {0,1}, {1,2}, {2,1}
        };
        int[][] positions2 = new int[][] {
                {0,1}, {1,2}, {2,1}, {1,0}, {0,2}, {0,0}, {1,1},
        };
        // Solution1 sol = new Solution1();
        // Solution2 sol = new Solution2();
        Solution3 sol = new Solution3();
        List<Integer> ans = sol.numIslands2(3, 3, positions1);
        for (int i : ans) {
            System.out.println(i);
        }
        System.out.println();
        ans = sol.numIslands2(3, 3, positions2);
        for (int i : ans) {
            System.out.println(i);
        }
    }
}
