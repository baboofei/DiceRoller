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

/*
 *	To change behavior on error, modify the following
 */

#define CONFIG_ENABLE_ERROR_HALT

#ifdef CONFIG_ENABLE_ERROR_HALT
#define ERROR_HALT() while(true){}
#else
#define ERROR_HALT()
#endif
void printDebug(String sender, String message)
{
#ifdef CONFIG_ENABLE_PRINT_DEBUG
	Serial.print(millis());
	Serial.print(" [DEBUG]");
	Serial.print(" ");
	Serial.print(sender);
	Serial.print(" : ");
	Serial.print(message);
	Serial.print("\n");
#endif
}

void printMessage(String sender, String message)
{
#ifdef CONFIG_ENABLE_PRINT_MESSAGE
	Serial.print(millis());
	Serial.print(" [MSG]");
	Serial.print(" ");
	Serial.print(sender);
	Serial.print(" : ");
	Serial.print(message);
	Serial.print("\n");
#endif
}

void printError(String sender, String message, int level)
{
	String error_lvl[10] = {"DANGER", "CRITICAL", "ERROR", "FAILURE", "OOPS", "PANIC", "WARNING", "PROBLEM", "MESSAGE", ""};

#ifdef CONFIG_ENABLE_PRINT_ERROR
	if(level <= CONFIG_ERROR_LEVEL)
	{
		Serial.print(millis());
		Serial.print(" [");
		Serial.print(error_lvl[level]);
		Serial.print("] ");
		Serial.print(" ");
		Serial.print(sender);
		Serial.print(" : ");
		Serial.print(message);
		Serial.print("\n");
	}
#endif

	ERROR_HALT();
}
