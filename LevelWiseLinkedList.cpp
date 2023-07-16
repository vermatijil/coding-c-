#include <iostream>
#include <vector>
#include <queue>
#include "BinaryTreeNode.cpp"
#include "Node.cpp"

using namespace std;

BinaryTreeNode<int> *takeInput()
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
        cout << "enter the leftNode data of " << front->data;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftData);
            front->left = leftNode;
            pendingNodes.push(leftNode);
        }
        int rightData;
        cout << "enter the rightNodes Data of " << front->data;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightData);
            front->right = rightNode;
            pendingNodes.push(rightNode);
        }
    }
    return root;
}

vector<Node<int> *> levelWiseLinkdList(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> ans;
    // this is not the base condition
    if (root == NULL)
    {
        return ans;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        Node<int> *head = NULL;
        Node<int> *tail = NULL;
        int size = pendingNodes.size();
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            Node<int> *newNode = new Node<int>(front->data);
            if (head == NULL and tail == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->link = newNode;
                tail = newNode;
            }
            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
        }
        ans.push_back(head);
    }
    return ans;
}

void printLinkedList(Node<int> *head)
{
    if (head == NULL)
    {
        return;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->link;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans;
    ans = levelWiseLinkdList(root);
    for (int i = 0; i < ans.size(); i++)
    {
        printLinkedList(ans[i]);
        cout << endl;
    }
    return 0;
}