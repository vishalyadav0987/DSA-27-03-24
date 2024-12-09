// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;

    node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};

node *buildtree(node *root)
{
    std::cout << "Enter the data: " << endl;
    int data;
    std::cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    std::cout << "Enter data for left node " << data << ": ";
    root->left = buildtree(root->left);
    cout << "Enter data for right node " << data << ": ";
    root->right = buildtree(root->right);
    return root;
}

void leveOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}
void leveOrderTraversalPattern(node *root)
{
    queue<node *> q;
    q.push(root);
    // first level push kar chucke toh seprator dal denge
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();

        // if 1st level complete then eneter
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            { // queue still have some node
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void buildTreeUsingLevelOrderTraversal(node *&root)
{
    queue<node *> q;
    std::cout << "Enter the data for root: " << endl;
    int data;
    std::cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter data for left node: " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data for right node: " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    // Write C++ code here

    node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    /*
    // creating treee;
    root=buildtree(root);

    // print tree
    cout<<"Printing tree using level order traversal: ";
    leveOrderTraversal(root);

    cout<<endl;

    cout<<"Print tree using level order traversal in prented form :"<<endl;
    leveOrderTraversalPattern(root);

    */

    // build tree using traversal
    buildTreeUsingLevelOrderTraversal(root);

    cout << "Print tree using level order traversal in prented form :" << endl;
    leveOrderTraversalPattern(root);

    return 0;
}