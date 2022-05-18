#pragma once

#include "common.h"
#include <atomic>

using namespace cv;
using namespace std;
// /#include "detector/detector.h"
//#include "streamer/synchronizer.h"

class RTSPStreamer
{
	std::thread 		_threadHandle;
	std::atomic<bool> 	_on;
	std::atomic<bool>   _pause;


	std::string	_url;

	ConcurrentQueue<Mat> *_pFrameQ;

	cv::VideoCapture _pCap;


public:
	RTSPStreamer(ConcurrentQueue<Mat> *_pFrameQ, string url);
	//~RTSPStreamer();

	void run();
	void start();
	void stop();

	std::string getDateTimeString();

	int nextFrameCap(cv::Mat &frame);
};
