#pragma once
#include"stdafx.h"

class CObject {
public:
	virtual CRuntimeClass* GetRuntimeClass() const;
	virtual ~CObject() {}

protected:
	CObject() {}
};