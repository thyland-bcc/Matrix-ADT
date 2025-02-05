#include <iostream>
#include <string>
using namespace std;

struct Matrix
{
    string name;
    int row1col1;
    int row1col2;
    int row2col1;
    int row2col2;
};

void get_matrix(string& name, Matrix& m) {
    m.name = name;
    cout << "Enter value for Row 1 Column 1: ";
    cin >> m.row1col1;

    cout << "Enter value for Row 1 Column 2: ";
    cin >> m.row1col2;

    cout << "Enter value for Row 2 Column 1: ";
    cin >> m.row2col1;
    
    cout << "Enter value for Row 2 Column 2: ";
    cin >> m.row2col2;
}

void get_scalar(int& k) {
    cout << "Enter a scalar value: ";
    cin >> k;
}

void calc_sum(const Matrix& m1, const Matrix& m2, Matrix& sum) {
    sum.row1col1 = m1.row1col1 + m2.row1col1;
    sum.row1col2 = m1.row1col1 + m2.row1col2;
    sum.row2col1 = m1.row1col2 + m2.row1col1;
    sum.row2col2 = m1.row1col2 + m2.row1col2;
}

void calc_diff(const Matrix& m1, const Matrix& m2, Matrix& diff) {
    diff.row1col1 = m1.row1col1 - m2.row1col1;
    diff.row1col2 = m1.row1col1 - m2.row1col2;
    diff.row2col1 = m1.row1col2 - m2.row1col1;
    diff.row2col2 = m1.row1col2 - m2.row1col2;
}

void scalar_mult(int& k, Matrix m, Matrix k_m) {
    k_m.row1col1 = k * m.row1col1;
    k_m.row1col2 = k * m.row1col2;
    k_m.row2col1 = k * m.row2col1;
    k_m.row2col2 = k * m.row2col2;
}

void calc_prod(Matrix m1, Matrix m2, Matrix prod) {
    prod.row1col1 = (m1.row1col1 * m2.row1col1) + (m1.row1col2 * m2.row2col1);
    prod.row1col2 = (m1.row1col1 * m2.row1col2) + (m1.row1col2 * m2.row2col2);
    prod.row2col1 = (m1.row2col1 * m2.row1col1) + (m1.row2col2 * m2.row2col1);
    prod.row2col2 = ((m1.row2col1 * m2.row1col2) + (m1.row2col2 * m2.row2col2));
}

void calc_inverse(Matrix m, Matrix m_inv) {
    int determinant((m.row1col1 * m.row2col2) - (m.row2col1 * m.row1col2));

    m_inv.row1col1 = m.row2col2 / determinant;
	m_inv.row1col2 = -m.row1col2 / determinant;
	m_inv.row2col1 = -m.row2col1 / determinant;
	m_inv.row2col2 = m.row1col1 / determinant;
}

void print_matrix(string name, Matrix m) {
    cout << "Matrix: " + name;
    cout << "[" + to_string(m.row1col1) + " " + to_string(m.row1col2) + "]";
	cout << "[" + to_string(m.row2col1) + " " + to_string(m.row2col2) + "]";
}

int main()
{
}