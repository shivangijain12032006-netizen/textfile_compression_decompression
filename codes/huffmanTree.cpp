#include <queue>
#include <unordered_map>
#include <string>
#include <fstream>
using namespace std;

string getfile(string src)
{
    // receives source file path as an argument, reads the text and returns in string form

    ifstream fin(src);
    string content;
    string final = "";
    while (fin.eof() == 0)
    {
        getline(fin, content);
        final = final + content + "\n";
    }
    return final;
}

struct Node
{
    // tree node

    char ch;
    int freq;
    Node *left, *right;
};

Node *getNode(char ch, int freq, Node *left, Node *right)
{
    // to allocate a new tree node in bst

    Node *node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

struct comp
{
    // for comparison to order the heap

    bool operator()(Node *l, Node *r)
    {
        // highest priority item has the lowest frequency
        return l->freq > r->freq;
    }
};

Node *buildHuffmanTree(string text)
{

    // builds huffman tree and decode given input text

    unordered_map<char, int> freq; //counts freq of each character and store it in a freq map
    for (char ch : text)
    {
        freq[ch]++;
    }

    priority_queue<Node *, vector<Node *>, comp> pq; // priority queue to store the leaf nodes of huffman tree
    for (auto pair : freq)
    {
        // leaf node creation of each character and adding it to the priority queue
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (pq.size() != 1)
    {
        // iterate till pq has more than one node in the queue

        // removing the two nodes of highest priority (ie lowest frequency) from the queue
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        // creating a new internal node with these two nodes as children and with frequency equal to the sum of the nodes' freq
        // adding the new node to the priority queue
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    Node *root = pq.top(); // stores the pointer to the root of the huffman tree

    return root;

    // unordered_map<char,string> huffmanCode;
}
