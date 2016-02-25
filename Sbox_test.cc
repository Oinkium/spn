#include <iostream>

#include "Sbox4.h"

int main()
{
  std::string sbox_hex_string =
    "7DE3069A1285BC4F";

  Sbox4 sbox4(sbox_hex_string);

  unsigned int plaintext = 0xFACEF11C;

  std::cout << "Plaintext: " << std::hex << plaintext << std::endl;
  
  unsigned int ciphertext = 
    sbox4.encrypt32(plaintext);

  std::cout << "Ciphertext: " << std::hex << ciphertext << std::endl;

  return(0);
}
