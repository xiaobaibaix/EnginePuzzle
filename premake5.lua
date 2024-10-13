workspace "EnginePuzzle2.0"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"]="Puzzle/vendor/GLFW/include"
IncludeDir["GLAD"]="Puzzle/vendor/GLAD/include"
IncludeDir["ImGui"]="Puzzle/vendor/imgui"

include "Puzzle/vendor/GLFW"
include "Puzzle/vendor/GLAD"
include "Puzzle/vendor/imgui"

project "Puzzle"
	location "Puzzle"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	pchheader "pzpch.h"
	pchsource "Puzzle/src/platform/pzpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs{
		".",
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}"
	}
	
	links{
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"PZ_PLATFORM_WINDOWS",
			"PZ_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
			"PZ_ENABLE_ASSERTS"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/"..outputdir.."/Sandbox")
		}

	filter "configurations:Debug"
		defines "PZ_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PZ_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "PZ_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Puzzle/vendor/spdlog/include",
		"Puzzle/src"
	}
	
	links{
		"Puzzle"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"PZ_PLATFORM_WINDOWS",
		}


	filter "configurations:Debug"
		defines "PZ_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PZ_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "PZ_DIST"
		buildoptions "/MD"
		optimize "On"