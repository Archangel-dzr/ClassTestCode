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

// �������ڵ㶨��
struct TreeNode {
    int val;              // �ڵ�ֵ
    TreeNode* left;      // ���ӽڵ�
    TreeNode* right;     // ���ӽڵ�

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // ���캯��
};

// ���뺯������ֵ���������
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val); // �����Ϊ�գ��򷵻��½ڵ�
    }
    if (val < root->val) {
        root->left = insert(root->left, val); // �ݹ����������
    } else {
        root->right = insert(root->right, val); // �ݹ����������
    }
    return root; // ���ظ��ڵ�
}

// �����������
void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return; // �����Ϊ�գ�ֱ�ӷ���
    }
    
    queue<TreeNode*> q; // ʹ�ö�����֧�ֲ������
    q.push(root); // �����ڵ�ѹ�����

    while (!q.empty()) {
        TreeNode* node = q.front(); // ��ȡ����ͷ���ڵ�
        q.pop(); // ��������ͷ���ڵ�
        cout << node->val << " "; // ����ڵ�ֵ
        
        // �����ӽڵ�����ӽڵ�ѹ�����
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}

int main() {
    TreeNode* root = nullptr; // ��ʼ������
    root = insert(root, 5); 
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    cout << "������������";
    levelOrderTraversal(root); // ���ò����������
    cout << endl;

    return 0;
}
