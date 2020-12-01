#include <iostream>
#include <sstream>
//#include "recursive.h"
#include "hw4.h"
#include <unordered_set> 

void userInput (list_t &list);
list_t hashOne (list_t list);
list_t hashTwo (list_t list);
list_t subtractOneTwo(list_t list_1, list_t list_2);
bool isPrime(int num);
int countCollisions(list_t list);

int main () {
  list_t input = list_make();
  list_t output = list_make();
  list_t newHash = hashOne(input);
  list_t difference = subtractOneTwo(newHash, output);
  list_t input2 = list_make();
  list_t output2 = list_make();
  list_t newHash2 = hashTwo(input2);
  list_t difference2 = subtractOneTwo(newHash2, output2);

  std::cout<< "New user hash input: ";
  userInput(input);
  std::cout << "Old user hash output: ";
  userInput(output);
  std::cout << "New user hash keys: ";
  list_print(newHash);
  std::cout << "Difference: ";
  list_print(difference);

  std::cout << "New user hash input 2: ";
  userInput(input2);
  std::cout << "Old user hash output 2: ";
  userInput(output2);
  std::cout << "New user hash keys 2: ";
  list_print(newHash2);
  std::cout << "Difference 2: ";
  list_print(difference2);


}
// * * * * * F U N C T I O N S * * * * *

void userInput (list_t &list) {
  std::string input = "";
  int num = 0;
  getline(std::cin, input);
  std::istringstream iss(input);
  while (iss >> num) {
    list = list_make(num,list);
  }
  list = reverse(list);
}

list_t hashOne(list_t list) {
  list_t newHashList = list_make ();
  int sumList = sum(list);
}

























/*
using namespace std;


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
  list_t oldList2 = list_make();
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

  // * * * T E S T 2 * * *  

  for (int i = 1; <= i <= 6; i++) {
    std::cin >> old_hash2_ints;
    oldList2 = list_make(old_hash2_ints, oldList2);
  }

  oldList = reverse(oldList2);
  std::cout<< "old output";
  list_print(oldList);
  std::cout << "\n";

  finalEvenOdd = even_or_odd_hash.hash_test2(oldList, readInput);


}
*/
