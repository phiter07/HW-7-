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
  while(!list_isEmpty(list)) {
    int newHashKey = fib(list_first(list)) + sumList;
    newHashList = list_make(newHashKey, newHashList);
  }
  return reverse(newHashList);
}

list_t subtractOneTwo (list_t list_1, list_t list_2) {
  list_t output = list_make();
  while(!list_isEmpty(list_1) && !list_isEmpty(list_2)) {
    int absSub = abs(list_first(list_1) - list_first(list_2));
    output = list_make(absSub, output);
    list_1 = list_rest(list_1);
    list_2 = list_rest(list_2);
  }
  return reverse(output);
}

list_t hashTwo (list_t list) {
  list_t output = list_make();
  list_t temp = filter_odd(list);
  list_t hashOdd = list_make();
  int oddProd = product(temp);
  int ctr = 0;
  while (!list_isEmpty(temp)) {
    int newHashKey = oddProd + list_first(temp);
    hashOdd = list_make(newHashKey, hashOdd);
    temp = list_rest(temp);
    ctr++;
  }
  if(!list_isEmpty(hashOdd)) {
    while (ctr > 0) {
      if (isPrime(list_first(hashOdd))) {
        hashOdd = list_rest(hashOdd);
      }
      hashOdd = rotate (hashOdd, 1);
      ctr --;
    }
  }
  int sumOdd = 0;
  if(!list_isEmpty(hashOdd)) {
    sumOdd=sum(hashOdd);
  }
  while (!list_isEmpty(list)) {
    if (list_first(list) % 2 != 0) {
      int newHashKey = oddProd + list_first(list);
      output = list_make(newHashKey, output);
    }
    else {
      int newHashKey = sumOdd + list_first(list);
      output = list_make(newHashKey, output);
    }
    list = list_rest(list);
  }
  return reverse(output);
}

bool isPrime(int num) {
  bool flag = true;
  if (num == 0 || num == 1) {
    flag = false;
  }
  else {
    for (int i =2; i <= num / 2; i++) {
      if (num % i == 0) {
        flag = false;
        break;
      }
    }
  }
  return flag;
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
