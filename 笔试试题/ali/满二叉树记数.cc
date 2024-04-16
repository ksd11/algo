#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v){
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

// 按层序遍历读数据
TreeNode* readData(){
    int val;
    cin >> val;
    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        cin >> val;
        if(val!=-1){
            TreeNode* left = new TreeNode(val);
            node->left = left;
            q.push(left);
        }

        cin >> val;
        if(val!=-1){
            TreeNode* right = new TreeNode(val);
            node->right = right;
            q.push(right);
        }
    }
    return root;
}

TreeNode* read(){
    int n;
    cin >> n; //节点数量
    vector<TreeNode*> nodes;
    for(int i=0;i<=n;i++){
        nodes.push_back(new TreeNode(0));
    }

    for(int i=1;i<=n;i++){
        int l, r;
        cin >> l >> r;
        if(l!=-1) nodes[i]->left = nodes[l];
        if(r!=-1) nodes[i]->right = nodes[r];
    }
    return nodes[1];
}

// 返回是否是满二叉树
bool full(TreeNode* root, int& res, int &height){
    if(!root){
        height = 0;
        return true;
    }

    int left, right;
    bool is_full_left = full(root->left, res, left);
    bool is_full_right = full(root->right, res, right);
    if(is_full_left && is_full_right && left == right){
        height = left + 1;
        res+=1;
        return true;
    }
    return false;
}


int main(int argc,char *argv[]){
    // auto root = readData();
    auto root = read();

    int res = 0;
    int height = 0;
    full(root, res, height);

    cout << res << endl;
    return 0;
}
