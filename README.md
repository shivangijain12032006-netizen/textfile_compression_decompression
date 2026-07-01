
# Text File Compression-Decompression

This project provides a C++ implementation of text file compression using Huffman coding. The program compresses a given text file upto 40-50% and can also decompress the compressed file back to its original form.

## Huffman Coding

Huffman coding is a popular data compression algorithm that uses variable-length prefix codes to represent characters in a text file. The algorithm assigns shorter codes to more frequently occurring characters, resulting in efficient compression.

## Features
 - Compress a text file using Huffman coding algorithm.
 - Decompresses a previously compressed file back to its original form.
 - Handles file input/output errors and displays appropriate error messages.
 - Supports .txt text file format.
 - Includes sample input file for testing and demonstration purposes.

## Deployment

Clone or download the project repository to your local machine. The files to be compressed and decompressed should be available in the _data_ folder.

Open a terminal or command prompt and navigate to this project directory.

To run the project, use following command 
```C++
./main.exe
```
Choose your option to either compress the file and decompress the file and appropriate the filename.
```C++
1- Compress File
2- Decompress File

Please enter your choice : 
```

The compressed and decompressed file will be created in this project directory within the _data_ folder.
```C++
Processing..
The file has been successfully compressed.
```

## Limitations
- The project currently supports only text files. Other file formats (e.g., images, videos) are not compatible.
- Large text files or files with complex structures may take longer to compress and decompress.


## Author

- [@anisha-singh07](https://github.com/anisha-singh07)

