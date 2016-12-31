#include <iostream>
#include "../both/Driver.h"
#include "../both/Udp.h"

using namespace std;
using namespace boost::iostreams;
using namespace boost::archive;

int main(int argc, char *argv[]) {
    std::cout << "Hello, from client" << std::endl;

    int id, age, experience, cabId;
    Status status;
    char c, statusLetter;
    Driver *driver;

    cin >> id >> c >> age >> c >> statusLetter >> c >>
        experience >> c >> cabId;
    status = Status(statusLetter);
    driver = new Driver(id, age, status, experience, cabId);
    // set the pointer to point on null so when
    // the object will delete this pointer will no longer point on it

    //Driver *driver = new Driver(0, 30, Status(0), 1, 2);
    string serial_str;
    back_insert_device<std::string> inserter(serial_str);
    stream<boost::iostreams::back_insert_device<std::string>> s(inserter);
    binary_oarchive oa(s);
    oa << driver;
    s.flush();


    Socket *udp = new Udp(0, atoi(argv[1]));
    cout << serial_str << endl;
    udp->initialize();
    char buffer[1024];

    udp->sendData(serial_str);
    // get a cab
    udp->reciveData(buffer, sizeof(buffer));
    Cab* cab;
    boost::iostreams::basic_array_source<char> device(buffer, sizeof(buffer));
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > stream1
            (device);
    boost::archive::binary_iarchive ia(stream1);
    ia >> cab;

    driver->setCab(cab);

    udp->reciveData(buffer, sizeof(buffer));
    cout << buffer << endl;
    Point * p;
    boost::iostreams::basic_array_source<char> device1(buffer, sizeof(buffer));
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2
            (device1);
    boost::archive::binary_iarchive ia1(s2);
    ia1 >> p;
    while (p !=NULL) {
        cout << *p << endl;
        driver->setCurrLocation(p);
        udp->reciveData(buffer, sizeof(buffer));
        cout << buffer << endl;
        boost::iostreams::basic_array_source<char> d(buffer, sizeof
        (buffer));
        boost::iostreams::stream<boost::iostreams::basic_array_source<char> >
                s3(d);
        boost::archive::binary_iarchive ia(s3);
        ia >> p;
    }
    return 0;

}

