Node* segregate(Node *head) {
        
        // Add code here
        int c_0 = 0, c_1 = 0, c_2 = 0;
        
        Node *temp = head;
        while(temp!=NULL){
            if(temp->data == 0) c_0++;
            else if(temp->data == 1) c_1++;
            else c_2++;
            
            temp = temp->next;
        }
        temp = head;
        while(c_0--){
            temp->data = 0;
            temp = temp->next;
        }
        while(c_1--){
            temp->data = 1;
            temp = temp->next;
        }
        while(c_2--){
            temp->data = 2;
            temp = temp->next;
        }
        return head;
    }
