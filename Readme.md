# Compressor

This program implements a simple text compressor using the Huffman coding algorithm.

# HowTo
**1:** Calculate the frequency of each string.
**2:** Sort all the characters on the basis of their frequency in ascending order.
**3:** Mark each unique character as a leaf node.
**4:** Create a new internal node. 
**5:** The frequency of the new node as the sum of the single leaf node
**6:** Mark the first node as this left child and another node as the right child of the recently created node. 
**7:** Repeat all the steps from step-2 to step-6.

![Huffman_huff_demo](https://github.com/mendax0110/compressor/assets/52537419/b7b327c4-174e-4ca7-95d7-ca8850a6a3e5)
License: https://creativecommons.org/licenses/by-sa/3.0/
Source: https://commons.wikimedia.org/wiki/File:Huffman_huff_demo.gif


## Usage

To compress a text file:
```bash
./compressor [input_file] -comp [output_file]
````

To decompress a compressed file:
```bash
./compressor [input_file] -decomp [output_file]
````

## Example:

To compress a file named input.txt and save the compressed output as compressed.bin
```bash
./compressor input.txt -comp compressed
````

To decompress a file named compressed.bin and save the decompressed output as restored.txt:
```bash
./compressor compressed.bin -decomp restored.txt
````
## Note:

The input file must be a text file.
The compressed output will have a .bin extension.
The decompressed output will be saved without any extension.
