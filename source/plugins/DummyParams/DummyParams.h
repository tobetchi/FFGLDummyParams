#pragma once

#include "FFGLPluginSDK.h"

class DummyParams : public CFreeFrameGLPlugin {
public:
    DummyParams();
    ~DummyParams();

    ///////////////////////////////////////////////////
    // FreeFrame plugin methods
    ///////////////////////////////////////////////////

    FFResult SetFloatParameter(unsigned int index, float value) override;
    float GetFloatParameter(unsigned int index) override;
    FFResult ProcessOpenGL(ProcessOpenGLStruct* pGL) override;

    ///////////////////////////////////////////////////
    // Factory method
    ///////////////////////////////////////////////////

    static FFResult __stdcall CreateInstance(CFreeFrameGLPlugin **ppOutInstance) {
        *ppOutInstance = new DummyParams();
        if (*ppOutInstance != NULL)
            return FF_SUCCESS;
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
