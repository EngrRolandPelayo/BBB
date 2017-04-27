#include <unistd.h>
#include <stdio.h>

Servo::Servo()
{}

uint8_t Servo::attach(int pin)
{
	FILE *loadOverlay = NULL;
	FILE *configPin = NULL;
	FILE *enablePin = NULL;
	
	if(pin == 0){
		char overlay[] = "BB-PWM0";
		char pwmNum[] = "0";
		
		loadOverlay = fopen("/sys/devices/platform/bone_capemgr/slots","w");
		fwrite(overlay,1,sizeof(overlay),loadOverlay);
		fclose(loadOverlay);

		configPin = fopen("/sys/class/pwm/pwmchip0/pwm0/period","w");
		fwrite(pwmNum,1,sizeof(pwmNum),configPin);
		fclose(configPin);

		enablePin = fopen("/sys/class/pwm/pwmchip0/pwm0/enable","w");
		fwrite(enable,1,sizeof(enable),enablePin);
		fclose(enablePin);	
	}
}
