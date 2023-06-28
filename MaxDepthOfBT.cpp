//https://practice.geeksforgeeks.org/problems/maximum-depth-of-binary-tree/1
int maxDepth(Node *root) {
         queue<Node*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int size = q.size();
            cnt++;
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return cnt;
    }
