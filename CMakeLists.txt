cmake_minimum_required(VERSION 3.23)
project(GemetrySandbox)

set(CMAKE_CXX_STANDARD 14)

include_directories(Intermediate/Build/Win64/GemetrySandboxEditor/Development/Engine)
include_directories(Intermediate/Build/Win64/UE4Editor/Development)
include_directories(Intermediate/Build/Win64/UE4Editor/Development/GemetrySandbox)
include_directories(Intermediate/Build/Win64/UE4Editor/Inc/GemetrySandbox)
include_directories(Source/GemetrySandbox)
include_directories(Source/GemetrySandbox/Public)

add_executable(GemetrySandbox
        Intermediate/Build/Win64/GemetrySandboxEditor/Development/Engine/SharedPCH.Engine.ShadowErrors.cpp
        Intermediate/Build/Win64/GemetrySandboxEditor/Development/Engine/SharedPCH.Engine.ShadowErrors.h
        Intermediate/Build/Win64/GemetrySandboxEditor/Development/Engine/SharedPCH.Engine.ShadowErrors.h.pch
        Intermediate/Build/Win64/UE4Editor/Development/GemetrySandbox/Definitions.GemetrySandbox.h
        Intermediate/Build/Win64/UE4Editor/Inc/GemetrySandbox/BaseGeometryActor.gen.cpp
        Intermediate/Build/Win64/UE4Editor/Inc/GemetrySandbox/BaseGeometryActor.generated.h
        Intermediate/Build/Win64/UE4Editor/Inc/GemetrySandbox/GemetrySandbox.init.gen.cpp
        Intermediate/Build/Win64/UE4Editor/Inc/GemetrySandbox/GemetrySandboxClasses.h
        Intermediate/Build/Win64/UE4Editor/Inc/GemetrySandbox/GemetrySandboxGameModeBase.gen.cpp
        Intermediate/Build/Win64/UE4Editor/Inc/GemetrySandbox/GemetrySandboxGameModeBase.generated.h
        Source/GemetrySandbox/Private/BaseGeometryActor.cpp
        Source/GemetrySandbox/Public/BaseGeometryActor.h
        Source/GemetrySandbox/GemetrySandbox.cpp
        Source/GemetrySandbox/GemetrySandbox.h
        Source/GemetrySandbox/GemetrySandboxGameModeBase.cpp
        Source/GemetrySandbox/GemetrySandboxGameModeBase.h)
