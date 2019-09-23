/**
 * @file   util.cpp
 * @brief  Utils
 * @author Hao Chen
 * @date   09/22/2019
 *
 **/

#include <sys/stat.h>

#include "util.hpp"

PROJECT_NAMESPACE_START

namespace util {
  void showSysInfo() {
    FILE* fout = stdout;
    fprintf(fout, "\n");
    fprintf(fout, "*********************************************************\n");
    fprintf(fout, "*                        AnaRoute                       *\n");
    fprintf(fout, "*                                                       *\n");
    fprintf(fout, "*              Hao Chen, Keren Zhu, Mingjie Liu,        *\n");
    fprintf(fout, "*                    and David Z. Pan                   *\n");
    fprintf(fout, "*                   UT Design Automation                *\n");
    fprintf(fout, "*             The University of Texas at Austin         *\n");
    fprintf(fout, "*              https://www.cerc.utexas.edu/utda         *\n");
    fprintf(fout, "*                                                       *\n");
    fprintf(fout, "*********************************************************\n");

#ifdef __linux__
    int systemret = 0;
    fprintf(fout, "=================== SYSTEM INFORMATION ==================\n");
    systemret += system(">&2 echo 'User:       '`whoami`@`hostname`");
    systemret += system(">&2 echo 'Date:       '`date`");
    systemret += system(">&2 echo 'System:     '`uname -a`");
    fprintf(fout, "=========================================================\n");
    assert(!systemret);
#endif
  }
  
  // filename
  bool existFile (const String_t& filename) {
    struct stat buffer;
    return stat(filename.c_str(), &buffer) == 0;
  }

  String_t getFileDirName(const String_t& filePathName) {
    String_t retStr = filePathName;
    String_t::size_type pos = retStr.rfind("/");
    if (pos != String_t::npos)
      retStr = retStr.substr(0, pos);
    return retStr;
  }

  String_t getFileName(const String_t& filePathName) {
    String_t retStr = filePathName;
    String_t::size_type pos = retStr.rfind("/");
    if (pos != String_t::npos)
      retStr = retStr.substr(pos + 1);
    return retStr;
  }
  
  // String_t
  void splitString(const char* str, const String_t& delims, Vector_t<String_t>& tokens) {
    tokens.clear();
    String_t s(str), token;
    size_t cur, prev = 0;
    cur = s.find_first_of(delims);
    while (cur != String_t::npos) {
      token = s.substr(prev, cur - prev);
      if (token != "") tokens.push_back(token);
      prev = cur + 1;
      cur = s.find_first_of(delims, prev);
    }
    token = s.substr(prev, cur - prev);
    if (token != "") tokens.push_back(token);
  }

  void splitString(const String_t& s, const String_t& delims, Vector_t<String_t>& tokens) {
    tokens.clear();
    String_t token;
    size_t cur, prev = 0;
    cur = s.find_first_of(delims);
    while (cur != String_t::npos) {
      token = s.substr(prev, cur - prev);
      if (token != "") tokens.push_back(token);
      prev = cur + 1;
      cur = s.find_first_of(delims, prev);
    }
    token = s.substr(prev, cur - prev);
    if (token != "") tokens.push_back(token);
  }

  void splitString(const char* str, const char c, Vector_t<String_t>& tokens) {
    tokens.clear();
    do {
      const char* begin = str;
      while (*str != c && *str) ++str;
      String_t s = String_t(begin, str);
      if (s != "") tokens.push_back(s);
    } while (*str++);
  }
}

PROJECT_NAMESPACE_END
