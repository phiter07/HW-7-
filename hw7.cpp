#include<iostream>
#include "recursive.h"
#include "hw4.h"
#include <unordered_map> 

using namespace std;

// 2 lines of input
// list_to_hash
// list_already_hashed
// Then hash list_to_hash with our own hash
// Print difference of our - list_already_hashed

//22 22 23 24 26 29

list_t subtract(list_t, list_t, list_t); 

class Hash{ 
  public: 
    list_t hash_test1(list_t, list_t); 
    list_t hash_test2(list_t, list_t);
    list_t subtract(list_t,list_t,list_t);
}; 

Hash fib_sum_hash, even_or_odd_hash, old_collisions_hash, subtract_list; 
  int old_hash1_ints, old_hash2_ints; 

int main(){
  
  list_t old_list = list_make();
  list_t old_list2 = list_make();
  list_t input = list_make(); 
  list_t fibhash = list_make();
  list_t fibsum = list_make();
  list_t already_hashed = list_make();
  list_t final_even_odd = list_make();  
  list_t differnece = list_make(); 

/*
  for (int i = 1; i <= 6; i++) {
    std::cin >> old_hash1_ints;
    old_list = list_make(old_hash1_ints, old_list);  
  }
*/
  old_list = reverse(old_list);
  cout << "\nold_hash_output:";
  list_print(old_list);

  cout << endl;

  for(int i = 1; i <= 6; i++){
    input = list_make(i, input);
  }

  input = reverse(input);
  //list_print(input);
/*
  fibsum = fib_sum_hash.hash_test1(old_list, input); // turn in to fib
  
    differnece = subtract(fibsum, old_list, differnece);
    cout << "\nfinal_diff_output:";
    differnece = reverse(differnece); 
    list_print(differnece); 
*/
    cout << endl;
    /////////////////////////Hash Test 2/////////////////////////
  cout << endl;
  cout << "Hast Test 2" << endl;

  for (int i = 1; i <= 6; i++) {
    std::cin >> old_hash2_ints;
    old_list2 = list_make(old_hash2_ints, old_list2);  
  }

  old_list = reverse(old_list2);
  cout << "\nold_hash_output: ";
  list_print(old_list);

  cout << endl;



  final_even_odd = even_or_odd_hash.hash_test2(old_list, input);

    //list_print(final_even_odd);
}

list_t subtract(list_t fibsum, list_t old_list, list_t differnece){
    //list_t final_diff_output = list_make(); 
    while(!list_isEmpty(fibsum)) {
      differnece = list_make(list_first(fibsum)-list_first(old_list), differnece); 
      old_list = list_rest(old_list);
      fibsum = list_rest(fibsum); 
    }
    return differnece;
}

list_t Hash::hash_test1 (list_t old_list, list_t input) {

    int key; 
    list_t final_list = list_make();
    list_t turn_into_fibsum = list_make(); 
    list_t final_diff_output = list_make(); 
    list_t original_input = input; 


    // get sum of old list

    int sumTotal = sum(input);

    while (!list_isEmpty(input)) {
        key = fib(list_first(input)) + sumTotal; 
        input = list_rest(input);
       final_list = list_make(key, final_list); 
    }

    final_list = reverse(final_list);
    return final_list;
}

bool prime(int n){
  //cout << n << endl;
  // 0 and 1 are not prime numbers
  if (n <= 1) {
    return true;
  }
      // Check from 2 to n-1 
  for (int i = 2; i <= n/2; i++) {
    if(n % i == 0){
      return true;
    }
  }

  return false; 
}

list_t Hash::hash_test2(list_t old_list, list_t input) {
  ////16 58 18 56 20 62

  int key, n;
  list_t even_list = list_make();
  list_t odd_list = list_make();
  list_t changed_even = list_make();
  list_t changed_odd = list_make();
  list_t odd_prod_sum = list_make();
  list_t even_prod_sum = list_make();
  list_t odd_primes = list_make();
  list_t filter_odd_primes = list_make();
  list_t combined_list = list_make();

  

  even_list = filter_even(input);
  changed_even = even_list;
  cout << endl;
  odd_list = filter_odd(input);
  changed_odd = odd_list;
   
  while(!list_isEmpty(changed_odd)) { 
    key = list_first(changed_odd); 
    odd_prod_sum = list_make(key + product(odd_list), odd_prod_sum); 
    changed_odd = list_rest(changed_odd); 
  }

  //odd_primes = odd_prod_sum;  
  //list_print(odd_prod_sum); 

  changed_odd = odd_list;
  cout << "this is changed_odd"; list_print(changed_odd);
  cout << endl;


  filter_odd_primes = filter(odd_prod_sum, *prime);
  
  list_print(filter_odd_primes);

  list_t odd_sum = list_make();
  
  changed_even = even_list;

  while(!list_isEmpty(even_list)) {
    key = list_first(even_list); 
    changed_even = list_make(sum(filter_odd_primes)+key, changed_even);
    changed_even = reverse(changed_even);
    changed_even = list_rest(changed_even); 
    changed_even = reverse(changed_even);
     even_list = list_rest(even_list); 
  }
  reverse(changed_even);
  list_print(changed_even); 

  // Combine both list
  //list_t list_make(changed_even);

  //reverse(list_t list)

  combined_list = insert_list(filter_odd_primes, changed_even, 3);

// while (!list_isEmpty(changed_even) && !list_isEmpty(odd_prod_sum)) {
//     final_manip_list = list_make(list_first(odd_prod_sum), final_manip_list);
//     final_manip_list = list_make(list_first(new_even), final_manip_list);
//     new_even = list_rest(new_even); 
//     odd_prod_sum = list_rest(odd_prod_sum); 
//   }

  list_print(combined_list);
  
  
  //cout << "this is odd_add_sum"; list_print(odd_add_sum);
  return odd_list;

}

/*
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
