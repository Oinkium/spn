#ifndef PERMUTATION16_INCLUDED
#define PERMUTATION16_INCLUDED

#include <map>
#include <string>

#include "Sbox4.h"

/*
 * A permutation of length 16.
 */
class Permutation16
{
  private:
    /*
     * We use an S-box of length 4 to do most of our work for us.
     */
    Sbox4 sbox4;

  public:

    /*
     * Builds the permutation, using a supplied hex string.
     */
    Permutation16(std::string hex_string) : sbox4(hex_string) {}

    unsigned int permute32(unsigned int);
};

#endif
