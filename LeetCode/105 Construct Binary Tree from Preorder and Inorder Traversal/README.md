难度符号说明（仅代表个人）：

 - ？多次思考可以尝试解决

思路：

- 给出一种速度比较快的

  - ```cpp
    class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            for(int i=0;i<inorder.size();i++) {
                inMap[inorder[i]]=i;
            }
            return createNode(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        }
        
        TreeNode* createNode(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd) {
            if (iStart>iEnd || pStart>pEnd) {
                return nullptr;
            }
            
            TreeNode* node = new TreeNode(preorder[pStart]);
            int inorderIdx = inMap[preorder[pStart]];
            
            node->left = createNode(preorder,pStart+1,pStart+inorderIdx-iStart, inorder,iStart,inorderIdx-1);
            node->right = createNode(preorder,pStart+inorderIdx-iStart+1,pEnd,inorder,inorderIdx+1,iEnd);
            return node;
        }
    private:
        unordered_map<int,int> inMap;//inorder val,idx map
    };
    ```

  - 巧在如何使用map，他把中序遍历时的值当作key，其索引当作map中的值

- 我提交的代码，思路跟其差不多，没有借助map。

  - 从先序中找到根节点，在从中序中找到根节点左边的节点和根节点右边的节点
  - 递归建树。



- 考虑如何用中序和后序建树？

  - ```cp
    auto inRoot = find(inBeg, inEnd, root->val);
    root->left = buildTree(inBeg, inRoot, postBeg, next(postBeg, inRoot-inBeg));
    root->right = buildTree(next(inRoot), inEnd, next(postBeg, inRoot-inBeg), prev(postEnd));
    ```

  - 更改些许代码