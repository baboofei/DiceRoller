#include "Config.ino"

/* Pins to be used as the dice leds */
const int dice_leds[7] = {
	CONFIG_PIN_DICE_1,
	CONFIG_PIN_DICE_2,
	CONFIG_PIN_DICE_3,
	CONFIG_PIN_DICE_4,
	CONFIG_PIN_DICE_5,
	CONFIG_PIN_DICE_6,
	CONFIG_PIN_DICE_7
};

const int input_roll = CONFIG_PIN_INPUT_ROLL;	/* Pin to be used to hook the "roll" button */
const int input_set = CONFIG_PIN_INPUT_SET;	/* Pin to be used to hook the "increase guess" button */
const int mode_led = CONFIG_PIN_MODE;		/* Pin to be used to hook the mode indicator button */

static int guess;				/* Current guess */

void setup()
{
	SET_SERIAL();

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
