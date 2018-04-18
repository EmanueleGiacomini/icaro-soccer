/**
 * @brief 
 * 
 * @file eeprom.cpp
 * @author your name
 * @date 2018-04-14
 */

template <typename T>

void putEEPROM(int address, const T& value) {
    const char* c = reinterpret_cast<const char*>(&value);
    int a = address;
    for (int i = 0; i < sizeof(T); i++) {
    }
}