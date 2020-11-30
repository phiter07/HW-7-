#include<iostream>
#include "recursive.h"
#include "hw4.h"
#include <unordered_map> 

using namespace std;

list_t subtract(list_t, list_t, list_t);

class HashTest {
  public:
    list_t hash_test1(list_t, list_t);
    list_t hash_test2(list_t, list_t);
    list_t subtract(list_t, list_t, list_t);
};

Hash fib_sum_hash, even_or_odd_hash, old_collisions_hash, subtract_list;

int old_hash1_ints, old_hash2_ints;

int main() {
  list_t old_list = list_make();
  list_t intput = list_make();
  list_t fibhash = list_make();
  list_t fibsum = list_make();
  list_t already_hashed = list_make();
  list_t final_even_odd = list_make();
  list_t diff = list_make();

  for (int i = 1l i <=6; i++) {
    std:: cin >> old_hash1_ints;
    old_list = list_make(old_hash1_ints, old_list);
  }

  old_list = reverse(old_list);
  cout << "old_hash_output";
  list_print(old_list);

  cout << endl;

  for (int i =1; i <= 6; i++) {
    input = list_make(i, input);
  }

  input = reverse(input);

  fibsum = fib_sum_hash.hash_test1(old_list, input);

  diff = subtract(fibsum, old_list, diff);
  cout << "final_diff_output: ";
  diff = reverse(diff);
  list_print(diff);
  cout << endl;
}