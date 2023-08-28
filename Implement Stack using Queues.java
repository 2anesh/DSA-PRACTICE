class MyStack {
    private Queue<Integer> q1;
    private Queue<Integer> q2;

    /** Initialize your data structure here. */
    public MyStack() {
        q1 = new LinkedList<>();
        q2 = new LinkedList<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        q1.add(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        while (q1.size() > 1) {
            q2.add(q1.poll());
        }
        int rst = q1.poll();
        swap();
        return rst;
    }

    /** Get the top element. */
    public int top() {
        while (q1.size() > 1) {
            q2.add(q1.poll());
        }
        int rst = q1.poll();
        q2.add(rst);
        swap();
        return rst;
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q1.isEmpty();
    }

    /** Swap the two queues. */
    private void swap() {
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;
    }
}
