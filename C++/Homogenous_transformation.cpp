#include <iostream>
#include <cmath>
#include <eigen3/Eigen/Dense>
#include <sophus/so3.hpp>
#include <sophus/se3.hpp>

int main(){
    using Sophus::SO3d;
    using Sophus::SE3d;
    using Eigen::Vector3d;

    double theta = M_PI / 2.0;
    SO3d R = SO3d::exp(Vector3d(0, 0, theta)); //about Z-axis
    Vector3d p(0.1, 0, 0);
    std::cout<<"Rotation Matrix:\n"<<R.matrix()<<std::endl; //R internally stores the values as quaternion 

    SE3d T_joint(R, Vector3d::Zero()); //joint transformation
    SE3d T_link(SO3d(), Vector3d(1, 0, 0)); //link transformation
    // SO3d() --> just a constructor to feed in Identity rotation matrix
    SE3d T_end = T_joint * T_link; //end-effector transformation

    std::cout<<"End-effector Transformation:\n"<<T_end.matrix()<<std::endl;
    std::cout<<"Tip position:\n"<<T_end.translation().transpose()<<std::endl;
    
}