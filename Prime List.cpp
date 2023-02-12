class Solution{

    bool isprime(int n){

        for(int i=2;i*i<=n;i++){

            if(n%i==0){

                return false;

            }

        }

        return true;

    }

public:

    Node *primeList(Node *head){

        Node* curr=head;

        while(curr){

            int diff=INT_MAX;

            int mini=INT_MAX;

            if(curr->val==1){

                curr->val=2;

            }

            int x=curr->val;

            int y=curr->val;

            while(!isprime(x)){

                x++;

            }

            diff=abs(curr->val-x);

            mini=x;

            while(!isprime(y)&&y>1){

                y--;

            }

            if(abs(curr->val-y)<=diff){

                diff=abs(curr->val-y);

                mini=y;

            }

            curr->val=mini;

            curr=curr->next;

        }

        return head;

    }

};
