#ifndef JIEBA_API_INCLUDE_C_H_
#define JIEBA_API_INCLUDE_C_H_

#include "cppjieba/Jieba.hpp"
#include <iostream>

using namespace std;
using namespace cppjieba;

#ifdef __cplusplus
extern "C" {
#endif

Jieba* jieba;

typedef struct
{
	char* word;
	size_t length;
} AWord;

int jieba_open(const char* dict_path, const char* hmm_path, const char* user_dict_path, const char* idf_path, const char* stop_word_path);
void jieba_close();
AWord* jieba_cut(const char* input, bool with_hmm, size_t* length);
void jieba_free(AWord* words, size_t length);

#ifdef __cplusplus
}  /* end extern "C" */
#endif

#endif  /* JIEBA_API_INCLUDE_C_H_ */