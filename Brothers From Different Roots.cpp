class Solution
{
public:
void inorder(Node* root, unordered_set<int> &s)
    {
        if (root == NULL)
            return;
        inorder(root->left, s);
        s.insert(root->data);
        inorder(root->right, s);
    }
    
    int countPairs(Node* root1, Node* root2, int x)
    {
 unordered_set<int> s;
        inorder(root1, s);
        int count = 0;
        stack<Node*> st;
        Node* curr = root2;
        while (!st.empty() || curr != NULL)
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if (s.find(x - curr->data) != s.end())
                count++;
            curr = curr->right;
        }
        return count;
    }
};
