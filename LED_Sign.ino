/**
 * This code is for the black-box LED sign.  The first 7 columns don't work.
 * I will likely use this just for demo purposes and learning.
 * 
 * 1-20 are LED column pins.
 * 
 * Olin Gallet
 * 4/2/2017
 */

int column = 1;


String H_LETTER[7] = {
 "110011",
 "110011",
 "111111",
 "111111",
 "110011",
 "110011",
 "110011"
};

String I_LETTER[7] = {
  "111111",
  "111111",
  "001100",
  "001100",
  "001100",
  "111111",
  "111111"
};
/**
 * Initializes pin for output with state LOW.
 */
void init_pin(int number){
  pinMode(number, OUTPUT);
  digitalWrite(number, LOW);
}

/**
 * Displays symbol noted as 6 x 7 array.
 * Poorly coded due to poor wiring of the transistors.
 */
void display_symbol(int *pin, String letter[7]){
  int count = *pin;
  while (*pin < count + 6){
    digitalWrite(*pin, HIGH);
    
    if (letter[0].charAt(*pin - count) == '1'){
     digitalWrite(25, HIGH);
    } else {
     digitalWrite(25, LOW); 
    }

    if (letter[1][*pin - count] == '1'){
      digitalWrite(22, HIGH);
    } else {
      digitalWrite(22, LOW);
    }

    if (letter[2][*pin - count] == '1'){
      digitalWrite(21, HIGH);
    } else {
      digitalWrite(21, LOW);
    }

    if (letter[3][*pin - count] == '1'){
      digitalWrite(24, HIGH);
    } else {
      digitalWrite(24, LOW);
    }

    if (letter[4][*pin - count] == '1'){
      digitalWrite(23, HIGH);
    } else {
      digitalWrite(23, LOW);
    }

    if (letter[5][*pin - count] == '1'){
      digitalWrite(26, HIGH);
    } else {
      digitalWrite(26, LOW);
    }

    if (letter[6][*pin - count] == '1'){
      digitalWrite(20, HIGH);
    } else {
      digitalWrite(20, LOW);
    }
    delay(1);
    digitalWrite(*pin, LOW);
    *pin = *pin + 1;
  }
}
 
void setup() {  
  int y = 1;
  while (y < 27){
    init_pin(y);
    y = y + 1;
  }
}

// the loop routine runs over and over again forever:
void loop() {
  if (column == 6){
    display_symbol(&column, H_LETTER);
  } else if (column == 13){
    display_symbol(&column, I_LETTER);
  }
  column = column + 1;
  if (column == 20){
    column = 1;
  }
  delay(1);
}
