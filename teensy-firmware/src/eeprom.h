/**
 * @brief 
 * 
 * @file eeprom.h
 * @author your name
 * @date 2018-04-14
 */

#pragma once

const uint32_t firmware_version = 0xDEADBEB0;

const int eeprom_version_address = 0x0000;
const int eeprom_system_param_address = 0x0010;

/**
 * @brief Initialize the eeprom with firmware version
 * if it is the first time this function is called, it writes once the suff in EEPROM
 */
void initEEPROM();

/**
 * @brief Reads the default params from eeprom
 * 
 * @param param_type 
 */
void loadParamsFromEEPROM(uint8_t param_type);

/**
 * @brief Writes the default params to eeprom
 * 
 * @param param_type 
 */
void writeParamsToEEPROM(uint8_t param_type);
