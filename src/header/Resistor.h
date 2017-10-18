#ifndef RESISTOR_H
#define RESISTOR_H

#include <string>

#define CONNECTION 2

using namespace std;

class Resistor
{
private:
   int rIndex=0; // index of this resistor in array
   double resistance=0.0; // resistance (in Ohms)
   string name; // C++ string holding the label
   int endpointNodeIDs[CONNECTION]; // IDs of nodes it attaches to

public:
   Resistor(int rIndex_,string name_,double resistance_,int endpoints_[CONNECTION]);
   // rIndex_ is the index of this resistor in the resistor array
   // endpoints_ holds the node indices to which this resistor connects

   ~Resistor();

   string getName() const; // returns the name
   double getResistance() const; // returns the resistance

   void setResistance (double resistance_);

   // you *may* create either of the below to print your resistor
   void print ();
};

#endif	/* RESISTOR_H */
