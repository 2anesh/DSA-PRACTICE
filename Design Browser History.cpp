class BrowserHistory {
    
//     Node doubly linked list
   class Node{
        public:
        string url;
        Node* next = NULL;
        Node* prev = NULL;
     };
    
     Node* head = NULL;
     Node* tail = NULL;
     Node* current = NULL;
public:
    BrowserHistory(string homepage) {
        Node* newNode = new Node;
        newNode->url = homepage;
        head = tail = current = newNode;
    }
    
    void visit(string url) {
        Node* tempCurrent = current->next;
        while(tempCurrent != NULL){
            Node* tempHold = tempCurrent->next;
            delete tempCurrent;
            tempCurrent = tempHold;
        }
        current->next = new Node;
        current->next->url = url;
        current->next->prev = current;
        current = current->next;
        tail = current;
    }
    
    string back(int steps) {
        int x = 0;
        while(current != head && x < steps){
            current = current->prev;
            x++;
        }
        return current->url;
    }
    
    string forward(int steps) {
        int x = 0;
        while(current != tail && x < steps){
            current = current->next;
            x++;
        }
        return current->url;
    }
};
