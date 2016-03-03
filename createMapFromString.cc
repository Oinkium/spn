#include "createMapFromString.h"

/*
 * Builds a map from a specified hex string.
 */
std::map<size_t, size_t> createMapFromString(std::string hex_string)
{
  std::map<size_t, size_t> cipher_map;

  // If the string is not the right length, then we can't do anything.
  if (hex_string.length() != 16)
  {
    throw "Wrong length of hex string!  Should have length 16!";
  }

  // We now build and populate the map from the hex string.
  for (size_t i = 0 ; i < 16 ; ++i)
  {
    size_t enciphered_value = hex_decrypt(hex_string[i]);
    cipher_map.insert(std::pair<size_t, size_t>(i, enciphered_value));
  }

  return(cipher_map);
}

/*
 * Decrypts a hex character to return the numerical value.
 */
size_t hex_decrypt(char& hex_character)
{
  std::pair<char, size_t> hex_decoding_data[] = {
    std::make_pair('0', 0),
    std::make_pair('1', 1),
    std::make_pair('2', 2),
    std::make_pair('3', 3),
    std::make_pair('4', 4),
    std::make_pair('5', 5),
    std::make_pair('6', 6),
    std::make_pair('7', 7),
    std::make_pair('8', 8),
    std::make_pair('9', 9),
    std::make_pair('A', 10),
    std::make_pair('B', 11),
    std::make_pair('C', 12),
    std::make_pair('D', 13),
    std::make_pair('E', 14),
    std::make_pair('F', 15)
  };

  std::map<char, size_t>
    hex_decoder(hex_decoding_data, 
                hex_decoding_data +
                  (sizeof(hex_decoding_data) / sizeof(hex_decoding_data[0])));

  return hex_decoder[hex_character];
}
