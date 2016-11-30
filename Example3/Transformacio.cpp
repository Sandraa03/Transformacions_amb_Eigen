#include <iostream>
#include <cmath>

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

int main()
{
	//Definim les variables (angles en rad)

	Eigen::Vector3d qB, qO;

	//Localització
	double theta_deg = 30;
	Eigen::Vector3d pO; 
	pO << 50,25,1;

	//Calibració
	double beta_deg = 25;
	Eigen::Vector3d mB;
	mB << 1.5, 0.75, 1;

	//Mesura
	Eigen::Vector3d qs;
	qs << 12, 5, 1;

	double theta_rad = (M_PI/180)*theta_deg;
	double beta_rad = (M_PI/180)*beta_deg;


	Eigen::Matrix3d TS_B; //Matriu Transformació de S a B
	TS_B << cos(beta_rad), -sin(beta_rad), mB(0), sin(beta_rad), cos(beta_rad), mB(1), 0, 0, 1;
	qB = TS_B*qs;


	Eigen::Matrix3d TB_O; //Matriu Transformació de B a O
	TB_O << cos(theta_rad), -sin(theta_rad), pO(0), sin(theta_rad), cos(theta_rad), pO(1), 0, 0, 1;
	qO = TB_O*qB;

	std::cout << "qO calculat multiplicant qs per la matriu de Transformació corresponent i el resultat per la matriu de Transformació corresponent:" << std::endl;
	std::cout << qO << std::endl << std::endl;

	//Comprovem que es el mateix que multiplicar primer les matrius i després per el punt.
	Eigen::Matrix3d TS_O; //Matriu Transformació de S a O
	TS_O = TB_O * TS_B;
	qO = TS_O * qs;

	std::cout << "qO calculat multiplicant les matrius de Transformació corresponents per aconseguir la matriu de Transformació TS_O i després pel punt qs:" << std::endl;
	std::cout << qO << std::endl;

	return 0;
}








