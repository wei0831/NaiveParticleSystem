GOTO EndComment
/******************************************************************************/
/*!
 \file   _clean.bat
 \author Jack Chang
 \date   07/31/2014
 \par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
    Clear all unneeded files
 */
/******************************************************************************/
:EndComment

@echo off
rmdir /S /Q obj
rmdir /S /Q bin
rmdir /S /Q build
rmdir /S /Q debug
rmdir /S /Q release
rmdir /S /Q ipch
rm *.sdf
rm *.opensdf
rm *.sln
rm *.suo
rm *.vcxproj*
