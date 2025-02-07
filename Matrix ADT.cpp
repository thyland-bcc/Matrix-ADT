#include <iostream>
#include <string>
using namespace std;

struct Matrix 
{
    string name;
    float row1col1 = 0;
    float row1col2 = 0;
    float row2col1 = 0;
    float row2col2 = 0;
};

void get_matrix(string name, Matrix& m) {
    m.name = name;
    cout << "Matrix: " << name << endl;

    cout << "Enter value for Row 1 Column 1: ";
    cin >> m.row1col1;

    cout << "Enter value for Row 1 Column 2: ";
    cin >> m.row1col2;

    cout << "Enter value for Row 2 Column 1: ";
    cin >> m.row2col1;
    
    cout << "Enter value for Row 2 Column 2: ";
    cin >> m.row2col2;
}

void get_scalar(float& k) {
    cout << "Enter a scalar value: ";
    cin >> k;
}

void calc_sum(const Matrix& m1, const Matrix& m2, Matrix& sum) {
    sum.row1col1 = m1.row1col1 + m2.row1col1;
    sum.row1col2 = m1.row1col2 + m2.row1col2;
    sum.row2col1 = m1.row2col1 + m2.row2col1;
    sum.row2col2 = m1.row2col2 + m2.row2col2;
}

void calc_diff(const Matrix& m1, const Matrix& m2, Matrix& diff) {
    diff.row1col1 = m1.row1col1 - m2.row1col1;
    diff.row1col2 = m1.row1col2 - m2.row1col2;
    diff.row2col1 = m1.row2col1 - m2.row2col1;
    diff.row2col2 = m1.row2col2 - m2.row2col2;
}

void scalar_mult(float k, const Matrix& m, Matrix& k_m) {
    k_m.row1col1 = k * m.row1col1;
    k_m.row1col2 = k * m.row1col2;
    k_m.row2col1 = k * m.row2col1;
    k_m.row2col2 = k * m.row2col2;
}

void calc_prod(const Matrix& m1, const Matrix& m2, Matrix& prod) {
    prod.row1col1 = (m1.row1col1 * m2.row1col1) + (m1.row1col2 * m2.row2col1);
    prod.row1col2 = (m1.row1col1 * m2.row1col2) + (m1.row1col2 * m2.row2col2);
    prod.row2col1 = (m1.row2col1 * m2.row1col1) + (m1.row2col2 * m2.row2col1);
    prod.row2col2 = ((m1.row2col1 * m2.row1col2) + (m1.row2col2 * m2.row2col2));
}

void calc_inverse(const Matrix& m, Matrix& m_inv) {
    float determinant((m.row1col1 * m.row2col2) - (m.row2col1 * m.row1col2));
    if (determinant == 0) {
        cout << "Matrix is singular, unable to calculate inverse. \n";
        return;
    }
    m_inv.row1col1 = m.row2col2 / determinant;
	m_inv.row1col2 = -m.row1col2 / determinant;
	m_inv.row2col1 = -m.row2col1 / determinant;
	m_inv.row2col2 = m.row1col1 / determinant;
}

void print_matrix(string name, Matrix& m) {
    cout << "Matrix: " + name << endl;
    cout << "[" << m.row1col1 << " " << m.row1col2 << "]" << endl;
	cout << "[" << m.row2col1 << " " << m.row2col2 << "]" << endl;
}

int main() 
{
    Matrix m1, m2, sum, diff, k_m1, prod, m1_inv;
    float k;
    int choice = -1;

    while (choice !=0 )
    {
        cout << "Matrix Operation Program\n";
        cout << "1. Input Matrix 1 and Matrix 2\n";
        cout << "2. Input Scalar\n";
        cout << "3. Compute Sum (m1 + m2)\n";
        cout << "4. Compute Difference (m1 - m2)\n";
        cout << "5. Compute Scalar Multiplication (k * m1)\n";
        cout << "6. Compute Matrix Product (m1 * m2)\n";
        cout << "7. Compute Inverse of m1\n";
        cout << "8. Print Matrices\n";
        cout << "0. Exit\n";
        
        cout << "Enter your choice: \n";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                get_matrix("m1", m1);
                get_matrix("m2", m2);
                cout << "Matricies successfully stored.\n";
                print_matrix(m1.name, m1);
                print_matrix(m2.name, m2);
                break;

            case 2:
                get_scalar(k);
                cout << "Scalar successfully stored: " << k << endl;
                break;

            case 3:
                calc_sum(m1, m2, sum);
                print_matrix("Sum", sum);
                break;

            case 4:
                calc_diff(m1, m2, diff);
                print_matrix("Difference", diff);
                break;

            case 5:
                scalar_mult(k, m1, k_m1);
                print_matrix("Scalar Multiple", k_m1);
                break;

            case 6:
                calc_prod(m1, m2, prod);
                print_matrix("Product", prod);
                break;

            case 7:
                calc_inverse(m1, m1_inv);
                print_matrix("Inverse", m1_inv);
                break;

            case 8:
                print_matrix("M1", m1);
                print_matrix("M2", m2);
                break;
            
            case 0:
                cout << "Exiting program.";
                break;

            default:
                cout << "Invalid choice, please enter a number from the menu.\n";
                break;
        }
    }
    
}