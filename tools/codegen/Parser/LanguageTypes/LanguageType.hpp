#pragma once

#include "CursorType.hpp"
#include "MetaDataManager.hpp"
#include "Types.hpp"

class Cursor;

class LanguageType
{
public:
  LanguageType(Cursor const & cursor, const Namespace &currentNamespace);
  virtual ~LanguageType(void) { }

  const MetaDataManager & GetMetaData(void) const;

protected:
  MetaDataManager m_metaData;

  // determines if the type is enabled in reflection database generation
  bool m_enabled;

  // determines if the pointer type to this type will be generated
  // in the reflection database
  bool m_ptrTypeEnabled;

  // determines if the constant pointer type to this type will be
  // generated in the reflection database
  bool m_constPtrTypeEnabled;

  Namespace m_currentNamespace;

  CX_CXXAccessSpecifier m_accessModifier;

private:
};
