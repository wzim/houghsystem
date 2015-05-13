#pragma once
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

#pragma unmanaged
class CannyInit {
	public:	
		Mat src;
		Mat src_gray;
		Mat dst;
		Mat detected_edges;
		int edgeThresh;
		int lowThreshold;
		int static const max_lowThreshold = 100;
		int ratio;
		int kernel_size;
		char* window_name;
		CannyInit(void);
};

#pragma managed
ref class CannyAlg
{
	private: 
		CannyInit* c;
		delegate void ChangeThresholdDelegate(int Th, void *param);
		ChangeThresholdDelegate^ ChangeThresholdDelegateInstance;
		cv::TrackbarCallback ChangeThresholdCallbackPointer;
		void init();
	public:
		CannyAlg(void);
		void CannyThreshold(int, void*);
		void setSource(std::string img);
};

