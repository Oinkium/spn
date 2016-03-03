#include <iostream>

#include "Sbox.h"
#include "createMapFromString.h"

int main()
{
  std::string sbox_hex_string =
    "7DE3069A1285BC4F";

  Sbox<4> sbox(createMapFromString(sbox_hex_string));

  std::bitset<32> plaintext(0xFACEF11C);

  std::cout << "Plaintext:\t" << std::hex << plaintext << std::endl;
  
  std::bitset<32> ciphertext = 
    sbox.encrypt<32>(plaintext);

  std::cout << "Ciphertext:\t" << std::hex << ciphertext << std::endl;

  return(0);
}
