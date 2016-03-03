#ifndef PERMUTATION_INL_INCLUDED
#define PERMUTATION_INL_INCLUDED

/*
 * Enciphers a 32-bit plaintext.
 */
template <size_t N>
template <size_t L>
std::bitset<L> Permutation<N>::permute(std::bitset<L> plaintext)
{
  std::bitset<L> cipher_text(0x0);

  // Split the cipher text into N-bit words and permute the words.
  for (size_t i = 0 ; i < L ; i+=N)
  {
    // Set up the current N-bit word.
    std::bitset<N> current_word;

    for (size_t j = 0 ; j < N ; ++j)
    {
      current_word.set(j, plaintext[i + j]);
    }
    
    // We now permute the current 16-bit word.
    std::bitset<N> permuted_word;

    for (size_t j = 0 ; j < N ; ++j)
    {
      size_t permuted_index = permutation_map[j];
      
      // Create a variable that is 1 if the plaintext has a 1 in index j, and a 0 if it has a 0.
      std::bitset<N> one_in_place_j;
      one_in_place_j.set(j, true);
      bool current_digit = ((current_word & one_in_place_j) != 0);

      // Now place that 1 or 0 in the correct position in the permuted word.
      permuted_word.set(permuted_index, current_digit);
    }

    for (size_t j = 0 ; j < N ; ++j)
    {
      cipher_text.set(i + j, permuted_word[j]);
    }
  }

  return(cipher_text);
}

#endif
