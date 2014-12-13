const int dice_leds[7] = {5, 6, 7, 8, 9, 10, 11};

const int input_roll = 2;
const int input_set = 3;
const int mode_led = 12;

const int random_seeder = A0;

int guess;

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
  int random_seed = (analogRead(A0) + analogRead(A1) + analogRead(A2) + analogRead(A3) + analogRead(A4) + analogRead(A5)) / 6;

  randomSeed(random_seed);

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
