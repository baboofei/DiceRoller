const int dice_display[7][7] = {
	{LOW, 	LOW, 	LOW, 	LOW, 	LOW, 	LOW, 	LOW}, 		/* A wrapper "empty" LED state set */
	{LOW, 	LOW, 	LOW, 	LOW, 	LOW, 	HIGH, 	LOW},
	{LOW, 	LOW, 	LOW, 	LOW, 	HIGH, 	LOW, 	HIGH},
	{HIGH, 	LOW, 	LOW, 	HIGH, 	LOW, 	HIGH, 	LOW},
	{HIGH, 	HIGH, 	HIGH, 	HIGH, 	LOW, 	LOW, 	LOW},
	{HIGH, 	HIGH, 	HIGH, 	HIGH, 	LOW, 	HIGH, 	LOW},
	{HIGH, 	HIGH, 	HIGH, 	HIGH, 	HIGH, 	LOW, 	HIGH}
};

/*
 *	Display a given integer between 1 to 6 with the dice leds
 */

int displayNumber(int side)
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

		return -1;
	}

	for(int a = 0; a < 7; ++a)
		digitalWrite(dice_leds[a], dice_display[side][a]);

	return 0;
}

/*
 *	Turn all leds back off
 */

int resetAll()
{
	for(int a = 0; a < 7; ++a)
		digitalWrite(dice_leds[a], LOW);

	return 0;
}

/*
 *	Blink all dice leds to indicate victory
 */

int displayVictory()
{
	delay(1000);

	for(int i = 0; i < 10; ++i)
	{
		for(int a = 0; a < 7; ++a)
			digitalWrite(dice_leds[a], HIGH);

		delay(100);

		for(int b = 0; b < 7; ++b)
			digitalWrite(dice_leds[b], LOW);

		delay(100);
	}

	printDebug("displayVictory", "Displaying victory sequence.");

	return 0;
}

/*
 *	Turn all leds on to test if they are working properly
 */

int displayTest()
{
	for(int i = 0; i < 7; ++i)
		digitalWrite(dice_leds[i], HIGH);

	return 0;
}

/*
 *	Returns true if a button hooked to pin is pressed
 */

int buttonPressed(int pin)
{
	if(!digitalRead(pin))
	{
		printDebug("buttonPressed", "Button Pressed");
		printDebug("buttonPressed", String(pin));
	}

	return !digitalRead(pin);
}
