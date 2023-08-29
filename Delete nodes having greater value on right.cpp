class Solution
{
    public:
    Node *goFind(Node **head, int &valBigger) {
        if(!(*head)) {
            return *head;
        }
        Node *nextOne = goFind(&((*head)->next), valBigger);
        if((*head)->data >= valBigger) {
            valBigger = (*head)->data;
            return (*head);            
        }
        return (*head) = nextOne;
    }
    
    Node *compute(Node *head)
    {
        int valBigger = INT_MIN;
        goFind(&head, valBigger);
        return head;
    }
    
};
