/*** 
 * @Author: Archangel 781446156@qq.com
 * @Date: 2024-11-28 09:17:47
 * @LastEditTime: 2024-11-28 09:25:25
 * @LastEditors: Archangel 781446156@qq.com
 * @Description:  
 * @FilePath: \ClassTestCode\treeNode.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */
#include <iostream>
#include <queue>

using namespace std;

// 二叉树节点定义
struct TreeNode {
    int val;              // 节点值
    TreeNode* left;      // 左子节点
    TreeNode* right;     // 右子节点

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // 构造函数
};

// 插入函数：将值插入二叉树
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val); // 如果树为空，则返回新节点
    }
    if (val < root->val) {
        root->left = insert(root->left, val); // 递归插入左子树
    } else {
        root->right = insert(root->right, val); // 递归插入右子树
    }
    return root; // 返回根节点
}

// 层序遍历函数
void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return; // 如果树为空，直接返回
    }
    
    queue<TreeNode*> q; // 使用队列来支持层序遍历
    q.push(root); // 将根节点压入队列

    while (!q.empty()) {
        TreeNode* node = q.front(); // 获取队列头部节点
        q.pop(); // 弹出队列头部节点
        cout << node->val << " "; // 输出节点值
        
        // 将左子节点和右子节点压入队列
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}

int main() {
    TreeNode* root = nullptr; // 初始化树根
    root = insert(root, 5); 
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    cout << "层序遍历结果：";
    levelOrderTraversal(root); // 调用层序遍历函数
    cout << endl;

    return 0;
}
