#include "Config.ino"

/*
 *	Generate a random integer between 1 and 6 (inclusive)
 *
 *	@func genDice
 *
 *	@return int		-	Return the integer generated
 */

int genDice()
{
	int dice = random(1, 7);

	printDebug("genDice", "Generating Dice:");
	printDebug("genDice", String(dice));

#ifndef CONFIG_CHEAT_ALWAYS_NUM
	return dice;
#else
	return CONFIG_CHEAT_ALWAYS_NUM;
#endif
}

/*
 *	Compare current guess with a given integer
 *
 *	@func compareDice
 *
 *	@param int dice		-	The integer to be compared with current guess
 *
 *	@return int			-	Return 1 if current guess equal given integer, 0
 *							otherwise
 */

int compareDice(int dice)
{
	printDebug("compareDice", "Comparing guess with dice:");
	printDebug("compareDice", (dice == guess)? "True" : "False");

#ifndef CONFIG_CHEAT_ALWAYS_WIN
	return dice == guess;
#else
	return 1;
#endif
}
