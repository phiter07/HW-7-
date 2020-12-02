/* * * PSEUDOCODE * * *
Void function userInput();
  Takes input from user list_t

list_t hashOne function
  Initialize newHashList
  Initialize sumList
  while(list is not empty)
    int newHashkey is assigned to fib(list_first + sumList)
    newHashList is assigned to list_make(newHashkey, newHashList)
    list is assigned to list_rest(temp)
    list is assigned to reverse(newHashList)

list_t subtractOneTwo function
  Initialize output
  while (list is not empty(list1) AND list is not empty(list2))
    int absSub assigned to abs(list_1 - list_2)
    assign output to (absSub, output)
    list_1 is assigned to list_rest(list_1)
    list_2 is assigned to list_rest(list_2)

list_t hashTwo
  initialize output
  initialize temp to filter_odd(list)
  initialize hashOdd 
  int oddProd is assigned to product(temp)
  initialize ctr to 0
  while (list is not empty(temp)
    int newHashKey is assigned to oddProd + list_first(temp)
    hashOdd is assigned to list_make(newHashkey, hashOdd)
    temp is assigned to list_rest(temp)
    ctr is increased by 1
  if (list is not empty(hashOdd))
    while(ctr is greater than 0)
      if (isPrime(list_first(hashOdd)))
        hashOdd is assigned to list_rest(hashOdd)
      hashOdd is assigned to rotate (hashOdd, 1)
      ctr is then decreased by 1
  int sumOdd is assigned to 0
  if(list is not empty(hashOdd)
    sumOdd is assigned to sum(hashOdd)
    while (list is not empty(list))
      if(list_first(list) mod 2 not equal to 0)
        int newHashKey is assigned to oddProd _ list_first(list)
        output is assigned to list_make(newHashKey, output)
      else
        int newHashKey is assigned to sumOdd plus list_first(list)
        output is assigned to list_make(newHashKey,output)
      list is assigned to list_rest(list)
    return the reverse(output)

bool isPrime function
  bool flag is assigned to true
  if (num is equal to 0 OR num equal to 1)
    flag is assigned to false
  else
    for(int i assigned to 2; i less than or equl to num/2; increase i by 1)
      if(num mod i equal to 0)
        flag is assigned to false
        break
  return flag

int countCollisions function
  Initialize undordered set
  int output is assigned to 0
  while(list is not empty)
    if(unordered set is equal to uSet.end())
      insert
    else
      output is plus or equal to 1
    list is assigned to list_rest(list)
  return output
*/
#include <iostream>
#include <sstream>
#include "recursive.h"
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
  list_t input2 = list_make();
  list_t output2 = list_make();

  std::cout<< "New user hash input: ";
  userInput(input);

  std::cout << "Old user hash output: ";
  userInput(output);

  list_t newHash = hashOne(input);
  std::cout << "New user hash keys: ";
  list_print(newHash);
  std::cout << "\n";

  list_t difference = subtractOneTwo(newHash, output);
  std::cout << "Difference: ";
  list_print(difference);
  std::cout << "\n";

  std::cout << "New user hash input 2: ";
  userInput(input2);

  std::cout << "Old user hash output 2: ";
  userInput(output2);

  list_t newHash2 = hashTwo(input2);
  std::cout << "New user hash keys 2: ";
  list_print(newHash2);
  std::cout << "\n";

  list_t difference2 = subtractOneTwo(newHash2, output2);
  std::cout << "Difference 2: ";
  list_print(difference2);
  std:: cout << "\n";

  std::cout << "- * - * - Collision Count - * - * -" << "\n";
  std::cout << "- - Hash #1 - -" << "\n";

  int collision = countCollisions(newHash);
  std::cout << "new_code: " << collision << "\n";
  int oldCol = countCollisions(output);
  std::cout << "old_code: " << oldCol << "\n";
  std::cout << "- - Hash #2 - -" << "\n";
  int col2 = countCollisions(newHash2);
  std::cout << "new_code2: " << col2 << "\n";
  int oldCol2 = countCollisions(output2);
  std::cout << "old_code2: " << oldCol2 << "\n";
  return 0;
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
    list = list_rest(list);
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

int countCollisions(list_t list) {
  std::unordered_set<int> uSet;
  int output = 0;
  while (!list_isEmpty(list)) {
    if (uSet.find(list_first(list)) == uSet.end()) {
      uSet.insert(list_first(list));
    }
    else {
      output += 1;
    }
    list = list_rest(list);
  }
  return output;
}