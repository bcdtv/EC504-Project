#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_header(string header){
  cout << endl;
  cout << "=================== " << header << " ===================";
  cout << endl;
}

void print_footer(){
  cout << "================================================================";
  cout << endl << endl;
}

vector<int> generate_numbers(){
  // declare parameters
  int N;
  int MIN_INT;
  int MAX_INT;

  // request parameters
  cout << "N: ";
  cin >> N;
  cout << "MIN_INT: ";
  cin >> MIN_INT;
  cout << "MAX_INT: ";
  cin >> MAX_INT;

  // validate given parameters
  if (N <= 0){
    cout << "Error: N is not greater than 0" << endl;
    vector<int> empty;
    return empty;
  }
  if (MIN_INT >= MAX_INT){
    cout << "Error: MIN_INT is not less than MAX_INT" << endl;
    vector<int> empty;
    return empty;
  }
  
  // generate numbers and store into vector
  vector<int> numbers(N);
  srand(time(NULL));
  for (int i=0; i<N; i++){
    numbers[i] = MIN_INT + (rand() % (MAX_INT-MIN_INT+1));
  }

  // display the numbers
  cout << "Random numbers: ";
  for (int i=0; i<numbers.size(); i++){
    cout << numbers[i] << " ";
  }
  cout << endl;

  return numbers;
}

#endif
