// Interrupt on A changing state
void doEncoderA(){
  delayMicroseconds(5000);
  // Low to High transition?
  if (digitalRead(encoder0PinA) == HIGH) { 
    A_set = true;
    if (!B_set) {
      encoderPos = encoderPos - 1;
    }        
  }

  // High-to-low transition?
  if (digitalRead(encoder0PinA) == LOW) {
    A_set = false;
  }

}

// Interrupt on B changing state
void doEncoderB(){
  delayMicroseconds(5000);

  // Low-to-high transition?
  if (digitalRead(encoder0PinB) == HIGH) {   
    B_set = true;
    if (!A_set) {
      encoderPos = encoderPos + 1;
    }
  }

  // High-to-low transition?
  if (digitalRead(encoder0PinB) == LOW) {
    B_set = false;
  }
}

