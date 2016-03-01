# Usage


Copy **FFGLDummyParams.dll** into **(Resolume dir)/plugins/vfx** folder

By default this effect has 16 parameters named "Param1", "Param 2" etc


# Customising parameter names

If you want to customise parameter names you will have to install the FFGL SDK and rebuild the project. If that phrase makes your eyes glaze over, fear not. I'll try and explain *all* the steps involved.

If anyone knows how to change parameter names dynamically from an .ini file or something please let me know as this would be considerably easier!

## Getting set up

First, install Microsoft Visual Studio (I used [Community Edition 2015](https://www.visualstudio.com/en-us/products/visual-studio-community-vs.aspx))

Go to the [ FFGL project page](https://sourceforge.net/p/freeframe/svn/HEAD/tree/trunk/FFGL-SDK/), press "Download Snapshot" and extract the **freeframe-svn-137-trunk** folder somewhere on your computer. This has all the code we need to build a FFGL plugin.

Download [this repository](https://github.com/Leskos/FFGLDummyParams/archive/master.zip) and pop the **FFGLDummyParams-master** folder into **freeframe-svn-137-trunk/FFGL SDK/Projects/FFGLPlugins/**


## Editing the code

Open **freeframe-svn-137-trunk/FFGL SDK/Projects/FFGLPlugins/FFGLDummyParams-master/FFGLPlugins.sln** in Visual Studio and navigate to **FFGLDummyParams/Source Files/FFGLDummyParams.cpp**

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



## Building the .dll

When you are happy with your changes, go to **Build** or press **Ctrh+Shift+B** in Visual Studio to build the project. This should hopefully spit out a few files including your shiny new .dll into either **FFGLDummyParams-master/Debug** or **FFGLDummyParams-master/Release**

Copy the new **FFGLDummyParams.dll** file into your **(Resolume dir)/plugins/vfx** folder, overwriting any old ones that might still be hanging about (trying to figure an easy way to have multiple instances with different names, if anyone has any ideas please get in touch)

Enjoy!
