#indicate minimum version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#project name
PROJECT(Transformacio)

#find required packages (look for the package, usually at /usr/share/cmake-2.8/Modules/ or /usr/share/)

#set header directories

#Create an executable
ADD_EXECUTABLE(${PROJECT_NAME} Transformacio.cpp)

#Link with libraries