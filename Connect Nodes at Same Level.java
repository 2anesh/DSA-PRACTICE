class Solution {

    public void connect(Node root) {

        

        Queue<Node> q = new LinkedList<>();

        q.offer(root);

        while(!q.isEmpty()) {

            int levelSize = q.size();

            Node prev = null;

            for(int i = 0; i < levelSize; i++) {

                Node curr = q.poll();

                if(curr.left != null) {

                    q.offer(curr.left);

                }

                if(curr.right != null) {

                    q.offer(curr.right);

                }

                if(prev != null) {

                    prev.nextRight = curr;

                }

                prev = curr;

            }

        }

    }

}
