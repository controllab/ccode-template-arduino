_______________________________________________________________________________
 
                20-sim code generation for Arduino (AVR/ARM)
_______________________________________________________________________________

20-sim has successfully generated ANSI-C code from the model:
  '%MODEL_NAME%'
for the following submodel:
  '%SUBMODEL_NAME%'
at:
  %GENERATION_DIR%

The generated code consists of the following three files:
  %SUBMODEL_NAME%.c
  %SUBMODEL_NAME%.h
and an Arduino sketch:
  sketch_%SUBMODEL_NAME%.ino

When using an Arduino IDE, just open the sketch.
When using a different AVR IDE, add the .c and .h files to your Arduino/AVR project.
The submodel functions to be called from your code are (see the sketch as example):

XXDouble %FUNCTIONPREFIX%InitializeSubmodel(%IF%%NUMBER_INPUTS%
XXDouble *u, %ENDIF%
%IF%%NUMBER_OUTPUTS%
XXDouble *y, %ENDIF%
XXDouble t);
XXDouble %FUNCTIONPREFIX%CalculateSubmodel(%IF%%NUMBER_INPUTS%
XXDouble *u, %ENDIF%
%IF%%NUMBER_OUTPUTS%
XXDouble *y, %ENDIF%
XXDouble t);
XXDouble %FUNCTIONPREFIX%TerminateSubmodel(%IF%%NUMBER_INPUTS%
XXDouble *u, %ENDIF%
%IF%%NUMBER_OUTPUTS%
XXDouble *y, %ENDIF%
XXDouble t);

with:
%IF%%NUMBER_INPUTS%
 u = input vector (array of XXDouble)
%ENDIF%
%IF%%NUMBER_OUTPUTS%
 y = output vector (array of XXDouble)
%ENDIF%
 t = time (XXDouble)

%IF%%NUMBER_INPUTS%
 The input array size is: %NUMBER_INPUTS%
 The order of the inputs is:
%INPUT_NAMES%
%ENDIF%
%IF%%NUMBER_OUTPUTS%
 The output array size is: %NUMBER_OUTPUTS%
 The order of the outputs is:
%OUTPUT_NAMES%
%ENDIF%

Timing requirements:
____________________

You need to call the %FUNCTIONPREFIX%CalculateSubmodel() function periodically
every %TIME_STEP_SIZE% {s}
  
Limitations:
____________
20-sim submodel for Arduino is a small target to generate C-code for the
Arduino for simple submodels. The native data type in 20-sim is
a 64-bit double floating point value. For the Arduino/AVR, this mapped
onto a 32-bit float data type using the following typedef:
  typedef float XXDouble;

The following 20-sim features are partly supported in the generated code:
- Vector / Matrix support:
   Arduino memory constrains will limit the usage of vectors and matrices
- Integration methods:
   Only Discrete, Euler, RungeKutta 2 and RungeKutta 4 are supported

The following 20-sim features that are not supported in the generated code:
- dll(), dlldynamic(), domatlab(), tomatlab(), frommatlab()
- Motion profiles, EulerAngles
- DataFromFile and other file access functions

Please contact Controllab for assistance if you need support for these
unsupported features.
