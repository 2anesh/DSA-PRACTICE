class Solution
{
  public:

    void InorderTravarsal(Node *root, vector<Node*>&nodes)
    {
        if(!root)return;
        InorderTravarsal(root -> left, nodes);
        nodes.push_back(root);
        InorderTravarsal(root -> right, nodes);
    }
    Node *bTreeToCList(Node *root)
    {
        vector<Node*>nodes;
        InorderTravarsal(root, nodes);
        if(nodes.size() == 0)return NULL;
        Node* result = nodes[0];
        int n = nodes.size();
        // return result;
        for(int i = 0; i < n; i++)
        {
            auto curr_node = nodes[i];
            if(i == 0)
            {
                if(n <= 1)continue;
                curr_node -> right = nodes[i + 1];
                curr_node -> left = nodes[n - 1];
            }
            else if(i == n - 1)
            {
                if(n <= 1)continue;
                curr_node -> right = nodes[0];
                curr_node -> left = nodes[i - 1];
            }
            else
            {
                curr_node -> left = nodes[i - 1];
                curr_node -> right = nodes[i + 1];
            }
        }
        return result;
    }
};
