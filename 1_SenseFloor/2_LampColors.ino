int highValue, lowValue, lowerValue;
int lampState;

void lampColors(int lampState) {
  highValue = map(soundValue, 0, maxSoundValue, 6, 255);
  lowValue = map(soundValue, 0, maxSoundValue, 3, 128);
  lowerValue = map(soundValue, 0, maxSoundValue, 2, 55);
  //  Serial.println(soundValue);

  if (lampState == 1) {
    // Red middle, orange around (= sunset)
    for (int i = 0; i < numberOfLamps - 1; i++) {
      Orange(i, highValue, lowValue);
    }
    Red(5, highValue);

  } else if (lampState == 2) {
    // blue middle, pink/orange around
    for (int i = 1; i < numberOfLamps - 1; i += 2) {
      Pink(i, highValue, lowValue);
    }
    for (int i = 0; i < numberOfLamps - 1; i += 2) {
      Orange(i, highValue, lowerValue);
    }
    Blue(5, highValue);

  } else if (lampState == 3) {
    // Purple middle, green/blue around
    for (int i = 1; i < numberOfLamps - 1; i += 2) {
      Blue(i, highValue);
    }
    for (int i = 0; i < numberOfLamps - 1; i += 2) {
      Green(i, highValue);
    }
    Purple(5, highValue, lowValue, lowerValue);

  } else if (lampState == 4) {
    // Disco vibes!
    Green(0, highValue);
    Red(1, highValue);
    Green(2, highValue);
    Yellow(3, highValue, lowValue);
    Pink(4, highValue, lowValue);
    Blue(5, highValue);
  }


}
