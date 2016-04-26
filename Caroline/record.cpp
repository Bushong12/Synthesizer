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
	Notes["a"]=261.63;   // Middle C (C4)
	Notes["s"]=293.66;   // D4
	Notes["d"]=329.63;   // E4
	Notes["f"]=349.23;    // F4
	Notes["g"]=392.00;    // G4
	Notes["h"]=440.00;    // A4 (tuning pitch)
	Notes["j"]=493.88;    // B4
	Notes["k"]=523.25;    // C5
	Notes["l"]=587.33;    // D5
	Notes[";"]=659.25;    // E5
	Notes["w"]=277.18;    // C#4/ Db4
	Notes["e"]=311.13;    // D#4/ Eb4
	Notes["t"]=369.99;    // F#4/ Gb4
	Notes["y"]=415.30;    // G#4/ Ab4
	Notes["u"]=466.16;    // A#4/ Bb4
	Notes["o"]=554.37;    // C#5/ Db5
	Notes["p"]=622.25;    // D#5/ Eb5
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

	//iterate through each note stored in the set
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
