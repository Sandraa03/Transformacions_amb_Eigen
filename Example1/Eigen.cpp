#include <iostream>

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

int main()
{
	Eigen::Vector3d va; //va is a vector in R³
	Eigen::Vector3d vb; //vb is another vector in R³
	va << 1,2,3; //fill the vector va
	vb << -1,-1,0; //fill the vector vb
	double norm_va = va.norm(); //|va|
	double dot_vab = va. dot(vb); //va^T · vb
	Eigen::Vector3d cross_vab = va.cross(vb); //va x vb
	std::cout << "va x vb is" << cross_vab.transpose() << std::endl << std::endl;

	Eigen::Matrix<double, 4, 6> M1;
	Eigen::Matrix3d M2;

	M1 << 1, 2, 3, 4, 5, 6, 0, 0, 0, 0, 0, 0, 99, 99, 99, 99, 99, 99, 0, 0, 0, 0, 0, 0;
	M2 << Eigen::Matrix3d::Zero();

	M2(1,2) = M2.cols();

	std::cout << M1 << std::endl << std::endl << M2 << std::endl;

	return 0;
}