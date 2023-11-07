#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node
{
public:
    int freq;
    string symbol;
    Node *left;
    Node *right;
    string huff;

    Node(int f, string sym, Node *l = nullptr, Node *r = nullptr) : freq(f), symbol(sym), left(l), right(r), huff("") {}

    bool operator<(const Node &other) const
    {
        return freq > other.freq; // Using greater than for min-heap
    }
};

void printNodes(Node *node, string val = "")
{
    string newVal = val + node->huff;

    if (node->left)
    {
        printNodes(node->left, newVal);
    }
    if (node->right)
    {
        printNodes(node->right, newVal);
    }

    if (!node->left && !node->right)
    {
        cout << node->symbol << " -> " << newVal << endl;
    }
}

int main()
{
    string chars[] = {"a", "b", "c", "d", "e", "f"};
    int freq[] = {5, 9, 12, 13, 16, 45};

    priority_queue<Node> nodes;

    for (int i = 0; i < 6; i++)
    {
        nodes.push(Node(freq[i], chars[i]));
    }

    while (nodes.size() > 1)
    {
        Node *left = new Node(nodes.top().freq, nodes.top().symbol, nodes.top().left, nodes.top().right);
        nodes.pop();
        Node *right = new Node(nodes.top().freq, nodes.top().symbol, nodes.top().left, nodes.top().right);
        nodes.pop();

        left->huff = "0";
        right->huff = "1";

        Node *newNode = new Node(left->freq + right->freq, left->symbol + right->symbol, left, right);
        nodes.push(*newNode);
    }

    Node *huffmanTree = new Node(nodes.top().freq, nodes.top().symbol, nodes.top().left, nodes.top().right);
    printNodes(huffmanTree);

    return 0;
}
