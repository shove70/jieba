[![Build Status](https://travis-ci.org/shove70/jieba.svg?branch=master)](https://travis-ci.org/shove70/jieba)
[![GitHub tag](https://img.shields.io/github/tag/shove70/jieba.svg?maxAge=86400)](https://github.com/shove70/jieba/releases)
[![Dub downloads](https://img.shields.io/dub/dt/jieba.svg)](http://code.dlang.org/packages/jieba)

# Jieba chinese word segmentation D Deimos Bindings.

Reference:

+ https://github.com/yanyiwu/cppjieba (upstream)
+ https://github.com/shove70/cppjieba/tree/shove (Fork, Add APIs)


### Quick Start:

```d
import std.string : toStringz;
import std.conv : to;
import std.stdio: writeln;

import deimos.jieba.jieba;

string dict_path = "./dict/jieba.dict.utf8";
string hmm_path = "./dict/hmm_model.utf8";
string user_dict_path = "./dict/user.dict.utf8";
string idf_path = "./dict/idf.utf8";
string stop_word_path = "./dict/stop_words.utf8";

jieba_open(dict_path.toStringz, hmm_path.toStringz, user_dict_path.toStringz, idf_path.toStringz, stop_word_path.toStringz);

string s = "A chinese string";
size_t length;
AWord* words = jieba_cut(s.toStringz, true, &length);

for (size_t i = 0; i < length; i++)
{
    writeln(words[i].word.to!string);
}

jieba_free(words, length);
jieba_close();
```
