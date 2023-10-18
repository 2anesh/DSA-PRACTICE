class Solution {
    public int minimumTime(int n, int[][] relations, int[] time) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i =0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] relation : relations) {
            int prevCourse = relation[0];
            int nextCourse = relation[1];
            graph.get(prevCourse).add(nextCourse);
        }

        int[] inDegree = new int[n + 1];
        for (int[] relation : relations) {
            int nextCourse = relation[1];
            inDegree[nextCourse]++;
        }

        Queue<Integer> queue = new LinkedList<>();

        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }

        int[] completionTime = new int[n + 1];
        int minTime = 0;

        while (!queue.isEmpty()) {
            int course = queue.poll();
            minTime = Math.max(minTime, completionTime[course] + time[course - 1]);

            for (int nextCourse : graph.get(course)) {
                inDegree[nextCourse]--;
                completionTime[nextCourse] = Math.max(completionTime[nextCourse], completionTime[course] + time[course - 1]);
                if (inDegree[nextCourse] == 0) {
                    queue.offer(nextCourse);
                }
            }
        }

        return minTime;
    }
}
