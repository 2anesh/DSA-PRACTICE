class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = profits.length;
        // create a list of projects with their corresponding capital and profit
        List<int[]> projects = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            projects.add(new int[]{capital[i], profits[i]});
        }
        // sort projects by their capital in ascending order
        Collections.sort(projects, (a, b) -> a[0] - b[0]);

        // use a max heap to store projects with maximum profit
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        int i = 0;
        while (k-- > 0) {
            // add all affordable projects to the max heap
            while (i < n && projects.get(i)[0] <= w) {
                maxHeap.offer(projects.get(i)[1]);
                i++;
            }
            // if there are no affordable projects, break the loop
            if (maxHeap.isEmpty()) {
                break;
            }
            // select the project with maximum profit and add its profit to capital
            w += maxHeap.poll();
        }
        return w;
    }
}
