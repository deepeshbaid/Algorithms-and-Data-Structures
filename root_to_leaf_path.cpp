#include <iostream>
#include <vector>
using namespace std;

    //problem - https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(root,sum,ans,tmp);
        print(ans);
        return ans;
    }
    void solve(TreeNode* root, int sum,vector<vector<int>> &ans,vector<int> &tmp)
    {
        if(root==NULL)return;
        
        sum=sum-root->val;
        
        tmp.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL)
            {
                if(sum==0)
                {
                    ans.push_back(tmp);
                }
                sum=sum+tmp.back();
                tmp.pop_back();
            }
            else
            {
                solve(root->left,sum,ans,tmp);
                solve(root->right,sum,ans,tmp);
                sum=sum+tmp.back();
                tmp.pop_back();
            }
        
    }
    void print(vector<vector<int>> &ans)
    {
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

	T.pathSum(root,22);
	
	return 0;
}
