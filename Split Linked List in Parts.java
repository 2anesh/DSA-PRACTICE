class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        ListNode[] res = new ListNode[k];

        if (root == null) {
            return res;
        }

        ListNode curNode = root;
        int count = 0;

        while (curNode != null) {
            curNode = curNode.next;
            ++count;
        }

        int size = count / k, rem = count % k;

        curNode = root;
        for (int i = 0; i < k; i++) {
            ListNode head = curNode;
            for (int j = 0; j < size + (i < rem ? 1 : 0) - 1; j++) {
                if (curNode != null) {
                    curNode = curNode.next;
                }
            }

            
            if (curNode != null) {
                ListNode preNode = curNode;
                curNode = curNode.next;
                preNode.next = null;
            }
            res[i] = head;
        }
        return res;
    }
}
