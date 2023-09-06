#include <Arduino.h>

const int8_t etvsPin[] = {-1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
const int8_t etvNum = 9;

void setup() {
	for(int i = 1; i <= etvNum; i++) {
		pinMode(etvsPin[i], OUTPUT);
		digitalWrite(etvsPin[i], HIGH);
	}
	delay(5000);
}

intmax_t i = 0;
int8_t e = 1;

void loop() {
	if(i % 2 == 0) {
		digitalWrite(etvsPin[e], HIGH);
	} else {
		e++;
		if(e > etvNum) e = 1;
		digitalWrite(etvsPin[e], LOW);
	}
	i++;
	delay(100);
}
