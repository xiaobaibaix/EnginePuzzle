
project "GLAD"
	kind "StaticLib"
	language "C"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("bin-int/"..outputdir.."/%{prj.name}")

	files{
		"inlcude/GLAD/glad.h",
		"inlcude/KHR/khrplatform.h",
		"src/glad.c",
	}
	
	includedirs{
		"include"
	}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

	filter{"system:windwows","configurations:Release"}
		buildoptions "/MT"
