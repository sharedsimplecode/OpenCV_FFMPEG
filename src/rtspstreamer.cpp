#include "rtspstreamer.h"

#include <chrono>
using namespace std::chrono;


RTSPStreamer::RTSPStreamer( ConcurrentQueue<Mat> *pFrameQ, string url):
                _pFrameQ(pFrameQ),
                _url(url)
{

    _on = true;
    _pause = false;
}

string RTSPStreamer::getDateTimeString()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%Y-%m-%d_%H-%M-%S",timeinfo);
    std::string str(buffer);
    return str;
}

void RTSPStreamer::run()
{
    Mat frame;
    _pCap.set(cv::CAP_PROP_BUFFERSIZE, 1);

    LOG(INFO) << "Opencv VideoCapture opening " << _url << "\n";
    auto start = chrono::system_clock::now();
    _pCap.open(_url, cv::CAP_FFMPEG);
    auto end = chrono::system_clock::now();

    LOG(INFO) << "Successfully connected in " << duration_cast<milliseconds>(end - start).count() << " ms\n";



    auto startEvery     = chrono::steady_clock::now();
    int measureEvery    = 1000;
    int counter = 0;
    float total_dur = 0;
    while(_on)
    {
        auto start = chrono::system_clock::now();
        _pCap >> frame;
        auto end = chrono::system_clock::now();
        float dur = duration_cast<milliseconds>(end - start).count();
        total_dur += dur;

        if (frame.empty()) break;

        _pFrameQ->push(frame);

        std::this_thread::sleep_for(30ms);
        counter++;

        LOG_EVERY_N(INFO, 100) << "Decoding time = " << total_dur/counter << " ms/frame" << endl;
    }
    _pCap.release();
}



void RTSPStreamer::start()
{
    _threadHandle = std::thread(&RTSPStreamer::run, this);
}

void RTSPStreamer::stop()
{
    _on = false;
    _threadHandle.join();
}
