#include<iostream>
using namespace std;
#include<stdexcept>

struct Point2D{
    double u;
    double v;
};

struct Point3D{
    double X;
    double Y;
    double Z;
};

struct CameraParams{
    double focal_x;
    double focal_y;
    double cx;
    double cy;
};


Point2D project3Dto2D(const Point3D& worldPoints){ 
    //worldpoints here is reference --> if we dont want to modify the object (if we know the values are fixed throughout the function)
    CameraParams intrinsicValues = {800, 800, 320, 240};

    if(worldPoints.Z <= 0){
        throw invalid_argument("Z not valid");
    }

    //pass by reference
    Point2D imgPoints;
    imgPoints.u = (intrinsicValues.focal_x * (worldPoints.X/worldPoints.Z)) + intrinsicValues.cx;
    imgPoints.v = (intrinsicValues.focal_y * (worldPoints.Y/worldPoints.Z)) + intrinsicValues.cy;
    return imgPoints;

    //pass by value
    double u = (intrinsicValues.focal_x * (worldPoints.X/worldPoints.Z)) + intrinsicValues.cx;
    double v = (intrinsicValues.focal_y * (worldPoints.Y/worldPoints.Z)) + intrinsicValues.cy;
    return {u, v};

}

int main(){

    //variables
    Point3D worldPoints;

    cout << "Geben Sie den 3D Punkte ein"<<endl;
    cout<<"X:";
    cin>>worldPoints.X;
    cout<<"Y:";
    cin>>worldPoints.Y;
    cout<<"Z:";
    cin>>worldPoints.Z;

    try{
        Point2D imgPoints = project3Dto2D(worldPoints);
        cout<<"Die 2D-Koordinaten sind: "<<endl;
        cout<<"u: "<<imgPoints.u<<endl;
        cout<<"v: "<<imgPoints.v<<endl;
    }
    catch(const invalid_argument& e){
        cout << "Fehler: " << e.what() << endl;
    }
    
    return 0;
}