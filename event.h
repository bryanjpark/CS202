// File: event.h
// Author: Bryan Park
// Programming Assignment #1; draft .h files

#include <iostream>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>

#include "transportation.h"

// In this subset, there is a name class that keeps track of any name of an
// address. 
// There is an address class which keeps track of the address of an event.
// Then there is an event class that keeps track of the event title and other
// event details.

// Figured that every location has a name or something that it
// is called. An open field is named an open field, it does not
// need to be an official name registered with the State Secretary.
class name
{
    public:
        name();
        name(char * init_loc_name);
        name(const name & to_copy);
        ~name();
        void display() const;
        void change_name(char * new_name);
        void set_name(const name & setup_name);
        void copy_name(const char * to_copy);
        bool find_by_name(const char * to_compare) const;
    protected:
        char * a_name;
};

// This was origianally named Location and changed to Address. Made more sense
// in my head. Street does not need to an official street address, so cross
// streets description would also work.

// So, I am not having this as a full address class with street number, city 
// and state by choice. I chose to leave those fields out because I felt that
// the information could easily be added to the street field if the information
// was desired. It also allowed for the use of cross street instead of an
// official street address used by the US Mail. The only street address that
// I know is my own for the purpose of mail, otherwise I go by cross streets.
// I also did not worry about city and state, because that information could be
// easily figured out by the zip.

// The address class is derived from the name class. This is designed this way
// because the address class "IS A" name plus more. 
class address:public name
{
    public:
        address();
        address(char * street, char * zip);
        ~address();
        void display() const;
        void copy_adress(const address & to_copy);
        void change_address(char * new_street, char * new_zip);
        bool find_zip(const char * compare_zip);
    protected:
        char * street;
        char * zip;
};

// Event class also has a name field listed as title so the event can be named
// something different than the name of where it is going to be. Changed from
// the UML is when was changed to start_time and added duration.

// The event class is derived from the address class since every event "IS A"
// address and name for that matter. Event is where things would start spliting
// also. Other classes could be for durations that were more than 24 hours, or 
// required no travel such as housework if it was felt like scheduling that.
// Which I probrably should.
class event:public address
{
    public:
        event();
        ~event();
        event(char * name, char * street, char * zip);
        bool find_by_date(const char * compare_date);
        void display() const;
        void copy_event(const event & to_copy);
        bool find_event(const char * event_to_compare);
    protected:
        char * title;
        char * start_time;
        char * duration;
        float event_cost;
        transportation my_transportation;
};

// Using a linked list to have a listing of the events that I have planned.
// I have the linked list derived from the event class thinking that a node
// "IS A" event (the data) plus the pointers to manage and traverse the list.
// But I am thinking that it could be a "HAS A" relation also, so not sure
// about it. 
class node:public event
{
    public:
        node();
        ~node();
        node *& go_next();
        void connect_next(node * connection);
        void display_all(node * head);
    protected:
        node * next;
};

// Not every event, trip, education class, whatever it might be will need
// a mode of transportation. So transportation has a "HAS A" relationship
// with the event class.
class transportation
{
    public:
        transportation();
        ~transportation();
        transportation(char * means, float cost);
        void display() const;
        void copy_transport(const char * means);
        void change_transportation(char * new_means, float cost);
    protected:
        char * trans_means;
        float cost;
};