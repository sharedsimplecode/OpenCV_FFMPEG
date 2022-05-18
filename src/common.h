#pragma once

#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
// #include "nlohmann/json.hpp"
#include <signal.h>

// std
#include <deque>
#include <thread>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>



// OPENCV INCLUDE
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp> // added


#include <glog/logging.h>
//
//
// // BOOST INCLUDE
// #include <boost/serialization/vector.hpp>
// #include <boost/serialization/string.hpp>
// #include <boost/archive/text_oarchive.hpp>
// #include <boost/archive/text_iarchive.hpp>
// #include <boost/archive/binary_oarchive.hpp>
// #include <boost/archive/binary_iarchive.hpp>
// #include <boost/serialization/utility.hpp>
// #include <boost/format.hpp>
// #include <boost/asio.hpp>
// #include <boost/filesystem.hpp>

// TBB ConcurrentQueue
#include <tbb/concurrent_unordered_map.h>
#include <tbb/concurrent_queue.h>
#include <tbb/concurrent_priority_queue.h>
template <typename T>
using ConcurrentQueue = tbb::concurrent_bounded_queue<T>;

template <typename T1,typename T2>
using ConcurrentHPQueue = tbb::concurrent_priority_queue<T1, T2>;
