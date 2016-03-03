#ifndef SBOX_INL_INCLUDED
#define SBOX_INL_INCLUDED

/*
 * Enciphers a plaintext with a given length L.
 */
template <size_t D>
template <size_t L>
std::bitset<L> Sbox<D>::encrypt(std::bitset<L> plaintext)
{
  std::bitset<L> cipher_text(0x0);

  // Split the cipher text into D-bit words and apply the S-box to each
  // word.
  for (size_t i = 0 ; i < L ; i+= D)
  {
    // Set up the current D-bit word.
    std::bitset<D> current_word;

    for (size_t j = 0 ; j < D ; ++j)
    {
      current_word.set(j, plaintext[i + j]);
    }

    // We now apply the S-box to the current word.
    std::bitset<D> new_word(sbox_map[current_word.to_ulong()]);

    // Write this word into the ciphertext.
    for (size_t j = 0 ; j < D ; ++j)
    {
      cipher_text.set(i + j, new_word[j]);
    }
  }

  return(cipher_text);
}

#endif
