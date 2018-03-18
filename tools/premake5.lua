--[[
/******************************************************************************/
/*!
 \file   premake5.lua
 \author Jack Chang
 \par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
]]

solution "NaiveParticleSystem"
  configurations { "Debug", "Release" }
  location "../"

project "NaiveParticleSystem"
  targetname "NaiveParticleSystem"
  location "../build/"
  language "C++"
  objdir "../build/obj"
  kind "ConsoleApp"

  -- source files
  files
  {
    "../include/**.h",
    "../include/**.hpp",
    "../source/**.cpp",
    "../source/**.hpp"
  }

  includedirs
  {
    "../dependency/SFML/include",
    "../dependency/AntTweakBar/include",
    "../include",
    "../include/**"
  }

  libdirs
  {
    "../dependency/SFML/lib",
    "../dependency/AntTweakBar/lib"
  }

  configuration "Debug"
    flags { "Symbols", "NoMinimalRebuild" }
    buildoptions { "/MP" }
    defines { "_DEBUG", "_CRT_SECURE_NO_WARNINGS" }
    links
    {
      "sfml-audio-d", "sfml-graphics-d", "sfml-network-d", "sfml-system-d", "sfml-window-d",
      "AntTweakBar64"
    }
    targetdir "../debug"
    postbuildcommands
    {
      "copy ..\\dependency\\SFML\\bin\\sfml-audio-d-2.dll ..\\debug\\",
      "copy ..\\dependency\\SFML\\bin\\sfml-graphics-d-2.dll ..\\debug\\",
      "copy ..\\dependency\\SFML\\bin\\sfml-network-d-2.dll ..\\debug\\",
      "copy ..\\dependency\\SFML\\bin\\sfml-system-d-2.dll ..\\debug\\",
      "copy ..\\dependency\\SFML\\bin\\sfml-window-d-2.dll ..\\debug\\",
      "copy ..\\dependency\\AntTweakBar\\lib\\AntTweakBar.dll ..\\debug\\"
    }

  configuration "Release"
    flags { "NoMinimalRebuild" }
    buildoptions { "/MP" }
    optimize "Full"
    defines { "NDEBUG", "_CRT_SECURE_NO_WARNINGS" }
    links
    {
      "sfml-audio", "sfml-graphics", "sfml-network", "sfml-system", "sfml-window",
      "AntTweakBar64"
    }
    targetdir "../release"
    postbuildcommands
    {
      "copy ..\\dependency\\SFML\\bin\\sfml-audio-2.dll ..\\release\\",
      "copy ..\\dependency\\SFML\\bin\\sfml-graphics-2.dll ..\\release\\",
      "copy ..\\dependency\\SFML\\bin\\sfml-network-2.dll ..\\release\\",
      "copy ..\\dependency\\SFML\\bin\\sfml-system-2.dll ..\\release\\",
      "copy ..\\dependency\\SFML\\bin\\sfml-window-2.dll ..\\release\\",
      "copy ..\\dependency\\AntTweakBar\\lib\\AntTweakBar.dll ..\\release\\"
    }
