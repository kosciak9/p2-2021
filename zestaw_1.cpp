#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <limits>

int* generate_random_array(int n) {
  int* array = new int[n];

  for (int i = 0; i < n; i++) {
    *(array + i) = (rand() % 11);
  };

  return array;
};

int find_biggest_value(int* array, int length) {
  int max = *array;
  for (int i = 0; i < length; i++) {
    if (*(array + i) > max) {
      max = *(array + i);
    }
  };

  return max;
};

void invert_array(int* array, int length) {
  for (int i = 0; i < length / 2; i++) {
    int tmp = *(array + i);
    *(array + i) = *(array + (length - 1) - i);
    *(array + (length - 1) - i) = tmp;
  };
};

void cyclic_move_array(int* array, int length, int step) {
  for (int j = 0; j < step; j++) {
    int first = *(array);
    for (int i = 0; i < length - 1; i++) {
      *(array + i) = *(array + i + 1);
    };
    *(array + length - 1) = first;
  }
};

void merge_arrays() {
  int a_length = 10;
  int* a_array = new int[a_length];

  std::cout << "A: ";
  for (int i = 0; i < a_length; i++) {
    *(a_array + i) = i * 2;
    std::cout << i * 2 << " ";
  };
  std::cout << std::endl;

  int b_length = 11;
  int* b_array = new int[b_length];

  std::cout << "B: ";
  for (int i = 0; i < b_length; i++) {
    *(b_array + i) = i * 3;
    std::cout << i * 3 << " ";
  };
  std::cout << std::endl;

  int a_index = 0;
  int b_index = 0;
  int merged_index = 0;
  int merged_length = a_length + b_length;
  int* merged_array = new int[merged_length];

  while (merged_index < a_length + b_length) {
    int a;
    if (a_index >= a_length) {
      a = std::numeric_limits<int>::max();
    } else {
      a = *(a_array + a_index);
    };

    int b;
    if (b_index >= b_length) {
      b = std::numeric_limits<int>::max();
    } else {
      b = *(b_array + b_index);
    };

    if (a < b) {
      *(merged_array + merged_index) = a;
      a_index++;
    } else {
      *(merged_array + merged_index) = b;
      b_index++;
    }

    merged_index++;
  };

  std::cout << "Merged: ";
  for (int i = 0; i < merged_length; i++) {
    std::cout << *(merged_array + i) << " ";
  };
  std::cout << std::endl;
};

int* multiply_polynomials(int* a_array, int a_length, int* b_array, int b_length) {
  int result_length = a_length + b_length - 1;
  int* result = new int[result_length];
  for (int i = 0; i < result_length; i++) {
    *(result + i) = 0;
  }

  for (int i = 0; i < a_length; i++) {
    for (int j = 0; j < b_length; j++) {
      *(result + i + j) += *(a_array + i) * *(b_array + j);
    }
  }

  return result;
}

int factorial(int n) {
  if (n > 1) {
    return n * factorial(n - 1);
  } else {
    return 1;
  }
}
void generate_newton_array(int N) {
  int** S = new int*[N];
  for (int i = 0; i < N; i++) {
    S[i] = new int[i+1];
    for (int j = 0; j < i; j++) {
      S[i][j] = factorial(i) / (factorial(i - j) * factorial(j));
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      std::cout << "you can select "<< j << " from " << i << " items in " << S[i][j]  << " ways" << std::endl;
    }
  }

  for (int i = 0; i < N; i++) {
      delete S[i];
  }
    delete S;
}

int main() {
  // random seed
  srand((unsigned) time(0));

  std::cout << "0. random array generation" << std::endl;
  int length = 10;
  int* A = generate_random_array(length);
  for (int i = 0; i < length; ++i) {
    std::cout << *(A + i) << " ";
  }
  std::cout << std::endl;

  std::cout << "1. biggest number: " << find_biggest_value(A, length) << std::endl;

  std::cout << "2. inverting array" << std::endl;
  invert_array(A, length);
  for (int i = 0; i < length; ++i) {
    std::cout << *(A + i) << " ";
  }
  std::cout << std::endl;

  std::cout << "3. cycle moving array" << std::endl;
  cyclic_move_array(A, length, 3);
  for (int i = 0; i < length; ++i) {
    std::cout << *(A + i) << " ";
  }
  std::cout << std::endl;

  std::cout << "4. merge arrays" << std::endl;
  merge_arrays();

  std::cout << "5. multiply polynomials" << std::endl;
  int left_length = 3;
  int* left = generate_random_array(left_length);
  int right_length = 2;
  int* right = generate_random_array(right_length);
  int* multiplication_result = multiply_polynomials(left, left_length, right, right_length);
  std::cout << "left: ";
  for (int i = 0; i < left_length; ++i) {
    std::cout << *(left + i) << " ";
  }
  std::cout << std::endl;
  std::cout << "right: ";
  for (int i = 0; i < right_length; ++i) {
    std::cout << *(right + i) << " ";
  }
  std::cout << std::endl;
  for (int i = 0; i < left_length + right_length - 1; ++i) {
    std::cout << *(multiplication_result + i) << " ";
  }
  std::cout << std::endl;

  std::cout << "6. newton's" << std::endl;
  generate_newton_array(10);

  return 0;
};
