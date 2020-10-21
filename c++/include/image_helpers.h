#ifndef IMAGE_HELPERS_H_
#define IMAGE_HELPERS_H_

#include "opencv2/opencv.hpp"

#define BYTE	unsigned char
//.size() is meant to describe a rectangle. .size works for multi-dimensional mats
static void PrintImageSize(const cv::Mat& input)
{
    int dimensions = input.dims;
    int channels = input.channels();
    std::cout << "Dims: " << dimensions << " Chan: " << channels << " - ";
    for(int i = 0; i < dimensions; i++)
    {
        std::cout << input.size[i] << ", ";
    }
    std::cout << std::endl;
}

static void DrawFloat_1_Image(const cv::Mat& input, const std::string& windowName, float scale = 255.0)
{
    cv::Mat converted;
    input.convertTo(converted,CV_8U,scale);
    cv::Mat output;
    cv::Mat in[] = {converted,converted,converted};
    cv::merge(in,3,output);
    cv::imshow(windowName, output);
    cv::waitKey(1);
}

static void PrintImagePixelValues(const cv::Mat& input)
{
    for(int x = 0; x < input.rows; x++)
     {
       for(int y = 0; y < input.cols; y++)
       {
            int val = input.at<uchar>(x,y);
            std::cout <<"val " << val << std::endl;
       }
     }
}

BYTE g_pbyContrastLUT[256] = { 0,  15,  22,  27,  31,  35,  39,  42,  45,  47,  50,  52,  55,
        57,  59,  61,  63,  65,  67,  69,  71,  73,  74,  76,  78,  79,
        81,  82,  84,  85,  87,  88,  90,  91,  93,  94,  95,  97,  98,
        99, 100, 102, 103, 104, 105, 107, 108, 109, 110, 111, 112, 114,
       115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
       128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140,
       141, 141, 142, 143, 144, 145, 146, 147, 148, 148, 149, 150, 151,
       152, 153, 153, 154, 155, 156, 157, 158, 158, 159, 160, 161, 162,
       162, 163, 164, 165, 165, 166, 167, 168, 168, 169, 170, 171, 171,
       172, 173, 174, 174, 175, 176, 177, 177, 178, 179, 179, 180, 181,
       182, 182, 183, 184, 184, 185, 186, 186, 187, 188, 188, 189, 190,
       190, 191, 192, 192, 193, 194, 194, 195, 196, 196, 197, 198, 198,
       199, 200, 200, 201, 201, 202, 203, 203, 204, 205, 205, 206, 206,
       207, 208, 208, 209, 210, 210, 211, 211, 212, 213, 213, 214, 214,
       215, 216, 216, 217, 217, 218, 218, 219, 220, 220, 221, 221, 222,
       222, 223, 224, 224, 225, 225, 226, 226, 227, 228, 228, 229, 229,
       230, 230, 231, 231, 232, 233, 233, 234, 234, 235, 235, 236, 236,
       237, 237, 238, 238, 239, 240, 240, 241, 241, 242, 242, 243, 243,
       244, 244, 245, 245, 246, 246, 247, 247, 248, 248, 249, 249, 250,
       250, 251, 251, 252, 252, 253, 253, 254, 255};
       
#endif //IMAGE_HELPERS_H_