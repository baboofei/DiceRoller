int genDice()
{
	int dice = 0;

	for(int a = 0; a < 1000; ++a)
	{
		dice += random(1, 7);
	}

	dice /= 1000;

	printDebug("genDice", "Generating Dice:");
	printDebug("genDice", String(dice));

	return dice;
}

int compareDice(int dice)
{
	printDebug("compareDice", "Comparing guess with dice:");
	printDebug("compareDice", String(dice == guess));

	return dice == guess;
}
