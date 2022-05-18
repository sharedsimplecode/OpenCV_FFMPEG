#include "rtspstreamer.h"

ConcurrentQueue<Mat> frameQ;
int main(int argc, char** argv)
{
    RTSPStreamer streamer(&frameQ, "rtsp://rtsp.stream/pattern");
    streamer.start();

    std::string main_window_name     = "MAIN_DISPLAY";
    namedWindow(main_window_name, cv::WINDOW_NORMAL);
    resizeWindow(main_window_name, 700, 400);

    while(true)
    {
        Mat frame;
        if (frameQ.try_pop(frame))
            imshow(main_window_name, frame);

        int c = (char)cv::waitKey(5);
        if (c == 27 || c == 'q')
    	    break;
    }

    streamer.stop();
    return 0;
}

//OPENCV_FFMPEG_CAPTURE_OPTIONS = "video_codec;h264_cuvid"
