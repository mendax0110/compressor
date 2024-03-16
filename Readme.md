# Compressor

This program implements a simple text compressor using the Huffman coding algorithm.

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
