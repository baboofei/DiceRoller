void printDebug(String sender, String message)
{
	Serial.print(millis());
	Serial.print(" [DEBUG]");
	Serial.print(" ");
	Serial.print(sender);
	Serial.print(" : ");
	Serial.print(message);
	Serial.print("\n");
}

void printMessage(String sender, String message)
{
	Serial.print(millis());
	Serial.print(" [MSG]");
	Serial.print(" ");
	Serial.print(sender);
	Serial.print(" : ");
	Serial.print(message);
	Serial.print("\n");
}

void printError(String sender, String message, int level)
{
	String error_lvl[10] = {"DANGER", "CRITICAL", "ERROR", "FAILURE", "OOPS", "PANIC", "WARNING", "PROBLEM", "MESSAGE", ""};

	Serial.print(millis());
	Serial.print(error_lvl[level]);
	Serial.print(" ");
	Serial.print(sender);
	Serial.print(" : ");
	Serial.print(message);
	Serial.print("\n");
}
