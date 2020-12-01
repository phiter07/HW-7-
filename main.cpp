#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

//#include "hw4.h"
#include "hw4.cpp"
//#include "recursive.h"
#include "recursive.cpp"

// static list_t hash_test1() {
//   list_t hash_list1 = list_make();
//   list_t empty_list = list_make();
//   std::string input;
//   std::cin >> input;
  
//   for (int i = 0; i < input.size(); ++i)
//   {
//     while (input[i] != '\n') {
//       if (input[i] != ' ') {
//         std::string temp_string = temp_string.substr(i,1);
//         int insert_num = stoi(temp_string);
//         list_t temp_list = list_make(insert_num, empty_list);
//         hash_list1 = insert_list(temp_list, hash_list1, 0);
//       }
//     }
//   }
//   list_print(hash_list1);
// }

static list_t hash_test1() {
  list_t hash_list1 = list_make();
  list_t empty_list = list_make();

  std::string input;
  getline(std::cin, input, ' ');
  std::istringstream ss(input);
  int temp;
  while(ss >> temp) {
    list_t temp_list = list_make(temp, empty_list);
    hash_list1 = insert_list(temp_list, hash_list1, 0);
  }
  list_print(hash_list1);
  return empty_list;
}


// void list_print_helper(list_t list)
// {
//     if (list_isEmpty(list)) {
//       return;
//     } 
//     else {
//       std::cout << list_first(list) << " ";
//       list_print_helper(list_rest(list));
//   }
// }

// void list_print(list_t list)
// {
//     std::cout << "( ";
//     list_print_helper(list);
//     std::cout << ")";
// }

// static list_t FibHash(list_t list) {
//   list_t hashed_list = list_make();
//   int sum_of_original_list = sum(list);
//   for (int i = 1; i < 7; i++) {
//     int fib_number = fib_tail(i);
//     int hashed_number = fib_number + sum_of_original_list;
//     hashed_list = list_make(hashed_number, hashed_list);
//   }
//   return reverse(hashed_list);
// }

// static int CollisionDetection(list_t list) {
//   int hash_table[16];
//   int collisions = 0;

//   for (int i = 0; i < 16; i++) {
//     hash_table[i] = -1;
//   }

//   while (!list_isEmpty(list)) {
//     int hashed_list_value = list_first(list);
//     int hash_placement = hashed_list_value % 16;
//     if (hash_table[hash_placement] == -1) {
//       hash_table[hash_placement] = 1;
//     } else {
//       collisions++;
//     }
//     list = list_rest(list);
//   }
//   return collisions;
// }

int main() {
  hash_test1();
}
