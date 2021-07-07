// File: transportation.h
// Author: Bryan Park
// Programming Assignment #1; draft .h files

// Not every event, trip, education class, whatever it might be will need
// a mode of transportation. So transportation has a "HAS A" relationship
// with the event class.
class transportation
{
    public:
        transportation();
        ~transportation();
        transportation(char * means, float cost);
        void display();
        void copy_transport(const char * means);
        void change_transportation_cost(float new_cost)
    protected:
        char * trans_means;
        float cost;
};