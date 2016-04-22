//record.cpp
//implementation file for Record class
#include <iostream>
#include <vector>
#include "stk/SineWave.h"
#include "stk/RtWvOut.h"
#include "record.h"
using namespace std;
using namespace stk;

//default constructor
Record::Record(){
	Stk::setSampleRate(44100.0);
	Stk::showWarnings(true);

	RtWvOut *dac=0;

	try{
		dac=new RtWvOut(1);
	}
	catch (StkError &){
		exit(1);
	}
	//add frequencies
	Notes["a"]=1;
	Notes["s"]=1;
	Notes["d"]=2;
	Notes["f"]=;
	Notes["g"]=;
	Notes["h"]=;
	Notes["j"]=;
	Notes["k"]=;
	Notes["l"]=;
	Notes[";"]=;
	Notes["w"]=;
	Notes["e"]=;
	Notes["t"]=;
	Notes["y"]=;
	Notes["u"]=;
	Notes["o"]=;
	Notes["p"]=;
}

//add key to the vector Recorded
void Record::AddKey(string key, double length){
	pair<string, double> tempPair;
	tempPair = make_pair(key, length);
	Recorded.push_back(tempPair);
}

//play the notes
void Record::Play(){
	vector< pair<string, double> >::iterator It;
	SineWave sine;
	RtWvOut *dac = 0;

	for(It=Recorded.begin(); It!=Recorded.end(); ++It){
		//play the note
		double note = It->second;
		sine.setFrequency(note);
		for(int j=0; j<It->second; j++){
			try{
				dac->tick(sine.tick());
			}
			catch (StkError & ){
				goto cleanup;
			}
		}
	}
}
