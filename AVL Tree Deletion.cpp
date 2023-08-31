void getElements(Node* root, vector<int>& inorder, int data){
    if(!root)
        return;
    getElements(root -> left, inorder, data);
    if(data != root -> data)
        inorder.push_back(root -> data);
    getElements(root -> right, inorder, data);
}

Node* getBalancedTree(vector<int> elements, int height){
    if(elements.size() == 0){
        return NULL;
    }
    int mid = elements.size() >> 1;
    Node* temp = new Node(elements[mid]);
    temp -> height = height;
    if(elements.size() == 1){
        
        return temp;
    }
    vector<int> left(elements.begin(), elements.begin() + mid), right(elements.begin() + mid + 1, elements.end());
    temp -> left = getBalancedTree(left, height + 1);
    temp -> right = getBalancedTree(right, height + 1);
    return temp;
    
}

Node* deleteNode(Node* root, int data)
{
    vector<int> inorder;
    getElements(root, inorder, data);
    return getBalancedTree(inorder, 1);
}
