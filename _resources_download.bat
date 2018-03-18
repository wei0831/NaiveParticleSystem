@echo off
GOTO EndComment
/******************************************************************************/
/*!
 \file   _dependency_download.bat
 \author Jack Chang
 \date   07/31/2014
 \par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
    Download a zip file contains all the dependency
    Create a folder named dependency and unzip all the files into the folder
 */
/******************************************************************************/
:EndComment

SET ThisScriptsDirectory=%~dp0
SET PowerShellScriptPath=%ThisScriptsDirectory%\tools\dependency_unzip.ps1

echo Downloading Dependency... Please Wait...
powershell -Command "Invoke-WebRequest https://dl.dropboxusercontent.com/u/25873174/dependency.zip -OutFile dependency.zip"
mkdir dependency
PowerShell -NoProfile -ExecutionPolicy Bypass -Command "& '%PowerShellScriptPath%' 'dependency.zip'" 
rm dependency.zip

SET ThisScriptsDirectory=%~dp0
SET PowerShellScriptPath=%ThisScriptsDirectory%\tools\dependency_unzip.ps1

echo Downloading Assests... Please Wait...
powershell -Command "Invoke-WebRequest https://dl.dropboxusercontent.com/u/25873174/assets.zip -OutFile assets.zip"
mkdir assets
PowerShell -NoProfile -ExecutionPolicy Bypass -Command "& '%PowerShellScriptPath%' 'assets.zip'" 
rm assets.zip

echo All resources are downloaded.

pause
