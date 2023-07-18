class Node {
    public int key, val;
    public Node next, pre;
    public Node(int key, int val) {
        this.key = key;
        this.val = val;
    }
}

class DoubleList {
    private Node head, tail;
    private int size;
    public DoubleList() {
        this.head = new Node(0, 0);
        this.tail = new Node(0, 0);
        this.head.next = this.tail;
        this.tail.pre = this.head;
        this.size = 0;
    }

    public void addLast(Node x) {
        Node predessor = tail.pre;
        predessor.next = x;
        x.next = tail;
        x.pre = predessor;
        tail.pre = x;
        size++;

    }

    public void remove(Node x) {
        x.pre.next = x.next;
        x.next.pre = x.pre;
        size--;
    }

    public Node removeFirst() {
        if (head.next == tail) {
            return head;
        }
        Node target = head.next;
        head.next = head.next.next;
        target.next.pre = head;
        size--;
        return target;
    }

    public int size() {
        return size;
    }
}
class LRUCache {
    private Map<Integer, Node> map;
    private int capacity;
    private DoubleList cache;

    public LRUCache(int capacity) {
        map = new HashMap<>();
        this.capacity = capacity;
        cache = new DoubleList();      
    }
    
    public int get(int key) {
        if (!map.containsKey(key)) {
            return -1;
        }
        makeRecent(key);
        return map.get(key).val;
    }

    private void makeRecent(int key) {
        Node node = map.get(key);
        cache.remove(node);
        cache.addLast(node);
    }

    private void addRecent(int key, int val) {
        Node node = new Node(key, val);
        cache.addLast(node);
        map.put(key, node);
    }

    private void delete(int key) {
        cache.remove(map.get(key));
        map.remove(key);
    }

    private void removeLeastUsed() {
        Node first = cache.removeFirst();
        map.remove(first.key);
    }
    
    public void put(int key, int value) {
        if (map.containsKey(key)) {
            Node oldNode = map.get(key);
            delete(key);
            addRecent(key, value);
        } else{
            if (capacity == cache.size()) {
                removeLeastUsed();
            }
            addRecent(key, value);
        }
        
    }
}
