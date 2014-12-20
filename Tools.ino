#include "Config.ino"

/*
 *	Print a debug message to on-board hardware serial
 *
 *	@func printDebug
 *
 *	@param String sender	-	Sender of the message; the name of the function
 *								calling this function is recommended
 *
 *	@param String message	-	Debug message to be printed
 */

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

/*
 *	Print a message to on-board hardware serial
 *
 *	@func printMessage
 *
 *	@param String sender	-	Sender of the message; the name of the function
 *								calling this function is recommended
 *
 *	@param String message	-	Debug message to be printed
 */

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

/*
 *	Print a error message to on-board hardware serial; halt the program if
 *	configured to do so in Config.ino
 *
 *	@func printError
 *
 *	@param String sender	-	Sender of the message; the name of the function
 *								calling this function is recommended
 *
 *	@param String message	-	Debug message to be printed
 *
 *	@param int level		-	Error level of the message
 */

void printError(String sender, String message, int level)
{
	const String error_lvl[10] = {"DANGER", "CRITICAL", "ERROR", "FAILURE", "OOPS", "PANIC", "WARNING", "PROBLEM", "MESSAGE", ""};

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
