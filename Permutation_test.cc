#include <iostream>

#include "Permutation.h"
#include "createMapFromString.h"

int main()
{
  std::string permutation_hex_string = 
    "048C159D26AE37BF";

  Permutation<16> permutation(createMapFromString(permutation_hex_string));

  std::bitset<32> plaintext(0xFACEF11C);

  std::cout << "Plaintext: " << std::hex << plaintext << std::endl;

  plaintext = permutation.permute<32>(plaintext);

  std::cout << "Enciphered once: " << std::hex << plaintext << std::endl;

  plaintext = permutation.permute<32>(plaintext);

  std::cout << "Enciphered twice: " << std::hex << plaintext << std::endl;

  return(0);
}
