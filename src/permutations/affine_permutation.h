//
//  AffinePermutation.h
//  StegoFS
//
//  Created by Martin Kosdy on 3/22/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef STEGODISK_PERMUTATIONS_AFFINEPERMUTATION_H_
#define STEGODISK_PERMUTATIONS_AFFINEPERMUTATION_H_

#include "permutation.h"

namespace stego_disk {

class AffinePermutation : public Permutation {

public:
  virtual void Init(PermElem requested_size, Key key);
  virtual PermElem Permute(PermElem index) const;
  virtual PermElem GetSizeUsingParams(PermElem requested_size, Key key);

  virtual const std::string GetNameInstance() const { return "Affine"; }

  //    const string getNameInstance() const;
  //    static const string getName();
  //    virtual shared_ptr<Permutation> getNewInstance();
  //    static shared_ptr<Permutation> getNew();

protected:
  PermElem GetSizeUsingParams(PermElem requested_size, Key key,
                              bool overwrite_members);
  uint64 key_param_a_;
  uint64 key_param_b_;
};

} // stego_disk

#endif // STEGODISK_PERMUTATIONS_AFFINEPERMUTATION_H_
