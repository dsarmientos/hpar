#include <vector>
#include <string>
#include <iterator>
#include <iostream>


int N_LETTERS;
char alphabet[62];

int gen_all_words(int);
void Print(std::vector<std::string> &);

int main() {
  int i = 0;
  for (char l = 'A'; l <= 'Z'; ++l) {
    alphabet[i] = l;
    ++i;
  }
  for (char l = 'a'; l <= 'z'; ++l) {
    alphabet[i] = l;
    ++i;
  }
  for (char l = '0'; l <= '9'; ++l) {
    alphabet[i] = l;
    ++i;
  }
  N_LETTERS = i;
  std::cout << "Total letters to try: " << N_LETTERS << std::endl;
  int len = gen_all_words(2);
  std::cout << "Total combinatios" << len << std::endl;

  return 0;
}

int gen_all_words(int length)
{
  std::vector<int> index(length, 0);
  int len = 0;

  while(true)
  {
    std::string word(length, ' ');
    for (int i = 0; i < length; ++i)
      word[i] = alphabet[index[i]];
    std::cout << word << std::endl;
    len++;

    for (int i = length-1; ; --i)
    { 
      if (i < 0)
        return len; 
      index[i]++;
      if (index[i] == N_LETTERS)
        index[i] = 0;
      else
        break;
    }
  }
}

void Print(std::vector<std::string> & Vec) {
  for (std::vector<std::string>::iterator p= Vec.begin(); p != Vec.end(); p++)
    std::cout << *p <<  std::endl;
}
