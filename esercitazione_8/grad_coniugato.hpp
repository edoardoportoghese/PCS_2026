#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

// Metodo del Gradiente Coniugato
VectorXd gradienteConiugato(const MatrixXd& A,const VectorXd& b,const VectorXd& x0,int iter_max,double tol_rel)
{
    VectorXd x = x0;

    // r = b - A*x
    VectorXd r = b - A * x;

    // p = r
    VectorXd p = r;

    double norm_b = b.norm();

    int k = 0;

    while (k < iter_max && r.norm() / norm_b > tol_rel)
    {
        // alpha = (r^T r) / (p^T A p)
        double alpha = r.dot(r) / p.dot(A * p);

        // x_{k+1} = x_k + alpha * p_k
        x = x + alpha * p;

        // r_{k+1} = r_k - alpha * A p_k
        VectorXd r_new = r - alpha * A * p;

        // beta = (r_{k+1}^T r_{k+1}) / (r_k^T r_k)
        double beta = r_new.dot(r_new) / r.dot(r);

        // p_{k+1} = r_{k+1} + beta * p_k
        p = r_new + beta * p;

        // aggiorna residuo
        r = r_new;

        k++;
    }


    return x;
}