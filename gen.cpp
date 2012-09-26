#include <cstdio>
#include <iostream>
#include <math.h>
#include <string>
#include <list>
#include <sstream>
#include <assert.h>


int N_LETTERS;
const int BASE = 62;
char alphabet[BASE+1] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void gen_all_words(int);
std::string join_list(std::list<char>);
std::string decimal_to_base62(int);


int main() {
  gen_all_words(2);

  return 0;
}


std::string decimal_to_base62(int wet) {
  std::list<char> base62;
  char letter;
  int pos;
  while (wet >= BASE) {
    pos = wet % BASE;
    letter = alphabet[pos];
    base62.push_front(letter);
    wet /= BASE;
  }
  letter = alphabet[wet];
  base62.push_front(letter);
  std::string word = join_list(base62);

  return word;
}


std::string join_list(std::list<char> list) {
  std::stringstream ss;
  for(std::list<char>::iterator list_iter = list.begin(); 
      list_iter != list.end(); list_iter++) {
    ss << *list_iter;
  }
  return ss.str();
}


void gen_all_words(int length) {
  assert(length > 0);
  int total_words = pow(BASE, length);
  int start = pow(BASE, length-1);
  std::cout << "Total combinations" << total_words << std::endl;
  std::cout << "start" << start << std::endl;
  for (int i=start; i !=  total_words; ++i) {
    std::string word = decimal_to_base62(i);
    printf("%s\n", word.c_str());
  }
}

