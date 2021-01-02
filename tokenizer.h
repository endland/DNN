/*
 * tokenizer.h
 *
 */

#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <mecab.h>
#include <string>

std::vector<std::string> split(const std::string &str, char sep)
{
    std::vector<std::string> v;        // DIVIDED RESULT STORING VECTOR
    auto first = str.begin();              // an iterator that points to the beginning of a text
    while( first != str.end() ) {         // Loops while text remains
        auto last = first;                      // Iterator to end of split string
        while( last != str.end() && *last != sep )       //Go to the end or separator character
            ++last;
        v.push_back(std::string(first, last));       // Print split characters
        if( last != str.end() )
            ++last;
        first = last;          // Configure Iterators to:
    }
    return v;
}


class Tokenizer {
private:
    MeCab::Tagger *tagger;

public:
    Tokenizer(){
        //tagger = MeCab::createTagger("-Owakati");
        //tagger = MeCab::createTagger("-xunknown -d /usr/local/lib/mecab/dic/mecab-ipadic-neologd");
        tagger = MeCab::createTagger("-d /usr/local/lib/mecab/dic/mecab-ipadic-neologd");
    }
    ~Tokenizer(){
        delete tagger;
    }

    std::vector<std::string> parse(std::string input){


        std::vector<std::string> result;

        const MeCab::Node* node = tagger->parseToNode(input.c_str());

        char buf[1024];

        for (; node; node = node->next) {
            string feature(node->feature);
            //if (feature.find("noun")==0 || feature.find("unknown_word")==0){
                strcpy(buf,node->surface);
                buf[node->length]='\0';
                string surface(buf);
                result.push_back(surface);
            //}
        }
        return result;
    }
};




#endif /* TOKENIZER_H_ */
