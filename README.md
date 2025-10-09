# BPE Tokenizer

This project is a C++ implementation of the Byte Pair Encoding (BPE) algorithm, a data compression technique that is now prominently used in Natural Language Processing for tokenization. This implementation reads a text corpus from a file, builds a vocabulary of individual characters, and iteratively merges the most frequent pair of tokens to create a new token.

## How it Works

The BPE algorithm starts with a vocabulary consisting of all individual characters present in the training corpus. It then iteratively performs the following steps:
1.  Counts the frequency of all adjacent token pairs in the corpus.
2.  Identifies the most frequent pair.
3.  Merges this pair into a single new token.
4.  Adds the new token to the vocabulary.
5.  Replaces all occurrences of the most frequent pair in the corpus with the new token.

This process is repeated for a specified number of merges or until no more pairs can be merged, resulting in a vocabulary that captures subword units and helps in handling rare words.

## Project Structure

```
└── mohamedelhoudaigui-tokenizer/
    ├── BPE.cpp          # Source file for the BPE class implementation
    ├── BPE.hpp          # Header file for the BPE class
    ├── main.cpp         # Example usage of the BPE class
    └── Makefile         # Makefile for building the project
```

## Features

*   **Train from a file:** Initializes the tokenizer with a corpus from a given text file.
*   **Custom Vocabulary Size:** Allows specifying the desired final vocabulary size.
*   **Step-by-step logging:** Prints the state of the tokenized corpus and the vocabulary at each step of the training process.

## Getting Started

### Prerequisites

*   A C++ compiler (g++ or clang++)
*   `make`

### Building the Project

1.  Clone the repository:
    ```bash
    git clone https://github.com/mohamedelhoudaigui/tokenizer.git
    cd tokenizer
    ```

2.  Build the project using the Makefile. This will create a static library `libbpe.a`.
    ```bash
    make
    ```

### Building the Executable

To build the main executable that runs the training process, you can compile `main.cpp` and link it against the created library. A simple way to do this is:

```bash
c++ main.cpp BPE.cpp -o tokenizer_trainer
```

## Usage

1.  Create a text file with your corpus. For example, `corpus.txt`:

    ```
    low lower newest widest
    low low low low low newest
    ```

2.  Run the tokenizer executable with the path to your corpus file as an argument:

    ```bash
    ./tokenizer_trainer corpus.txt
    ```

3.  The program will output the training process, showing the vocabulary growth and the merging of tokens at each step. The training will stop when the vocabulary size reaches 50 or when no more pairs can be merged.

## Customization

You can change the target vocabulary size by modifying the `train` function call in `main.cpp`:

```cpp
// In main.cpp
// Change 50 to your desired vocabulary size
aa.train(100); 
```

If you pass a negative number to the `train` function, it will run until no more pairs can be merged.

```cpp
// In main.cpp
// Train until completion
aa.train(-1);
```
