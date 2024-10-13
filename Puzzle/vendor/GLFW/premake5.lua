
project "GLFW"
	kind "StaticLib"
	language "C"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("bin-int/"..outputdir.."/%{prj.name}")

	files{
		"inlcude/GLFW/glfw3.h",
		"inlcude/GLFW/glfw3native.h",
		"src/*.h",
		"src/**.c",
	}
	
	filter "system:windows"
		buildoptions {"-std=c11","-lgdi32"}
		systemversion "latest"
		staticruntime "On"

		files{
			"src/**.c",
		}

		defines{
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}
	filter{"system:windwows","configurations:Release"}
		buildoptions "/MT"
