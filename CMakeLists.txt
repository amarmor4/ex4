cmake_minimum_required(VERSION 3.6)
project(ex4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(SOURCE_FILES
        both/Block.cpp
        both/Block.h
        both/Cab.cpp
        both/Cab.h
        both/CarType.h
        both/Color.h
        both/Driver.cpp
        both/Driver.h
        both/LuxuryCab.cpp
        both/LuxuryCab.h
        both/Point.cpp
        both/Point.h
        both/Socket.cpp
        both/Socket.h
        both/StandardCab.cpp
        both/StandardCab.h
        both/Status.h
        both/Trip.cpp
        both/Trip.h
        client/CommunicationClient.cpp
        client/CommunicationClient.h
        client/UdpClient.cpp
        client/UdpClient.h
        server/Bfs.cpp
        server/Bfs.h
        server/CommunicationServer.cpp
        server/CommunicationServer.h
        server/GameFlow.cpp
        server/GameFlow.h
        server/Map.cpp
        server/Map.h
        server/Matrix.cpp
        server/Matrix.h
        server/Passenger.cpp
        server/Passenger.h
        server/TaxiCenter.cpp
        server/TaxiCenter.h
        server/UdpServer.cpp
        server/UdpServer.h
        )
set(BOOST_ROOT CACHE PATH "/usr/include/boost/")
find_package(Boost 1.57.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})


add_executable(Client ${SOURCE_FILES}
        both/Block.cpp
        both/Block.h
        both/Cab.cpp
        both/Cab.h
        both/CarType.h
        both/Color.h
        both/Driver.cpp
        both/Driver.h
        both/LuxuryCab.cpp
        both/LuxuryCab.h
        both/Point.cpp
        both/Point.h
        both/Socket.cpp
        both/Socket.h
        both/StandardCab.cpp
        both/StandardCab.h
        both/Status.h
        both/Trip.cpp
        both/Trip.h
        client/Client.cpp
        client/CommunicationClient.cpp
        client/CommunicationClient.h
        client/UdpClient.cpp
        client/UdpClient.h
        server/Map.cpp
        server/Map.h
        server/Matrix.cpp
        server/Matrix.h
        server/Bfs.cpp
        server/Bfs.h)
add_executable(Server ${SOURCE_FILES}
        server/Server.cpp
        both/Block.cpp
        both/Block.h
        both/Cab.cpp
        both/Cab.h
        both/CarType.h
        both/Color.h
        both/Driver.cpp
        both/Driver.h
        both/LuxuryCab.cpp
        both/LuxuryCab.h
        both/Point.cpp
        both/Point.h
        both/Socket.cpp
        both/Socket.h
        both/StandardCab.cpp
        both/StandardCab.h
        both/Status.h
        both/Trip.cpp
        both/Trip.h
        server/Bfs.cpp
        server/Bfs.h
        server/CommunicationServer.cpp
        server/CommunicationServer.h
        server/GameFlow.cpp
        server/GameFlow.h
        server/Map.cpp
        server/Map.h
        server/Matrix.cpp
        server/Matrix.h
        server/Passenger.cpp
        server/Passenger.h
        server/TaxiCenter.cpp
        server/TaxiCenter.h
        server/UdpServer.cpp
        server/UdpServer.h)

#add_executable(ex4 ${SOURCE_FILES})
#target_link_libraries(ex4 ${Boost_LIBRARIES})

target_link_libraries(Client ${Boost_LIBRARIES})
target_link_libraries(Server ${Boost_LIBRARIES})

#target_link_libraries(ex4 ${Boost_LIBRARIES})