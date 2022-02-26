#ifndef SC_PROTOCOL_HPP
#define SC_PROTOCOL_HPP

#include "SCProcess.hpp"

namespace SC
{

class sc_protocol
{
public:
  sc_protocol();

private:
  SCProcess* supercollider;
};

}
#endif // SC_PROTOCOL_HPP
