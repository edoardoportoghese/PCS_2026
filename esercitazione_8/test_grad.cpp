#include "grad_coniugato.hpp"
using namespace std;
using namespace Eigen;
int main()
{
    MatrixXd A(3,3);
    A << 4, 1, 0,
         1, 3, 1,
         0, 1, 2;

    VectorXd b(3);
    b << 1, 2, 3;

    VectorXd x0 = VectorXd::Zero(3);

    int iter_max = 100;
    double tol_rel = 1e-8;

    VectorXd x = gradienteConiugato(A, b, x0, iter_max, tol_rel);

    cout << "Soluzione x:\n" << x << endl;

    return 0;
}