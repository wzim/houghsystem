#include "CannyAlg.h"

CannyInit::CannyInit(void)
{
	this->edgeThresh = 1;
	this->ratio = 3;
	this->kernel_size = 3;
	this->window_name = "Edge Map";
}

CannyAlg::CannyAlg(void)
{
	this->c = new CannyInit();

	this->ChangeThresholdDelegateInstance = gcnew ChangeThresholdDelegate(this, &CannyAlg::CannyThreshold);
	System::IntPtr delegatePointer = System::Runtime::InteropServices::Marshal::GetFunctionPointerForDelegate(this->ChangeThresholdDelegateInstance);
	this->ChangeThresholdCallbackPointer = reinterpret_cast<cv::TrackbarCallback>(delegatePointer.ToPointer());
}

void CannyAlg::CannyThreshold(int, void*)
{
	/// Reduce noise with a kernel 3x3
	cv::blur(this->c->src_gray, this->c->detected_edges, cv::Size(3,3) );

	/// Canny detector
	cv::Canny(this->c->detected_edges, this->c->detected_edges, this->c->lowThreshold, this->c->lowThreshold * this->c->ratio, this->c->kernel_size );

	/// Using Canny's output as a mask, we display our result
	this->c->dst = cv::Scalar::all(0);

	this->c->src.copyTo(this->c->dst, this->c->detected_edges);
	cv::imshow(this->c->window_name, this->c->dst);
}

void CannyAlg::setSource(std::string img)
{
	this->c->src = cv::imread(img);
	if(!this->c->src.data) throw "Brak obrazu do wczytania!";
	this->init();
}

void CannyAlg::init()
{
	this->c->dst.create(this->c->src.size(), this->c->src.type() );

	/// Convert the image to grayscale
	cv::cvtColor(this->c->src, this->c->src_gray, CV_BGR2GRAY);

	/// Create a window
	cv::namedWindow(this->c->window_name, CV_WINDOW_AUTOSIZE);

	/// Create a Trackbar for user to enter threshold
	cv::createTrackbar( "Min Threshold:", this->c->window_name, &this->c->lowThreshold, this->c->max_lowThreshold, this->ChangeThresholdCallbackPointer);
}

