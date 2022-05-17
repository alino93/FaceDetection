#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Face Detection with Cascade Classifier //////////////////////

void main() {

    string path = "Resources/test.png";
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgEdge, imgDil;

    CascadeClassifier faceCascade;
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");
    
    vector<Rect> faces;

    faceCascade.detectMultiScale(img, faces, 1.1, 10);

    for (int i = 0; i < faces.size(); i++)
    {
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 150, 0), 3);
    }
    imshow("Image", img);

    waitKey(0);


}
