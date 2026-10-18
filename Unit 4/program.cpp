#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

Node* createNode(char value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree(string postfix)
{
    stack<Node*> s;
    int i;
    char ch;

    for (i = 0; i < postfix.length(); i++)
    {
        ch = postfix[i];

        if (isalnum(ch))
        {
            s.push(createNode(ch));
        }
        else
        {
            if (s.size() < 2)
            {
                cout << "Invalid postfix expression!";
                return NULL;
            }

            Node* newNode = createNode(ch);

            newNode->right = s.top();
            s.pop();

            newNode->left = s.top();
            s.pop();

            s.push(newNode);
        }
    }

    if (s.size() != 1)
    {
        cout << "Invalid postfix expression!";
        return NULL;
    }

    return s.top();
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
            cout << "(";

        inorder(root->left);
        cout << root->data;
        inorder(root->right);

        if (root->right != NULL)
            cout << ")";
    }
}

void preorder(Node* root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int evaluate(Node* root)
{
    int leftValue, rightValue;

    if (root->left == NULL && root->right == NULL)
        return root->data - '0';

    leftValue = evaluate(root->left);
    rightValue = evaluate(root->right);

    switch (root->data)
    {
        case '+':
            return leftValue + rightValue;

        case '-':
            return leftValue - rightValue;

        case '*':
            return leftValue * rightValue;

        case '/':
            if (rightValue == 0)
            {
                cout << "\nError: Division by zero!";
                return 0;
            }
            return leftValue / rightValue;

        default:
            return 0;
    }
}

int main()
{
    string postfix;
    Node* root;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    root = buildTree(postfix);

    if (root == NULL)
    {
        cout << endl;
        return 0;
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    cout << "\nEvaluated Result: ";

    cout << evaluate(root) << endl;

    return 0;
}
