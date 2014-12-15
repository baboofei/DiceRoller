/*
 *	Configurations
 *
 *	The following macros are for configuration purpose
 */

/*
 *	To enable true random seeding, uncomment
 *	#define CONFIG_ENABLE_TRUE_RANDOM
 */

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


