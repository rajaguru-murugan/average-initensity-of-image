# average-initensity-of-an-image
To calculate the mean intensity of all the pixels of a given image.

Write a program in C++ to calculate the average intensity of the image. (Do mention if any optimization is possible to reduce complexity but still can give approximate results)

        - The program calculates a straight forward average of all the pixel values.
        - It is slower to access all the pixel, especially if the images are large.
        - Since most of the real world images have a spatial connection, any color or a bright spot we see is a group of similar pixels.
        - Thus by resizing the image to a lower size drastically reduces the computational cost!
        - The images are resized to a constant size to have a constant compuational effort and time.
        - Also the calculation is repeated for 100 cycles to average the run time.
        - Inputs:
                > argument 1: path to image file
                > argument 2: To enable or disable optimization

Details on how to use the programs
==================================
To Compile:
==========
        cd build/
        make avg_intensity

To execute:
==========
        cd build
        
Runs with a default image included in data\/

        ./avg_intensity ../data/img_3.jpg 0
        
Change the last parameter to 1 for optimization

        ./avg_intensity ../data/img_3.jpg 1

Development environment:
=======================
1. Ubuntu/Linux OS
1. Opencv for C++ --version=4.4
