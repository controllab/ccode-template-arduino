#include "%SUBMODEL_NAME%.h"

%IF%%NUMBER_INPUTS%
XXDouble u[xx_number_of_inputs];
%ENDIF%
%IF%%NUMBER_OUTPUTS%
XXDouble y[xx_number_of_outputs];
%ENDIF%

XXDouble model_time = 0.0;

void setup() {
	// TODO: add your I/O initialization
	// For example to enable digital pins as input and output:
	// pinMode(2, INPUT);      // sets the digital pin 2 as input
	// pinMode(13, OUTPUT);     // sets the digital pin 13 (LED) as output

%IF%%NUMBER_INPUTS%
	// Initialize the model inputs
%INITIALIZE_INPUTS%
%ENDIF%
%IF%%NUMBER_OUTPUTS%
	// Initialize the model outputs
%INITIALIZE_OUTPUTS%
%ENDIF%
	// Initialize the model
	XXInitializeSubmodel(%IF%%NUMBER_INPUTS%
u, %ENDIF%
%IF%%NUMBER_OUTPUTS%
y, %ENDIF%
model_time);
	XXInitTiming(); /* Setup AVR Timer/Counter 0 to generate our periodic timer interrupts */
}

void loop() {
	// put your main code here, to run repeatedly:
	
	/* Calculate the 20-sim model task when our timing counter overflows */
	if (xx_timer_counter > xx_timer_overflow)
	{
%IF%%NUMBER_INPUTS%
		// TODO: assign the input values to the u array elements here
		// For example to read the digital value from pin 2 and assign it to the first input:
		// u[0] = (XXDouble) digitalRead(2);
%ENDIF%
		model_time = XXCalculateSubmodel(%IF%%NUMBER_INPUTS%
u, %ENDIF%
%IF%%NUMBER_OUTPUTS%
y, %ENDIF%
model_time); /* calculate one step of %SUBMODEL_NAME% */
%IF%%NUMBER_OUTPUTS%
		// TODO: do something useful with the output values of the y array elements here
		// For example to write the first output value to a digital output on pin 13 (LED):
		// digitalWrite(13, ((y[0] > 0.0) ? HIGH : LOW));
%ENDIF%

		/* Reset the timer counter. It will trigger the next calculation when it overflows again.*/
		xx_timer_counter = 0;
	}
}
