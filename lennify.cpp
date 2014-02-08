#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <opencv2/opencv.hpp>

using namespace cv;

static int selectState = 0;
static char * windowName = "Display Image";

static std::string num2str(int num);

static void onMouse(int event, int x, int y, int, void*) 
{
	std::cout << std::endl;
	std::cout << "EVENT:" << num2str(event) << std::endl;
	std::cout << "X:" << num2str(x) << std::endl;
	std::cout << "Y:" << num2str(y) << std::endl;
}

int main( int argc, char** argv )
{
  Mat image;
  image = imread( argv[1], 1 );

  if( argc != 2 || !image.data )
    {
      printf( "No image data \n" );
      return -1;
    }

  namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );

  setMouseCallback("Display Image",onMouse,0);

  imshow( "Display Image", image );



  waitKey(0);

  return 0;
}

static std::string num2str(int num) 
{
	std::stringstream ss;

	ss << num;

	return ss.str();
}
