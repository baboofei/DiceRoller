#include "Config.ino"

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
