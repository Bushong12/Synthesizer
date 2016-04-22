//record.h
//interface file for Record class
//creates a vector of pairs that keeps track of key pressed and length of key press
#ifndef RECORD_H
#define RECORD_H

#include "stk/SineWave.h"
#include "stk/RtWvOut.h"
#include <map>

using namespace std;
using namespace stk;

class Record{
	public:
		Record();		//default constructor
		void AddKey(string, double);	//add a new key to Recorded
		void Play();		//play the recording

	private:
		vector< pair<string, double> > Recorded;
		map<string, double> Notes;
		SineWave sine;
};

#endif
