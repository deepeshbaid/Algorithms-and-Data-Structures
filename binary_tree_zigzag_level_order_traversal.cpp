#include <iostream>
#include <vector>
#include <stack>
using namespace std;

    //https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

    //   TREE STRUCTURE USED FOR EXAMPLE
    //         5
    //       /   \
    //      4     8
    //     /     / \ 
    //   11    13  4
    //   /  \      / \
    //  7    2    5   1


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> v;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        if(root)s1.push(root);
        while(!s1.empty() || !s2.empty())
        {
            while(!s1.empty())
            {
                TreeNode* tmp=s1.top();s1.pop();
                if(tmp->left)s2.push(tmp->left);
                if(tmp->right)s2.push(tmp->right);
                v.push_back(tmp->val);
            }
            if(v.size()>0)ans.push_back(v);
            v.clear();
            while(!s2.empty())
            {
                TreeNode* tmp=s2.top();s2.pop();
                if(tmp->right)s1.push(tmp->right);
                if(tmp->left)s1.push(tmp->left);
                v.push_back(tmp->val);
            }
            if(v.size()>0)ans.push_back(v);
            v.clear();
        }
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
};



int main() {
  Solution T;
	TreeNode *root=new TreeNode(5);
	root->left=new TreeNode(4);
	root->left->left=new TreeNode(11);
	root->left->left->left=new TreeNode(7);
	root->left->left->right=new TreeNode(2);
	root->right=new TreeNode(8);
	root->right->left=new TreeNode(13);
	root->right->right=new TreeNode(4);
	root->right->right->right=new TreeNode(1);
	root->right->right->left=new TreeNode(5);

	T.zigzagLevelOrder(root);
	
	return 0;
}
