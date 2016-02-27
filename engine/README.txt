Setting up GE with CMake:

mkdir build
cd build

Windows:
	32-Bit:
		cmake -G "Visual Studio 14 2015 Win64" ..
	64-Bit:
		cmake -G "Visual Studio 14 2015" ..
	Cygwin:
		cmake -G "Unix Makefiles" ..
	MinGW:
		cmake -G "MinGW Makefiles" ..
	
Linux:
	cmake -G "Unix Makefiles" ..
