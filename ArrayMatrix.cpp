// Name: Jaia Falls
// Section: CS 210 - 05
// Date: October 7, 2026
/*
How the Single-Index Hack Works

When you write mat[r][c], the compiler parses it from
left to right as (mat[r])[c].mat[r] triggers your
overloaded operator[](size_t row), which performs
bounds checking on the row and returns a memory address
(T*) pointing exactly to the first element of that row.
The remaining [c] evaluates natively against that
returned pointer using standard C++ pointer arithmetic
(pointer + c), shifting right to the correct column.
Note: While elegant, a downside to this raw-pointer
method is that the secondary [c] step bypasses your
class logic, meaning column-level bounds checking cannot
be safely handled at runtime.
*/

#include "ArrayMatrix.h"
int main() {
    // TODO: Create matrices to demonstrate use of ALL
    //       methods in ArrayMatrix class.
    try {
        //1. Constructor
        std::cout << "1. testing constructor and getters:\n";
        ArrayMatrix<int> mat1(2,3,5);
        std::cout << "matrix 1 rows: " <<mat1.rows() << ", cols: " << mat1.cols() <<"\n";
        std::cout << "matrix 1 contents:\n";
        mat1.print();
        std::cout <<"\n";
        //2. subscript operator
        std::cout << "2. testing subscript operator:\n";
        mat1[0][0] = 1;
        mat1[0][1] = 2;
        mat1[0][2] = 3;
        mat1[1][0] = 4;
        mat1[1][1] = 5;
        mat1[1][2] = 6;
        std::cout << "modified matrix 1, double brakets:\n";
        mat1.print();
        std::cout <<"\n";
        //3. copy construtor
        std::cout << "3. test copy constructor:\n";
        ArrayMatrix<int> mat2(mat1);
        std::cout << "matrix 2 copied from matrix 1:\n";
        mat2.print();
        std::cout <<"\n";
        //4. copy assignment operator
        std::cout << "4. testing copy assignment operator:\n";
        ArrayMatrix<int> mat3(2,3,0);
        mat3 = mat2;
        std::cout << "matrix 3 after assignment:\n";
        mat3.print();
        std::cout <<"\n";
        //5. matrix addition operator
        std::cout << "5. testing matrix addition operators:\n";
        ArrayMatrix<int> matAddResult = mat1 + mat3;
        std::cout << "matrix 1 + matrix3 Resuly:\n";
        matAddResult.print();
        std::cout <<"\n";
        //6. Matrix multiplication operator
        std::cout << "6. testing matrix multiplication:\n";
        ArrayMatrix<int> matMultiplier(3,2,3);
        std::cout << "matrix multipler (3x2):\n";
        matMultiplier.print();

        ArrayMatrix<int> matMultResult = mat1 * matMultiplier;
        std::cout << "Matrix 1 * matrix multiplier result:\n";
        matMultResult.print();
        std::cout << "\n";

        //7. Output stream operator
        std::cout << "7. testing output stream operator\n";
        std::cout << "printing matrix 1 using std::cout << mat1:\n"<< mat1 << "\n";


    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    // Use streams to init and output
    // Create a 2x3 matrix for user input
    ArrayMatrix<int> mat(2, 3);

    // Prompt user input using standard stream extraction (cin)
    std::cout << "Enter 6 integer values for a 2x3 matrix (separated by spaces or newlines):\n";
    // TODO: cin statement
    stf::cin >> mat;
    // Output the matrix formatting cleanly via custom insertion stream
    std::cout << "\nYou entered the following matrix:\n";
    // TODO: cout statement
    std::cout << mat;
    return 0;
}
