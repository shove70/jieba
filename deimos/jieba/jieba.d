
module deimos.jieba.jieba;

public:
extern(C):

struct AWord
{
    char* word;
    size_t length;
}

int jieba_open(const char* dict_path, const char* hmm_path, const char* user_dict_path, const char* idf_path, const char* stop_word_path);
void jieba_close();
AWord* jieba_cut(const char* input, bool with_hmm, size_t* length);
void jieba_free(AWord* words, size_t size);
