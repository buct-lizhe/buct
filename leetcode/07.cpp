#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* build( vector<int>& preorder, vector<int>& inorder , int preSta, int preLast, int inSta, int inLast ){
    if( preSta >= preLast || inSta >= inLast )
        return nullptr;
    int rootValue = preorder[ preSta ];
    TreeNode* tree = new TreeNode( preorder[ preSta ] );
    int count = 0;
    int index = -1;
    for( int i = inSta; i < inLast; i++ ){
        if( inorder[ i ] == rootValue ){
            index = i;
            break;
        }
        count++;
    } //找到中序遍历中头结点的下标
    tree->left = build( preorder , inorder , preSta+1 , preSta+1+count , inSta , index );  //建立左子树
    tree->right = build( preorder , inorder , preSta+1+count , preLast , index+1 , inLast );  //建立右子树
    return tree;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* treeNode = build( preorder , inorder, 0 , preorder.size() , 0 , inorder.size() );
    // TreeNode* T = treeNode;
    return treeNode;
}


int main()
{
    vector<int> preorder = {3,9,20,15,7}; 
    vector<int> inorder  = {9,3,15,20,7};
    TreeNode* t = buildTree(preorder,inorder);
    system( "pause" );

}