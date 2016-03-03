#include "Sbox.h"

/*
 * Builds the S-box from a given hex string.
 */
Sbox4::Sbox4(std::string hex_string)
{
  // If the string is not the right length, then we can't do anything.
  if (hex_string.length() != 16)
  {
    throw "Wrong length of hex string!  Should have length 16!";
  }

  // We now build and populate the map from the hex string.
  for (INT4BIT i = 0 ; i < 16 ; ++i)
  {
    INT4BIT enciphered_value = hex_decrypt(hex_string[i]);
    cipher_map.insert(std::pair<INT4BIT, INT4BIT>(i, enciphered_value));
  }
}

/*
 * Enciphers a 32-bit plaintext.
 */
unsigned int Sbox4::encrypt32(unsigned int plaintext)
{
  unsigned int ciphertext = 0x0;

  for (int i = 0 ; i < 8 ; ++i)
  {
    // Encipher the plain text one 4-bit word at a time.
    INT4BIT current_word = plaintext & 0xF;
    INT4BIT enciphered_word = cipher_map[current_word];

    // Push the enciphered word on to the cipher text.
    ciphertext |= (enciphered_word << (i * 4));

    // Bit shift the plain text to push the word off the end.
    plaintext >>= 4;
  }

  return(ciphertext);
}

/*
 * Decrypts a hex character to return the numerical value.
 */
INT4BIT Sbox4::hex_decrypt(char& hex_character)
{
  std::pair<char, INT4BIT> hex_decoding_data[] = {
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

  std::map<char, INT4BIT>
    hex_decoder(hex_decoding_data, 
                hex_decoding_data +
                  (sizeof(hex_decoding_data) / sizeof(hex_decoding_data[0])));

  return hex_decoder[hex_character];
}
