
#include<iostream>
#include "recursive.h"
#include "hw4.h"
#include <unordered_map> 

using namespace std;

/*
list_t subtract(list_t, list_t, list_t);

class HashTest {
  public:
    list_t hash_test1(list_t, list_t);
    list_t hash_test2(list_t, list_t);
    list_t subtract(list_t, list_t, list_t);
};

HashTest fib_sum_hash, even_or_odd_hash, old_collisions_hash, subtract_list;

int old_hash1_ints, old_hash2_ints;

int main() {
  list_t oldList = list_make();
  list_t readInput = list_make();
  list_t fibHash = list_make();
  list_t fibSum = list_make();
  list_t alreadyHashed = list_make();
  list_t finalEvenOdd = list_make();
  list_t diffTwo = list_make();

  for (int i = 1; i <=6; i++) {
    std:: cin >> old_hash1_ints;
    oldList = list_make(old_hash1_ints, oldList);
  }

  oldList = reverse(oldList);
  cout << "old_hash_output";
  list_print(oldList);

  cout << endl;

  for (int i =1; i <= 6; i++) {
    readInput = list_make(i, readInput);
  }

  readInput = reverse(readInput);

  fibSum = fib_sum_hash.hash_test1(oldList, readInput);

  diffTwo = subtract(fibSum, oldList, diffTwo);
  cout << "final_diff_output: ";
  diffTwo = reverse(diffTwo);
  list_print(diffTwo);
  cout << endl;
}
*/