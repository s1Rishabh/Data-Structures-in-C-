#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
    }
};
class BinaryTree
{
public:
    Node *construct(int arr[], int n)
    {
        Node *root = NULL;
        vector<Node *> nlist;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == -1)
            {
                nlist.pop_back();
            }
            else
            {
                Node *res = new Node(arr[i]);
                if (nlist.size() == 0)
                {
                    root = res;
                }
                else
                {
                    Node *nn = nlist[nlist.size() - 1];
                    if (nn->left == NULL)
                    {
                        nn->left = res;
                    }
                    else if (nn->right == NULL)
                    {
                        nn->right = res;
                    }
                }
                nlist.push_back(res);
            }
        }
        return root;
    }

    void display(Node *node)
    {
        if (node == NULL)
        {
            return;
        }

        string str = "";

        if (node->left != NULL)
        {
            str += node->left->data;
        }
        else
        {
            str += ".";
        }
        str += " => ";
        str += node->data;
        str += " <= ";
        if (node->right != NULL)
        {
            str += node->right->data;
        }
        else
        {
            str += ".";
        }
        cout << str;
        display(node->left);
        display(node->right);
    }
};

int main()
{
    int arr[] = {50, 25, 12, 13, -1, -1, 37, 30, 12, -1, -1, 40, -1, -1, -1, 75, 62, 60, -1, 70, -1, -1, 87, -1,
                 -1, -1};
    int n = sizeof(arr) / sizeof(int);
    vector<int> vs(arr, arr + n);
    BinaryTree bt;
    Node *root = bt.construct(arr, n);
    // bt.display(root);
    return 0;
}