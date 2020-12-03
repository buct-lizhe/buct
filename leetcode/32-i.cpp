#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> vc;
queue<TreeNode*> queueTree;

//层序遍历
vector<int> levelOrder(TreeNode* root) {
    if( root == NULL )
        return vc;
    vc.push_back( root->val );
    queueTree.push( root->left );
    queueTree.push( root->right );
    while ( !queueTree.empty() )
    {
        /* code */
        TreeNode* t = queueTree.front();
        queueTree.pop();
        if( t != NULL ){
            vc.push_back( t->val );
            if( t->left != NULL)
                queueTree.push( t->left );
            if( t->right != NULL)
                queueTree.push( t->right );
        }
    }
    return vc;
}

int main()
{

}