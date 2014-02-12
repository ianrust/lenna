#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;

typedef enum
{
	START = 0,
	FIRST_CORNER = 1,
	LAST_CORNER = 2,
	DRAWING_FORE = 3,
	DRAWING_BACK = 4,
	DONE = 5
} uiState;

void operator--(uiState & lastState,int)
{
	int intState=static_cast<int>(lastState)-1;
	lastState=static_cast<uiState>(intState);
}


static uiState selectState = START;
static string  windowName = "Display Image";
Scalar annoColor = Scalar(255,255,255);
Scalar bgdColor = Scalar(GC_BGD);
Scalar fgdColor = Scalar(GC_FGD);

CvPoint startRect;
CvPoint endRect;
Mat image;
Mat startImage;
Mat mask;
Mat startMask;
Mat grabbedImage;
Mat finalImage;
std::vector<Point> backPoints;
std::vector<Point> forePoints;

static std::string num2str(int num);
void refreshImage();
void runGrabCut();
void assembleArts();

static void onMouse(int event, int x, int y, int, void*) 
{
	if (event == EVENT_LBUTTONUP)
	{

		if (selectState == START)
		{
			startRect.x=x;
			startRect.y=y;

			selectState=FIRST_CORNER;
		}
		else if (selectState == FIRST_CORNER)
		{
			endRect.x=x;
			endRect.y=y;

			selectState=LAST_CORNER;
		}
		else if (selectState == DRAWING_FORE)
		{
			forePoints.push_back(Point(x,y));
		}
		else if (selectState == DRAWING_BACK)
		{
			backPoints.push_back(Point(x,y));
		}
		refreshImage();
	}
}

void assembleArts()
{
	Mat edges;
		
	Canny(grabbedImage,edges,50,150);
	
	int x0,y0,x1,y1;

	if (startRect.x>endRect.x)
	{
		x0=endRect.x;
		x1=startRect.x;
	}
	else
	{
		x1=endRect.x;
		x0=startRect.x;
	}

	if (startRect.y>endRect.y)
	{
		y0=endRect.y;
		y1=startRect.y;
	}
	else
	{
		y1=endRect.y;
		y0=startRect.y;
	}

  	finalImage = Mat(Size((x1-x0)*3,y1-y0),CV_8UC3,Scalar(132,254,255));
	Mat blurMan = finalImage.colRange(0,x1-x0);
	Mat blackMan = finalImage.colRange(x1-x0,2*(x1-x0));
	Mat greenMan = finalImage.colRange(2*(x1-x0),3*(x1-x0));
	

	Mat edgeMask=edges(Rect(x0,y0,x1-x0,y1-y0)).clone();
        edgeMask = (edgeMask == 255);	
	blackMan.setTo(Scalar(0,0,0),edgeMask);
	
	Mat blur = blurMan.clone();
	blur.setTo(Scalar(0,100,0),edgeMask);
	addWeighted(blurMan,0.85,blur,0.15,0.0,blurMan);
	GaussianBlur(blurMan,blurMan,Size(3,7),2,6);
	
	Mat edgeMaskHalfFull = edgeMask.clone();
	Mat edgeMaskToClear = edgeMaskHalfFull.rowRange(0,(int)(0.3*(y1-y0)));
	edgeMaskToClear.setTo(Scalar(0));
	greenMan.setTo(Scalar(0,255,0),edgeMaskHalfFull);
	

	
	imshow("finalImage",finalImage);
}


void runGrabCut()
{
	Mat fgd,bgd;
	image.release();
	startImage.copyTo(image);
	
	grabCut(image,mask,Rect(startRect,endRect),fgd,bgd,2,GC_INIT_WITH_RECT);
	
	Mat fgdMask = (mask == GC_FGD) | (mask == GC_PR_FGD);

	image.copyTo(grabbedImage,fgdMask);
	
	
}

void refreshImage()
{
	image.release();
	startImage.copyTo(image);
	mask.release();
	startMask.copyTo(mask);
	if (selectState < LAST_CORNER)
	{
		imshow(windowName,image);
	}
	else if (selectState == LAST_CORNER)
	{
		rectangle(image,startRect,endRect,annoColor);
		imshow(windowName,image);
		selectState=DRAWING_FORE;
		forePoints.clear();
	}
	else if (selectState == DRAWING_FORE)
	{	
		rectangle(image,startRect,endRect,annoColor);
		polylines(image,forePoints,false,annoColor);
		
		polylines(mask,forePoints,false,fgdColor);

		imshow(windowName,image);

		backPoints.clear();
	}
	else if (selectState == DRAWING_BACK)
	{	
		rectangle(image,startRect,endRect,annoColor);
		polylines(image,backPoints,false,Scalar(0,0,0));
		polylines(image,forePoints,false,annoColor);
	
		polylines(mask,forePoints,false,fgdColor);
		polylines(mask,backPoints,false,bgdColor);

		imshow(windowName,image);
	}
}

int main( int argc, char** argv )
{
  image = imread( argv[1], 1 );
  startImage = image.clone();
  mask = Mat(image.size(),CV_8UC1,bgdColor);
  startMask = mask.clone();

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

  
	if (key == 27)
	{
		if ((int)selectState > 0)
		{
			selectState--;
		}

		refreshImage();
	}
	else if (key==101 & selectState == DRAWING_FORE)
	{
		selectState=DRAWING_BACK;
	}
	else if (key==101 & selectState == DRAWING_BACK)
	{
		runGrabCut();

		assembleArts();
	}
	
  }

}

static std::string num2str(int num) 
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}
