#include "rfid_i2c.h"
#include "esphome/core/log.h"

namespace esphome {
namespace rfid_i2c {

static const char *const TAG = "rfid_i2c";

void RFID_I2C::setup() {
  ESP_LOGI(TAG, "RFID I2C setup complete");
}

void RFID_I2C::update() {
  const uint8_t UID_LENGTH = 4;
  uint8_t buffer[UID_LENGTH];

  Wire.requestFrom(0x28, UID_LENGTH);

  if (Wire.available() == UID_LENGTH) {
    for (int i = 0; i < UID_LENGTH; i++) {
      buffer[i] = Wire.read();
    }

    char uid_hex[UID_LENGTH * 2 + 1];
    for (int i = 0; i < UID_LENGTH; i++) {
      sprintf(uid_hex + (i * 2), "%02X", buffer[i]);
    }

    uid_sensor->publish_state(uid_hex);
    ESP_LOGI(TAG, "UID letto: %s", uid_hex);
  }
}

}  // namespace rfid_i2c
}  // namespace esphome
