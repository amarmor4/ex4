#include <iostream>
//#include "gtest/gtest.h"
#include "Matrix.h"
#include "Map.h"
#include "Bfs.h"
#include "GameFlow.h"
#include "CommunicationServer.h"
#include "../both/Udp.h"
#include <unistd.h>

using namespace std;

int main(int args, char **argv) {
    /**
     * get input from user.
     * width of map >> height of map >> x value of start point >>
     * y value of start point >> x value of end point >> y value of end point.
     * format: 4_4,3_2,1_2
     */
    int sizeX, sizeY, numOfObstacles;
    char c;
    cin >> sizeX >> sizeY;

    // create matrix.
    //Matrix matrix(sizeX, sizeY);
    Matrix matrix(6, 6);
    // save matrix address at map object.
    Map *map = &matrix;
    Bfs bfs(map);


    cin >> numOfObstacles;
    if (numOfObstacles > 0) {
        map->setObstacles(numOfObstacles);
    }

//    if (args < 2) {
//        cout << stderr << " ERROR, no port provided" << endl;
//        exit(0);
//    }
//   int portNo = atoi(argv[1]);

//    CommunicationServer *communication = new CommunicationServer();
//
//       communication->startCommunicate();

    std::cout << "Hello, from server" << std::endl;
    GameFlow *g = new GameFlow(map, atoi(argv[1]));
    g->startGame();


// delete (communication);

    delete (g);


//    testing::InitGoogleTest(&args, argv);
//    return RUN_ALL_TESTS();

//    Point *gp2;
//    boost::iostreams::basic_array_source<char> device(serial_str.c_str(), serial_str.size());
//    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
//    boost::archive::binary_iarchive ia(s2);
//    ia >> gp2;
//
//    cout << *gp2;



//    UdpServer udp(1, 5555);
//    udp.initialize();
//
//    char buffer[1024];
//    std::string serial_str;
//    udp.reciveData(buffer, sizeof(buffer));
//
//    //Trip *gp=new Trip(map,0,new Point(0,0),new Point(1,0),1,2,1);
//    Point *gp = new Point(1,5);
//
//    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
//    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
//    boost::archive::binary_oarchive oa(s);
//    oa << gp;
//    s.flush();
//
//    cout << serial_str << endl;
//    Point *gp2;
//    boost::iostreams::basic_array_source<char> device(serial_str.c_str(), serial_str.size());
//    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
//    boost::archive::binary_iarchive ia(s2);
//    ia >> gp2;
//
//    cout << *gp2 << endl;
//
//    cout << buffer << endl;
//    udp.sendData("sup?");




//
//    usleep(5000);
//    UdpServer udp2(1, 5554);
//    udp2.initialize();
//
//    char buffer2[1024];
//    udp2.reciveData(buffer2, sizeof(buffer2));
//    cout << buffer2 << endl;
//    udp2.sendData("sup?");


    return 0;
}
