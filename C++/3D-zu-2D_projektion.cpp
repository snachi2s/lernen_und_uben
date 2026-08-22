#include<iostream>
using namespace std;

struct Point2D{
    float u,v;
};

struct Point3D{
    float X, Y, Z;
};

struct CameraParams{
    float focal_x, focal_y, cx, cy;
};

Point2D project3Dto2D(Point3D worldPoints){
    CameraParams intrinsicValues = {800, 800, 320, 240};
    Point2D imgPoints;
    imgPoints.u = (intrinsicValues.focal_x * (worldPoints.X/worldPoints.Z)) + intrinsicValues.cx;
    imgPoints.v = (intrinsicValues.focal_y * (worldPoints.Y/worldPoints.Z)) + intrinsicValues.cy;
    return imgPoints;
}

int main(){

    //variables
    Point3D worldPoints;

    cout << "Geben Sie die 3D Punkte ein"<<endl;
    cout<<"X:";
    cin>>worldPoints.X;
    cout<<"Y:";
    cin>>worldPoints.Y;
    cout<<"Z:";
    cin>>worldPoints.Z;

    Point2D imgPoints = project3Dto2D(worldPoints);
    cout<<"Die 2D-Koordinaten sind: "<<endl;
    cout<<"u: "<<imgPoints.u<<endl;
    cout<<"v: "<<imgPoints.v<<endl;
    
    return 0;
}