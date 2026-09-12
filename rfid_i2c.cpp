#include "rfid_i2c.h"
#include "esphome/core/log.h"

namespace esphome {
namespace rfid_i2c {

static const char *const TAG = "rfid_i2c";

void RFID_I2C::setup() {
  ESP_LOGI(TAG, "RFID I2C setup complete");
}

void RFID_I2C::update() {
  uint8_t data = 0;

  if (Wire.requestFrom(0x28, 1) == 1) {
    data = Wire.read();
    this->value_sensor->publish_state(data);
  }
}

}  // namespace rfid_i2c
}  // namespace esphome
