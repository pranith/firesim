#ifndef __SERIAL_H
#define __SERIAL_H

#include "endpoints/endpoint.h"
#include "fesvr/firesim_fesvr.h"

template<class T>
struct serial_data_t {
    struct {
        T bits;
        bool valid;
        bool ready;
        bool fire() { return valid && ready; }
    } in;
    struct {
        T bits;
        bool ready;
        bool valid;
        bool fire() { return valid && ready; }
    } out;
};

class serial_t: public endpoint_t
{
    public:
        serial_t(simif_t* sim, firesim_fesvr_t* fesvr);
        void init();
        void tick();
        virtual bool done() { return read(SERIALWIDGET_0(done)); }
        bool stall() { return false; }

    private:
        // Number of target cycles between fesvr interactions
        int fesvr_step_size = 128;
        firesim_fesvr_t* fesvr;

        // Tell the widget to start enqueuing tokens
        void go();
        // Moves data to and from the widget and fesvr
        void send(); // FESVR -> Widget
        void recv(); // Widget -> FESVR
};

#endif // __SERIAL_H
