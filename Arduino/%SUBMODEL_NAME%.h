/**********************************************************
 * This file is generated by 20-sim ANSI-C Code Generator
 * Specific for the Arduino
 *
 *  file:  %FILE_NAME%
 *  subm:  %SUBMODEL_NAME%
 *  model: %MODEL_NAME%
 *  expmt: %EXPERIMENT_NAME%
 *  date:  %GENERATION_DATE%
 *  time:  %GENERATION_TIME%
 *  user:  %USER_NAME%
 *  from:  %COMPANY_NAME%
 *  build: %GENERATION_BUILD%
 *
 * Assumptions: No delays and matrices.
 *              Reals on the Arduino are floats (real32)
 *
 * Please contact Controllab (info@controllab.nl)
 * if you need modifications.
 **********************************************************/
 
#ifndef %SUBMODEL_NAME%_H
#define %SUBMODEL_NAME%_H

#ifdef __cplusplus
extern "C" {
#endif

/* 20-sim boolean defines */
#define XXTRUE	1
#define XXFALSE 0

/* Enable the define below to toggle Arduino pin 13 at the model sampling frequency
 * The result should be a 50% duty cycle wave at half of the sample frequency
 */
//#define ARDUINO_TIMER_DEBUG

/* 20-sim string defines */
#define XXString2Double *(XXDouble *)&
#define XXDouble2String *(XXString *)&

/* the chosen integration method */
#define %INTEGRATION_METHOD_NAME%_METHOD

/* 20-sim typedefs for the Arduino, reals are floats (4 byte) */
typedef float XXDouble;
typedef int XXInteger;
typedef char XXCharacter;
typedef char XXBoolean;
typedef char* XXString;
%IF%%NUMBER_MATRICES%
/* the matrix declaration */
typedef struct
{
	XXDouble *mat;
	XXInteger rows;
	XXInteger columns;
} XXMatrix;

%ENDIF%
/* Submodel functions to be called from outside
%IF%%NUMBER_INPUTS%
 *    u = input vector (array of XXDouble)
%ENDIF%
%IF%%NUMBER_OUTPUTS%
 *    y = output vector (array of XXDouble)
%ENDIF%
 *    t = time (XXDouble)
 */
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

/* the submodel I/O variables */
%IF%%NUMBER_INPUTS%
const int %VARPREFIX%number_of_inputs = %NUMBER_INPUTS%;
%ENDIF%
%IF%%NUMBER_OUTPUTS%
const int %VARPREFIX%number_of_outputs = %NUMBER_OUTPUTS%;
%ENDIF%

/* timing details */
const unsigned long xx_period_us = (%TIME_STEP_SIZE% * 1000000);
const unsigned long xx_period_ms = (%TIME_STEP_SIZE% * 1000);

/* 20-sim function prototypes */
void %FUNCTIONPREFIX%CalculateStatic (void);
void %FUNCTIONPREFIX%CalculateDynamic (void);
%IF%%NUMBER_INPUTS%
void %FUNCTIONPREFIX%CopyInputsToVariables (XXDouble *u);
%ENDIF%
%IF%%NUMBER_OUTPUTS%
void %FUNCTIONPREFIX%CopyVariablesToOutputs (XXDouble *y);
%ENDIF%
%IF%%NUMBEROF_ABSFUNCTION%
XXDouble XXAbsolute (XXDouble argument);
%ENDIF%
%IF%%NUMBEROF_ARCCOSHYPERBOLICFUNCTION%
XXDouble XXArcCosineHyperbolic (XXDouble argument);
%ENDIF%
%IF%%NUMBEROF_ARCSINHYPERBOLICFUNCTION%
XXDouble XXArcSineHyperbolic (XXDouble argument);
%ENDIF%
%IF%%NUMBEROF_ARCTANHYPERBOLICFUNCTION%
XXDouble XXArcTangentHyperbolic (XXDouble argument);
%ENDIF%
%IF%%NUMBEROF_EXP2FUNCTION%
XXDouble XXExponent2 (XXDouble argument);
%ENDIF%
%IF%%NUMBEROF_EXP10FUNCTION%
XXDouble XXExponent10 (XXDouble argument);
%ENDIF%
%IF%%NUMBEROF_DIVISION%
XXDouble XXIntegerDivide (XXDouble argument1, XXDouble argument2);
%ENDIF%
%IF%%NUMBEROF_MODULO%
XXDouble XXIntegerModulo (XXDouble argument1, XXDouble argument2);
%ENDIF%
%IF%%NUMBEROF_LOG2FUNCTION%
XXDouble XXLogarithm2 (XXDouble argument);
%ENDIF%
%IF%%NUMBEROF_LOG10FUNCTION%
XXDouble XXLogarithm10 (XXDouble argument);
%ENDIF%
%IF%%NUMBEROF_POWER%
XXDouble XXPow2 (XXDouble argument);
XXDouble XXPower (XXDouble argument1, XXDouble argument2);
%ENDIF%
%IF%%OR(NUMBEROF_GAUSSFUNCTION,NUMBEROF_RANDOMFUNCTION)%
XXDouble XXRandom (XXDouble argument);
%ENDIF%
%IF%%NUMBEROF_RAMPFUNCTION%
XXDouble XXRamp (XXDouble argument, XXDouble time);
%ENDIF%
%IF%%NUMBEROF_ROUNDFUNCTION%
XXDouble XXRound (XXDouble argument);
%ENDIF%
%IF%%NUMBEROF_SIGNFUNCTION%
XXDouble XXSign (XXDouble argument);
%ENDIF%
%IF%%NUMBEROF_STEPFUNCTION%
XXDouble XXStep (XXDouble argument, XXDouble time);
%ENDIF%
%IF%%NUMBEROF_IMPULSEFUNCTION%
XXDouble XXImpulse (XXDouble impulsestarttime, XXDouble impulseduration, XXDouble currenttime, XXDouble stepsize);
%ENDIF%
%IF%%NUMBEROF_DELAYFUNCTION%
XXDouble XXDelay (XXDouble argument1, XXDouble argument2, XXInteger id);
void XXDelayUpdate(void);
%ENDIF%
%IF%%NUMBEROF_XOR%
XXDouble XXXor (XXDouble argument1, XXDouble argument2);
%ENDIF%
%IF%%NUMBEROF_INITIALFUNCTION%
XXDouble XXInitialValue (XXDouble argument, XXInteger identifier);
%ENDIF%
%IF%%NUMBEROF_BITAND%
XXInteger XXBitAnd(XXInteger argument1, XXInteger argument2);
%ENDIF%
%IF%%NUMBEROF_BITOR%
XXInteger XXBitOr(XXInteger argument1, XXInteger argument2);
%ENDIF%
%IF%%NUMBEROF_BITXOR%
XXInteger XXBitXor(XXInteger argument1, XXInteger argument2);
%ENDIF%
%IF%%NUMBEROF_BITCMP%
XXInteger XXBitCmp(XXInteger argument, XXInteger nrBits);
%ENDIF%
%IF%%NUMBEROF_BITGET%
XXInteger XXBitGet(XXInteger argument, XXInteger bitPos);
%ENDIF%
%IF%%NUMBEROF_BITSET%
XXInteger XXBitSet(XXInteger argument1, XXInteger bitPos);
%ENDIF%
%IF%%NUMBEROF_BITCLEAR%
XXInteger XXBitClear(XXInteger argument1, XXInteger bitPos);
%ENDIF%
%IF%%NUMBEROF_BITSHIFT%
XXInteger XXBitShift(XXInteger argument, XXInteger bitsToShift);
%ENDIF%
%IF%%NUMBEROF_BITSWAPBYTES%
XXDouble XXSwapBytes(XXDouble argument);
%ENDIF%
/* 20-sim stub prototypes */
%IF%%NUMBEROF_DATAFUNCTION%
XXDouble XXData (XXString name, XXInteger column, XXInteger id);
%ENDIF%
%IF%%NUMBEROF_TABLEFUNCTION%
XXDouble XXTable (XXString name, XXDouble argument, XXInteger id);
%ENDIF%
%IF%%NUMBEROF_EVENTFUNCTION%
XXBoolean XXEvent (XXDouble argument, XXInteger id);
%ENDIF%
%IF%%NUMBEROF_EVENTUPFUNCTION%
XXBoolean XXEventUp (XXDouble argument, XXInteger id);
%ENDIF%
%IF%%NUMBEROF_EVENTDOWNFUNCTION%
XXBoolean XXEventDown (XXDouble argument, XXInteger id);
%ENDIF%
%IF%%NUMBEROF_FREQUENCYEVENTFUNCTION%
XXBoolean XXFrequencyEvent (XXDouble argument, XXInteger id);
XXBoolean XXFrequencyEvent1 (XXDouble argument1, XXDouble argument2, XXInteger id);
%ENDIF%
%IF%%NUMBEROF_TIMEEVENTFUNCTION%
XXBoolean XXTimeEvent (XXDouble argument, XXInteger id);
%ENDIF%
%IF%%NUMBEROF_TDELAYFUNCTION%
XXDouble XXTimeDelay (XXDouble argument, XXDouble time, XXInteger id);
%ENDIF%
%IF%%NUMBEROF_WARNSTATEMENT%
XXBoolean XXWarning (XXString message, XXInteger id);
%ENDIF%
%IF%%NUMBEROF_STOPSTATEMENT%
XXBoolean XXStopSimulation (XXString message, XXInteger id);
%ENDIF%
%IF%%NUMBEROF_REALTIME%
XXDouble XXRealTime(void);
%ENDIF%

%IF%%NUMBER_MATRICES%
/* Matrix support functions */
/* copy a matrix source to a matrix destination */
void XXMatrixMov (XXMatrix *mat_dest, XXMatrix *mat_source);

/* copy a scalar to every element in a matrix destination */
void XXMatrixScalarMov (XXMatrix *mat_dest, XXDouble s);

/* get the row(zero_based) designated by the integer
   from the source to the destination. destination is vector */
void XXMatrixGetRow (XXMatrix *mat_dest, XXMatrix *mat_source, XXInteger row);

/* set the row(zero_based) designated by the integer
   to the destination from the source. source is vector*/
void XXMatrixSetRow (XXMatrix *mat_dest, XXMatrix *mat_source, XXInteger row);

/* get the column(zero_based) designated by the integer
   from the source to the destination. destination is vector */
void XXMatrixGetColumn (XXMatrix *mat_dest, XXMatrix *mat_source, XXInteger column);

/* set the column(zero_based) designated by the integer
   to the destination from the source. source is vector */
void XXMatrixSetColumn (XXMatrix *mat_dest, XXMatrix *mat_source, XXInteger column);
%IF%%NUMBEROF_DIAGFUNCTION%
/* use the source vector as elements of the diagonal in the
   destination matrix */
void XXMatrixDiag (XXMatrix *mat_dest, XXMatrix *mat_source);
%ENDIF%
/* add a matrix source1 to a matrix source2 to a matrix destination */
void XXMatrixAdd (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* add a matrix source1 to a scalar source2 to a matrix destination */
void XXMatrixScalarAdd (XXMatrix *mat_dest, XXMatrix *mat_source1, XXDouble s2);

/* add a scalar source1 to a matrix source2 to a matrix destination */
void XXScalarMatrixAdd (XXMatrix *mat_dest, XXDouble s1, XXMatrix *mat_source2);

/* add a scalar source1 to a scalar source2 to a matrix destination */
void XXScalarScalarAdd (XXMatrix *mat_dest, XXDouble s1, XXDouble s2);

/* subtract a Matrix source2 from a matrix source1 to a matrix destination */
void XXMatrixSub (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* subtract a scalar source2 from a matrix source1 to a matrix destination */
void XXMatrixScalarSub (XXMatrix *mat_dest, XXMatrix *mat_source1, XXDouble s2);

/* subtract a matrix source2 from a scalar source1 to a matrix destination */
void XXScalarMatrixSub (XXMatrix *mat_dest, XXDouble s1, XXMatrix *mat_source2);

/* subtract a scalar source2 from a scalar source1 to a matrix destination */
void XXScalarScalarSub (XXMatrix *mat_dest, XXDouble s1, XXDouble s2);

/* multiply matrix source1 and matrix source2 to destination matrix */
void XXMatrixMul (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* multiply matrix source1 with scalar source2 to matrix destination */
void XXMatrixScalarMul (XXMatrix *mat_dest, XXMatrix *mat_source1, XXDouble s2);

/* multiply scalar source1 with matrix source2 to matrix destination */
void XXScalarMatrixMul (XXMatrix *mat_dest, XXDouble s1, XXMatrix *mat_source2);

/* multiply scalar source1 with scalar source2 to matrix destination */
void XXScalarScalarMul(XXMatrix *mat_dest, XXDouble s1, XXDouble s2);

/* multiply matrix source1 with matrix source2 to scalar destination
   the sizes are not checked but it should be that rows of source1 == 1 and columns source2 == 1*/
void XXScalarMatrixMatrixMul (XXDouble *dest, XXMatrix *mat_source1, XXMatrix *mat_source2);
%IF%%NUMBEROF_ELEMENTMUL%
/* multiply all elements element-wise to the destination */
void XXMatrixMulElement (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);
%ENDIF%
%IF%%NUMBEROF_ELEMENTDIV%
/* divide all elements element-wise to the destination */
void XXMatrixDivElement (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);
%ENDIF%
%IF%%NUMBEROF_ELEMENTPOWER%
/* pow all elements element-wise with the same scalar value to the destination: M = X .^ y */
void XXMatrixScalarPowElement (XXMatrix *mat_dest, XXMatrix *mat_source1, XXDouble scalar_source2);
/* pow all elements element-wise to the destination: M = X .^ Y */
void XXMatrixPowElement (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);
%ENDIF%

/* take the inverse of a matrix source to a matrix destination
   workarray size at least (3 * n * n + 2 * n)
   with n is rows is columns from source (=equal to destination) */
void XXMatrixInverse (XXMatrix *mat_dest, XXMatrix *mat_source, XXDouble *workarray);

/* divide matrix source1 with matrix source2 to matrix destination
   workarray size at least (4 * n * n + 2 * n)
   with n is rows is columns from source2 */
void XXMatrixDiv (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2, XXDouble *workarray);

/* divide matrix source1 with scalar source2 to matrix destination */
void XXMatrixScalarDiv (XXMatrix *mat_dest, XXMatrix *mat_source1, XXDouble s2);

/* divide scalar source1 with matrix source2 to matrix destination
   workarray size at least (3 * n * n + 2 * n)
   with n is rows is columns from source2 (=equal to destination) */
void XXScalarMatrixDiv (XXMatrix *mat_dest, XXDouble s1, XXMatrix *mat_source2, XXDouble *workarray);

/* divide scalar source1 with scalar source2 to matrix destination */
void XXScalarScalarDiv (XXMatrix *mat_dest, XXDouble s1, XXDouble s2);

/* take the negative value of the matrix source to the the matrix destination */
void XXMatrixInv (XXMatrix *mat_dest, XXMatrix *mat_source);

/* take the transpose of the matrix source to the the matrix destination */
void XXMatrixTranspose (XXMatrix *mat_dest, XXMatrix *mat_source);
%IF%%NUMBEROF_DETFUNCTION%
/* take the determinant of the matrix source and put it in the scalar destination */
XXDouble XXMatrixDeterminant (XXMatrix *mat_source, XXDouble *workarray);
%ENDIF%
/* use the source1 as an integer index for the destination
   and copy the scalar value of source2 at this point */
void XXMatrixMovRelAbs (XXMatrix *mat_dest, XXDouble s1, XXDouble s2);

/* use the source2 as an integer index for the source1
   and copy this value of source1 to the scalar destination */
void XXMatrixMovAbsRel (XXDouble *dest, XXMatrix *mat_source1, XXDouble s2);
%IF%%NUMBEROF_MINFUNCTION%
/* find the minimum value in a matrix source and place this in
   the destination */
void XXMatrixMinimum (XXDouble *dest, XXMatrix *mat_source);
%ENDIF%
%IF%%NUMBEROF_MAXFUNCTION%
/* find the maximum value in a matrix source and place this in
   the destination */
void XXMatrixMaximum (XXDouble *dest, XXMatrix *mat_source);
%ENDIF%
/* summize all the elements of the matrix and put the result in the dest */
void XXMatrixSum (XXDouble *dest, XXMatrix *mat_source);

/* set the destination to the eye matrix */
void XXMatrixEye (XXMatrix *mat_dest);

/* multiply the source1 n times with itself, with n in source2
   an integer number. The result is put in the destination,
   workarray must have at least the size of the destination matrix
   plus the workarray size of an inverse matrix operation
   this makes 4 * n * n + 2 * n with n = rows/columns of source/dest.
   source and destination should be square */
void XXMatrixPow (XXMatrix *mat_dest, XXMatrix *mat_source1,
				XXDouble s2, XXDouble *workarray);
/* and the scalar scalar variant */
void XXScalarScalarPow (XXMatrix *mat_dest, XXDouble s1, XXDouble s2);

%IF%%NUMBEROF_CROSSFUNCTION%
/* take the cross product of matrix source1 and matrix source2
   to a destination matrix. all matrices must be 3x1 */
void XXMatrixCrossProduct (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);
%ENDIF%
%IF%%NUMBEROF_INNERFUNCTION%
/* take the inner product of matrix source1 and matrix source2
   to a scalar destination. the source matrices must be nx1 */
void XXMatrixInnerProduct (XXDouble *dest, XXMatrix *mat_source1, XXMatrix *mat_source2);
%ENDIF%
%IF%%NUMBEROF_NORMFUNCTION%
/* take the 2-norm of matrix source to a scalar destination */
void XXMatrixNorm (XXDouble *dest, XXMatrix *mat_source);
%ENDIF%
%IF%%NUMBEROF_NORMINFFUNCTION%
/* take the inf norm of matrix source to a scalar destination */
void XXMatrixNormInf (XXDouble *dest, XXMatrix *mat_source);
%ENDIF%
%IF%%NUMBEROF_TRACEFUNCTION%
/* take the Trace of the matrix source to the scalar destination.
   The trace is defined as the sum of the diagonal values */
XXDouble XXMatrixTrace (XXMatrix *mat_source);
%ENDIF%
%IF%%NUMBEROF_SYMMETRICFUNCTION%
/* take the symetric value of the source matrix.
   the result is placed in the destination matrix.
   the work array must have the same size as the source */
void XXMatrixSym (XXMatrix *mat_dest, XXMatrix *mat_source, XXDouble *workarray);
%ENDIF%
%IF%%NUMBEROF_ANTISYMMETRICFUNCTION%
/* take the anti symetric value of the source matrix.
   the result is placed in the destination matrix.
   the work array must have the same size as the source */
void XXMatrixAsym (XXMatrix *mat_dest, XXMatrix *mat_source, XXDouble *workarray);
%ENDIF%
%IF%%NUMBEROF_SKEWFUNCTION%
/* take the skew of the source matrix to a matrix destination
   source = 3x1, destination is 3x3 */
void XXMatrixSkew (XXMatrix *mat_dest, XXMatrix *mat_source);
%ENDIF%
%IF%%NUMBEROF_HOMOGENEOUSFUNCTION%
/* take the skew of the source1 matrix and source2 matrix
   to a matrix destination.
   source1 is 3x3 and source2 = 3x1, destination is 4x4 */
void XXMatrixHomogeneous (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);
%ENDIF%
%IF%%NUMBEROF_INVERSEHOMOGENEOUSFUNCTION%
/* take the inverse of a sourceH matrix to a destination matrix
   the source is 4x4 and the destination matrix is 4x4 */
void XXMatrixInverseH (XXMatrix *mat_dest, XXMatrix *mat_source);
%ENDIF%
%IF%%NUMBEROF_ADJOINTFUNCTION%
/* Create an Adjoint matrix.
   source matrix is 4x4, destination matrix is 6x6 */
void XXMatrixAdjoint (XXMatrix *mat_dest, XXMatrix *mat_source);

/* Create an Adjoint matrix from two source matrices
   source1 matrix is 3x3 (orientation),
   source2 matrix is 3x1 (position),
   destination matrix is 6x6 */
void XXMatrixAdjoint1 (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* Create an Adjoint matrix from a source matrix
   source1 matrix is 6x1
   destination matrix is 6x6 */
void XXMatrixadjoint (XXMatrix *mat_dest, XXMatrix *mat_source);

/* Create an adjoint matrix from two source matrices
   source1 matrix is 3x1
   source2 matrix is 3x1
   destination matrix is 6x6 */
void XXMatrixadjoint1 (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);
%ENDIF%
%IF%%NUMBEROF_TILDEFUNCTION%
/* calcalate the tilde matrix from a source matrix
   source1 matrix is 6x1
   destination matrix is 4x4 */
void XXMatrixTilde (XXMatrix *mat_dest, XXMatrix *mat_source);

/* calcalate the tilde matrix from two source matrices
   source1 matrix is 3x1
   source2 matrix is 3x1
   destination matrix is 4x4 */
void XXMatrixTilde1 (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);
%ENDIF%
%IF%%NUMBEROF_BACKDIVISION%
/* calculate the solution of Ax=b towards x 
   inside 20-sim this is done with an advanced linear solver
   code generation uses the x=inverse(A)*b approach instead */
void XXLinearSolve (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2, XXString method, XXInteger id, XXDouble *workarray);
%ENDIF%
%ENDIF%

#if ARDUINO >= 100

/* Time related support functions (only available when using the Arduino SDK) */
#define ULONG_MAX (__LONG_MAX__ * 2UL + 1UL)
extern unsigned char xx_timer_counter;
extern unsigned char xx_timer_overflow;
/* Initialize the time variable used by XXWaitPeriod() */
void XXInitTiming();

%IF%%NUMBEROF_DLL_Arduino%
void Arduino_Initialize();
%ENDIF%
%IF%%NUMBEROF_DLL_Arduino_SetPinOutput%
void Arduino_SetPinOutput(XXDouble *inarr, int inputs, XXDouble *outarr, int outputs, int major);
%ENDIF%
%IF%%NUMBEROF_DLL_Arduino_SetPinInput%
void Arduino_SetPinInput(XXDouble *inarr, int inputs, XXDouble *outarr, int outputs, int major);
%ENDIF%
%IF%%NUMBEROF_DLL_Arduino_pinMode%
void Arduino_pinMode(XXDouble *inarr, int inputs, XXDouble *outarr, int outputs, int major);
%ENDIF%
%IF%%NUMBEROF_DLL_Arduino_digitalRead%
void Arduino_digitalRead(XXDouble *inarr, int inputs, XXDouble *outarr, int outputs, int major);
%ENDIF%
%IF%%NUMBEROF_DLL_Arduino_digitalWrite%
void Arduino_digitalWrite(XXDouble *inarr, int inputs, XXDouble *outarr, int outputs, int major);
%ENDIF%
%IF%%NUMBEROF_DLL_Arduino_analogWrite%
void Arduino_analogWrite(XXDouble *inarr, int inputs, XXDouble *outarr, int outputs, int major);
%ENDIF%
#endif /* ARDUINO >= 100 */

void %FUNCTIONPREFIX%%INTEGRATION_METHOD_NAME%Initialize (void);
void %FUNCTIONPREFIX%%INTEGRATION_METHOD_NAME%Terminate (void);
void %FUNCTIONPREFIX%%INTEGRATION_METHOD_NAME%Step (void);

#ifdef __cplusplus
}
#endif

#endif /* %SUBMODEL_NAME%_H */
