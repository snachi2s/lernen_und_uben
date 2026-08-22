#include<iostream>
using namespace std;
#include <vector>

struct BoundingBox{
    float x_min;
    float y_min;
    float x_max;
    float y_max;
    float score;
};

void printBoxes(const vector<BoundingBox>& boxes){
    cout<<"Bounding Boxes:"<<endl;
    for(const auto& box:boxes){
        cout<<"x_min: "<<box.x_min<<", y_min: "<<box.y_min<<", x_max: "<<box.x_max<<", y_max: "<<box.y_max<<", score: "<<box.score<<endl;
    }
}

float calculateIoU(const BoundingBox& predictbox, const BoundingBox& groundtruthbox){
    
    //find intersection coordinates
    float x_min_intersection = max(predictbox.x_min, groundtruthbox.x_min);
    float y_min_intersection = max(predictbox.y_min, groundtruthbox.y_min);

    float x_max_intersection = min(predictbox.x_max, groundtruthbox.x_max);
    float y_max_intersection = min(predictbox.y_max, groundtruthbox.y_max);

    //intersection width and height
    float intersection_width = max(0.0f, x_max_intersection - x_min_intersection);
    float intersection_height = max(0.0f, y_max_intersection - y_min_intersection);

    float intersectionArea = intersection_width * intersection_height;

    //union
    float predictBoxArea = (predictbox.x_max - predictbox.x_min) * (predictbox.y_max - predictbox.y_min);
    float groundtruthBoxArea = (groundtruthbox.x_max - groundtruthbox.x_min) * (groundtruthbox.y_max - groundtruthbox.y_min);   

    float unionArea = predictBoxArea + groundtruthBoxArea - intersectionArea;

    return intersectionArea / unionArea;
}

int main(){

    //sample boxes as vectors (used simple vector initialization)
    //other ways: boxes.push_back(BoundingBox box1) or boxes.insert(boxes.begin(), box1)
    vector<BoundingBox> predictedBoxes = {     
        {1.0, 20.0, 50.0, 80.0, 0.9},
        {15.0, 25.0, 55.0, 85.0, 0.8},
        {2.0, 22.0, 52.0, 82.0, 0.95}
    };

    vector<BoundingBox> groundtruthBoxes = {
        {11.0, 21.0, 51.0, 81.0, 1.0},
        {14.0, 24.0, 54.0, 84.0, 1.0},
        {13.0, 23.0, 53.0, 83.0, 1.0}
    };

    //printBoxes(predictedBoxes);

    //IoU = intersection area / union area
    for (int i=0; i<predictedBoxes.size(); i++){
        float iou = calculateIoU(predictedBoxes[i], groundtruthBoxes[i]);
        cout<<"IoU Scores --> Box ["<<i<<"]"<<iou<<endl;
    }

    return 0;
}