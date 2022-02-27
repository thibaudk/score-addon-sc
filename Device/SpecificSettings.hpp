#pragma once
#include <score/tools/std/StringHash.hpp>

#include <verdigris>

namespace SC
{
struct SpecificSettings
{
  int control{1234};
};
}

Q_DECLARE_METATYPE(SC::SpecificSettings)
W_REGISTER_ARGTYPE(SC::SpecificSettings)
