/**
 * @file   parser.hpp
 * @brief  Parser manager for database
 * @author Hao Chen
 * @date   09/09/2019
 *
 **/

#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include "src/global/global.hpp"
#include "src/db/dbCir.hpp"
#include "parLef.hpp"
#include "parTech.hpp"
#include "parIspd08.hpp"
#include "parGds.hpp"
#include "parSymNet.hpp"

PROJECT_NAMESPACE_START

class Parser {
public:
  Parser(CirDB& c)
    : _cir(c), _lefr(c.lef()), _techr(c), _ispd08r(c),
      _gdsr(c), _symNetr(c) {}
  ~Parser() {}
  
  void parseLef(const String_t& filename)       { _lefr.parse(filename); }
  void parseTechfile(const String_t& filename)  { _techr.parse(filename); }
  void parseIspd08(const String_t& filename)    { _ispd08r.parse(filename); }
  void parseGds(const String_t& filename)       { _gdsr.parse(filename); }
  void parseSymNet(const String_t& filename)    { _symNetr.parse(filename); }

  // patch for the bug from placement
  void correctPinNBlkLoc();

private:
  CirDB&           _cir;
  LefReader        _lefr;
  TechfileReader   _techr;
  Ispd08Reader     _ispd08r;
  GdsReader        _gdsr;
  SymNetReader     _symNetr;
};

PROJECT_NAMESPACE_END

#endif /// _PARSER_HPP_
