#include "SpecificSettings.hpp"

#include <score/serialization/DataStreamVisitor.hpp>
#include <score/serialization/JSONVisitor.hpp>

template <>
void DataStreamReader::read(const SC::SpecificSettings& n)
{
  m_stream << n.control;
  insertDelimiter();
}

template <>
void DataStreamWriter::write(SC::SpecificSettings& n)
{
  m_stream >> n.control;
  checkDelimiter();
}

template <>
void JSONReader::read(const SC::SpecificSettings& n)
{
  obj["Control"] = n.control;
}

template <>
void JSONWriter::write(SC::SpecificSettings& n)
{
  n.control <<= obj["Control"];
}
