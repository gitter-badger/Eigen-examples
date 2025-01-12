#include <iostream>
#include <Eigen/Dense>

#include "examples.h"

void exInstance() {
	std::cout << "-------- Representing a matrix and a vector --------" << std::endl;
	std::cout << "-mat1, mat2, mat3, and mat4 all represent 2 by 2 matricies." << std::endl;
	std::cout << "-mat1 is declared explicitly with a fixed size (2 by 2) consisting of int." << std::endl;
	Eigen::Matrix<int, 2, 2> mat1;
	std::cout << "-mat2 is declared using a typedef definition identical to the type mat1 uses." << std::endl;
	Eigen::Matrix2i mat2;
	std::cout << "-mat3 is declared explicitly with a dynamic size consisting of int." << std::endl;
	std::cout << "-The Matrix constructor, which accepts the dimensions of the matrix, is called (2 by 2)." << std::endl;
	Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic> mat3(2, 2);
	std::cout << "-mat4 is declared using a typedef definition identical to the type mat3 uses, and calls the constructor similarly." << std::endl;
	Eigen::MatrixXi mat4(2, 2);
	std::cout << "-vec1 is declared explicitly as a fixed 2 by 1 matrix (vertical size first) consisting of int. Vectors are treated as a special case of matricies." << std::endl;
	Eigen::Matrix<int, 2, 1> vec1;
	std::cout << "-vec2 is declared using a typedef definition identical to the type vec1 uses." << std::endl;
	Eigen::Vector2i vec2;
	std::cout << "-vec3 is declared explicitly as a \"Dynamic\" by 1 matrix consisting of int, and a constructor is called to set the vertical size to 2." << std::endl;
	Eigen::Matrix<int, Eigen::Dynamic, 1> vec3(2);
	std::cout << "-vec4 is declared using a typedef definition identical to the type vec3 uses." << std::endl;
	Eigen::VectorXi vec4(2);
	std::cout << std::endl;

	std::cout << "-Parenthesis operators are overloaded so they can be used to access an element in the matrix. They are 0-indexed." << std::endl;
	std::cout << "-mat3 will now be assigned the following matrix:" << std::endl;
	std::cout << "1 3" << std::endl;
	std::cout << "2 4" << std::endl;
	mat3(0, 0) = 1;
	mat3(1, 0) = 2;
	mat3(0, 1) = 3;
	mat3(1, 1) = 4;
	std::cout << "-First argument is row index, followed by col index." << std::endl;
	std::cout << "-The lhs << operator is also overloaded so mat3 can be displayed easily:" << std::endl;
	std::cout << mat3 << std::endl;
	std::cout << "-The rhs << operator is overloaded for easy matrix assignment." << std::endl;
	std::cout << "-mat4 will now be assigned the same matrix as mat3." << std::endl;
	mat4 << 1, 3,
		    2, 4;
	std::cout << "-Displaying mat4:" << std::endl;
	std::cout << mat4 << std::endl;
	std::cout << "-Similarly assigning and displaying vec4:" << std::endl;
	vec4 << 2,
		    3;
	std::cout << vec4 << std::endl;
	std::cout << std::endl;
}

void exMultiply() {
	std::cout << "-------- Multiplying matricies together --------" << std::endl;
	std::cout << "mat[number] are arbitrary matricies." << std::endl;
	std::cout << "mat1 is a dynamic 2 by 2 integer matrix." << std::endl;
	Eigen::MatrixXi mat1(2, 2);
	mat1 << 2, 3,
		    5, 7;
	std::cout << "mat 1 has the values:" << std::endl;
	std::cout << mat1 << std::endl;
	std::cout << "ident2 is a dynamic 2 by 2 integer identity matrix:" << std::endl;
	Eigen::MatrixXi ident2 = Eigen::MatrixXi::Identity(2, 2);
	std::cout << ident2 << std::endl;
	std::cout << "mat1 * ident2 == mat1:" << std::endl;
	std::cout << mat1 * ident2 << std::endl;
	std::cout << std::endl;

	std::cout << "mat2 is a dynamic 3 by 3 integer matrix." << std::endl;
	Eigen::MatrixXi mat2(3, 3);
	mat2 << 2, -3,  1,
		    5,  7, -9,
		   -4,  6,  8;
	std::cout << "mat2 has the values:" << std::endl;
	std::cout << mat2 << std::endl;
	std::cout << "mat1 * mat2 is not good since mat1's width and mat2's height does not match." << std::endl;
	//std::cout << mat1 * mat2 << std::endl;
	std::cout << "mat3 is a dynamic 2 by 3 integer matrix." << std::endl;
	Eigen::MatrixXi mat3(2, 3);
	mat3 << 1, 2, 3,
		    4, 5, 6;
	std::cout << "mat3 has the values:" << std::endl;
	std::cout << mat3 << std::endl;
	std::cout << "mat3 * mat2 is valid:" << std::endl;
	std::cout << mat3 * mat2 << std::endl;
	std::cout << "but mat2 * mat3 is not valid." << std::endl;
	//std::cout << mat2 * mat3 << std::endl;
	std::cout << "mat4 is a dynamic 3 by 2 integer matrix." << std::endl;
	Eigen::MatrixXi mat4(3, 2);
	mat4 << 1, 2,
		    3, 4,
		    5, 6;
	std::cout << "mat4 has the values:" << std::endl;
	std::cout << mat4 << std::endl;
	std::cout << "mat3 * mat4 is valid:" << std::endl;
	std::cout << mat3 * mat4 << std::endl;
	std::cout << "mat4 * mat3 is also valid:" << std::endl;
	std::cout << mat4 * mat3 << std::endl;
	std::cout << std::endl;

	std::cout << "Here is an example of converting a vector into a new basis using a square change of basis matrix and converting it back." << std::endl;
	std::cout << "trans1 is the change of basis matrix:" << std::endl;
	Eigen::MatrixXd trans1(3, 3);
	trans1 << 2,  7, 13,
		      3,  9, 17,
		      5, 11, 19;
	std::cout << trans1 << std::endl;
	std::cout << "vec1 is the vector in the standard basis:" << std::endl;
	Eigen::VectorXd vec1(3);
	vec1 << 1,
		    1,
		    1;
	std::cout << vec1 << std::endl;
	std::cout << "vec2 is vec1 in the new basis:" << std::endl;
	Eigen::VectorXd vec2 = trans1 * vec1;
	std::cout << vec2 << std::endl;
	std::cout << "trans1inv is the inverse of trans1:" << std::endl;
	Eigen::MatrixXd trans1inv = trans1.inverse();
	std::cout << trans1inv << std::endl;
	std::cout << "vec3 is vec2 in the original basis (should be equal to vec1):" << std::endl;
	Eigen::VectorXd vec3 = trans1inv * vec2;
	std::cout << vec3 << std::endl;
	std::cout << std::endl;
}