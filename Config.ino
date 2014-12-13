/*
 *	Configurations
 *
 *	The following macros are for configuration purpose
 */

#define CONFIG_ENABLE_TRUE_RANDOM

#ifdef CONFIG_ENABLE_TRUE_RANDOM
	#define SEED_RANDOM() (randomSeed(analogRead(A0)))
#else
	#define SEED_RANDOM() ()
#endif
