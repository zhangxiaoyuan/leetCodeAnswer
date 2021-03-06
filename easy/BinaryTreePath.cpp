/*
Q：给出一个二叉树，然后返回每一条从根节点到不同叶子节点的不重复路径，并打印出来路径 

U：https://leetcode.com/problems/binary-tree-paths/

A:采用一个vector<string>保存需要返回的所有结果集，从根节点开始采用中序遍历，每遍历一个节点，将节点值加入到vector<int>中，
直到到达一个了叶子节点，此时把vector<int>中的所有数据拼装成字符串并push_back到vector<string>结果集中，然后将此叶子节点
pop_back弹出vector<int>，然后再去轮询叶子节点父节点的右子树，以此类推，采用递归左右子树。直到所有路径全部找出为止返回。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <vector>
 #include <string>
 #include <sstream>
 using namespace std;

class Solution {
public:

    /*
    string convertRes(const vector<int>& nodeVec)
    {
        string str;
        
        if (!nodeVec.empty())
        {
            int i = 0;
            for(;i < (nodeVec.size() - 1); i++)
            {
                stringstream ss;
			    ss << nodeVec.at(i);
			    str.append(ss.str());	
			    str.append("->");
            }
            
            stringstream ss;
		    ss << nodeVec.at(i);
		    str.append(ss.str());
        }
        
        return str;
    }
    */
    string convertRes(const vector<int>& nodeVec)
    {
        string str;
        if (!nodeVec.empty())
        {
            int i = 0;
            for(;i < nodeVec.size() -1; i++)
            {
                str += to_string(nodeVec.at(i)) + "->";
            }
            
            str += to_string(nodeVec.at(i));
        }
        
        return str;
    }
    
    void parseNode(TreeNode* node)
    {
        m_nodeVec.push_back(node->val);
        
        if (node->left == NULL && NULL == node->right)
        {
            string str = convertRes(m_nodeVec);
            m_strVec.push_back(str);
            
            m_nodeVec.pop_back();
            
            return;
        }
        
        if (node->left != NULL)
        {
            parseNode(node->left);
        }
        
        if (node->right != NULL)
        {
            parseNode(node->right);
        }
        
        m_nodeVec.pop_back();
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if (NULL == root)
        {
            return m_strVec;
        }
        
        parseNode(root);
        
        return m_strVec;
    }
    
private:
    vector<string> m_strVec;
    vector<int> m_nodeVec;
};


/*最优解：不需要单独用vector<int>存储每一个节点的值，因为递归的时候返回会自动回退到上一步，所以每一步只需要去构造结果string即可*/
class Solution {
public:
    
    void parseNode1(TreeNode* root, string str)
    {
        if(root->left == NULL && root->right == NULL)
       	{
            m_strVec.push_back(str + to_string(root->val));
            return;
       	}   
        if(root->left != NULL)
            parseNode1(root->left, str + to_string(root->val) + "->");
            
        if(root->right != NULL)
           parseNode1(root->right, str + to_string(root->val) + "->");
    }
    
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if (NULL != root)
        {
            string str = "";
            parseNode1(root, str);
        }
        
        return m_strVec;
    }
    
private:
    vector<string> m_strVec;
};
