int genDice()
{
	int dice = random(1, 7);

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
