#include <iostream>
#include <vector>
 
int main() {

  // 3x3 zero-initialized array
  int size3 = 3;
  std::vector<std::vector<int>> arr3(size3, std::vector<int>(size3, 0));
 
  // 6x6 zero-initialized array
  int size6 = 6;
  std::vector<std::vector<int>> arr6(size6, std::vector<int>(size6, 0));
 
  std::cout << "Task 1" << std::endl;
 
  //  Apply pattern to 3x3 
  for (int i = 0; i < size3; ++i) {
    for (int j = 0; j < size3; ++j) {
      if (j < size3 - i) {
        arr3[i][j] = 1;
      } else {
        arr3[i][j] = 0;
      }
    }
  }
 
  //  Print 3x3 
  std::cout << "// Result for the 3x3 array" << std::endl;
  for (int i = 0; i < size3; ++i) {
    std::cout << "[";
    for (int j = 0; j < size3; ++j) {
      std::cout << arr3[i][j];
      if (j < size3 - 1) {
        std::cout << "|";
      }
    }
    std::cout << "]" << std::endl;
  }
 
  //  Apply pattern to 6x6 
  for (int i = 0; i < size6; ++i) {
    for (int j = 0; j < size6; ++j) {
      if (j < size6 - i) {
        arr6[i][j] = 1;
      } else {
        arr6[i][j] = 0;
      }
    }
  }
 
  // Print 6x6 
  std::cout << "// Result for the 6x6 array" << std::endl;
  for (int i = 0; i < size6; ++i) {
    std::cout << "[";
    for (int j = 0; j < size6; ++j) {
      std::cout << arr6[i][j];
      if (j < size6 - 1) {
        std::cout << "|";
      }
    }
    std::cout << "]" << std::endl;
  }
 
  std::cout << std::endl << "Task 2" << std::endl;
 
  //  Apply X pattern to 3x3 
  for (int i = 0; i < size3; ++i) {
    for (int j = 0; j < size3; ++j) {
      if (i == j || j == size3 - 1 - i) {
        arr3[i][j] = 1;
      } else {
        arr3[i][j] = 0;
      }
    }
  }
 
  //  Print 3x3 
  std::cout << "// 3x3 array" << std::endl;
  for (int i = 0; i < size3; ++i) {
    std::cout << "[";
    for (int j = 0; j < size3; ++j) {
      std::cout << arr3[i][j];
      if (j < size3 - 1) {
        std::cout << "|";
      }
    }
    std::cout << "]" << std::endl;
  }
 
  //  Apply X pattern to 6x6 
  for (int i = 0; i < size6; ++i) {
    for (int j = 0; j < size6; ++j) {
      if (i == j || j == size6 - 1 - i) {
        arr6[i][j] = 1;
      } else {
        arr6[i][j] = 0;
      }
    }
  }
 
  //  Print 6x6 
  std::cout << "// 6x6 array" << std::endl;
  for (int i = 0; i < size6; ++i) {
    std::cout << "[";
    for (int j = 0; j < size6; ++j) {
      std::cout << arr6[i][j];
      if (j < size6 - 1) {
        std::cout << "|";
      }
    }
    std::cout << "]" << std::endl;
  }
 
  std::cout << std::endl << "=== Task 3 ===" << std::endl;
 
  int n3 = 3;
  std::vector<std::vector<int>> vec3 = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
 
  // Print the source matrix
  std::cout << "// 3x3 vector" << std::endl;
  for (int i = 0; i < n3; ++i) {
    std::cout << "[";
    for (int j = 0; j < n3; ++j) {
      std::cout << vec3[i][j];
      if (j < n3 - 1) {
        std::cout << "|";
      }
    }
    std::cout << "]" << std::endl;
  }
 
  // Build the 2xn summary matrix (all zeros to start)
  std::vector<std::vector<int>> sums(2, std::vector<int>(n3, 0));
 
  for (int i = 0; i < n3; ++i) {
    for (int j = 0; j < n3; ++j) {
      sums[0][i] += vec3[i][j];  // row i sum goes into top row, column i
      sums[1][j] += vec3[i][j];  // col j sum goes into bottom row, column j
    }
  }
 
  // Print the 2xn result
  std::cout << "// Result: 2x" << n3
            << " array (top row = row sums, bottom row = col sums)"
            << std::endl;
  for (int i = 0; i < 2; ++i) {
    std::cout << "[";
    for (int j = 0; j < n3; ++j) {
      std::cout << sums[i][j];
      if (j < n3 - 1) {
        std::cout << "|";
      }
    }
    std::cout << "]" << std::endl;
  }
 
  std::cout << std::endl << "=== Task 4 ===" << std::endl;
 
  int n4 = 3;
  std::vector<std::vector<int>> vec4 = {
    {2, 1, 3},
    {0, 4, 0},
    {1, 2, 5}
  };
 
  // Print the source matrix
  std::cout << "// 3x3 array" << std::endl;
  for (int i = 0; i < n4; ++i) {
    std::cout << "[";
    for (int j = 0; j < n4; ++j) {
      std::cout << vec4[i][j];
      if (j < n4 - 1) {
        std::cout << "|";
      }
    }
    std::cout << "]" << std::endl;
  }
 
  // Compute diagonal sums
  int d1 = 0;  // main diagonal (top-left to bottom-right)
  int d2 = 0;  // anti-diagonal (top-right to bottom-left)
 
  for (int i = 0; i < n4; ++i) {
    d1 += vec4[i][i];
    d2 += vec4[i][n4 - 1 - i];
  }
 
  // For odd-sized matrices the centre element appears in both diagonals;
  // subtract it once so it is counted exactly once in the final total.
  int centre = 0;
  if (n4 % 2 != 0) {
    int mid = n4 / 2;
    centre = vec4[mid][mid];
  }
 
  int total = d1 + d2 - centre;
 
  std::cout << "// Diagonal sums" << std::endl;
  std::cout << "d1 = " << d1 << "  // main diagonal" << std::endl;
  std::cout << "d2 = " << d2 << "  // anti-diagonal" << std::endl;
  if (n4 % 2 != 0) {
    std::cout << "c  = " << centre
              << "  // centre element (counted once)" << std::endl;
  }
  std::cout << "// Total X-sum" << std::endl;
  std::cout << "S = d1 + d2 - c = " << total << std::endl;
 
  return 0;
}
 