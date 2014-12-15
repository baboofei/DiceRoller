const int dice_leds[7] = {5, 6, 7, 8, 9, 10, 11};

const int input_roll = 2;
const int input_set = 3;
const int mode_led = 12;

const int random_seeder = A0;

static int guess;

#define CONFIG_ENABLE_TRUE_RANDOM
#define CONFIG_LEVEL_TRUE_RANDOM 0

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

void setup()
{
  Serial.begin(9600);

  for(int i = 0; i < 7; ++i)
  {
    pinMode(dice_leds[i], OUTPUT);
  }

  pinMode(input_roll, INPUT_PULLUP);
  pinMode(input_set, INPUT_PULLUP);
  pinMode(mode_led, OUTPUT);

  guess = 1;

  printDebug("setup", "Initializing");
}

void loop()
{
  SEED_RANDOM();

  if(buttonPressed(input_set))
  {
    printDebug("loop", "Increasing guess; Current guess:");
    printDebug("loop", String(guess));

    digitalWrite(mode_led, HIGH);

    guess = (guess == 6)? 0 : guess;

    ++guess;

    displayNumber(guess);
  }

  if(buttonPressed(input_roll))
  {
    digitalWrite(mode_led, LOW);

    for(int i = 0; i < 25; ++i)
    {
      int dice = genDice();

      displayNumber(dice);

      delay((1000 / (25 - i)));

      resetAll();
    }

    delay(100);

    int dice = genDice();

    displayNumber(dice);

    delay(100);

    if(compareDice(dice))
    {
      displayVictory();
    }
  }

  delay(10);
}
