# DNN

## Prerequisite
* CUDA install
* MeCab install
```bash
git clone https://github.com/taku910/mecab.git
cd mecab/
./configure
make
make check
make install
```


## Compile & Execution
Assume cuMat directory is in the same row.
```bash
cp test.cpp.[Type of processing]　test.cpp
make
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../cuMat
./test
```
* If you get an error, test.cpp:8:17: fatal error: png.h: No such file or directory

```bash
apt-get install libpng12-0
apt-get install libpng-dev
find / -name png.h
```
* install boost
```bash
apt-get install libboost-all-dev
```

* install utilities
```bash
apt update
apt install git
apt install net-tools
apt install net-tools
apt install vim-tiny
```


#### [Type of processing]
* autoencoder: 
* cnn: CONVOLUTION NEURAL NETWORK
* iris: HIERARCHICAL PERCEPTRON BY IRIS DATA SET
* lstm.sin:sin wave reproduction with LSTM
* mlp:stratified interceptron by MNIST
* number:LSTM Counting
* seq2seq:LSTM Translation Model

## Download MNIST(test.cpp.mlp, for autoencoder)
http://yann.lecun.com/exdb/mnist/

train-images-idx3-ubyte.gz:  training set images (9912422 bytes) 

train-labels-idx1-ubyte.gz:  training set labels (28881 bytes) 

t10k-images-idx3-ubyte.gz:   test set images (1648877 bytes) 

t10k-labels-idx1-ubyte.gz:   test set labels (4542 bytes)

Download and Extract to DNN Directory

## Cifar-10 Download (for test.cpp.cnn)
https://www.cs.toronto.edu/~kriz/cifar.html

CIFAR-10 binary version (suitable for C programs)

Downloaded and extracted to DNN directory with data stored under cifar-10-batches-bin directory.

## Tanaka Corpus Download(for test.cpp.seq2seq)
http://www.edrdg.org/wiki/index.php/Tanaka_Corpus

complete version (UTF-8) Download and extract to the DNN directory, including examples.utf.

Extract only the necessary part of examples.utf from norm_tanaka_corpus.py and create tanaka_corpus_e.txt and tanaka_corpus_j.txt.

Randomly extract 10000 items from the data created above with sample_tanaka_corpus.py and save them in a separate file (tanaka_corpus_e_10000.txt, tanaka_corpus_j_10000.txt). Rename this to use as training data (tanaka_corpus_e_10000.txt.train, tanaka_corpus_j_10000.txt.train)

Similarly, use sample_tanaka_corpus.py again to create data for evaluation.(tanaka_corpus_e_10000.txt.test, tanaka_corpus_j_10000.txt.test)

    

