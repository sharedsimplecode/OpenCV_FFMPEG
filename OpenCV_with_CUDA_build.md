# OPENCV Installation with cuda support

## Requirements:
  	Please ensure the FFMPEG with cuda support has been added. 


## Install dependencies

	sudo apt -y install build-essential checkinstall cmake pkg-config yasm
	sudo apt -y install git gfortran
	sudo apt -y install libjpeg8-dev libpng-dev
	sudo apt -y install libssl-dev

	sudo apt -y install software-properties-common
	sudo add-apt-repository "deb http://security.ubuntu.com/ubuntu xenial-security main"
	sudo apt -y update

	sudo apt -y install libjasper1
	sudo apt -y install libtiff-dev

	sudo apt -y install libxine2-dev libv4l-dev
	cd /usr/include/linux
	sudo ln -s -f ../libv4l1-videodev.h videodev.h
	cd "$cwd"

	sudo apt -y install libgtk2.0-dev libtbb-dev qt5-default
	sudo apt -y install libatlas-base-devmake -j$(nproc)
	sudo make -j$(nproc) install
	sudo apt -y install libfaac-dev libmp3lame-dev libtheora-dev
	sudo apt -y install libvorbis-dev libxvidcore-dev
	sudo apt -y install libopencore-amrnb-dev libopencore-amrwb-dev
	sudo apt -y install libavresample-dev
	sudo apt -y install x264 v4l-utils

## Optional dependencies

	sudo apt -y install libprotobuf-dev protobuf-compiler
	sudo apt -y install libgoogle-glog-dev libgflags-dev
	sudo apt -y install libgphoto2-dev libeigen3-dev libhdf5-dev doxygen

### Step 3: Install Python Libraries

	sudo apt -y install python3-dev python3-pip
	sudo -H pip3 install -U pip numpy
	sudo apt -y install python3-testresources


## now install python libraries within this virtual environment

	pip install wheel numpy scipy matplotlib scikit-image scikit-learn ipython dlib

	python3 -m pip install --user virtualenv


## download opencv


	wget -O opencv_4.5.0.zip https://github.com/opencv/opencv/archive/4.5.0.zip
	unzip opencv_4.5.0.zip
	wget -O opencv-contrib_4.5.0.zip https://github.com/opencv/opencv_contrib/archive/refs/tags/4.5.0.zip
	unzip opencv-contrib_4.5.0.unzip

## build OpenCV

	cd opencv_4.5.0 & mkdir build
	cd build

	cmake -D CMAKE_BUILD_TYPE=RELEASE \
		  -D CMAKE_INSTALL_PREFIX=/usr/local \
		  -D WITH_CUDA=ON \
		  -D WITH_DNN=ON \
		  -D WITH_DNN_CUDA=ON \
		  -D WITH_CUDNN=ON \
		  -D OPENCV_DNN_CUDA=ON \
		  -D CUDA_FAST_MATH=ON   \
		  -D WITH_NVCUVID=ON \
		  -D WITH_QT=OFF \
		  -D WITH_FFMPEG=ON \
		  -D WITH_OPENGL=ON \
		  -D WITH_OPENCL=ON \
		  -D WITH_GTK=ON \
		  -D WITH_GTK_2_X=ON \
		  -D WITH_V4L=ON \
		  -D ENABLE_FAST_MATH=1 \
		  -D CUDA_FAST_MATH=1 \
		  -D WITH_CUBLAS=1 \
		  -D CUDA_ARCH_BIN=6.1 \
		  -D BUILD_TBB=ON \
		  -D BUILD_TESTS=OFF \
		  -D WITH_CUDEV=ON \
		  -D BUILD_PERF_TESTS=OFF \
		  -D WITH_GSTREAMER=ON \
		  -D OPENCV_ENABLE_NONFREE:BOOL=ON \
		  -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-4.5.0/modules ..

	make -j$(nproc)
	sudo make -j$(nproc) install
