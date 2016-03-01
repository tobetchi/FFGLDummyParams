#include <FFGL.h>
#include <FFGLLib.h>
#include "FFGLDummyParams.h"

#define FFPARAM_DUMMY1  (0)
#define FFPARAM_DUMMY2  (1)
#define FFPARAM_DUMMY3  (2)
#define FFPARAM_DUMMY4  (3)
#define FFPARAM_DUMMY5  (4)
#define FFPARAM_DUMMY6  (5)
#define FFPARAM_DUMMY7  (6)
#define FFPARAM_DUMMY8  (7)
#define FFPARAM_DUMMY9  (8)
#define FFPARAM_DUMMY10 (9)
#define FFPARAM_DUMMY11 (10)
#define FFPARAM_DUMMY12 (11)
#define FFPARAM_DUMMY13 (12)
#define FFPARAM_DUMMY14 (13)
#define FFPARAM_DUMMY15 (14)
#define FFPARAM_DUMMY16 (15)


////////////////////////////////////////////////////////////////////////////////////////////////////
//  Plugin information
////////////////////////////////////////////////////////////////////////////////////////////////////

static CFFGLPluginInfo PluginInfo(
	FFGLDummyParams::CreateInstance,	    // Create method
	"GLPT",								// Plugin unique ID
	"Dummy Parameters",                 // Plugin name											
	1,						   			// API major version number 													
	000,								// API minor version number	
	1,									// Plugin major version number
	000,								// Plugin minor version number
	FF_EFFECT,																							// Plugin type
	"An effect with 16 dummy parameters for linking external software to Resolume's parameter system",  // Plugin description
	"by Louis dAboville"																			    // About
	);


////////////////////////////////////////////////////////////////////////////////////////////////////
//  Constructor and destructor
////////////////////////////////////////////////////////////////////////////////////////////////////

FFGLDummyParams::FFGLDummyParams()
	: CFreeFrameGLPlugin()
{
	// Input properties
	SetMinInputs(1);
	SetMaxInputs(1);

	// Parameters
	SetParamInfo(FFPARAM_DUMMY1,  "Param 1",  FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY2,  "Param 2",  FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY3,  "Param 3",  FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY4,  "Param 4",  FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY5,  "Param 5",  FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY6,  "Param 6",  FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY7,  "Param 7",  FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY8,  "Param 8",  FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY9,  "Param 9",  FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY10, "Param 10", FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY11, "Param 11", FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY12, "Param 12", FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY13, "Param 13", FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY14, "Param 14", FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY15, "Param 15", FF_TYPE_STANDARD, 0.5f);
	SetParamInfo(FFPARAM_DUMMY16, "Param 16", FF_TYPE_STANDARD, 0.5f);

	m_dummyOne		= 0.5f;
	m_dummyTwo		= 0.5f;
	m_dummyThree	= 0.5f;
	m_dummyFour     = 0.5f;
	m_dummyFive     = 0.5f;
	m_dummySix      = 0.5f;
	m_dummySeven    = 0.5f;
	m_dummyEight    = 0.5f;
	m_dummyNine     = 0.5f;
	m_dummyTen      = 0.5f;
	m_dummyEleven   = 0.5f;
	m_dummyTwelve   = 0.5f;
	m_dummyThirteen = 0.5f;
	m_dummyFourteen = 0.5f;
	m_dummyFifteen  = 0.5f;
	m_dummySixteen  = 0.5f;
}

FFGLDummyParams::~FFGLDummyParams()
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////
//  Methods
////////////////////////////////////////////////////////////////////////////////////////////////////

DWORD FFGLDummyParams::ProcessOpenGL(ProcessOpenGLStruct *pGL)
{
	if (pGL->numInputTextures<1)
		return FF_FAIL;

	if (pGL->inputTextures[0] == NULL)
		return FF_FAIL;

	FFGLTextureStruct &Texture = *(pGL->inputTextures[0]);

	//bind the texture handle
	glBindTexture(GL_TEXTURE_2D, Texture.Handle);

	//enable texturemapping
	glEnable(GL_TEXTURE_2D);

	//get the max s,t that correspond to the 
	//width,height of the used portion of the allocated texture space
	FFGLTexCoords maxCoords = GetMaxGLTexCoords(Texture);

	//set the gl rgb color to the brightness level
	//The FFGL spec says we must restore any state changes to the
	//default state as defined by OPENGL, this means we must restore
	//the color to white (1,1,1,1) before returning
	glColor4f(1.0, 1.0, 1.0, 1.0);

	//Default texturemapping behavior of OpenGL is to
	//multiply texture colors by the current gl color, so the
	//brightness effect is almost complete - all we need to do
	//now is draw a quad with the input texture mapped onto it

	glBegin(GL_QUADS);

	//lower left
	glTexCoord2d(0.0, 0.0);
	glVertex2f(-1, -1);

	//upper left
	glTexCoord2d(0.0, maxCoords.t);
	glVertex2f(-1, 1);

	//upper right
	glTexCoord2d(maxCoords.s, maxCoords.t);
	glVertex2f(1, 1);

	//lower right
	glTexCoord2d(maxCoords.s, 0.0);
	glVertex2f(1, -1);
	glEnd();

	//unbind the texture
	glBindTexture(GL_TEXTURE_2D, 0);

	//disable texturemapping
	glDisable(GL_TEXTURE_2D);

	//restore default color
	glColor4f(1.f, 1.f, 1.f, 1.f);

	return FF_SUCCESS;
}

DWORD FFGLDummyParams::GetParameter(DWORD dwIndex)
{
	DWORD dwRet;

	switch (dwIndex) {

	case FFPARAM_DUMMY1:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummyOne;
		return dwRet;

	case FFPARAM_DUMMY2:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummyTwo;
		return dwRet;

	case FFPARAM_DUMMY3:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummyThree;
		return dwRet;

	case FFPARAM_DUMMY4:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummyFour;
		return dwRet;

	case FFPARAM_DUMMY5:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummyFive;
		return dwRet;

	case FFPARAM_DUMMY6:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummySix;
		return dwRet;

	case FFPARAM_DUMMY7:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummySeven;
		return dwRet;

	case FFPARAM_DUMMY8:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummyEight;
		return dwRet;

	case FFPARAM_DUMMY9:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummyNine;
		return dwRet;

	case FFPARAM_DUMMY10:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummyTen;
		return dwRet;

	case FFPARAM_DUMMY11:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummyEleven;
		return dwRet;

	case FFPARAM_DUMMY12:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummyTwelve;
		return dwRet;

	case FFPARAM_DUMMY13:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummyThirteen;
		return dwRet;

	case FFPARAM_DUMMY14:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummyFourteen;
		return dwRet;

	case FFPARAM_DUMMY15:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummyFifteen;
		return dwRet;

	case FFPARAM_DUMMY16:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = m_dummySixteen;
		return dwRet;

	default:
		return FF_FAIL;
	}
}

DWORD FFGLDummyParams::SetParameter(const SetParameterStruct* pParam)
{
	if (pParam != NULL) {

		switch (pParam->ParameterNumber) {

		case FFPARAM_DUMMY1:
			//sizeof(DWORD) must == sizeof(float)
			m_dummyOne = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY2:
			//sizeof(DWORD) must == sizeof(float)
			m_dummyTwo = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY3:
			//sizeof(DWORD) must == sizeof(float)
			m_dummyThree = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY4:
			//sizeof(DWORD) must == sizeof(float)
			m_dummyFour = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY5:
			//sizeof(DWORD) must == sizeof(float)
			m_dummyFive = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY6:
			//sizeof(DWORD) must == sizeof(float)
			m_dummySix = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY7:
			//sizeof(DWORD) must == sizeof(float)
			m_dummySeven = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY8:
			//sizeof(DWORD) must == sizeof(float)
			m_dummyEight = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY9:
			//sizeof(DWORD) must == sizeof(float)
			m_dummyNine = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY10:
			//sizeof(DWORD) must == sizeof(float)
			m_dummyTen = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY11:
			//sizeof(DWORD) must == sizeof(float)
			m_dummyEleven = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY12:
			//sizeof(DWORD) must == sizeof(float)
			m_dummyTwelve = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY13:
			//sizeof(DWORD) must == sizeof(float)
			m_dummyThirteen = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY14:
			//sizeof(DWORD) must == sizeof(float)
			m_dummyFourteen = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY15:
			//sizeof(DWORD) must == sizeof(float)
			m_dummyFifteen = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		case FFPARAM_DUMMY16:
			//sizeof(DWORD) must == sizeof(float)
			m_dummySixteen = *((float *)(unsigned)&(pParam->NewParameterValue));
			break;

		default:
			return FF_FAIL;
		}

		return FF_SUCCESS;

	}

	return FF_FAIL;
}
