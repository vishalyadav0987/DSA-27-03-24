/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    // return parent Node
    // create parent mapping using L.O.T
    TreeNode *
    createMappingNodeToParent(TreeNode *root, int start,
                              map<TreeNode *, TreeNode *> &nodeToParent)
    {
        TreeNode *targetNode = NULL;
        queue<TreeNode *> q; // for LOT
        q.push(root);
        nodeToParent[root] = NULL; // mark null root
        // havent parent
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();

            // check for target Node
            if (front->val == start)
            {
                targetNode = front;
            }
            if (front->left)
            {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right)
            {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return targetNode;
    }
    void burnTime(TreeNode *targetNode, map<TreeNode *, TreeNode *> &nodeToParent,
                  int &minTime)
    {
        // create vistied node map
        // checking phle woh burn ho chucki hai ya nh
        map<TreeNode *, bool> visited;
        // using LOT

        queue<TreeNode *> q;
        q.push(targetNode);
        // visted true kar denge rrot node key liye
        visited[targetNode] = true;
        while (!q.empty())
        {
            bool flag = 0;
            // flag for i have element aya hai ki nh queue me
            // aur ushme ag lagi hai yah nh
            int size = q.size();
            // hume check karna hai sabhi node ke liye
            // jo queue me padi hai
            for (int i = 0; i < size; i++)
            {
                TreeNode *frontNode = q.front();
                q.pop();

                // we konw that;
                // node have three choice
                // 1. burn parent
                // 2. left child
                // 3. right child
                // if have aur visited true nh hai toh

                // 1. checking left me null toh hai
                //    aur woh node visted toh nh hai
                if (frontNode->left && !visited[frontNode->left])
                {
                    flag = 1;
                    q.push(frontNode->left);
                    visited[frontNode->left] = true;
                }
                // 2. checking right me null toh hai
                //    aur woh node visted toh nh hai
                if (frontNode->right && !visited[frontNode->right])
                {
                    flag = 1;
                    q.push(frontNode->right);
                    visited[frontNode->right] = true;
                }
                // 2. checking it have parent or not
                //    aur woh node visted toh nh hai
                if (nodeToParent[frontNode] &&
                    !visited[nodeToParent[frontNode]])
                {
                    flag = 1;
                    q.push(nodeToParent[frontNode]);
                    visited[nodeToParent[frontNode]] = true;
                }
            }
            if (flag == 1)
            {
                minTime++;
            }
        }
    }
    int amountOfTime(TreeNode *root, int start)
    {

        // steps:
        // 1. Creating mapping of node to parent
        map<TreeNode *, TreeNode *> nodeToParent;
        // target Node also return
        // 2. Find target Node
        TreeNode *targetNode =
            createMappingNodeToParent(root, start, nodeToParent);

        int minTime = 0;
        // 3. Minimum time to burn
        burnTime(targetNode, nodeToParent, minTime);

        return minTime;
    }
};