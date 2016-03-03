#include <iostream>

#include "Permutation.h"
#include "createMapFromString.h"

int main()
{
  std::string permutation_hex_string = 
    "048C159D26AE37BF";

  Permutation<16> permutation(createMapFromString(permutation_hex_string));

  std::bitset<32> plaintext(0xFACEF11C);

  std::cout << "Plaintext:\t\t" << std::hex << plaintext << std::endl;

  plaintext = permutation.permute<32>(plaintext);

  std::cout << "Enciphered once:\t" << std::hex << plaintext << std::endl;

  plaintext = permutation.permute<32>(plaintext);

  std::cout << "Enciphered twice:\t" << std::hex << plaintext << std::endl;

  return(0);
}
