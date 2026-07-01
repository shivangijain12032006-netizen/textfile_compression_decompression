#include <iostream>
#include "huffmanTree.cpp"

void stringTObinfile(string destbin, unordered_map<char, string> mapdata, string text)
{
    ofstream bfile(destbin, ios::binary);

    if (bfile.is_open() == false)
    {
        cout << "Failed to open the file." << endl;
        return;
    }

    int mapsize = mapdata.size();
    int strlen = text.length();

    bfile.write(reinterpret_cast<const char *>(&strlen), sizeof(int));
    bfile.write(reinterpret_cast<const char *>(&mapsize), sizeof(int));

    // writes map to binary file
    for (const auto &ch : mapdata)
    {
        // writes char to the file
        bfile.write(reinterpret_cast<const char *>(&ch.first), sizeof(char));
        // writes the size of the string having code for char
        int strlength = ch.second.length();
        bfile.write(reinterpret_cast<const char *>(&strlength), sizeof(int));
        // writes the string code to the file
        bfile.write(ch.second.c_str(), strlength);
    }

    // write text to binary file
    unsigned char byte = 0;
    int bitPosition = 0;

    for (char c : text)
    {
        if (c == '0' || c == '1')
        {
            byte |= (c - '0') << (7 - bitPosition);
            bitPosition++;
            if (bitPosition == 8)
            {
                bfile.write(reinterpret_cast<const char *>(&byte), sizeof(byte));
                byte = 0;
                bitPosition = 0;
            }
        }
    }
    // Write the remaining bits if the total count is not a multiple of 8
    if (bitPosition > 0)
    {
        bfile.write(reinterpret_cast<const char *>(&byte), sizeof(byte));
    }

    bfile.close();
}

void encode(Node *root, string str, unordered_map<char, string> &huffmanCode)
{
    // traverse the huffman tree and store huffman codes in a map

    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
    {
        // if leaf node is found
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void compressfile(string src, string dest)
{
    string original = getfile(src);

    // encoded text in source file is added to the destination file path
    unordered_map<char, string> huffmanCode;
    Node *root = buildHuffmanTree(original);
    encode(root, "", huffmanCode);

    string output = "";
    for (char ch : original)
    {
        output += huffmanCode[ch];
    }

    // cout<<"encoded1"<<endl<<output<<endl;

    stringTObinfile(dest, huffmanCode, output);
}
