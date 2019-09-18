#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cassert>
#include <cstring>
using namespace std;


string answer(unordered_map<string, string> dict, string line)
{
  if(dict.count(line) > 0) {
    return dict.find(line)->second;
  }
  else {
    return "eh";
  }
}
void test()
{
  unordered_map<string, string> dict = {{"soccer", "btccer"}, {"school", "ool"}, {"eh", "deez"}};

  assert(answer(dict, "soccer") == "btccer");
  assert(answer(dict, "school") == "ool");
  assert(answer(dict, "eh") == "deez");
cout << "All test cases passed...";
}


void kattis()
{
  string line;
  unordered_map<string, string> dict;
  while(getline(cin, line) && line != "")
    {
        string english, foreign;
        int index = line.find(' ');
        english = line.substr(0, index);
        foreign = line.substr(index+1, line.size()-1);

        dict.insert({foreign, english});
    }

   cout<< answer(dict, line);
}

int main(int argc, char* argv[]) {
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) //argument to be used for testing
          test();
      else
          kattis();
      return 0;

  }
