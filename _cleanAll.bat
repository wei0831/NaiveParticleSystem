GOTO EndComment
/******************************************************************************/
/*!
 \file   _cleanAll.bat
 \author Jack Chang
 \date   07/31/2014
 \par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
    Clear all unneeded files
 */
/******************************************************************************/
:EndComment

@echo off
call _clean.bat

rm dependency.zip
rm assests.zip
rmdir /S /Q dependency
rmdir /S /Q assets
