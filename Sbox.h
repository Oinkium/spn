#include <map>
#include <string>
#include <bitset>

typedef int INT4BIT;

/*
 * An S-box with length 4
 */
class Sbox
{
  private:
    /*
     * The map that maps each plaintext block to the associated ciphertext block
     */
    std::map<INT4BIT,INT4BIT> cipher_map;

    INT4BIT hex_decrypt(char&);

  public:

    template <size_t N>
    std::bitset<N> encrypt32(std::bitset<N>);
};
