#ifndef SBOX_INCLUDED
#define SBOX_INCLUDED

#include <map>
#include <string>
#include <bitset>

typedef int INT4BIT;

/*
 * An S-box of a given length D.
 */
template <size_t D>
class Sbox
{
  private:
    /*
     * Map that permutes the set {0, 1}^D
     */
    std::map<size_t, size_t> sbox_map;

  public:

    /*
     * Builds the S-box from a given map.
     */
    Sbox(std::map<size_t, size_t> sbox_map_) :
      sbox_map(sbox_map_) {}

    /*
     * Applies the S-box to a bitset of length L.
     */
    template <size_t L>
    std::bitset<L> encrypt(std::bitset<L> plaintext);
};

#include "Sbox.inl"

#endif
