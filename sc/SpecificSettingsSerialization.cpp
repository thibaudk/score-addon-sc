#include "SpecificSettings.hpp"

#include <score/serialization/DataStreamVisitor.hpp>
#include <score/serialization/JSONVisitor.hpp>

template <>
void DataStreamReader::read(const sc::SpecificSettings& n)
{
  m_stream << n.control;
  insertDelimiter();
}

template <>
void DataStreamWriter::write(sc::SpecificSettings& n)
{
  m_stream >> n.control;
  checkDelimiter();
}

template <>
void JSONReader::read(const sc::SpecificSettings& n)
{
  obj["Control"] = n.control;
}

template <>
void JSONWriter::write(sc::SpecificSettings& n)
{
  n.control <<= obj["Control"];
}