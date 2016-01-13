#include <string>
#include <iostream>
#include <iomanip>
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/math/SVD.h>
#include <yarp/math/Rand.h>
#include "wrdac/clients/icubClient.h"
#include <map>

#include "behavior.h"

using namespace std;
using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::math;
using namespace wysiwyd::wrdac;

class Dummy: public Behavior
{
private:
    static int n_instances;

    void run(Bottle args=Bottle()) {
        yDebug() << "Dummmy::run start " + name;
        Time::delay(10);
        yDebug() << "Dummmy::run stop " + name;
    }
    int id;

public:
    Dummy(Mutex* mut): Behavior(mut) {
        n_instances++;
        id = n_instances;
    }

    void configure() {
        name = "dummy";
        if (id >= 2)
            name += to_string(id);
        external_port_name = "None";
        from_sensation_port_name = "None";        
    }


    void close_extra_ports() {
        ;
    }

};
