#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <opencv2/opencv.hpp>

using namespace cv;

typedef enum uiState
{
	START = 0,
	FIRST_CORNER = 1,
	LAST_CORNER = 2,
	DRAWING = 3,
	DONE = 4
};

void operator--(uiState & lastState,int)
{
	int intState=static_cast<int>(lastState)-1;
	lastState=static_cast<uiState>(intState);
}


static uiState selectState = START;
static string  windowName = "Display Image";
Scalar annoColor = Scalar(255,255,255);

CvPoint startRect;
CvPoint endRect;
Mat image;
Mat startImage;

static std::string num2str(int num);
void refreshImage();

static void onMouse(int event, int x, int y, int, void*) 
{
	if (event == EVENT_LBUTTONUP)
	{

		std::cout << num2str(selectState) << std::endl;
		if (selectState == START)
		{
			startRect.x=x;
			startRect.y=y;

			std::cout << "first point" << std::endl;
			selectState=FIRST_CORNER;
		}
		else if (selectState == FIRST_CORNER)
		{
			endRect.x=x;
			endRect.y=y;

			std::cout << "last point" << std::endl;
			selectState=LAST_CORNER;
		}
		refreshImage();
		std::cout << "Click Up"  << std::endl;
	}
	if (event == EVENT_LBUTTONDOWN)
	{
		std::cout << "Click Down"  << std::endl;
	}
}

void refreshImage()
{
	if (selectState < LAST_CORNER)
	{
		std::cout << "going through ok" << std::endl;
		image.release();
		startImage.copyTo(image);
		imshow(windowName,image);
	}
	else if ((int)selectState < (int)DRAWING)
	{
		std::cout << "drawing image w/rect" << std::endl;
		rectangle(image,startRect,endRect,annoColor);
		imshow(windowName,image);
	}
}

int main( int argc, char** argv )
{
  image = imread( argv[1], 1 );
  startImage = image;

  if( argc != 2 || !image.data )
    {
      printf( "No image data \n" );
      return -1;
    }

  namedWindow(windowName, CV_WINDOW_AUTOSIZE );

  setMouseCallback(windowName,onMouse,0);

  imshow(windowName, image );

  int key = 0;
  while (key !=100)
  {
  	key = waitKey(0);

  	std::cout << num2str(key) << std::endl;
  
	if (key == 27)
	{
		if ((int)selectState > 0)
		{
			selectState--;
		}
		refreshImage();
	}
  }

}

static std::string num2str(int num) 
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}
