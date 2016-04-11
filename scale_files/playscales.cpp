// rtsine.cpp STK tutorial program

#include "SineWave.h"
#include "RtWvOut.h"
#include <cstdlib>

using namespace stk;

int main()
{
  // Set the global sample rate before creating class instances.
  Stk::setSampleRate( 44100.0 );
  Stk::showWarnings( true );

  int nFrames = 100000;
  SineWave sine;
  RtWvOut *dac = 0;

  try {
    // Define and open the default realtime output device for one-channel playback
    dac = new RtWvOut( 1 );
  }
  catch ( StkError & ) {
    exit( 1 );
  }

  // play an A
  sine.setFrequency( 440.0 );

  // Option 1: Use StkFrames
  /*
  StkFrames frames( nFrames, 1 );
  try {
    dac->tick( sine.tick( frames ) );
  }
  catch ( StkError & ) {
    goto cleanup;
  }
  */

  // Option 2: Single-sample computations
  for ( int i=0; i<nFrames; i++ ) {
    try {
      dac->tick( sine.tick() );
     }
    catch ( StkError & ) {
      goto cleanup;
    }
  }

  // play a B
  sine.setFrequency( 498.88 );

  for ( int i=0; i<nFrames; i++ ) {
    try {
      dac->tick( sine.tick() );
     }
    catch ( StkError & ) {
      goto cleanup;
    }
  }

  // play a C
  sine.setFrequency( 523.25 );

  for ( int i=0; i<nFrames; i++ ) {
    try {
      dac->tick( sine.tick() );
     }
    catch ( StkError & ) {
      goto cleanup;
    }
  }  

  // play a D
  sine.setFrequency( 587.33 );

    for ( int i=0; i<nFrames; i++ ) {
    try {
      dac->tick( sine.tick() );
     }
    catch ( StkError & ) {
      goto cleanup;
    }
  }

  // play an E
  sine.setFrequency( 659.25 );

    for ( int i=0; i<nFrames; i++ ) {
    try {
      dac->tick( sine.tick() );
     }
    catch ( StkError & ) {
      goto cleanup;
    }
  }

  // play an F
  sine.setFrequency( 698.46 );

    for ( int i=0; i<nFrames; i++ ) {
    try {
      dac->tick( sine.tick() );
     }
    catch ( StkError & ) {
      goto cleanup;
    }
  }

  // play a G
  sine.setFrequency( 783.99 );

    for ( int i=0; i<nFrames; i++ ) {
    try {
      dac->tick( sine.tick() );
     }
    catch ( StkError & ) {
      goto cleanup;
    }
  }


 cleanup:
  delete dac;

  return 0;
}