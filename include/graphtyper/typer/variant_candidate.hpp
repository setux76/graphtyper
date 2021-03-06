#pragma once

#include <string> // std::string
#include <vector> // std::vector

#include <graphtyper/typer/variant.hpp>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>


namespace gyper
{

/**
Variant candidate is almost the same as Variant, but I was not sure how to use polymorphism effectively here,
so I ended up repeating some code in both classes.
*/

class VariantCandidate
{
  friend class boost::serialization::access;

public:
  uint32_t abs_pos = 0;
  std::vector<std::vector<char> > seqs;
  bool is_low_qual = false;
  bool is_in_proper_pair = true;
  bool is_mapq0 = false;
  bool is_unaligned = false;
  bool is_clipped = false;
  bool is_first_in_pair = false;
  bool is_seq_reversed = false;
  uint32_t original_pos = 0u;

  /******************
   * CLASS MODIFERS *
   ******************/
  bool add_base_in_front(bool add_N = false);
  bool add_base_in_back(bool add_N = false);
  void normalize(); /** \brief Defined here: http://genome.sph.umich.edu/wiki/Variant_Normalization */

  /*********************
   * CLASS INFORMATION *
   ********************/
  bool is_normalized() const;
  bool is_snp_or_snps() const;
  std::string print() const;

  /*********************
   * OPERATOR OVERLOAD *
   *********************/
  bool operator==(VariantCandidate const & b) const;
  bool operator!=(VariantCandidate const & b) const;
  bool operator<(VariantCandidate const & b) const;

private:
  template <class Archive>
  void
  serialize(Archive & ar, const unsigned int)
  {
    ar & abs_pos;
    ar & seqs;
    ar & is_low_qual;
    ar & is_in_proper_pair;
    ar & is_mapq0;
    ar & is_unaligned;
    ar & is_clipped;
    ar & is_first_in_pair;
    ar & is_seq_reversed;
    ar & original_pos;
  }
};

// Hash function for VariantCandidate
struct VariantCandidateHash
{
  std::size_t operator()(VariantCandidate const & v) const;
};

} // namespace gyper
