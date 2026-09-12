#pragma once
#include "esphome.h"

class RFID_I2C : public PollingComponent {
 public:
  Sensor *value_sensor = new Sensor();

  RFID_I2C() : PollingComponent(100) {}

  void setup() override {}

  void update() override {
    uint8_t data = 0;

    if (Wire.requestFrom(0x28, 1) == 1) {
      data = Wire.read();
      value_sensor->publish_state(data);
    }
  }
};
