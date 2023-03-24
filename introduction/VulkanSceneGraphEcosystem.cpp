---
layout: page
title: VulkanSceneGraph - Ecosystem
permalink: /introduction/VulkanSceneGraphEcosystem
---

    
## Collection of libraries rather than a Monolythic SDK

One of the weakensses of the OoenSceneGraph project was, while it started as small scene graph library, it step by step encompassed a wider range of components and features that are bundled together. While the OpenSceneGraph stops short of providing all the functionality of Game Engine it is bloated for the needs of many application develolopers.  Early in the VulkanSceneGraph project the decision was made to create a core general purpose scene graph library and a collection of libraries each focused on specific features that users can easily compile and use in their applications if they need them.

Features that all Vulkan applications developers will need, so provide by the VulkanSceneGraph library:
* robustly create and cleanup data
* serialization of scene graph objects to native ascii and binary file formats
* extensible mechanism for reading/writing 3rd party data.
* vector math classes and associated functions
* robust management of the lifetime Vulkan objects including support for Vulkan extensions
* scene graph internal nodes, state and geometry
* creation and management of Vulkan capable windows, offscreen buffers and event handling
* support for views, cameras and control of them
* support for commoly used graphics pipelines - flat shaded, phong and physics based rendering

While the VulkanSceneGraph is focused on these general purpose features, it is intended that it be a foundation for other libraries that add additional features or as a base component for higher level SDK's like Image Generators (IGs) or Game Engines.

The [vsg-dev](https://github.com/vsg-dev) github account hosts the following projects which are officially supported as part the VulkanSceneGraph project, the three main projects that majority of developers will need to use are:
* [VulkanSceneGraph](https://github.com/vsg-dev/VulkanSceneGraph) - The VulkanSceneGraph library itself is capable of used on it's own for stand alone graphics applications, and for embedded platforms this may be the desired approach as it will minimize the code base that needs to be QA'd for sercurity and robustness, and minimizes the final exectuble size.
* [vsgXchange](https://github.com/vsg-dev/vsgXchange)  
It is expected for most desktop applications users will also want to load a range of 3rd image and 3d model data, to support this usage case the  library adds support for a wide range of image and 3d model formats, using assimp, as well as support for reading data from http/https using libcurl, and reading/writing/processing of GIS imagery and DEMS through the optional GDAL integration.
* [vsgExamples](https://github.com/vsg-dev/vsgExamples)  
A collection of 59 examples (as of 20th March 2023) that have written to help test VulkanSceneGraph features as they are developed and as an educational tool for new users.

Also hosted on vsg-dev are more specialist projects:

* [osg2vsg](https://github.com/vsg-dev/osg2vsg) - osg2vsg library for converting data and integrating OpenGL/OSG and Vulkan/VSG applications. vsgXchange will automatically add support for reading data using the the OpenSceneGraph's loader when osg2vsg has been built and installed before vsgXchange.
* [vsgImGui](https://github.com/vsg-dev/vsgImGui) - ImGui and ImPlot integration with the VulkanSceneGraph
* [vsgQt](https://github.com/vsg-dev/vsgQt) - Qt5/Qt6 integrtation with the VulkanSceneGraph
* [vsgUnity](https://github.com/vsg-dev/vsgUnity) - plugin for the Unity Editor for expoting VulkanSceneGraph models
* [MyFirstVsgApplication](https://github.com/vsg-dev/MyFirstVsgApplication) - simple stanndalone example illustrating the CMake and C++ required.
* [vsgFramework](https://github.com/vsg-dev/vsgFramework) - template project that uses CMake FetchContent to pull in all the main libraries associated with VulkanSceneGraph and dependencies and builds them together.

Community projects:
* [vsgSDL](https://github.com/ptrfun/vsgSDL) SDL integration with VulkanSceneGraph.
* [vsgvr](https://github.com/geefr/vsgvr) OpenVR integration with VulkanSceneGraph.
* [vsgCs](https://github.com/timoore/vsgCs) 3D Tiles and Cesium ion integration
* [vsgEarth](https://github.com/timoore/vsgEarth) osgEarth integration

## When 3rd party dependencies don't cut it

During the initial development of VulkanSceneGraph various 3rd party dependencies, like gm and glfw, were considered for features like maths and windowing, but in each of these cases it was decided to implement the required features within the project rather than add an external dependency.  The reasons for implementing the functionality within the project:

* Coherent class interfaces and naming
* Coherent memory management
* Provide classes focused just on the needs of the VulkanSceneGraph users
* Avoid the glue code required to bring different libraries to work well together
* Keep memory and CPU overhead to a minimum
* Keep dependencies to a minimum to avoid ***Dependency Hell**
* Keep licensing simple and permissive

An example how local implementations can achieve what we need with far less code can be seen looking the glm maths library. It's a header only library with over 63,000 lines of code.  The VulkanSceneGraph has all GLSL style vector, quaternion and matrix functionality it needs in less than 3,000 lines of code. The whole code base has 57,000 lines of code for it's headers and source, and it has a scene graph, Vulkan integration, cross plarform windoing, viewer classes, serialization support and much more.

## 3rd party dependencies that add value

The VulkanSceneGraph library uses Vulkan, C++17 and CMake as external dependencies. The Vulkan C headers are used rather then the Vulkan C++ header which is unncessary as the Vulkan scene graph provides it's own encapsulation of Vulkan objects in a way that is coherent with how they are used in the scene graph.

For runtime shader compilation support the [glslang](https://github.com/KhronosGroup/glslang) library, orginally an optionally external dependency, but since VulkanSceneGraph-1.0.3 is now built internally as a submodule, this is compiled in by default but can be toggled off by setting the CMake VSG_SUPPORTS_ShaderCompiler variable to 0 before building the source. Compiling glslang within the VulkanSceneGraph library resolved problems with inconsistent 3rd party packaging of glslang, so now users can have seamlessly experience across platforms.

The additional VulkanSceneGraph projects add their own dependencies:

| Project | Required | Optional |
| [VulkanSceneGraph](https://github.com/vsg-dev/VulkanSceneGraph) | C++17, CMake, Vulkan | glslang integrated as a submodule |
| [vsgXchange](https://github.com/vsg-dev/vsgXchange) | VulkanSceneGraph | curl, assimp, gdal, freetype, OpenEXR, osg2vsg |
| [vsgImGui](https://github.com/vsg-dev/vsgImGui) | VulkanScenegraph, ImGui integrated as a submodule | |
| [vsgQt](https://github.com/vsg-dev/vsgQt) | VulkanSceneGraph, Qt5.10 or later, Qt6 | |
| [vsgExamples](https://github.com/vsg-dev/vsgExamples) | VulkanSceneGraph | vsgXchange, vsgImGui |

---

 Prev: [Vulkan](Vulkan.md)| Next: [VulkanSceneGraph Library](VulkanSceneGraphLibrary.md)
