/**
 * 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:
[
   [5,4,11,2],
   [5,8,4,5]
]
提示：
节点总数 <= 10000
 * 
 * */

/**
 * 先序遍历+路径记录
 * */


#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> vcs;
vector<int> vc;



void dfs( TreeNode* root,  int s, int sum ){
    if( root->left == NULL && root->right == NULL ){
        if( s == sum ){
            vcs.push_back( vc );
            return;
        }
        else{
            return;
        }
    }
    if( root->left != NULL ){
        vc.push_back( root->left->val );
        dfs( root->left , s+root->left->val , sum );
        vc.pop_back();
    }
    if( root->right != NULL ){
        vc.push_back( root->right->val );
        dfs( root->right , s+root->right->val , sum );
        vc.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if( root == NULL )
        return vcs;
    vc.push_back( root->val );
    dfs( root , root->val , sum );
    vc.pop_back();
    return vcs;
}

int main()
{

}