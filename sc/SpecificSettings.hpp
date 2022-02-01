#pragma once
#include <score/tools/std/StringHash.hpp>

#include <verdigris>

namespace sc
{
struct SpecificSettings
{
  int control{1234};
};
}

Q_DECLARE_METATYPE(sc::SpecificSettings)
W_REGISTER_ARGTYPE(sc::SpecificSettings)