class BrowserHistory {
    private List<String> history;
    private int currentIndex;
    
    public BrowserHistory(String homepage) {
        history = new ArrayList<>();
        history.add(homepage);
        currentIndex = 0;
    }
    
    public void visit(String url) {
        // Remove all the URLs after the current index
        int n = history.size();
        for (int i = n - 1; i > currentIndex; i--) {
            history.remove(i);
        }
        // Add the new URL to the end of the history
        history.add(url);
        currentIndex = history.size() - 1;
    }
    
    public String back(int steps) {
        currentIndex = Math.max(currentIndex - steps, 0);
        return history.get(currentIndex);
    }
    
    public String forward(int steps) {
        int n = history.size();
        currentIndex = Math.min(currentIndex + steps, n - 1);
        return history.get(currentIndex);
    }
}
