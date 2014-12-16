/* Pins to be used as the dice leds */
const int dice_leds[7] = {5, 6, 7, 8, 9, 10, 11};

const int input_roll = 2;	/* Pin to be used to hook the "roll" button */
const int input_set = 3;	/* Pin to be used to hook the "increase guess" button */
const int mode_led = 12;	/* Pin to be used to hook the mode indicator button */

static int guess;		/* Current guess */

#define CONFIG_ENABLE_TRUE_RANDOM
#define CONFIG_LEVEL_TRUE_RANDOM 0

#include "Config.ino"

void setup()
{
	Serial.begin(9600);

	for(int i = 0; i < 7; ++i)
	{
		pinMode(dice_leds[i], OUTPUT);
	}

	pinMode(input_roll, INPUT_PULLUP);
	pinMode(input_set, INPUT_PULLUP);
	pinMode(mode_led, OUTPUT);

	guess = 1;

	printDebug("setup", "Initializing");
}

void loop()
{
	SEED_RANDOM();

	if(buttonPressed(input_set))
	{
		printDebug("loop", "Increasing guess; Current guess:");
		printDebug("loop", String(guess));

		digitalWrite(mode_led, HIGH);

		guess = (guess == 6)? 0 : guess;

		++guess;

		displayNumber(guess);
	}

	if(buttonPressed(input_roll))
	{
		digitalWrite(mode_led, LOW);

		for(int i = 0; i < 25; ++i)
		{
			int dice = genDice();

			displayNumber(dice);

			delay((1000 / (25 - i)));

			resetAll();
		}

		delay(100);

		int dice = genDice();

		displayNumber(dice);

		delay(100);

		if(compareDice(dice))
		{
			displayVictory();
		}
	}

	delay(10);
}
