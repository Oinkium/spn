#ifndef PERMUTATION_INCLUDED
#define PERMUTATION_INCLUDED

#include <map>
#include <bitset>

// Forward declaration
class Sbox;

/*
 * A permutation of a given length N.
 */
template <size_t N>
class Permutation
{
  private:
    /*
     * Map that permutes the numbers 0..N-1.
     */
    std::map<size_t, size_t> permutation_map;

  public:

    /*
     * Builds the permutation from a given map.
     */
    Permutation(std::map<size_t, size_t> permutation_map_) :
      permutation_map(permutation_map_) {}

    /*
     * Permutes a bitset of length L.
     */
    template <size_t L>
    std::bitset<L> permute(std::bitset<L> plaintext);
};

#include "Permutation.inl"

#endif
