#ifndef FFGLBRIGHTNESS_H
#define FFGLBRIGHTNESS_H

#include "../../FFGL-SDK/Source/FFGLPlugins/FFGLPluginSDK.h"

class FFGLDummyParams :
	public CFreeFrameGLPlugin
{
public:
	FFGLDummyParams();
	virtual ~FFGLDummyParams();

	///////////////////////////////////////////////////
	// FreeFrame plugin methods
	///////////////////////////////////////////////////

	DWORD	SetParameter(const SetParameterStruct* pParam);
	DWORD	GetParameter(DWORD dwIndex);
	DWORD	ProcessOpenGL(ProcessOpenGLStruct* pGL);

	///////////////////////////////////////////////////
	// Factory method
	///////////////////////////////////////////////////

	static DWORD __stdcall CreateInstance(CFreeFrameGLPlugin **ppInstance)
	{
		*ppInstance = new FFGLDummyParams();
		if (*ppInstance != NULL) return FF_SUCCESS;
		return FF_FAIL;
	}

protected:
	// Parameters
	float m_dummyOne;
	float m_dummyTwo;
	float m_dummyThree;
	float m_dummyFour;
	float m_dummyFive;
	float m_dummySix;
	float m_dummySeven;
	float m_dummyEight;
	float m_dummyNine;
	float m_dummyTen;
	float m_dummyEleven;
	float m_dummyTwelve;
	float m_dummyThirteen;
	float m_dummyFourteen;
	float m_dummyFifteen;
	float m_dummySixteen;
};


#endif
