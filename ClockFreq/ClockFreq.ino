#include "soc/rtc.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  rtc_cpu_freq_t frequency = rtc_clk_cpu_freq_get();
  Serial.println(frequency);
  
  delay(1000);
}
