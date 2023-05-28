class Solution
{
    //Function to find the data of nth node from the end of a linked list.
    int getNthFromLast(Node head, int n)
    {
    	// Your code here
    	int len=0;
    	Node temp=head;
    	while(temp!=null){
    	    len++;
    	    temp=temp.next;
    	}
    	if(n>len)return -1;
    	
        temp=head;
        int ind=1;
        while(ind<=len && ind!=len-(n-1)){
            temp=temp.next;
            ind++;
        }
    	return temp.data;
    }
}
