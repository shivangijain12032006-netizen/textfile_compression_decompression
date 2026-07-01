#include <iostream>
#include <string>
#include "compressFile.cpp"
#include "decompressFile.cpp"

void menu()
{
    cout << "\n 1 - Compress File \n 2 - Decompress File \n "
         << "\nPlease enter your choice :  ";
}

string getInput(string input)
{

    getline(cin, input);
    if (input.empty())
        input = "";
    return input;
}

string makePath(string inpFile, string extention)
{
    int n = inpFile.size();
    string temp = "";
    for (int i = 0; i <= n - 5; i++)
        temp += inpFile[i];
    return ("./data/" + temp + extention);
}

bool check(string fileName, string checkWith)
{
    int n = fileName.size();
    string temp = "";
    for (int i = n - 3; i < n; i++)
    {
        temp += fileName[i];
    }

    if (temp == checkWith)
        return false;
    else
        return true;
}

int main()
{
    string orgFile, compFile, retrFile;

    int choice;
    menu();
    cin >> choice;

    if (choice == 1)
    {
        string input1, input2;
        cout << "\nEnter the name of the text file [e.g., filename.txt] : ";
        cin.ignore();
        input1 = getInput(input1);

        orgFile = "./data/" + input1;
        ifstream file(orgFile);

        if (input1 == "")
        {
            cout << "\nPlease provide the text file.";
        }
        else if (!file)
        {
            cout << "\nThe specified file could not be found.";
        }
        else
        {
            cout << "\nPlease enter the name of the compressed file [e.g., filename.bin], or press Enter to leave it blank: ";
            input2 = getInput(input2);

            if (input2 == "")
            {
                compFile = makePath(input1, "_compressed.bin");
            }
            else if (check(input2, "bin"))
            {
                compFile = "./data/" + input2 + ".bin";
            }
            else
            {
                compFile = "./data/" + input2;
            }

            cout << "\nProcessing..";
            compressfile(orgFile, compFile);
            cout << "The file has been successfully compressed.";
        }
    }

    else if (choice == 2)
    {
        string input1, input2;
        cout << "\nEnter the name of the compressed binary file [e.g., filename.bin]: ";
        cin.ignore();
        input1 = getInput(input1);

        orgFile = "./data/" + input1;
        ifstream file(orgFile);

        if (input1 == "")
        {
            cout << "\nPlease provide the compressed binary file.";
        }
        else if (!file)
        {
            cout << "\nFile not found.";
        }
        else
        {
            cout << "\nPlease enter the name of the decompressed file [e.g., filename.txt], or press Enter to leave it blank: ";
            input2 = getInput(input2);

            if (input2 == "")
            {
                compFile = makePath(input1, "_decompressed.txt");
            }
            else if (check(input2, "txt"))
            {
                compFile = "./data/" + input2 + ".txt";
            }
            else
            {
                compFile = "./data/" + input2;
            }

            cout << "\nProcessing..";
            decompressfile(orgFile, compFile);
            cout << "The file has been successfully decompressed.";
        }
    }

    else
    {
        cout << "\nInvalid Choice!\n";
    }

    return 0;
}