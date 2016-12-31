#include <iostream>
#include "UdpClient.h"
#include "../both/Driver.h"

//using namespace std;

//int main(int args, char **argv) {
/**
 * get input from user.
 * width of map >> height of map >> x value of start point >>
 * y value of start point >> x value of end point >> y value of end point.
 * format: 4_4,3_2,1_2
 */
//
//    int sizeX, sizeY, numOfObstacles;
//    char c;
//    cin >> sizeX >> sizeY;
//
//    // create matrix.
//    Matrix matrix(sizeX, sizeY);
//    // save matrix address at map object.
//    Map *map = &matrix;
//    cin >> numOfObstacles;
//    if (numOfObstacles > 0) {
//        map->setObstacles(numOfObstacles);
//    }
//    int id, age, experience, cabId;
//        Status status;
//        char statusLetter;
//        Driver *driver;
//
//        cin >> id >> c >> age >> c >> statusLetter >> c >>
//            experience >> c >> cabId;
//        status = Status(statusLetter);
//        driver = new Driver(map, id, age, status, experience, cabId);
//        //taxiCenter->addDriverInfo(driver);
//        //driver = NULL;
//    int portNo = atoi(argv[2]);
// set the pointer to point on null so when
// the object will delete this pointer will no longer point on it
//    CommunicationClient *communication = new CommunicationClient();
//    communication->startCommunicate();
//    delete (communication);
//    return 0;


using namespace std;

int main(int argc, char *argv[]) {
    std::cout << "Hello, from client" << std::endl;
//
//    Point *gp = new Point(0,0);
//
//    std::string serial_str;
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

//    Driver *d = new Driver(0, 30, Status(0), 1, 2);
//    cout << *d->getCurrentLocation() << endl;
//
//    string serial_str;
//    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
//    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string>>s(inserter);
//    boost::archive::binary_oarchive oa(s);
//    oa << d;
//    s.flush();
//
//
//    cout << serial_str << endl;
//    Driver *d2;
//    boost::iostreams::basic_array_source<char> device(serial_str.c_str(), serial_str.size());
//    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
//    boost::archive::binary_iarchive ia(s2);
//    ia >> d2;
//
//    cout << *d2->getCurrentLocation() << endl;




//    cout << argv[1] << endl;
//    UdpClient udp(0, atoi(argv[1]));
//    udp.initialize();
//
//    char buffer[1024];

    //udp.sendData(serial_str);
   // udp.reciveData(buffer, sizeof(buffer));
    //cout << buffer << endl;

    Driver *d = new Driver(0, 30, Status(0), 1, 2);
    string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string>>s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << d;
    s.flush();


    Socket *comm=new UdpClient(false, atoi(argv[2]));
    cout<<serial_str<<endl;
    comm->initialize();
    char buffer[1024];

    comm->sendData(serial_str);
//    comm->reciveData(buffer, sizeof(buffer));
    cout << buffer << endl;
    return 0;

//    int portNo = atoi(argv[2]);
//    struct hostent* hp = gethostbyname(argv[1]);
//    if (argc < 3) {
//        fprintf(stderr,"usage %s hostname port\n", argv[0]);
//        exit(0);
//    }
//    // set the pointer to point on null so when
//    // the object will delete this pointer will no longer point on it
//    testclient *communication = new testclient(portNo, hp, d);
//    communication->startCommunicate(serial_str);
//    delete (communication);
//    return 0;
}

//}
