<#
/******************************************************************************/
/*!
 \file   dependency_unzip.ps1
 \author Jack Chang
 \date   07/31/2014
 \par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
    Script to extract zipfile
 */
/******************************************************************************/
#>
$shell_app=new-object -com shell.application
$filename = $args[0]
$zip_file = $shell_app.namespace((Get-Location).Path + "\$filename\")
$destination = $shell_app.namespace((Get-Location).Path)
$destination.Copyhere($zip_file.items())