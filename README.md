## Building

### Debug

    node-gyp --debug rebuild

## Issues

### Windows 64-bit

    cmake -G "Visual Studio 10 Win64" -DCMAKE_BUILD_TYPE=Debug -DENABLE_DEBUG=yes -DAPPS_TO_BUILD="cppwrapper cppreference"
    cmake -G "Visual Studio 10 Win64" -DCMAKE_BUILD_TYPE=Release -DAPPS_TO_BUILD="cppwrapper cppreference"

**skypekit\cmake_modules\Buildflags\Windows-msvc.cmake**

    if (ENABLE_DEBUG)
    	add_definitions(-DDEBUG -D_DEBUG /MTd)
	<...>
    else (ENABLE_DEBUG)
    	add_definitions(-DNDEBUG /MT)