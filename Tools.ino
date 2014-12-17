#include "Config.ino"

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
}
