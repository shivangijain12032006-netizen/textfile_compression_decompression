#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <bitset>

using namespace std;


void binTOstringfile(string binfile, string &textbin, unordered_map<string,char> &huffmandata, int &textsize)
{
    ifstream bfile(binfile, ios::binary);
    //unordered_map<string,char> mapdata;     
    //stores the reverse huffman tree map

    // text size, map size, map elements, text elements

    if(bfile.is_open()==false)
    {
        cout<<"Failed to open the file"<<endl;
        return;
    }

    int mapsize=0;

    bfile.read(reinterpret_cast<char*>(&textsize),sizeof(int));
    bfile.read(reinterpret_cast<char*>(&mapsize),sizeof(int));

    //to obtain the map
    for (int i=0; i<mapsize; ++i)
    {
        //reads the key, ie the character
        char key;
        bfile.read(reinterpret_cast<char*>(&key),sizeof(char));

        //reads the size of the string code
        int strlen=0;
        bfile.read(reinterpret_cast<char*>(&strlen),sizeof(int));

        string value(strlen,'\0');
        bfile.read(&value[0],strlen);

        huffmandata[value]=key;
    }

    //to read the text
    unsigned char byte;
    while(bfile.read(reinterpret_cast<char*>(&byte),sizeof(char)))
    {
        for (int bitPos=7; bitPos>=0; bitPos--)
        {
            char c=((byte>>bitPos)&1)+'0';
            textbin+=c;
        }
    }

}


void decompressfile(string binfile, string destfile)
{
    
    unordered_map<string,char> huffmandata;
    
    string textbin="";
    int textsize=0;
    binTOstringfile(binfile,textbin,huffmandata,textsize);

    textbin.resize(textsize);
    
    //cout<<"encoded2"<<endl<<textbin<<endl;

    string original="\0";
    string str="\0";
    for (auto ch:textbin)
    {
        str+=ch;
        if (huffmandata.find(str)!=huffmandata.end())
        {
            //if found the code
            original+=huffmandata[str];
            str="\0";
        }

    }

    ofstream fout;
    fout.open(destfile);
    fout<<original;
    fout.close();
}




