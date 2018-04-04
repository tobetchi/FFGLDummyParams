![Default Effect](http://i.imgur.com/eYtEywC.png "Dummy Parameter UI")

# Usage

Copy **FFGLDummyParams.bundle** into **(Resolume dir)/plugins/vfx** folder to use default effect settings as shown above

# Customising parameter names

If you want to customise parameter names you will have to rebuild the project.

## Editing the code

To alter how parameter **names** appear in Resolume, change the these lines of code:

```c++
// Parameters
SetParamInfo(FFPARAM_DUMMY1,  "Param 1",  FF_TYPE_STANDARD, 0.5f);
SetParamInfo(FFPARAM_DUMMY2,  "Param 2",  FF_TYPE_STANDARD, 0.5f);
SetParamInfo(FFPARAM_DUMMY3,  "Param 3",  FF_TYPE_STANDARD, 0.5f); ...etc
```

  like this

```c++
// Parameters
SetParamInfo(FFPARAM_DUMMY1,  "New Param Name 1",  FF_TYPE_STANDARD, 0.5f);
SetParamInfo(FFPARAM_DUMMY2,  "New Param Name 2",  FF_TYPE_STANDARD, 0.5f);
SetParamInfo(FFPARAM_DUMMY3,  "New Param Name 3",  FF_TYPE_STANDARD, 0.5f); ...etc
```

To change parameter **default values** in Resolume change the **0.5f** on these lines to anything between **0.0f** and **1.0f**

```c++
m_dummyOne   = 0.5f;
m_dummyTwo   = 0.5f;
m_dummyThree = 0.5f;
```
