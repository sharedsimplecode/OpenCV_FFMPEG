# FFMPEG installation with Hardware Acceleration

## 1.  dependencies
	sudo apt install yasm
	sudo apt-get -y install build-essential autoconf automake cmake libtool git
	sudo apt install libfreetype6-dev
	sudo apt install libx264-dev libx265-dev

## 2. nv-codec-headers Insallation for FFMPEG:

	git clone https://git.videolan.org/git/ffmpeg/nv-codec-headers.git
	cd nv-codec-headers
	make
	sudo make install

## Video_Codec_SDK_9.0.20.zip (download from https://developer.nvidia.com/video-codec-sdk-archive)
	unzip Video_Codec_SDK_9.0.20.zip
	cd Video_Codec_SDK_9.0.20/include
	sudo cp *.h /usr/local/cuda-11.1/include/

## 3.3 FFmpeg source code

	wget https://ffmpeg.org/releases/ffmpeg-3.4.8.tar.gz
	tar xvf ffmpeg-3.4.8.tar.gz
	cd ffmpeg-3.4.8


	./configure --prefix="$HOME/lib/ffmpeg_build" \
				--extra-cflags="-I$HOME/lib/ffmpeg_build/include -I/usr/local/cuda/include" \
				--extra-ldflags="-L$HOME/lib/ffmpeg_build/lib -L/usr/local/cuda/compat -L/usr/local/cuda/lib64" \
				--extra-libs="-lpthread -lm"  \
				--bindir="$HOME/bin" \
				--enable-cuda --enable-cuvid --enable-nvenc --enable-shared --enable-static \
				--enable-ffplay --enable-nonfree --enable-libnpp --enable-gpl  --enable-libx264 \
				--enable-libx265 --enable-libfreetype


	make -j$(nproc)
	make install

	cd $HOME/lib/ffmpeg_build/lib/pkgconfig
	sudo cp *.pc /usr/local/lib/pkgconfig/

	edit ~/.bashrc and append this
	export PATH=/home/lscm/Project/BINGO2/lib/ffmpeg_build/include:$PATH

	echo "export PATH=$HOME/lib/ffmpeg_build/include:$PATH" >> ~/.bashrc
	sudo ldconfig
