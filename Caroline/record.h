//record.h
//interface file for Record class
//creates a vector of pairs that keeps track of key pressed and length of key press
#ifndef RECORD_H
#define RECORD_H

#include "stk/SineWave.h"
#include "stk/RtWvOut.h"
#include <map>
#include <iostream>
#include <vector>

using namespace stk;

class Record{
	public:
		Record();		//default constructor
		void AddKey(char, double);	//add a new key to Recorded
		void Play();		//play the recording

	private:
		std::vector< std::pair<char, double> > Recorded;
		std::map<char, double> Notes;	//contains data of frequency that matches a key on the keyboard
		SineWave sine;
};

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
	Notes['a']=261.63;   // Middle C (C4)
	Notes['s']=293.66;   // D4
	Notes['d']=329.63;   // E4
	Notes['f']=349.23;    // F4
	Notes['g']=392.00;    // G4
	Notes['h']=440.00;    // A4 (tuning pitch)
	Notes['j']=493.88;    // B4
	Notes['k']=523.25;    // C5
	Notes['l']=587.33;    // D5
	Notes[';']=659.25;    // E5
	Notes['w']=277.18;    // C#4/ Db4
	Notes['e']=311.13;    // D#4/ Eb4
	Notes['t']=369.99;    // F#4/ Gb4
	Notes['y']=415.30;    // G#4/ Ab4
	Notes['u']=466.16;    // A#4/ Bb4
	Notes['o']=554.37;    // C#5/ Db5
	Notes['p']=622.25;    // D#5/ Eb5
}

//add key to the vector Recorded
void Record::AddKey(char key, double length){
	std::pair<char, double> tempPair;
	tempPair = std::make_pair(key, length);
	Recorded.push_back(tempPair);
}

//play the notes
void Record::Play(){
	std::vector< std::pair<char, double> >::iterator It;
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
	cleanup:
    	delete dac;
}

#endif
