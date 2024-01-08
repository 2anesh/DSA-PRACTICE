class GfG
{
    Node mergeResult(Node node1, Node node2)
    {
        
        Node temp1 = node1;
        Node temp2 = node2;
        
        ArrayList<Integer> array = new ArrayList<Integer>();
        
        while(temp1!=null){
            array.add(temp1.data);
            temp1 = temp1.next;
        }
        
        while(temp2!=null){
            array.add(temp2.data);
            temp2 = temp2.next;
        }
        
        Collections.sort(array);
        
        Node head = null;
        Node tail = null;
        
        for(int i=(array.size()-1);i>=0;i--){
            Node newNode = new Node(array.get(i));
            
            if(head==null){
                head = tail = newNode;
            }
            else{
                while(tail.next!=null){
                    tail = tail.next;
                }
                tail.next = newNode;
                tail = newNode;
            }
        }
        
        return head;
    }
}
