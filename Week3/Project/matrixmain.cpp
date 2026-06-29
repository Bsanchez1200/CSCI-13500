#include <iostream>

// Declaration of Print2DArray so other functions can use it to print results.
void Print2DArray(const int matrix_local[][3], const int matrix_local_rows_total);

void Print2DArray(const int matrix_local[][3], const int matrix_local_rows_total) {
    std::cout << "--- Print2DArray Started ---\n";
    
 
    for (int i = 0; i < matrix_local_rows_total; ++i) {
        std::cout << "[";
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix_local[i][j];
            if (j < 2) {
                std::cout << "|";
            }
        }
        std::cout << "]\n";
    }
    
    std::cout << "--- Print2DArray Ended ---\n\n";
}

void MatrixAddition(const int matrix_one[][3], const int matrix_one_rows_total,
                    const int matrix_two[][3], const int matrix_two_rows_total) {
    std::cout << "--- MatrixAddition Started ---\n";

    // Since specifications state no case checking for mismatched dimensions 

    int result[3][3] = {0};


    for (int i = 0; i < matrix_one_rows_total; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = matrix_one[i][j] + matrix_two[i][j];
        }
    }

    std::cout << "Resulting Matrix:\n";
    Print2DArray(result, matrix_one_rows_total);

    std::cout << "--- MatrixAddition Ended ---\n\n";
}

void TransposeMatrix(const int matrix_local[][3], const int matrix_local_rows_total) {
    std::cout << "--- TransposeMatrix Started ---\n";

    // Standard parameter passes a max of 3 columns. 
 
    int transposed[3][3] = {0}; 


    for (int i = 0; i < matrix_local_rows_total; ++i) {
        for (int j = 0; j < 3; ++j) {
            transposed[j][i] = matrix_local[i][j];
        }
    }

    std::cout << "Resulting Transposed Matrix:\n";
    // Columns of the transposed matrix equals matrix_local_rows_total
    for (int i = 0; i < 3; ++i) {
        std::cout << "[";
        for (int j = 0; j < matrix_local_rows_total; ++j) {
            std::cout << transposed[i][j];
            if (j < matrix_local_rows_total - 1) {
                std::cout << "|";
            }
        }
        std::cout << "]\n";
    }

    std::cout << "--- TransposeMatrix Ended ---\n\n";
}

void Determinant(const int matrix_local[][3], const int size) {
    std::cout << "--- Determinant Started ---\n";

    // Check for valid square dimensions 
    if (size < 2 || size > 3) {
        std::cout << "Invalid dimensions for determinant calculation.\n";
        std::cout << "--- Determinant Ended ---\n\n";
        return;
    }

    if (size == 2) {
        int det = (matrix_local[0][0] * matrix_local[1][1]) - (matrix_local[0][1] * matrix_local[1][2]);
        std::cout << "Determinant of 2x2 Matrix: " << det << "\n";
    } 
    else if (size == 3) {
        int det = matrix_local[0][0] * (matrix_local[1][1] * matrix_local[2][2] - matrix_local[1][2] * matrix_local[2][1])
                - matrix_local[0][1] * (matrix_local[1][0] * matrix_local[2][2] - matrix_local[1][2] * matrix_local[2][0])
                + matrix_local[0][2] * (matrix_local[1][0] * matrix_local[2][1] - matrix_local[1][1] * matrix_local[2][0]);
        std::cout << "Determinant of 3x3 Matrix: " << det << "\n";
    }

    std::cout << "--- Determinant Ended ---\n\n";
}

void SearchValue(const int matrix_local[][3], const int rows, const int target) {
    std::cout << "--- SearchValue Started ---\n";

    bool found = false;


    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matrix_local[i][j] == target) {
                std::cout << "Found " << target << " at [" << i << "][" << j << "]\n";
                found = true;
            }
        }
    }

    if (!found) {
        std::cout << "Target " << target << " was not found in the matrix\n";
    }

    std::cout << "--- SearchValue Ended ---\n\n";
}

void MatrixMultiplication(const int matrix_a[][3], const int matrix_b[][3],
                          const int rows_a, const int cols_a,
                          const int rows_b, const int cols_b) {
    std::cout << "--- MatrixMultiplication Started ---\n";

    // Validate  dimensions match for matrix multiplication
    if (cols_a != rows_b) {
        std::cout << "Invalid arrays: Columns of A must equal Rows of B.\n";
        std::cout << "--- MatrixMultiplication Ended ---\n\n";
        return;
    }

    int result[3][3] = {0};


    for (int i = 0; i < rows_a; ++i) {
        for (int j = 0; j < cols_b; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols_a; ++k) {
                result[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    std::cout << "Resulting Matrix:\n";
    for (int i = 0; i < rows_a; ++i) {
        std::cout << "[";
        for (int j = 0; j < cols_b; ++j) {
            std::cout << result[i][j];
            if (j < cols_b - 1) {
                std::cout << "|";
            }
        }
        std::cout << "]\n";
    }

    std::cout << "--- MatrixMultiplication Ended ---\n\n";
}

int main() {
    int testing_matrix_one[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    int testing_matrix_two[3][3] = {
        {12, 65, 82},
        {83, 2,  8},
        {10, 96, 67}
    };

    int size_row_one = sizeof(testing_matrix_one) / sizeof(testing_matrix_one[0]);
    int size_col_one = sizeof(testing_matrix_one[0]) / sizeof(testing_matrix_one[0][0]);

    int size_row_two = sizeof(testing_matrix_two) / sizeof(testing_matrix_two[0]);
    int size_col_two = sizeof(testing_matrix_two[0]) / sizeof(testing_matrix_two[0][0]);

    std::cout << "row: " << size_row_one << " col: " << size_col_one << std::endl << std::endl;

    // Testing all implementations sequentially
    Print2DArray(testing_matrix_one, size_row_one);
    MatrixAddition(testing_matrix_one, size_row_one, testing_matrix_two, size_row_two);
    TransposeMatrix(testing_matrix_one, size_row_one);
    Determinant(testing_matrix_one, size_row_one);
    SearchValue(testing_matrix_one, size_row_one, 5);
    MatrixMultiplication(testing_matrix_one, testing_matrix_two, size_row_one, size_col_one, size_row_two, size_col_two);

    return 0;
}