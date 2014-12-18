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

/*
 *	To change serial communication settings, modify the following
 *
 *	These options currently have problem affecting the overall performance:
 *	when CONFIG_ENABLE_PRINT_DEBUG is turned off, the program have trouble
 *	working properly.
 */

#define CONFIG_ENABLE_PRINT_DEBUG
#define CONFIG_ENABLE_PRINT_MESSAGE
#define CONFIG_ENABLE_PRINT_ERROR
#define CONFIG_ERROR_LEVEL 2

#define CONFIG_ENABLE_SERIAL
#define CONFIG_SERIAL_PORT 9600

#ifdef CONFIG_ENABLE_SERIAL
#define SET_SERIAL() (Serial.begin(CONFIG_SERIAL_PORT))
#else
#define SET_SERIAL()
#endif

/*
 *	To change behavior on error, modify the following
 */

#define CONFIG_ENABLE_ERROR_HALT

#ifdef CONFIG_ENABLE_ERROR_HALT
#define ERROR_HALT() while(true){}
#else
#define ERROR_HALT()
#endif
