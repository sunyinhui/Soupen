#ifndef YEDIS_DB_H_#define YEDIS_DB_H_#include "../ds/yedis_bloom_filter.h"#include "../ds/yedis_trie.h"#include "../ds/yedis_string.h"namespace yedis_server{  using yedis_datastructures::YedisString;  using yedis_datastructures::YedisBloomFilter;  using yedis_datastructures::YedisTrie;  using yedis_datastructures::YedisTrieNode;  template<typename T>  struct YedisDSTypeNode  {    ~YedisDSTypeNode()    {      val->~T();      key->~YedisString();    }    int init()    {      val = nullptr;      next = nullptr;      key = nullptr;      return YEDIS_SUCCESS;    }    T *val;    YedisDSTypeNode *next;    YedisString *key;  };  struct YedisDBElement  {    YedisDBElement()    {      bf = nullptr;      tn = nullptr;    }    YedisDSTypeNode<YedisBloomFilter> *bf;    YedisDSTypeNode<YedisTrie<YedisTrieNode> > *tn;  };  extern YedisDBElement ydbe[MAX_DB_NUM];}#endif /*YEDIS_DB_H_*/