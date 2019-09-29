/**
 * @file   dbPin.hpp
 * @brief  Circuit Element - Pin
 * @author Hao Chen
 * @date   09/20/2019
 *
 **/

#ifndef _DB_PIN_HPP_
#define _DB_PIN_HPP_

#include "src/global/global.hpp"
#include "src/geo/box.hpp"

PROJECT_NAMESPACE_START

class Pin {
  friend class Parser;
  friend class Ispd08Reader;
 public:
  Pin()
    : _name(""), _netName(""), _netIdx(MAX_INDEX), _layerIdxOffset(MAX_INDEX) {}
  ~Pin() {}

  ////////////////////////////////////////
  //   Getter                           //
  ////////////////////////////////////////
  const String_t&                         name()                                        const { return _name; }
  const String_t&                         netName()                                     const { return _netName; }
  Index_t                                 netIdx()                                      const { return _netIdx; }
  Index_t                                 minLayerIdx()                                 const { return _layerIdxOffset; }
  Index_t                                 maxLayerIdx()                                 const { return _layerIdxOffset + _vvBoxes.size(); }
  const Box<Int_t>&                       box(const Index_t layerIdx, const Index_t j)  const { return _vvBoxes[layerIdx - _layerIdxOffset][j]; }
  const Vector_t<Box<Int_t>>&             vBoxes(const Index_t layerIdx)                const { return _vvBoxes[layerIdx - _layerIdxOffset]; }
  const Vector_t<Vector_t<Box<Int_t>>>&   vvBoxes()                                     const { return _vvBoxes; }

  // for debug
  void printInfo() const;

 private:
  String_t                        _name;
  String_t                        _netName;
  Index_t                         _netIdx;
  Index_t                         _layerIdxOffset; // offset between extact layerIdx and local vvBoxes
  Vector_t<Vector_t<Box<Int_t>>>  _vvBoxes; // Boxes in multiple layers
  
  ////////////////////////////////////////
  //   Setter                           //
  ////////////////////////////////////////
  void setName(const String_t& n);
  void setNetName(const String_t& n);
  void setNetIdx(const Index_t i);
  void setLayerIdxOffset(const Index_t i );
  void addBox(const Index_t layerIdx, const Box<Int_t>& box);
  void setLayerBoxes(const Index_t layerIdx, const Vector_t<Box<Int_t>>& vBoxes);
};

PROJECT_NAMESPACE_END

#endif /// _DB_PIN_HPP_