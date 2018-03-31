#pragma config(Sensor, port3,  middleLightSensor, sensorVexIQ_ColorGrayscale)
#pragma config(Sensor, port4,  gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Sensor, port7,  rightLightSensor, sensorVexIQ_ColorGrayscale)
#pragma config(Sensor, port8,  bumperSensor,   sensorVexIQ_Touch)
#pragma config(Motor,  motor1,          ringHolder,    tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor2,          ringIntake,    tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor5,          clawMotor,     tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor6,          pivotMotor,    tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor11,         leftMotor,     tmotorVexIQ, openLoop, driveLeft, encoder)
#pragma config(Motor,  motor12,         rightMotor,    tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma DebuggerWindows("Motors")
#pragma DebuggerWindows("Globals")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

const int kMinimumBatteryLvel = 6000;

task main()
{
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(pivotMotor);
	resetMotorEncoder(rightMotor);
	resetMotorEncoder(ringHolder);
	resetMotorEncoder(clawMotor);
	resetMotorEncoder(ringIntake);
	displayMotorValues(line3, pivotMotor);
while(true)
	{
		if (nImmediateBatteryLevel < kMinimumBatteryLvel)
      {
         playSound(soundTollBooth);
         break;
      }
     displayVariableValues(1, nImmediateBatteryLevel);

		displayMotorValues(line3, pivotMotor);
		tankControl(ChD, ChA, 10);
					if(getMotorOverTemp(clawMotor) == 1) {
				playSound(soundCarAlarm4);
}
		//If Button "E-Up" is pressed in, we'll set the Pivot motor to run in reverse.
		if(getJoystickValue(BtnRUp) == 1)
		{
			setMotorSpeed(clawMotor, -75);

			displayMotorValues(line1, clawMotor);
		}
		//If the "E-Up" isn't pressed, but "E-Down" is, we'll set the motor to run forward.
		else if(getJoystickValue(BtnRDown) == 1)
		{
			setMotorSpeed(clawMotor, 127);
		}
		else  //If neither button is pressed, we'll set the motor off.
		{
			setMotorSpeed(clawMotor, 0);
		}

		//If Button "R-Up" is pressed in, we'll set the Ring Intake motor to run in reverse.
		if(getJoystickValue(BtnEUp) == 1)
		{
			setMotorSpeed(ringIntake, 70);
		}
		//If the "R-Up" isn't pressed, but "R-Down" is, we'll set the motor to run forward.
		else if(getJoystickValue(BtnEDown) == 1)
		{
			setMotorSpeed(ringIntake, -60);
		}
		else  //If neither button is pressed, we'll set the motor off.
		{
			setMotorSpeed(ringIntake, 0);
		}

				//If Button "F-Up" is pressed in, we'll set the Ring Holder motor to run in reverse.
		if(getJoystickValue(BtnFUp) == 1)
		{
			setMotorTarget(ringHolder, 360, 127);
		}
		//If the "F-Up" isn't pressed, but "F-Down" is, we'll set the motor to run forward.
		else if(getJoystickValue(BtnFDown) == 1)
		{
				setMotorTarget(ringHolder, 180, 127);
				waitUntilMotorStop(ringHolder);
		}
		else  //If neither button is pressed, we'll set the motor off.
		{
				resetMotorEncoder(ringHolder);
		}

						//If Button "L-Up" is pressed in, we'll set the Omni motor to run in reverse.
		if(getJoystickValue(BtnLUp) == 1)
		{
			setMotorSpeed(pivotMotor, -127);
		}
		//If the "L-Up" isn't pressed, but "L-Down" is, we'll set the motor to run forward.
		else if(getJoystickValue(BtnLDown) == 1)
		{
			setMotorSpeed(pivotMotor, 127);
		}
		else  //If neither button is pressed, we'll set the motor off.
		{
			setMotorSpeed(pivotMotor, 0);
		}

	}
}
