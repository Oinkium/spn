#include "Permutation16.h"

/*
 * Enciphers a 32-bit plaintext.
 */
unsigned int Permutation16::permute32(unsigned int plaintext)
{
  unsigned int cipher_text = 0x0;

  // Split the cipher text into two 16-bit words and run the permutation over each word.
  for (int i = 0 ; i < 2 ; ++i) {
    unsigned int current_16bit_word = 0xFFFF & (plaintext >> (16 * i));
    
    // We now permute the current 16-bit word.
    unsigned int permuted_word = 0x0;

    for (INT4BIT j = 0 ; j < 16 ; ++j)
    {
      INT4BIT permuted_index = sbox4.cipher_map[j];
      
      // Create a variable that is 1 if the plaintext has a 1 in index j, and a 0 if it has a 0.
      int current_digit = ((current_16bit_word & (0x1 << j)) != 0) ? 1 : 0;

      // Now place that 1 or 0 in the correct position in the permuted word.
      permuted_word |= (current_digit << permuted_index);
    }

    cipher_text |= (permuted_word << (16 * i));
  }

  return(cipher_text);
}
