#include <stdint.h>

const uint8_t primary_service_uuids[][16] = {
	{0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0x18, 0x01, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf0, 0x01, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb}
};

const uint16_t service_uuid16 = 0xF000;
const uint8_t primary_service_uuid16[]  = {0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb};
const uint8_t primary_service_uuid16_handles[]  = {0x24, 0x55};

const uint8_t primary_service_uuid128[] = {0x00, 0x00, 0xf0, 0x01, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb};
const uint8_t primary_service_uuid128_handles[]  = {0x56, 0x7A};

const uint8_t included_services_uuid16[] = {0x00, 0x00, 0xff, 0xf4, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb};
const uint8_t included_services_uuid16_handles[2] = {0x1F, 0x23};

const uint8_t included_services_uuid128[][16] = {
	{0x00, 0x00, 0xff, 0x10, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xff, 0x11, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
};

const uint8_t included_services_uuid128_handles[][2] = {
	{0x0F, 0x11},
	{0x12, 0x14}
};

uint8_t characteristic_handles[][2]= {
	{0x26, 0x2a}, {0x2b, 0x2f}, {0x30, 0x32}, {0x33, 0x35}, {0x36, 0x38}, 
	{0x39, 0x3b}, {0x3c, 0x3e}, {0x3f, 0x41}, {0x42, 0x44}, {0x45, 0x47}, 
	{0x48, 0x49}, {0x4a, 0x4f}, {0x50, 0x51}, {0x52, 0x53}, {0x54, 0x55} 
};

uint8_t characteristic_uuids[][16] = {
	{0x00, 0x00, 0xf1, 0x00, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf1, 0x01, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf1, 0x02, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf1, 0x03, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf1, 0x04, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf1, 0x05, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf1, 0x06, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf1, 0x07, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf1, 0x08, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf1, 0x09, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf1, 0x0a, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf1, 0x0b, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf1, 0x0d, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf1, 0x0c, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
	{0x00, 0x00, 0xf1, 0x0e, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb},
};

uint8_t indication[] = {GATT_CLIENT_CHARACTERISTICS_CONFIGURATION_NOTIFICATION, 0x00};
char long_value[] = "abcdefghijklmnopqrstuvwxyz";
char short_value[] = "abcd";
uint16_t short_value_length = sizeof(short_value);
uint16_t long_value_length  = sizeof(long_value);

