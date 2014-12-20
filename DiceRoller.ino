#include "Config.ino"

const int dice_leds[7] = {
	CONFIG_PIN_DICE_1,
	CONFIG_PIN_DICE_2,
	CONFIG_PIN_DICE_3,
	CONFIG_PIN_DICE_4,
	CONFIG_PIN_DICE_5,
	CONFIG_PIN_DICE_6,
	CONFIG_PIN_DICE_7
};

const int input_roll = CONFIG_PIN_INPUT_ROLL;
const int input_set = CONFIG_PIN_INPUT_SET;
const int mode_led = CONFIG_PIN_MODE;

static int guess = 1;

void setup(void)
{
	SET_SERIAL();

	for(int i = 0; i < 7; ++i)
		pinMode(dice_leds[i], OUTPUT);

	pinMode(input_roll, INPUT_PULLUP);
	pinMode(input_set, INPUT_PULLUP);
	pinMode(mode_led, OUTPUT);

	printDebug("setup", "Initializing");
}

void loop(void)
{
	SEED_RANDOM();

	if(buttonPressed(input_set))
		increaseGuess();

	if(buttonPressed(input_roll))
		rollDice();

	delay(10);
}

/*
 *	Increase the current guess by one
 *
 *	@func increaseGuess
 *
 *	@return int		-	Return 0 if function succeded
 */

inline int increaseGuess(void)
{
	printDebug("loop", "Increasing guess; Current guess:");
	printDebug("loop", String(guess));

	digitalWrite(mode_led, HIGH);

	if(guess == 6)
		guess = 0;

	++guess;

	displayNumber(guess);

	return 0;
}

/*
 *	Roll the dice and get the result of game
 *
 *	@func rollDice
 *
 *	@return int		-	Return 0 if function succeded
 */

inline int rollDice(void)
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
		displayVictory();

	return 0;
}
