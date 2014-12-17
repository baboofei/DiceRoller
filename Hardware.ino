const int dice_display[7][7] = {
	{LOW, LOW, LOW, LOW, LOW, LOW, LOW}, 		/* A wrapper "empty" LED state set */
	{LOW, LOW, LOW, LOW, LOW, HIGH, LOW},
	{LOW, LOW, LOW, LOW, HIGH, LOW, HIGH},
	{HIGH, LOW, LOW, HIGH, LOW, HIGH, LOW},
	{HIGH, HIGH, HIGH, HIGH, LOW, LOW, LOW},
	{HIGH, HIGH, HIGH, HIGH, LOW, HIGH, LOW},
	{HIGH, HIGH, HIGH, HIGH, HIGH, LOW, HIGH}
};

/*
 *	Display a given integer between 1 to 6 with the dice leds
 */

void displayNumber(int side)
{
	/*
	 * Side Designs:
	 *
	 *
	 *  LED 1       LED 2
	 *
	 *  LED 5 LED 6 LED 7
	 *
	 *  LED 3       LED 4
	 *
	 */

	side = (side >= 1 && side <= 6)? side : 0;

	printDebug("displayNumber", "Displaying side:");
	printDebug("displayNumber", String(side));

	if(!side)
	{
		printError("displayNumber", "Given side number cannot be resolved", 2 );
	}

	for(int a = 0; a < 7; ++a)
	{
		digitalWrite(dice_leds[a], dice_display[side][a]);
	}
}

/*
 *	Turn all leds back off
 */

void resetAll()
{
	for(int a = 0; a < 7; ++a)
	{
		digitalWrite(dice_leds[a], LOW);
	}
}

/*
 *	Blink all dice leds to indicate victory
 */

void displayVictory()
{
	delay(1000);

	for(int i = 0; i < 10; ++i)
	{
		for(int a = 0; a < 7; ++a)
		{
			digitalWrite(dice_leds[a], HIGH);
		}

		delay(100);

		for(int b = 0; b < 7; ++b)
		{
			digitalWrite(dice_leds[b], LOW);
		}

		delay(100);
	}

	printDebug("displayVictory", "Displaying victory sequence.");
}

/*
 *	Returns true if a button hooked to pin is pressed
 */

boolean buttonPressed(int pin)
{
	if(!digitalRead(pin))
	{
		printDebug("buttonPressed", "Button Pressed");
		printDebug("buttonPressed", String(pin));
	}

	return !digitalRead(pin);
}
