#pragma once

#include "LanguageType.hpp"

#include "Constructor.hpp"
#include "Field.hpp"
#include "Global.hpp"
#include "Method.hpp"
#include "Function.hpp"

struct BaseClass
{
    BaseClass(const Cursor &cursor);

	bool IsNative() const;
	
    std::string name;
};

class Class : public LanguageType
{
    // to access m_qualifiedName
    friend class Global;
    friend class Function;
    friend class Method;
    friend class Constructor;
    friend class Field;

public:
    Class(const Cursor &cursor, const Namespace &currentNamespace);
    virtual ~Class(void);

    bool ShouldGenerate(void) const;
	bool IsAgent() const;
	bool IsModule() const;

	void GenerateCode(std::string const & fileId, std::stringstream & outCode) const;
    void GenerateCodeInit(std::stringstream & outCode) const;
    void GenerateCodeStaticInit(std::stringstream & outCode) const;

    std::string GetGeneratedBodyLine() const;

protected:
    void GenerateFieldsInitCode(std::stringstream & outCode) const;
    void GenerateStaticFieldsInitCode(std::stringstream & outCode) const;
	void GenerateDeclarations(std::stringstream & outCode) const;
	void GenerateImpl(std::stringstream & outCode) const;
    
	BaseClass const * GetBaseClass(std::string const & name) const;
	BaseClass const * GetBaseAgentClass() const;

private:
    std::string m_name;
    std::string m_displayName;
    std::string m_qualifiedName;

	typedef std::vector<BaseClass*> tBaseClassVector;
	tBaseClassVector m_baseClasses;
        
    std::vector<Constructor*> m_constructors;

    typedef std::vector<Field*> tFieldsVector;
    tFieldsVector m_fields;
    
    typedef std::vector<Global*> tStaticFieldsVector;
    tStaticFieldsVector m_staticFields;
    
    typedef std::vector<Method*> tMethodVector;
    tMethodVector m_methods;

    std::vector<Function*> m_staticMethods;

    bool m_isScObject;
};