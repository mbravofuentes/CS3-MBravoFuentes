//Mario Bravo CSI 3
//Falling Apart Kattis
//9/6/2019
//This program is to give the highest integer possible to Alice and Bob as evenly as possible through the usage of stl vector and local testing
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

//sorting vector
string answer(vector<int> v )
{
  sort(v.rbegin(), v.rend()); //sorts the numbers in Beg and End

  int a = 0;  //initialize for Bob and Alice to be 0 everytime
  int b = 0;

  for(int i = 0; i < v.size(); i++) {
      if(i % 2 == 0) {
          a += v[i];
      }
      else {
          b += v[i];
      }
  }
  return  to_string(a) + " " + to_string(b);
}

void test()
{
  int test_list[] = {69, 0, 2}; //set test cases to different number
  int test_list2[] = {999, 1, 0};
  int test_list3[] = {1000, 1, 999};

  vector<int> test_vect01(test_list, test_list+3);
  vector<int> test_vect02(test_list2, test_list2+3);
  vector<int> test_vect03(test_list3, test_list3+3);

  assert(answer(test_vect01) == "69 2");
  assert(answer(test_vect02) == "999 1"); // assertion is like a fail/safe that determines if your function works correctly
  assert(answer(test_vect03) == "1001 999");

  cout << "all test cases passed..." << endl; //if you read this during the test, it is correct
}

void kattis()
{
  int n;
  cin >> n;
  vector<int> v(n); //puts input into vector
  for(auto& i : v) {
      cin >> i;
  }
  cout << answer(v);
}

int main(int argc, char* argv[])
{
  if (argc > 1 && strncmp(argv[1], "test", 4) == 0) //argument to be used for testing
      test();
  else
      kattis();
  return 0;
}
