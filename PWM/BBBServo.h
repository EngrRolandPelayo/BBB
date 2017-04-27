#ifndef BBBServo_h
#define BBBServo_h

#define MIN_PULSE
class Servo
{
public:
	Servo();
	uint8_t attach(int pin);
	void detach();
	void write(int value);
private:
	uint8_t servoIndex;
	int8_t min;
	int8_t max;
};

#endif
