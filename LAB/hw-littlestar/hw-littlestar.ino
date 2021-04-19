// https://github.com/lbernstone/Tone32
#include <Tone32.h>

#define BUZZER_PIN 13
#define BUZZER_CHANNEL 0
// The melody array 
int melody[] = {
  NOTE_D5, NOTE_D5, NOTE_FS5, NOTE_FS5, NOTE_G5, NOTE_G5, 
  NOTE_FS5,NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_DS5,
  NOTE_DS5, NOTE_D5,
};

// The note duration, 8 = 8th note, 4 = quarter note, etc.
int durations[] = {
  4, 4, 4, 4, 4, 4, 8, 
  4, 4, 4, 4, 4, 4, 8
};
int songLength = sizeof(melody)/sizeof(melody[0]);
void setup() {}

void loop() {
   for (int thisNote = 0; thisNote < songLength; thisNote++){
    // determine the duration of the notes that the computer understands
    // divide 1000 by the value, so the first note lasts for 1000/8 milliseconds
    int duration = 1000/ durations[thisNote];
    tone(BUZZER_PIN, melody[thisNote], duration, BUZZER_CHANNEL);
    // pause between notes
    int pause = duration * 1.3;
    delay(pause);
    // stop the tone
    noTone(BUZZER_PIN, BUZZER_CHANNEL);
  }
}
