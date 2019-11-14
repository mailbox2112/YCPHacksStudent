#define FILTER_LEN 100

// Moving average filters
int blueFilter[FILTER_LEN];
int blueTotal = 0;
int blueIdx = 0;

int greenFilter[FILTER_LEN];
int greenTotal = 0;
int greenIdx = 0;

int redFilter[FILTER_LEN];
int redTotal = 0;
int redIdx = 0;

void setup(void) {
  // TODO: add your setup code here!

  // hint: the setup code from the example programs is a good start
}

void loop() {
  // TODO: add your code here!

  // hint: you should be able to do this based off of just two of the examples included in the libraries
}

/*
 * Gets the average value from the moving average filter for the blue color
 * 
 */
int getBlueAverage(int brightness) {
  int blueAvg = 0;

  blueTotal = blueTotal - blueFilter[blueIdx];
  blueFilter[blueIdx] = brightness;
  blueTotal = blueTotal + blueFilter[blueIdx];
  blueIdx = blueIdx + 1;

  if (blueIdx >= FILTER_LEN) {
    blueIdx = 0;
  }

  blueAvg = blueTotal / FILTER_LEN;

  return blueAvg;
}

/*
 * Gets the average value from the moving average filter for the green color
 * 
 */
int getGreenAverage(int brightness) {
  int greenAvg = 0;

  greenTotal = greenTotal - greenFilter[greenIdx];
  greenFilter[greenIdx] = brightness;
  greenTotal = greenTotal + greenFilter[greenIdx];
  greenIdx = greenIdx + 1;

  if (greenIdx >= FILTER_LEN) {
    greenIdx = 0;
  }

  greenAvg = greenTotal / FILTER_LEN;

  return greenAvg;
}

/*
 * Gets the average value from the moving average filter for the red color
 * 
 */
int getRedAverage(int brightness) {
  int redAvg = 0;

  redTotal = redTotal - redFilter[redIdx];
  redFilter[redIdx] = brightness;
  redTotal = redTotal + redFilter[redIdx];
  redIdx = redIdx + 1;

  if (redIdx >= FILTER_LEN) {
    redIdx = 0;
  }

  redAvg = redTotal / FILTER_LEN;

  return redAvg;
}
