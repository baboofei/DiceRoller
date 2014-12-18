/*
 *	Configurations
 *
 *	The following macros are for configuration purpose
 */

/*
 *	To change pin assignments, modify the following
 */

#define CONFIG_PIN_DICE_1 5
#define CONFIG_PIN_DICE_2 6
#define CONFIG_PIN_DICE_3 7
#define CONFIG_PIN_DICE_4 8
#define CONFIG_PIN_DICE_5 9
#define CONFIG_PIN_DICE_6 10
#define CONFIG_PIN_DICE_7 11

#define CONFIG_PIN_INPUT_ROLL 2
#define CONFIG_PIN_INPUT_SET 3
#define CONFIG_PIN_MODE 12

/*
 *	To enable true random seeding, uncomment
 *	#define CONFIG_ENABLE_TRUE_RANDOM
 */

#define CONFIG_ENABLE_TRUE_RANDOM
#define CONFIG_LEVEL_TRUE_RANDOM 0

#ifdef CONFIG_ENABLE_TRUE_RANDOM
#if CONFIG_LEVEL_TRUE_RANDOM == 0
#define SEED_RANDOM() (randomSeed(analogRead(A0 + A1 + A2 + A3 + A4 + A5)))
#elif CONFIG_LEVEL_TRUE_RANDOM == 1
#define SEED_RANDOM() (randomSeed(analogRead(A0 + A1 + A2)))
#elif CONFIG_LEVEL_TRUE_RANDOM == 2
#define SEED_RANDOM() (randomSeed(analogRead(A0)))
#else
#define SEED_RANDOM() (randomSeed(analogRead(A0 + A1 + A2 + A3 + A4 + A5)))
#endif
#else
#define SEED_RANDOM()
#endif

#define CONFIG_ENABLE_SERIAL
#define CONFIG_SERIAL_PORT 9600

#ifdef CONFIG_ENABLE_SERIAL
#define SET_SERIAL() (Serial.begin(CONFIG_SERIAL_PORT))
#else
#define SET_SERIAL()
#endif

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
		pinMode(dice_leds[i], OUTPUT);

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
		increaseGuess();

	if(buttonPressed(input_roll))
		rollDice();

	delay(10);
}

int increaseGuess()
{
	printDebug("loop", "Increasing guess; Current guess:");
	printDebug("loop", String(guess));

	digitalWrite(mode_led, HIGH);

	guess = (guess == 6)? 0 : guess;

	++guess;

	displayNumber(guess);

	return 0;
}

int rollDice()
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

	return 0;
}
