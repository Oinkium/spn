#ifndef SBOX4_H_INCLUDED
#define SBOX4_H_INCLUDED

#include <map>
#include <string>

typedef int INT4BIT;

// Forward declaration
class Permutation16;

/*
 * An S-box with length 4
 */
class Sbox4
{
  friend class Permutation16;
  private:
    /*
     * The map that maps each plaintext block to the associated ciphertext block
     */
    std::map<INT4BIT,INT4BIT> cipher_map;

    INT4BIT hex_decrypt(char&);

  public:

    Sbox4(std::string);
    unsigned int encrypt32(unsigned int);
};

#endif
