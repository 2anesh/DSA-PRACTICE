class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        // Create a list of employees to represent the tree structure
        List<List<Integer>> employees = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            employees.add(new ArrayList<>());
        }

        // Build the tree structure using the manager array
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                employees.get(manager[i]).add(i);
            }
        }

        // Call the recursive helper function to calculate the time needed for each employee
        return informSubordinates(headID, employees, informTime);
    }
    private int informSubordinates(int currentEmployee, List<List<Integer>> employees, int[] informTime) {
        int maxTime = 0;

        // Iterate over the subordinates of the current employee
        for (int subordinate : employees.get(currentEmployee)) {
            // Calculate the time needed to inform the subordinate and recursively inform its subordinates
            int time = informSubordinates(subordinate, employees, informTime);
            maxTime = Math.max(maxTime, time);
        }

        // Return the total time needed for the current employee and its subordinates
        return maxTime + informTime[currentEmployee];
    }
}
