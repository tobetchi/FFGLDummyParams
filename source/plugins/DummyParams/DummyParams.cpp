#include <FFGL.h>
#include <FFGLLib.h>

#include "DummyParams.h"

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

static CFFGLPluginInfo PluginInfo (
    DummyParams::CreateInstance, // Create method
    "DP01",                      // Plugin unique ID
    "Dummy Params",              // Plugin name
    1,                           // API major version number
    000,                         // API minor version number
    1,                           // Plugin major version number
    000,                         // Plugin minor version number
    FF_EFFECT,                   // Plugin type
    "An effect with 16 dummy parameters for linking external software to Resolume's parameter system",  // Plugin description
    "by tobetchi"    // About
);

DummyParams::DummyParams()
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

    m_dummyOne      = 0.5f;
    m_dummyTwo      = 0.5f;
    m_dummyThree    = 0.5f;
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

DummyParams::~DummyParams() {
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//  Methods
////////////////////////////////////////////////////////////////////////////////////////////////////

FFResult DummyParams::ProcessOpenGL(ProcessOpenGLStruct *pGL) {
    if (pGL->numInputTextures<1)
        return FF_FAIL;

    if (pGL->inputTextures[0] == NULL)
        return FF_FAIL;

    FFGLTextureStruct &Texture = *(pGL->inputTextures[0]);

    glBindTexture(GL_TEXTURE_2D, Texture.Handle);
    glEnable(GL_TEXTURE_2D);

    FFGLTexCoords maxCoords = GetMaxGLTexCoords(Texture);

    glColor4f(1.0, 1.0, 1.0, 1.0);

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

    glBindTexture(GL_TEXTURE_2D, 0);

    glDisable(GL_TEXTURE_2D);

    //restore default color
    glColor4f(1.f, 1.f, 1.f, 1.f);

    return FF_SUCCESS;
}

float DummyParams::GetFloatParameter(unsigned int index) {
    float retValue = 0.0;

    switch (index) {
    case FFPARAM_DUMMY1:  retValue = m_dummyOne;      return retValue;
    case FFPARAM_DUMMY2:  retValue = m_dummyTwo;      return retValue;
    case FFPARAM_DUMMY3:  retValue = m_dummyThree;    return retValue;
    case FFPARAM_DUMMY4:  retValue = m_dummyFour;     return retValue;
    case FFPARAM_DUMMY5:  retValue = m_dummyFive;     return retValue;
    case FFPARAM_DUMMY6:  retValue = m_dummySix;      return retValue;
    case FFPARAM_DUMMY7:  retValue = m_dummySeven;    return retValue;
    case FFPARAM_DUMMY8:  retValue = m_dummyEight;    return retValue;
    case FFPARAM_DUMMY9:  retValue = m_dummyNine;     return retValue;
    case FFPARAM_DUMMY10: retValue = m_dummyTen;      return retValue;
    case FFPARAM_DUMMY11: retValue = m_dummyEleven;   return retValue;
    case FFPARAM_DUMMY12: retValue = m_dummyTwelve;   return retValue;
    case FFPARAM_DUMMY13: retValue = m_dummyThirteen; return retValue;
    case FFPARAM_DUMMY14: retValue = m_dummyFourteen; return retValue;
    case FFPARAM_DUMMY15: retValue = m_dummyFifteen;  return retValue;
    case FFPARAM_DUMMY16: retValue = m_dummySixteen;  return retValue;

    default:
        return retValue;
    }
}

FFResult DummyParams::SetFloatParameter(unsigned int index, float value) {
    switch (index) {
    case FFPARAM_DUMMY1:  m_dummyOne = value;      break;
    case FFPARAM_DUMMY2:  m_dummyTwo = value;      break;
    case FFPARAM_DUMMY3:  m_dummyThree = value;    break;
    case FFPARAM_DUMMY4:  m_dummyFour = value;     break;
    case FFPARAM_DUMMY5:  m_dummyFive = value;     break;
    case FFPARAM_DUMMY6:  m_dummySix = value;      break;
    case FFPARAM_DUMMY7:  m_dummySeven = value;    break;
    case FFPARAM_DUMMY8:  m_dummyEight = value;    break;
    case FFPARAM_DUMMY9:  m_dummyNine = value;     break;
    case FFPARAM_DUMMY10: m_dummyTen = value;      break;
    case FFPARAM_DUMMY11: m_dummyEleven = value;   break;
    case FFPARAM_DUMMY12: m_dummyTwelve = value;   break;
    case FFPARAM_DUMMY13: m_dummyThirteen = value; break;
    case FFPARAM_DUMMY14: m_dummyFourteen = value; break;
    case FFPARAM_DUMMY15: m_dummyFifteen = value;  break;
    case FFPARAM_DUMMY16: m_dummySixteen = value;  break;

    default:
        return FF_FAIL;
    }

    return FF_SUCCESS;
}
