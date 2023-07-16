#include <iostream>
#include <vector>
#include <queue>
#include "BinaryTreeNode.cpp"

using namespace std;

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "enter the rootData";
    cin >> rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        cout << "Enter the leftData of"
             << " " << front->data;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *left = new BinaryTreeNode<int>(leftData);
            front->left = left;
            pendingNodes.push(front->left);
        }
        int rightData;
        cout << "enter the rightData of"
             << " " << front->data;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *right = new BinaryTreeNode<int>(rightData);
            front->right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}

vector<vector<int>> printLevelWise(BinaryTreeNode<int> *root)
{
    vector<int> temp;
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        int size = pendingNodes.size();
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            temp.push_back(front->data);
            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
        }
        ans.push_back(temp);
        temp.clear();
    }
    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    vector<vector<int>> ans = printLevelWise(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}