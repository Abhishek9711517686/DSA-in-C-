/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator{
    stack<TreeNode*> myStack;
    // reverse->true->before
    // reverse->false->true
    bool reverse = true;

public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        PushAll(root);
    }

    bool hasNext(){
        return !myStack.empty();
    }

    int next(){
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) PushAll(tmpNode->right);
        else PushAll(tmpNode->left);
        return tmpNode->val;
    }

private:
    void PushAll(TreeNode* node){
        for(;node != NULL; ){
            myStack.push(node);
            if(reverse == true){
                node = node->right;
            }else{
                node = node->left;
            }
        }
    }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        // next
        BSTIterator l(root, false);
        // before
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};