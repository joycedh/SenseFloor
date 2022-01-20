int lampNumber;

void Red(int lampNumber, int highValue) {
  DmxSimple.write(10 * lampNumber + 1, highValue); // R
  DmxSimple.write(10 * lampNumber + 2, 0); // G
  DmxSimple.write(10 * lampNumber + 3, 0); // B
}

void Green(int lampNumber, int highValue) {
  DmxSimple.write(10 * lampNumber + 1, 0); // R
  DmxSimple.write(10 * lampNumber + 2, highValue); // G
  DmxSimple.write(10 * lampNumber + 3, 0); // B
}

void Blue(int lampNumber, int highValue) {
  DmxSimple.write(10 * lampNumber + 1, 0); // R
  DmxSimple.write(10 * lampNumber + 2, 0); // G
  DmxSimple.write(10 * lampNumber + 3, highValue); // B
}

void Orange(int lampNumber, int highValue, int lowValue) {
  DmxSimple.write(10 * lampNumber + 1, highValue); // R
  DmxSimple.write(10 * lampNumber + 2, lowValue); // G
  DmxSimple.write(10 * lampNumber + 3, 0); // B
}

void Purple(int lampNumber, int highValue, int lowValue, int lowerValue) {
  DmxSimple.write(10 * lampNumber + 1, lowValue); // R
  DmxSimple.write(10 * lampNumber + 2, 0); // G
  DmxSimple.write(10 * lampNumber + 3, highValue); // B
}

void Pink(int lampNumber, int highValue, int lowValue) {
  DmxSimple.write(10 * lampNumber + 1, highValue); // R
  DmxSimple.write(10 * lampNumber + 2, 0); // G
  DmxSimple.write(10 * lampNumber + 3, lowValue); // B
}

void Yellow(int lampNumber, int highValue, int lowValue) {
  DmxSimple.write(10 * lampNumber + 1, highValue); // R
  DmxSimple.write(10 * lampNumber + 2, highValue); // G
  DmxSimple.write(10 * lampNumber + 3, 0); // B
}
