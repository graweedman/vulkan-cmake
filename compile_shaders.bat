@echo off

set SHADER_COMPILER = "c:\VulkanSDK\1.3.250.1\Bin\glslc.exe"

c:\VulkanSDK\1.3.250.1\Bin\glslc.exe shaders\simple_shader.vert -o build\Debug\shaders\simple_shader.vert.spv
c:\VulkanSDK\1.3.250.1\Bin\glslc.exe shaders\simple_shader.frag -o build\Debug\shaders\simple_shader.frag.spv

pause