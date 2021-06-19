//---------------------------------------------//
//  Assignments for an Interview - 04 June'21  //
//                                             //
// Calculates the Average intensity of a image //
//---------------------------------------------//

#include <iostream>
#include <bits/stdc++.h>
#include <unistd.h>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

#include "../include/StopWatch.h"

using namespace std;
using namespace cv;

int calc_mean_intensity(cv::Mat &img);

//==========================================================//
int main(int argc, char** argv) 
{
        int mean_intensity;

        //__Read the image__//
        string img_name = "../data/img_3.jpg";
        if (argc > 1) img_name = argv[1];
        
        Mat img = imread(img_name);
        if (!img.data) {
            cout<< "Error: Invalid image!"<<endl;
            return 0;
        }
        
        //__Optimization option__//
        int performance = 0;
        if (argc > 2) performance = stoi(argv[2]);
        
        StopWatch watch;
        double start_time = watch.time();
        
        //__Convert to Grayscale__//
        //if (img.channels() == 3) cv::cvtColor(img, img, COLOR_BGR2GRAY); 
        
        //Averaging the run time
        int cycles = 100;
        for (int k=0; k<cycles; k++) {

                Mat new_img = img;
                if (performance == 1) {
                    //Optimized by resizing the image (Resizing to a const size for a const runtime)
                    cv::resize(new_img, new_img, cv::Size(100,100), 0, 0, INTER_NEAREST);
                }
                
                //__Calculate the Mean intensity__//
                mean_intensity = calc_mean_intensity(new_img);
        }

        double stop_time = watch.time();
        
        cout <<"Average intensity: \t"<< mean_intensity << endl;
        cout <<"Average Time:\t\t" << (stop_time - start_time)/cycles << " milli secs" << endl;
         
return 0;
}
//==========================================================//

//__Calculate the Mean intensity__//
int calc_mean_intensity(cv::Mat &img)
{
        float mean_intensity = 0.0f;
        for (unsigned int i=0; i<img.total()*img.channels(); i++) {
            mean_intensity += *(img.data + i);      //sum all pixels
        }
        mean_intensity /= (img.total()*img.channels());
        
        return (int)mean_intensity;
}

